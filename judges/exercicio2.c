/*
Em tempo de crise, tal qual ocorre no momento com o Covid-19, tudo que compõe orçamento de
governos e instituições deve ser repensando para redução de gastos. Eleições em muitos lugares do mundo são
realizadas em 2 turnos, entretanto, pode-se gerar alguma economia de recursos se puderem ser realizadas em
apenas 1 turno. Porém, a não realização de um segundo turno tem o potencial de eleger um candidato que tenha
um alto percentual de rejeição e que possivelmente não ganharia um segundo turno.
Com o objetivo de tornar eleições com 2 turnos mais econômica, uma universidade está propondo um
procedimento inovador para eleição de reitor para ser realizado em um único dia, onde cada eleitor pode votar em
até 3 candidatos, em ordem de sua preferência, ou seja, o primeiro candidato escolhido é o de maior preferência, e
assim sucessivamente. Para contabilização de votos no primeiro turno apenas os votos em primeira opção são
contabilizados. Caso não haja vencedor no primeiro turno com pelo menos 50% dos votos válidos, um segundo
turno virtual é realizado entre os 2 primeiros candidatos mais votados na eleição de primeiro turno sem realizar
outra consulta, onde, a escolha em qualquer das 3 opções feitas pelos eleitores pode ser contabilizada como um
único voto válido para o segundo turno.
Em uma eleição com C candidatos, cada candidato possui um número único entre 1 e C. Qualquer voto
com valor menor do que 1 ou maior do que C é considerado como voto inválido. Para um candidato vencer no
primeiro turno, ele precisa conquistar pelo menos 50% dos votos válidos. Uma eleição sem nenhum voto válido
no primeiro turno não possui um resultado válido. Empates em número de votos são resolvidos de acordo com o
número dos candidatos. Se dois candidatos empatarem em qualquer um dos turnos, a ordem entre esses candidatos
na classificação é definida de acordo com a ordem crescente dos números desses candidatos (considera-se que o
candidato de menor número é o de maior idade e, portanto, de maior prioridade).
Caso nenhum candidato tenha conquistado pelo menos 50% dos votos em primeira opção, então um
segundo turno virtual é realizado. No segundo turno, o voto de cada eleitor pode ser contabilizado no máximo
uma vez. Se o eleitor não votou em nenhum dos 2 candidatos que disputam o segundo turno em nenhuma das 3
opções, então o seu voto não é computado como voto válido no segundo turno. Caso contrário, o voto de sua
maior preferência em algum candidato que concorre no segundo turno é contado como voto válido ao candidato
escolhido. Por exemplo, em um segundo turno disputado entre os candidatos 2 e 3, se um eleitor votou nos
candidatos 1 2 3, então o seu voto vai para o candidato 2 apenas, pois, em caso do candidato 1 não passar do
primeiro turno, considera-se que o eleitor escolheria o candidato 2 em um segundo turno com a participação do
candidato 2 e qualquer outro candidato.
A sua tarefa é escrever um programa que realize a contagem de votos em até 2 turnos conforme as regras
propostas das eleições econômicas.

Entrada:
A primeira linha de um caso de teste contém os inteiros V (1 ≤ V ≤ 10.000), indicando o número de
eleitores votantes, e C, indicando o número de candidatos (1 ≤ C ≤ 100). Nas próximas V linhas, são apresentados
os votos de cada eleitor votante. Em cada uma dessas linhas, são fornecidos 3 inteiros com as escolhas, em ordem
de preferência, de um eleitor.

Saída:
Caso não haja nenhum voto válido em primeira opção, imprima apenas o número 0. Caso contrário, o seu
programa deve imprimir na primeira linha da saída o número do candidato vencedor do primeiro turno e a
porcentagem de votos com 2 dígitos de precisão, separados por um espaço em branco. Caso o vencedor do

primeiro turno tenha vencido com menos de 50% dos votos válidos, você deve imprimir na segunda linha o
número do vencedor do segundo turno e sua porcentagem de votos com 2 dígitos de precisão, separados por um
espaço em branco. Para os cálculos da porcentagens, deve-se considerar apenas os votos válidos.

Entrada 1:
10 3
1 2 3
1 2 4
2 1 4
2 3 1
3 2 1
3 2 1
1 3 2
4 3 2
2 1 3
1 2 4

Saída 1:
1 44.44
2 60.00

Entrada 2:
7 5
4 2 3
3 5 6
3 2 1
2 3 4
3 2 1
3 2 1
2 3 1

Saída 2:
3 57.14

Entrada 3:
5 3
4 4 4
4 4 4
4 4 4
4 4 1
4 4 4

Saída 3:
0
*/

#include <stdio.h>
#include <stdlib.h>
 
void bubblesort(int *voto1, int tamanho){
    int i, continua, auxiliar, fim = tamanho;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(voto1[i] > voto1[i + 1]){
                auxiliar = voto1[i];
                voto1[i] = voto1[i + 1];
                voto1[i + 1] = auxiliar;
                continua = i;
            }
        } 
        fim--;
    } while (continua != 0);
}
 
