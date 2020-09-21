#include <stdio.h>

int buscabinaria(int tamanho, int *vetor, int x){
    int inicio = 0;
    int final = tamanho - 1;
    int meio;

    while (inicio <= final){
        meio = (inicio + final) / 2;
        if (x < vetor[meio]){
            final = meio - 1;
        }else if(x > vetor[meio]){
            inicio = meio + 1;
        }else return meio;
    } return -1;
}

int buscabinariarecursiva(int x, int *vetor, int inicio, int final){
    int meio = (inicio + final) / 2;
    if(vetor[meio] == x)
        return meio;
    if(inicio > final)
        return -1;
    else if (vetor[meio] < x)
        return buscabinariarecursiva(x, vetor, (meio + 1), final);
    else return buscabinariarecursiva(x, vetor, inicio, (meio - 1));
}

int main(){
    int *vetor, tamanho, x, i, resposta, inicio, final;
        printf("qual o valor que deseja encontrar?\n");
        scanf("%d", &x);
        printf("qual o tamanho do vetor?\n");
        scanf("%d", &tamanho);
    vetor = (int *) malloc(tamanho * sizeof(int));
    printf("digite os valores ordenados do vetor:\n");
        for (i = 0; i < tamanho; i++){
            scanf("%d", &vetor[i]);
        }
    printf("seu vetor eh:\n");
        for (i = 0; i < tamanho; i++){
            printf("%d ", vetor[i]);
        }
    printf("\n1- forma iterativa\n2- forma recursiva\n");
        scanf("%d", &resposta);
    if(resposta == 1)
        printf("\n%d",buscabinaria(tamanho, vetor, x));
    else {
        inicio = 0;
        final = tamanho -1;
        printf("\n indice: %d",buscabinariarecursiva(x, vetor, inicio, final));
    }
    free(vetor);
    return 0;
}