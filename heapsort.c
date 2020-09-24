#include <stdio.h>

void heapsrot(int *vetor, int n){
    int i, auxiliar;
    for(i = (n - 1) / 2; i >= 0; i--){
        criaheap(vetor, i, (n - 1));
    }
    for (i = (n - 1); i >= 1; i--){
        auxiliar = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = auxiliar;
        criaheap(vetor, 0, (i - 1));
    }
}

void criaheap(int *vetor, int i, int final){
    int auxuliar = vetor[i];
    int j = i * 2 + 1;
    while (j <= final){
        if(j < final){
            if(vetor[j] < vetor[j + 1]){ // pai tem 2 filhos? quem é o maior?
                j = j + 1;
            }
        }
        if(auxuliar < vetor[j]){ // se o filho for maior que o pai, então troque as posições
            vetor[i] = vetor[j];
            i = j;
            j = 2 * i + 1; 
        }else{
            j = final + 1;
        }
    }
    vetor[i] = auxuliar; // antigo pai ocupa o lugar do último filho analisado
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

    heapsrot(vetor, tamanho);

    printf("seu vetor ordenado eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }
	free(vetor);
    return 0;
}
