#include <stdio.h>

int particiona(int *vetor, int inicio, int final){
    int esquerda, direita, pivo, auxiliar;
    esquerda = inicio;
    direita = final;
    pivo = vetor[inicio];
    while (esquerda < direita){
        while (vetor[esquerda] <= pivo) // avança posição da esquerda
            esquerda++;
        while (vetor[direita] > pivo) // avança posição da direita
            direita--;
        if(esquerda < direita){ // troca esquerda e direita
            auxiliar = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = auxiliar;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;
    return direita;
}

void quicksort(int *vetor, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(vetor, inicio, fim);
        quicksort(vetor, inicio, (pivo - 1));
        quicksort(vetor, (pivo + 1), fim);
    }
}

int main(){
int *vetor, tamanho, i, inicio = 0, final;
        printf("qual o tamanho do vetor?\n");
        scanf("%d", &tamanho);
    vetor = (int *) malloc(tamanho * sizeof(int));
    final = tamanho - 1;
    printf("digite os valores do vetor:\n");
        for (i = 0; i < tamanho; i++){
            scanf("%d", &vetor[i]);
        }
    printf("seu vetor eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }

    quicksort(vetor, inicio, final);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }

    free(vetor);
    return 0;
}