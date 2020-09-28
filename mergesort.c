#include <stdio.h>

void merge(int *vetor, int inicio, int meio, int final){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = final - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2])
                    temp[i] = vetor[p1++];
                else temp[i] = vetor[p2++];
                if(p1 > meio) fim1 = 1;
                if(p2 > final) fim2 = 1;
            }else{
                if(!fim1) temp[i] = vetor[p1++];
                else temp[i] = vetor[p2++];
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++)
            vetor[k] = temp[j];
    }
    free(temp);
}


void mergesort(int *vetor, int inicio, int final){
    int meio;
    if(inicio < final){
        meio = floor((inicio + final) / 2);
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, final);
        merge(vetor, inicio, meio, final);
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

    mergesort(vetor, inicio, final);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }

    free(vetor);
    return 0;
}