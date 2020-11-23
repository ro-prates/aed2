/*
Descrição:
Implemente um algoritmo que mescle dois vetores de números inteiros já
ordenados e crie um terceiro vetor, igualmente ordenado de números inteiros.

Entrada:
A entrada consiste de 4 linhas onde a primeira define o tamanho do primeiro
vetor (array VETA), limitado a 100 elementos do tipo inteiro. Na segunda linha
deve-se informar cada elementos de VETA (sempre números inteiros positivos,
negativos ou zero). Na terceira e quarta linha o procedimento se repete mas para o
segundo array, ou seja, deve-se informar o tamanho de VETB e os elementos do
próprio array VETB.

Saı́da:
Imprima o vetor mesclado resultante com os números em ordem crescente.

Entrada 1:
4
1 10 23 45
5
2 3 4 92 98

Saída 1:
1 2 3 4 10 23 45 92 98

Entrada 2:
3
10 20 30
6
1 15 35 40 70 80

Saída 2:
1 10 15 20 30 35 40 70 80
*/

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int *vetora, *vetorb, a=0, b=0, quantidadea, quantidadeb, i, total, *vetorfinal, restaa, restab;
        scanf("%d", &quantidadea);
        vetora = (int *) malloc(quantidadea*sizeof(int));
         for(i=0; i<quantidadea;i++){ //inserindo os valores no vetor a
            scanf("%d", &vetora[i]);
        }
            scanf("%d", &quantidadeb);
            vetorb = (int *) malloc(quantidadeb*sizeof(int));
            for(i=0; i<quantidadeb;i++){ //inserindo os valores no vetor b
                scanf("%d", &vetorb[i]);
            }
 
        total = quantidadeb + quantidadea;
        vetorfinal = (int *) malloc(total*sizeof(int));
        restaa = quantidadea; //variável para controlar se o vetor a já "ficou" vazio
        restab = quantidadeb; //variável para controlar se o vetor b já "ficou" vazio
     
        for(i=0; i<total; i++){ // fazendo as comparações necessárias
            if(restaa == 0 ){
                vetorfinal[i] = vetorb[b];
                b++;
            }else if(restab == 0){
                vetorfinal[i] = vetora[a];
                a++;
            }else if(vetora[a] < vetorb[b]){
                    vetorfinal[i] = vetora[a];
                    a++;
                    restaa--;
                 }else{ vetorfinal[i] = vetorb[b];
                     b++;
                     restab--;
                 }
        }
        for(i=0; i<total; i++){ //mostrando a saída
            printf("%d ", vetorfinal[i]);
        }
        free(vetora);
        free(vetorb);
        free(vetorfinal);
    return 0;
}