#include <stdio.h>

void selectionsort(int *vetor, int tamanho){
    int i, j, menor, auxiliar;
    for(i = 0; i < tamanho; i++){
        menor = i;
        for(j = i + 1; j < tamanho; j++){
            if(vetor[j] < vetor[menor])
                menor = j;
        }
        if(i != menor){
            auxiliar = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = auxiliar;
        }
    }
}

int main(){
int *vetor, tamanho, i;
        printf("qual o tamanho do vetor?\n");
        scanf("%d", &tamanho);
    vetor = (int *) malloc(tamanho * sizeof(int));
    printf("digite os valores do vetor:\n");
        for (i = 0; i < tamanho; i++){
            scanf("%d", &vetor[i]);
        }
    printf("seu vetor eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }

    selectionsort(vetor, tamanho);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }
	free(vetor);
    return 0;
}