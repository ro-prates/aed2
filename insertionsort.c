#include <stdio.h>

void insertionsort(int *vetor, int tamanho){
    int i, j, auxiliar;
    for(i = 1; i < tamanho; i++){
        auxiliar = vetor[i];
        for(j = i; (j > 0) && (auxiliar < vetor[j - 1]); j--)
            vetor[j] = vetor[j - 1];
        vetor[j] = auxiliar;
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

    insertionsort(vetor, tamanho);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }
	free(vetor);
    return 0;
}