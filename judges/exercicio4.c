/*
Implemente o algoritmo de ordenação HeapSort, conforme
especificado nos slides e video-aula (de acordo com o livro T. Cormen).

Escreva um procedimento separado para as seguintes operações: a) max-
heapfy(...), b) build-max-heap(...), c) heap-extract-max(...) e d)
heapSort(...).

Entrada
A entrada consiste de duas linhas, sendo a primeira contendo um número
inteiro N (1 ≤ N ≤ 10.000) que especifica a quantidade de valores do arranjo original a
serem ordenados.
A segunda linha contém uma sequência de números inteiros separados por
espaços, onde cada número inteiro Ai pode estar na faixa: 0 ≤ Ai ≤ 10.000,
correspondendo ao arranjo original a ser ordenado.

Saída
A saída consiste de duas linhas, sendo a primeira o vetor rearranjado após a
chamada a rotina build-max-heap(...). A segunda linha corresponde ao vetor final
devidamente ordenado.

Entrada 1:
4
8 5 6 7

Saída 1:
8 7 6 5
5 6 7 8

Entrada 2:
10
10 2 4 5 8 5 6 7 11 20

Saída 2:
20 11 6 10 8 5 4 7 5 2
2 4 5 5 6 7 8 10 11 20
*/

#include <stdio.h>
#include <stdlib.h>
 
int parent(int i){
    return (i/2);
}
 
int esquerda(int i){
    return (2*i+ 1);
}
 
int direita(int i){
    return (2*i + 2);
}
 
void max_heapify(int *vetor, int i, int *h){
    int maior, left, right;
    
    left = esquerda(i);
    right = direita(i);
    
    if(left <= *h && vetor[left] > vetor[i])
        maior =  left;
    else
        maior = i;
    
    if (right <= *h && vetor[right] > vetor[maior])
        maior = right;
    
    if(maior != i){
        int aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        max_heapify(vetor, maior, h);
    }
        
}
                            
void build_max_heap(int *vetor, int n, int *h){
    int i;
    *h = n - 1;
    for (i = n/2; i >= 0; i--){
        max_heapify(vetor,i,h);        
    }
}
 
void heapsort(int *vetor, int n, int *h){
    int i;
    build_max_heap(vetor,n,h);
    for (i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
 
    for(i = n - 1; i > 0; i--){
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        *h = *h  - 1;
        max_heapify(vetor,0,h);
    }
}
 
int main (){
    int i, *vetor, tamanho, heap_size = 0;
 
    scanf("%d", &tamanho);
 
    vetor = (int*) malloc(tamanho * sizeof(int));
    
    for (i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
 
    heapsort(vetor, tamanho, &heap_size);
 
    printf("\n");    
    for(i = 0; i < tamanho; i++)
        printf("%d ",vetor[i]);
    printf("\n");
 
    free(vetor);
    return 0;
}