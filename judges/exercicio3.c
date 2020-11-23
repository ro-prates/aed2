/*
O Quicksort é um algoritmo considerado muito rápido para a maioria das
situações. Considere o algoritmo abaixo do Quicksort, em que o pivô
escolhido como uma mediana de 3 valores, onde esse três valores devem
ser definidos como: a) primeiro elemento do intervalo considerado do vetor,
b) o elemento na posição do meio e c) o último elemento, de acordo com o
pseudo-código a seguir:

//Escolha do Pivo por mediana de 3
meio = (p+r)/2;
a = A[p];
b = A[meio];
c = A[r];
medianaIndice = 0; //índice da mediana (zero para inicio)
//A sequência de if...else a seguir verifica qual é a mediana
if (a < b)
if (b < c) //a < b && b < c
medianaIndice = meio;
else
if (a < c) //a < c && c <= b
medianaIndice = r;
else //c <= a && a < b
medianaIndice = p;
else
if (c < b) //c < b && b <= a
medianaIndice = meio;

eles
if (c < a) //b <= c && c < a
medianaIndice = r;
else //b <= a && a <= c
medianaIndice = p;
//coloca o elemento da mediana no fim para poder usar o
//Quicksort do Cormen
trocar(A, medianaIndice, r)
//Restante do código do algoritmo de particao (Cormen)
...

Você deve implementar um programa que leia da entrada um conjunto de
informações sobre N pessoas contendo o nome de cada pessoa com até 15
caracteres e a sua idade. O seu programa deverá utilizar o algoritmo do
Quicksort com escolha do pivo por mediana de 3, conforme indicado acima,
e que ordene-os de forma crescente por idade. Posteriormente deve-se
verificar se o resultado da ordenação é estável, ou seja, se pessoas com a
mesma idade foram mantidas na mesma ordem relativa da entrada. Após a
ordenação, você deve imprimir uma região indicada da lista ordenada.

Entrada
A primeira linha da entrada contém o número N (2 ≤ N ≤ 105.000) de pessoas a serem
ordenadas. Nas próximas N linhas são apresentados, em cada linha, um nome de até 15
caracteres e um inteiro representando a idade. A linha seguinte contém dois números P
(1 ≤ P ≤ N) da posição do primeiro nome a ser impresso e o número M (1 ≤ M ≤ N-P+1) de
pessoas a serem impressas partir do P-éssimo nome.

Saída
Na primeira linha da saída, imprima “yes” se a ordenação for estável, ou “no”, caso
contrário. Nas próximas M linhas, imprima os M nomes e idades presentes a partir da P-
éssima posição da lista ordenada, uma pessoa a cada linha.

Entrada 1:
4
Alex 20
Gabriel 20
Joana 18
Rodrigo 18
1 4

Saída 1:
no
Rodrigo 18
Joana 18
Alex 20
Gabriel 20

Entrada 2:
5
Daniel 25
Ana 21
Jose 22
Silvia 25
Joao 23
3 2

Saída 2:
yes
Joao 23
Daniel 25
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct pessoa{
    char nome[15];
    int idade;
}pessoa;
 
void swap(pessoa *pop, int i, int j){
    pessoa temp;
    temp = pop[i];
    pop[i] = pop[j];
    pop[j] = temp;
}
 
int partition(pessoa *pop, int inicio, int fim) {
    int meio, a, b, c, mediana_indice;
    pessoa pivo;
 
    meio = (inicio + fim) / 2;
    a = pop[inicio].idade;
    b = pop[meio].idade;
    c = pop[fim].idade;
    mediana_indice; 
 
    if (a < b){
        if (b < c){
            mediana_indice = meio;
        }else{
            if (a < c){
                mediana_indice = fim;
            }else{
                mediana_indice = inicio;
            }
        }
    }else{
        if (c < b){
            mediana_indice = meio;
        }else{
            if(c < a){
                mediana_indice = fim;
            }else{
                mediana_indice = inicio;
            }
        }
    }
    swap(pop, mediana_indice, fim);
        
    pivo = pop[fim];
    int i = inicio - 1;
    int j;
 
    for (j = inicio; j <= fim - 1; j++) {
        if (pop[j].idade <= pivo.idade) {
            i = i + 1;
            swap(pop, i, j);
        }
    }
    
    swap(pop, i + 1, fim);
    return i + 1; 
}
 
void quicksort(pessoa *pop, int inicio, int fim) {
    if (inicio < fim) {
        int q = partition(pop, inicio, fim);
        quicksort(pop, inicio, q - 1);
        quicksort(pop, q + 1, fim);
    }
}
 
void insertionsortidade(pessoa *auxiliar, int n){ //ordenação estável
    int i, j;
    pessoa aux;
 
    for(i = 1; i < n; i++){
        aux = auxiliar[i];
        for(j = i; (j > 0) && (aux.idade < auxiliar[j - 1].idade); j--)
            auxiliar[j] = auxiliar[j - 1];
        auxiliar[j] = aux;
    }
}
 
int main (){
    int i, tamanho, inicio = 0, final, mediana_indice = 0, posicao_inicial, quantidade_exibida;
    int controle = 0;
    pessoa *pop, *auxiliar;
 
    scanf("%d", &tamanho);
    pop = (pessoa *) malloc(tamanho * sizeof(pessoa));
    auxiliar = (pessoa *) malloc(tamanho * sizeof(pessoa));
 
    final = tamanho - 1;
 
        for (i = 0; i < tamanho; i++){
            scanf("%s %d", pop[i].nome, &pop[i].idade);
            auxiliar[i] = pop[i];
        }
        
    scanf("%d %d", &posicao_inicial, &quantidade_exibida);
    posicao_inicial--;
    quantidade_exibida = quantidade_exibida + posicao_inicial;
 
    quicksort(pop, inicio, final);
    insertionsortidade(auxiliar, tamanho);
 
 
    for(i = 0; i < tamanho; i++){
        if(strcmp(auxiliar[i].nome, pop[i].nome) == 0){
            controle++;
        }
    }
 
    if(controle == tamanho){
        printf("yes\n");
        for (i = posicao_inicial; i < quantidade_exibida; i++){
            printf("%s %d\n", pop[i].nome, pop[i].idade);
        }
    }else{
       printf("no\n");
        for (i = posicao_inicial; i < quantidade_exibida; i++){
            printf("%s %d\n", pop[i].nome, pop[i].idade);
        }
    }
    free(pop);
    free(auxiliar);
    return 0;
}