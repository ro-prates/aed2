#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};
 
typedef struct NO* ArvAVL;

int alt_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

void RotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no -> dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no -> alt = maior(alt_NO(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

void RotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    no->alt = maior(alt_NO(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

void RotacaoLR(ArvAVL *raiz){
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL *raiz){
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
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
int remove_ArvAVL(ArvAVL *raiz, int valor){
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
 
//cria uma árvore binária
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
 
//calcula a altura da árvore binária
int altura_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("(C%d", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
        printf(")");
    }else{
        printf("()");
    }
}

int insere_ArvAVL(ArvAVL* raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo -> info = valor;
        novo -> alt = 0;
        novo -> esq = NULL;
        novo -> dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res=insere_ArvAVL(&(atual->esq), valor))==1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esq->info){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res=insere_ArvAVL(&(atual->dir), valor))==1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("\nvalor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return res;
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return ;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int main(){
    int altura = 0 , valor, quantidade, i;
    int valor_pesquisado;
    ArvAVL *raiz;
    raiz = cria_ArvAVL();
     
    scanf("%d", &quantidade);

    for(i=0; i<quantidade; i++){
        scanf("%d", &valor);
        insere_ArvAVL(raiz, valor);
    }

    scanf("%d", &valor_pesquisado);

    if(consulta_ArvAVL(raiz, valor_pesquisado)){
        remove_ArvAVL(raiz, valor_pesquisado);
        preOrdem_ArvAVL(raiz);
    }else{
        insere_ArvAVL(raiz, valor_pesquisado);
        preOrdem_ArvAVL(raiz);
    }

    return 0;
}