#include <stdio.h>

void bubblesort(int *vetor, int tamanho){
    int i, continua, auxiliar, fim = tamanho;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;
                continua = i;
            }
        } 
        fim--;
    } while (continua != 0);
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

    bubblesort(vetor, tamanho);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }
	free(vetor);
    return 0;
}