int main(){
int numero_eleitores, quantidade_candidatos, *voto1, i, controle, atual = 0, segundo_maior = 0;
int numero_do_maior_candidato = 0, numero_do_segundo_candidato = 0;
int quantidade_voto1 = 0, verifica_voto1, verifica_voto2, verifica_voto3, j = 0, votos_validos1 = 0;
int *auxiliar1, *auxiliar2, *auxiliar3, *auxiliar4, controle_quantidade_votos1 = 0,controle_quantidade_votos2 = 0, controle_quantidade_votos3 = 0;
float porcentagem_votos1 = 0, maior1 = 0, porcentagem_final_maior = 0;
int controle_votos_primeira_opcao = 0;
int quantidade_votos_validos_segundo_turno = 0;
int controle_final_segundo_numero = 0, controle_final_maior_numero = 0;
int quantidade_final_maior = 0, quantidade_final_segundo = 0; 
    scanf("%d %d", &numero_eleitores, &quantidade_candidatos);
 
        auxiliar1 = (int *) malloc(numero_eleitores * sizeof(int));
        auxiliar2 = (int *) malloc(numero_eleitores * sizeof(int));
        auxiliar3 = (int *) malloc(numero_eleitores * sizeof(int));
        auxiliar4 = (int *) malloc(numero_eleitores * sizeof(int));
 
        for(i = 0; i < numero_eleitores; i++){
            scanf("%d %d %d", &verifica_voto1, &auxiliar2[i], &auxiliar3[i]);
            if(verifica_voto1 >= 1 && verifica_voto1 <= quantidade_candidatos){
                auxiliar1[controle_quantidade_votos1] = verifica_voto1;
                controle_quantidade_votos1++;
                controle_votos_primeira_opcao++;
            }
            auxiliar4[i] = verifica_voto1;
        }
 
        quantidade_voto1 = controle_quantidade_votos1;
        votos_validos1 = controle_quantidade_votos1;
 
        voto1 = (int *) malloc(quantidade_voto1 * sizeof(int));
 
        controle_quantidade_votos1 = 0;
        controle_quantidade_votos2 = 0;
        controle_quantidade_votos3 = 0;
        
        for(i = 0; i < numero_eleitores; i++){
            if(auxiliar1[i] != 0){
                voto1[controle_quantidade_votos1] = auxiliar1[i];
                controle_quantidade_votos1++; 
            }
        }
 
    bubblesort(voto1, quantidade_voto1);
 
    controle = voto1[0];
        for(i = 0; i < quantidade_voto1; i++){
            if(voto1[i] == controle){
                atual++;
            }else if(atual > maior1){
                    segundo_maior = maior1;
                    numero_do_segundo_candidato = numero_do_maior_candidato;
                    maior1 = atual;
                    controle = voto1[i];
                    numero_do_maior_candidato = voto1[i - 1];
                    atual = 0;
                    i--;
                }else if(atual > segundo_maior){
                    segundo_maior = atual;
                    numero_do_segundo_candidato = voto1[i - 1];
                    controle = voto1[i];
                    atual = 0;
                    i--;
                }else{
                    if(controle != voto1[quantidade_voto1 - 1]){
                    controle = voto1[i];
                    atual = 0;
                    i--;
                    }
                }
        }
 
        if(atual > maior1){
            segundo_maior = maior1;
            numero_do_segundo_candidato = numero_do_maior_candidato;
            maior1 = atual;
            controle = voto1[i];
            numero_do_maior_candidato = voto1[i - 1];
        }else if(atual > segundo_maior){
            segundo_maior = atual;
            numero_do_segundo_candidato = voto1[i - 1];
        }
 
        porcentagem_votos1 = (float)maior1 / (float)votos_validos1 * 100;
        controle_final_maior_numero = numero_do_maior_candidato;
        controle_final_segundo_numero = numero_do_segundo_candidato;
 
    if(controle_votos_primeira_opcao == 0){
        printf("0");
        return 0;
    }else if(porcentagem_votos1 >= 50){
        printf("\n%d %.2f\n", numero_do_maior_candidato, porcentagem_votos1);
        return 0;
    }else{
        if(controle_final_maior_numero < controle_final_segundo_numero){
        for(i = 0; i < numero_eleitores; i++){
            if(auxiliar4[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar4[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar2[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar2[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar3[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar3[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }
        }
    }else{
        for(i = 0; i < numero_eleitores; i++){
            if(auxiliar4[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar4[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar2[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar2[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar3[i] == controle_final_segundo_numero){
                quantidade_final_segundo++;
                quantidade_votos_validos_segundo_turno++;
            }else if(auxiliar3[i] == controle_final_maior_numero){
                quantidade_final_maior++;
                quantidade_votos_validos_segundo_turno++;
            }
        }
 
    }
}
 
    if(quantidade_final_maior == quantidade_final_segundo && numero_do_maior_candidato < numero_do_segundo_candidato){
        porcentagem_final_maior = (float) quantidade_final_maior / (float) quantidade_votos_validos_segundo_turno * 100;
        printf("%d %.2f\n", numero_do_maior_candidato, porcentagem_votos1);
        printf("%d %.2f", controle_final_maior_numero, porcentagem_final_maior);
    }else if(quantidade_final_maior == quantidade_final_segundo && numero_do_maior_candidato > numero_do_segundo_candidato){
        porcentagem_final_maior = (float) quantidade_final_maior / (float) quantidade_votos_validos_segundo_turno * 100;
        printf("%d %.2f\n", numero_do_maior_candidato, porcentagem_votos1);
        printf("%d %.2f", controle_final_segundo_numero, porcentagem_final_maior);
    }else if(quantidade_final_maior > quantidade_final_segundo){
        porcentagem_final_maior = (float) quantidade_final_maior / (float) quantidade_votos_validos_segundo_turno * 100;
        printf("%d %.2f\n", numero_do_maior_candidato, porcentagem_votos1);
        printf("%d %.2f", controle_final_maior_numero, porcentagem_final_maior);
    }else{
        porcentagem_final_maior = (float) quantidade_final_segundo / (float) quantidade_votos_validos_segundo_turno * 100;
        printf("%d %.2f\n", numero_do_maior_candidato, porcentagem_votos1);
        printf("%d %.2f", controle_final_segundo_numero, porcentagem_final_maior);
    }
 
    free(voto1);
    free(auxiliar1);
    free(auxiliar2);
    free(auxiliar3);
    free(auxiliar4);
    return 0;
}