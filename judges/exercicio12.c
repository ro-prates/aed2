/*
Descrição:

Implemente as operações básicas do algoritmo de pesquisa em  ́arvores B, conforme as especi-
ficações abaixo. Escreva um procedimento separado para as seguintes operações: (1) pesquisa
e (2) inserção.



• Entrada:
A entrada consiste de vários números inteiros separados por espaços. Todos os números
exceto o  ́ultimo serão inseridos na  ́arvore B. O  ́ultimo número será utilizado como chave a
ser pesquisada na ́arvore. No caso de uma pesquisa sem sucesso, esse número também será
inserido na ́arvore.

• Saída:
Imprima a ́arvore B representada por parênteses aninhados.

Entrada:
7 
3 4 9 2 5 1 8  
5

Saída:
((()C1()C2()C3())C4(()C5()C8()C9()))
*/

#include <stdio.h>
#include <stdlib.h>
 
#define MAX 4
#define MIN 2
 
struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};
 
struct BTreeNode *root;
 
// criando o nó
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}
 
// inserindo o nó
void insertNode(int val, int pos, struct BTreeNode *node,
        struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}
 
// fazendo a divisão
void splitNode(int val, int *pval, int pos, struct BTreeNode *node,
         struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;
 
  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;
 
  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;
 
  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}
 
// definindo o valor
int setValue(int val, int *pval,
           struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }
 
  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
    //valores duplicados
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}
 
void insert(int val) {
  int flag, i;
  struct BTreeNode *child;
 
  flag = setValue(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}
 
// procurando o nó
int search(int val, int *pos, struct BTreeNode *myNode) {
  if (!myNode) {
    return 0;
  }
 
  if (val < myNode->val[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos]) {
    //valor encontrado
      return 1;
    }
  }
  search(val, pos, myNode->link[*pos]);
  return 0;
}
 
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
      printf("(");
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      printf("C%d", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
      printf(")");
  }else{
      printf("()");
  }
}
 
int main() {
  int val, ch, quantidade = 0, i, insere, verifica;
  scanf("%d", &quantidade);
 
  for(i=0; i<quantidade; i++){
    scanf("%d", &insere);
    insert(insere);
  }
 
scanf("%d", &verifica);
 
if(search(verifica, &ch, root) == 0){
    insert(verifica);
}
  traversal(root);
  
}