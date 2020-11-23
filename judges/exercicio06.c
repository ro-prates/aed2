/*
Descrição:
Implemente as operações básicas de um algoritmo de pesquisa para Arvores Binárias de Busca  ́
conforme as especifiações abaixo. Escreva um programa que contenha os procedimentos a
seguir: (1) inicialização, (2) pesquisa, (3) inserção e (4) remoção. Não é permitido o uso de
algoritmos de ordenação para manter os dados ordenados, caso seja necessário. Na operação
de remoção, se necessário, dê a preferência para a promoção da menor chave da sub ́arvore à
direita, ou seja, o sucessor.
• Entrada:
A primeira linha da entrada consiste de uma sequência de números inteiros positivos separados
por espaços. A sequência termina quando for digitado um número inteiro negativo. A linha
seguinte cont ́em um número inteiro positivo que será utilizado como chave a ser pesquisada
no dicionário. No caso de uma pesquisa sem sucesso, esse número deverá ser inserido no
dicionário, caso contrário, ele deverá ser removido do dicionário.
• Saída:
Imprima duas linhas, cada qual com dois números inteiros, onde o primeiro valor representa
tamanho do dicionário de dados, ou seja, a quantidade de dados armazenados, e o segundo
valor deve exibir a altura m ́axima da  ́arvore a partir da raiz. A primeira linha exibe a
quantidade de elementos e altura da  ́arvore ap ́os a inserção dos dados, e a segunda linha deve
exibir as mesmas informações após a pesquisa, o que poderá causar aumento ou diminuição
na quantidade de elementos e/ou na altura da ́arvore.

Entrada 1:
4 10 12 5 8 -1 
5

Saída 1:
5 4 
4 3

Entrada 2:
4 10 12 5 8 -1 
7

Saída 2:
5 4 
6 5

Entrada 3:
-1
5

Saída 3:
0 0
1 1

Entrada 4:
4 -1
4

Saída 4:
1 1 
0 0
*/

#include <stdio.h>
#include <stdlib.h>
 
struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};
 
typedef struct NO* ArvBin;
 
//insere o valor na árvore binária
int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
 
    novo -> info = valor;
    novo -> dir = NULL;
    novo -> esq = NULL;
 
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual -> info){
                free(novo);
                return 0;
            }
            if(valor > atual -> info)
                atual = atual -> dir;
            else
                atual = atual -> esq;
        }
        if(valor > ant -> info)
            ant -> dir = novo;
        else
            ant -> esq = novo;
    }
    return 1;
}
 
//função auxiliar para ajduar na remoção
struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq==NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
 
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
 
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
 
//remove um valor na árvore binária
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) 
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual -> info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant -> dir == atual)
                    ant -> dir = remove_atual(atual);
                else
                    ant -> esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual -> info)
            atual = atual -> dir;
        else
            atual = atual -> esq;
    }
}
 
//verifica se existe um valor na árvore binária
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual -> info){
            return 1;
        }
        if(valor > atual -> info)
            atual = atual -> dir;
        else
            atual = atual -> esq;
    }
    return 0;
}
 
//cria uma árvore binária
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
 
//calcula a altura da árvore binária
int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}
 
int main(){
 
    //criando a árvore binária
    ArvBin *raiz = cria_ArvBin();
 
    int valor, tamanho_dicionario = 0;
    int numero_pesquisado = 0;
 
    scanf("%d", &valor);
 
    while(valor >= 0){
        insere_ArvBin(raiz, valor);
        tamanho_dicionario++;
        scanf("%d", &valor);
    }
 
    scanf("%d", &numero_pesquisado);
 
    int altura = altura_ArvBin(raiz);
 
    //primeira linha da saída
    printf("%d %d\n", tamanho_dicionario, altura);
 
    if(consulta_ArvBin(raiz, numero_pesquisado)){
        remove_ArvBin(raiz, numero_pesquisado);
        tamanho_dicionario--;
    }else{
        insere_ArvBin(raiz, numero_pesquisado);
        tamanho_dicionario++;
    }
 
    altura = altura_ArvBin(raiz);
 
    //segunda linha da saída
    printf("%d %d", tamanho_dicionario, altura);
 
    return 0;
}