/*
Descrição:
Implemente as operações básicas do algoritmo de pesquisa baseado em transformação de chave
(hashing), conforme as especificações abaixo. Utilize o método da divisão como função de
transformação e a estratégia de encadeamento para tratar colisões. Escreva um procedimento
separado para as seguintes operações: (1) pesquisa, (2) inserção e (3) remoção. Se necessário,
na operação de inserção, coloque o novo item após todos os itens demais, ou seja, no final.
• Entrada:
A entrada consiste de vários números inteiros separados por espaços. O primeiro número
indica o tamanho da tabela de hash a ser utilizada. Todos os demais números exceto o último
serão inseridos na tabela. O último número será utilizado como chave a ser pesquisada na
tabela. No caso de uma pesquisa sem sucesso, esse número também será inserido na tabela,
caso contrário, ele deverá ser removido.
• Saída:
Imprima a tabela de hash, cada entrada da tabela em uma linha, separando os elementos de
uma mesma entrada com um espaço.

Entrada:
7 
7 
3 4 9 2 5 1 8 
5

Saída:
[0] 
[1] 1 8
[2] 9 2
[3] 3
[4] 4
[5]
[6]
*/

#include <stdio.h>
#include <stdlib.h>
 
typedef struct SItem{
    int Chave;
    struct SItem *Prox;
}TItem;
 
typedef struct{
    TItem *Primeiro, *Ultimo;
    int tamanho;
}TLista;
 
void Imprime_Hash(TLista tabela[], int m){
    int i;
    TItem *aux;
 
    for(i=0;i<m;i++){
        printf("\n[%d] ",i);
        aux = tabela[i].Primeiro;
        while(aux != NULL){
            printf("%d ", aux->Chave);
            aux = aux->Prox;
        }
    }
}
 
int Pesquisa_Chave(TLista lista, int Chave){
    TItem *aux;
    aux = lista.Primeiro;
 
    while(aux){
        if(aux->Chave == Chave)
            return 1;
        aux = aux->Prox;
    }
    return 0;
}
 
int Insere_Chave(TLista *lista, int Chave) {
    if(Pesquisa_Chave((*lista), Chave))
        return 0;
    else {
        TItem *novo;
        novo = (TItem *) malloc(sizeof(TItem));
        novo->Chave = Chave;
        novo->Prox = NULL;
 
        if (lista->tamanho == 0) {
            lista->Primeiro = novo;
            lista->Ultimo = novo;
        } else {
            lista->Ultimo->Prox = novo;
            lista->Ultimo = novo;
        }
 
        lista->tamanho++;
        return 1;
    }
}
 
void Insere(TLista tabela[], int m){
    int n, aux, indice, i;
 
    scanf("%d", &n);
 
    for(i=0; i<n; i++){
        scanf("%d", &aux);
        indice = aux % m;
        Insere_Chave(&tabela[indice], aux);
    }
}
 
int Remove_Chave(TLista *lista, int Chave){
    TItem *p, *ant;
 
    if(lista->Primeiro == NULL)
        return 0;
    else{
        p = lista->Primeiro;
        ant = lista->Primeiro;
 
        while(p){
            if(p->Chave == Chave){
                if(p == lista->Primeiro){
                    lista->Primeiro = lista->Primeiro->Prox;
                    free(p);
                    lista->tamanho--;
                    return 1;
                }
                else{
                    ant->Prox = p->Prox;
                    free(p);
                    lista->tamanho--;
                    return 1;
                }
            }
            else{
                ant = p;
                p = p->Prox;
            }
        }
        return 0;
    }
}
 
 
int main() {
    int m, i, aux, r;
 
    scanf("%d", &m);
    TLista tabela[m];
 
    for (i = 0; i < m; i++) {
        tabela[i].Primeiro = NULL;
        tabela[i].Ultimo = NULL;
        tabela[i].tamanho = 0;
    }
 
    Insere(tabela, m);
 
    scanf("%d", &aux);
    i = aux%m;
    r = Pesquisa_Chave(tabela[i], aux);
 
    if(!r)
        Insere_Chave(&tabela[i], aux);
    else
        Remove_Chave(&tabela[i], aux);
 
    Imprime_Hash(tabela, m);
}