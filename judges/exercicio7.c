/*
Descrição:
Implemente as operações básicas do algoritmo de balanceamento em  ́arvores AVL. Escreva
um procedimento separado para as seguintes operações: (1) Altura: retorna a altura de um
dado nó; (2) FB: retorna o fator de balanceamento de um dado nó; (3) ArvoreAVL: verifica
se uma  ́arvore é ou não AVL; (4) LL, RR, LR, RL: executa uma rotação em um dado nó; (5)
BalancaNo: verifica um dado nó e efetua o seu balanceamento, caso necessário. Deve-se
ainda efetuar uma  ́unica rotação no nó raiz, de acordo com as regras de balanceamento de
uma arvore AVL.
• Entrada:

A entrada consiste de uma  ́arvore binária de busca (ABB) representada por parênteses ani-
nhados. Um exemplo pode ser encontrado abaixo.

• Saída:
Imprima, na primeira linha, a altura da  ́arvore binária de busca (ABB) de entrada e, em
seguida (segunda linha), a própria arvore usando a representação por parênteses aninhados.
Posteriormente, deve-se computar uma nova ABB onde se efetuou uma rotação LL, RR, LR
ou RL aplicada apenas no nó raiz. A rotação deverá ser efetuada de acordo com as regras
de balanceamento de uma  ́arvore AVL.
Após computada a nova árvore, deve-se imprimir o tipo de rotação efetuada (RR, LL, RL ou
LR, usando sempre letras ma ́ısculas) no nó raiz na terceira linha. Depois, na quarta linha,
imprima a altura desta ABB transformada. Finalmente, na quinta e última linha, imprima
própria ABB de sa ́ıda usando a representação por parênteses aninhados.
Obs: Todas as entradas exigem algum tipo de rotação no nó raiz.

Entrada:
(C3(C2(C1()())())(C4()(C9(C5()(C8()()))())))

Saída:
4 
(C3(C2(C1()())())(C4()(C9(C5()(C8()()))()))) 
RR 
3 
(C4(C3(C2(C1()())())())(C9(C5()(C8()()))()))
*/

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
 
//função que auxilia no cálculo do fator de balanceamento
int alt_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}
 
//calcula o fator de balanceamento
int fatorBalanceamento_NO(struct NO* no){
    return (alt_NO(no->esq) - alt_NO(no->dir));
}
 
//função que auxilia nas rotações
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
 
//cria uma árvore avl
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
 
//calcula a altura da árvore avl
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
 
//imprime a árvore avl com parênteses aninhados
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
 
//insere como se fosse uma AVL, calculando apenas alturas dos nós, mas não fazendo as rotações
int insereAVL(ArvAVL *raiz, int valor){
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
        if((res=insereAVL(&(atual->esq), valor))==1){
 
        }
    }else{
        if(valor > atual->info){
            if((res=insereAVL(&(atual->dir), valor))==1){
 
            }
        }else{
            return 0;
        }
    }
    atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir)) + 1;
    return res;
}
 
void verifica_rotacao(ArvAVL *raiz){
    int altura_certa = 0;
 
    if(fatorBalanceamento_NO(*raiz) < -1 && fatorBalanceamento_NO((*raiz)->dir) < 0){
        RotacaoRR(raiz);
        printf("RR\n");
        altura_certa = altura_ArvAVL(raiz);
        altura_certa--;
        printf("%d\n", altura_certa);
        preOrdem_ArvAVL(raiz);
    }else if(fatorBalanceamento_NO(*raiz) < -1 && fatorBalanceamento_NO((*raiz)->dir) > 0){
        RotacaoRL(raiz);
        printf("RL\n");
        altura_certa = altura_ArvAVL(raiz);
        altura_certa--;
        printf("%d\n", altura_certa);
        preOrdem_ArvAVL(raiz);
    }else if(fatorBalanceamento_NO(*raiz) > 1 && fatorBalanceamento_NO((*raiz)->esq) > 0){
        RotacaoLL(raiz);
        printf("LL\n");
        altura_certa = altura_ArvAVL(raiz);
        altura_certa--;
        printf("%d\n", altura_certa);
        preOrdem_ArvAVL(raiz);
    }else if(fatorBalanceamento_NO(*raiz) > 1 && fatorBalanceamento_NO((*raiz)->esq) < 0){
        RotacaoLR(raiz);
        printf("LR\n");
        altura_certa = altura_ArvAVL(raiz);
        altura_certa--;
        printf("%d\n", altura_certa);
        preOrdem_ArvAVL(raiz);
    }
}
 
int main(){
    int altura = 0 , resultado, valor, i;
    char palavra[100000], mostra[6];
 
    ArvAVL *raiz;
    raiz = cria_ArvAVL();
     
    scanf("%s", palavra);
 
    for(i=0; i<strlen(palavra); i++){
        if(palavra[i] != 40 && palavra[i] != 41 && palavra[i] != 67){
            if(palavra[i+1] == 40){
                valor = palavra[i];
                valor = valor - 48;
                insereAVL(raiz, valor);
                i += 2;
            }else if(palavra[i+2]==40){
                sprintf(mostra, "%d%d", palavra[i]-48, palavra[i]-48);
                valor = atoi(mostra);
                insereAVL(raiz, valor);
                i += 3;
            }else if(palavra[i+3]==40){
                sprintf(mostra, "%d%d%d", palavra[i]-48, palavra[i+1]-48, palavra[i+2]-48);
                valor = atoi(mostra);
                insereAVL(raiz, valor);
                i += 4;
            }else if(palavra[i+4]==40){
                sprintf(mostra, "%d%d%d%d", palavra[i]-48, palavra[i+1]-48, palavra[i+2]-48, palavra[i+3]-48);
                valor = atoi(mostra);
                insereAVL(raiz, valor);
                i += 5;
            }else if(palavra[i+5]==40){
                sprintf(mostra, "%d%d%d%d%d", palavra[i]-48, palavra[i+1]-48, palavra[i+2]-48, palavra[i+3]-48, palavra[i+4]-48);
                valor = atoi(mostra);
                insereAVL(raiz, valor);
                i += 6;
            }else if(palavra[i+6]==40){
                sprintf(mostra, "%d%d%d%d%d%d", palavra[i]-48, palavra[i+1]-48, palavra[i+2]-48, palavra[i+3]-48, palavra[i+4]-48, palavra[i+5]-48);
                valor = atoi(mostra);
                insereAVL(raiz, valor);
                i += 7;
            }
        }
    }
 
    altura = altura_ArvAVL(raiz);
    altura--;
    printf("%d\n", altura);
    preOrdem_ArvAVL(raiz);
    printf("\n");
 
    verifica_rotacao(raiz);
 
    return 0;
}