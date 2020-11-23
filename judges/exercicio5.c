/*
O Counting sort é um algoritmo de ordenação adequado para ordenar N inteiros de valores 0 a k
e k=O(N). Porém, este método apresenta restrição para ser aplicado na classificação de um
conjunto de strings, pois para isso seria preciso realizar conversão de base numérica e k se
tornaria muito grande para strings compridas.
O Radix sort, por outro lado, pode ser aplicado para ordenação de strings utilizando o Counting
sort para ordenar a entrada em relação a apenas uma posição das strings por vez, sendo que cada
caracter seria considerado como um “dígito” do algoritmo. Considerando que strings podem ter
comprimentos diferentes, um caractere adicional (espaço em branco, ou o número 32 da tabela
ASCII em decimal, por exemplo) pode ser utilizado para preencher posições vazias de strings
mais curtas, para que todas strings tenham o mesmo comprimento d (tamanho da maior string).

Deve-se implementar um programa que leia da entrada um conjunto de nomes com até 15
caracteres cada (cada caractere é uma letra dentro dos intervalos [A, Z] e [a, z]) e que ordene-os
em ordem alfabética. Você deverá converter todas as letras maiúsculas para letras minúsculas
antes de realizar a ordenação.
A ordenação deve ser realizada utilizando o algoritmo de ordenação Radix sort e o Counting
sort para ordenar cada posição das strings. O número de dígitos d deve ser o comprimento da
maior string presente na entrada de cada caso de teste. Para cada “dígito”, você deve imprimir os
valores em cada posição do vetor auxiliar C após a execução da linha 8 do algoritmo Counting
sort apresentado acima. O vetor C deve ser de tamanho k=27, sendo a primeira posição
destinada ao caractere adicional (vazio) e as posições restantes referentes às 26 letras minúsculas
em ordem crescente (a, ..., z).

Após a ordenação, você deve imprimir uma região indicada da lista ordenada com os nomes em
letras minúsculas.

Entrada
A primeira linha da entrada contém o número N (2 ≤ N ≤ 100.000) referente a quantidade de
nomes a serem ordenados. As próximas N linhas devem conter os respectivos nomes de acordo
com a ordem de entrada, sendo um nome para cada linha.
A linha seguinte indica o que deverá ser impresso na saída, e contém dois números: P (1 ≤ P ≤
N) referente a posição do primeiro nome da lista ordenada a ser impresso, e o número M (1 ≤ M
≤ N-P+1) referente a quantidade de números a partir do P-ésimo nome da lista ordenada.

Saída
Para cada “dígito” i do Radix sort, imprima uma linha com os 27 valores do vetor C do
Counting sort. Nas próximas M linhas, imprima os M nomes presentes a partir da P-ésima
posição da lista ordenada, um nome a cada linha sem os caracteres adicionais.

Entrada 1:
5
Daniel
Ana
Jose
Silvia
Joao
1 5

Saída 1:
3 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
3 3 3 3 3 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
1 1 1 1 1 2 2 2 2 3 3 3 3 3 3 4 4 4 4 4 4 4 5 5 5 5 5
0 2 2 2 2 2 2 2 2 2 2 2 3 3 4 4 4 4 4 5 5 5 5 5 5 5 5
0 1 1 1 1 1 1 1 1 2 2 2 2 2 3 5 5 5 5 5 5 5 5 5 5 5 5
0 1 1 1 2 2 2 2 2 2 4 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5
ana
daniel
joao
jose
silvia

Entrada 2:
10
Zurich
Zu
Wu
Hu
Zukemberg
Wei
Woo
Zoo
Zuu
aaaaa
1 10

Saída 2:
9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10
9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
8 8 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
7 8 8 9 9 9 9 9 9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10
7 8 8 8 8 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
3 4 4 4 4 4 4 4 4 5 5 6 6 6 6 8 8 8 9 9 9 10 10 10 10 10 10
0 1 1 1 1 2 2 2 2 2 2 2 2 2 2 4 4 4 4 4 4 10 10 10 10 10 10
0 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 5 5 5 10
aaaaa
hu
wei
woo
wu
zoo
zu
zukemberg
zurich
zuu

Entrada 3:
10
USA
brazil
zimbabwe
Burundi
Iraq
Vietnam
Greece
bhutan
Iran
Ukraine
5 5

Saída 3:
9 9 9 9 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
6 6 6 6 6 7 7 7 7 8 8 8 8 9 9 9 9 9 9 9 9 9 9 10 10 10 10
3 4 5 5 6 7 7 7 7 7 7 7 8 8 10 10 10 10 10 10 10 10 10 10 10 10 10
3 5 5 6 6 6 6 6 6 8 8 8 8 8 10 10 10 10 10 10 10 10 10 10 10 10 10
1 2 3 3 3 4 4 4 4 4 4 4 4 4 5 5 5 6 6 6 8 9 9 9 9 9 10
0 4 4 4 4 6 6 6 6 6 6 6 6 7 7 7 7 7 9 9 9 10 10 10 10 10 10
0 0 0 0 0 0 0 0 1 3 3 4 4 4 4 4 4 4 8 9 9 10 10 10 10 10 10
0 0 3 3 3 3 3 4 4 6 6 6 6 6 6 6 6 6 6 6 6 8 9 9 9 9 10
iran
iraq
ukraine
usa
vietnam
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void radixsort(char ** nomes_originais, int quantidade, int maior){
    int C[27], i; 
    char troca[maior];
    int controle_troca = maior-1;
 
    for(i=0; i<27; i++){
        C[i] = 0;
    }
 
    maior--;
    while(maior >= 0){
        int decremento = 1;
        int decremento1 = 1;
        for(i=0; i<quantidade; i++){
            if(nomes_originais[i][maior] == 32){
                C[0]++;
            }else{
                C[nomes_originais[i][maior] - 96]++;
            }
        }
        for(i=1; i<27; i++){
            C[i] += C[i-1];
        }
 
        for(i=0; i<27; i++){
            printf("%d ", C[i]);  
            C[i] = 0;
        }
    
        printf("\n");
        maior--;
    }
}
 
int main(){
    int quantidade = 0, i, espacos = 0;
    int posicao_de_inicio, quantidade_ser_mostrada;
    int maior = 0, j, soma = 0;
    char **nomes;
    char temp[15];
 
    scanf("%d", &quantidade);
 
    nomes = malloc(sizeof(char*)*quantidade); 
 
    for(i=0;i<quantidade;i++){
        nomes[i]=malloc(sizeof(char)*15); 
    }
 
    for(i = 0; i < quantidade; i++){
        scanf("%s", nomes[i]);
    }
 
    scanf("%d %d", &posicao_de_inicio, &quantidade_ser_mostrada);
    posicao_de_inicio--;
    soma = posicao_de_inicio + quantidade_ser_mostrada;
 
    //verificando qual a maior string
    maior = strlen(nomes[0]);
    for(i = 1; i < quantidade; i++){
        if(strlen(nomes[i]) > maior){
            maior = strlen(nomes[i]);
        }   
    }
 
    //formatando o primeiro digito dos nomes
    for(i = 0; i < quantidade; i++){
        for (j = 0; j < maior; j++){
            if(nomes[i][j] >= 65 && nomes[i][j] <= 90){
                nomes[i][j] = nomes[i][j] + 32;
            }
        }
    }
 
 
    //preenchendo os nomes com espaço em branco
    for(i = 0; i < quantidade; i++){
        espacos = strlen(nomes[i]);
        for (espacos; espacos < maior; espacos++){
            strcat(nomes[i], " ");
        }
    }
 
    radixsort(nomes, quantidade, maior);
 
    for(i=0;i<=quantidade-1;i++)
        for(j=i+1;j<=quantidade-1;j++){
            if(strcmp(nomes[i],nomes[j])>0){
                strcpy(temp,nomes[i]);
                strcpy(nomes[i],nomes[j]);
                strcpy(nomes[j],temp);
            }
        }
 
    for(posicao_de_inicio; posicao_de_inicio < soma; posicao_de_inicio++){
        printf("%s\n", nomes[posicao_de_inicio]);
    }
 
    for(i=0;i<quantidade;i++) 
        free(nomes[i]); 
    free(nomes);
    return 0;
}