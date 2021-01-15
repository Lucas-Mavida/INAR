#include <stdio.h>
#include <stdlib.h>


typedef struct arvore{
  int numero;
  struct arvore* direita;
  struct arvore* esquerda;
}Arvore;


Arvore* criaArvore(){
  return NULL;
}

int arvoreVazia(Arvore* t){
    return t == NULL;
}

void mostraArvore(Arvore* t){
  if(!arvoreVazia(t)) // verifica se a árvore não for vazia.
  {
    // Imprime numero em pré-ordem
    printf("%d ", t->numero); 
    mostraArvore(t->esquerda);
    mostraArvore(t->direita);
	}
}

void insereArvore(Arvore** t, int num){
  if(*t == NULL){
    *t = (Arvore*)malloc(sizeof(Arvore)); /* Aloca memória para a estrutura */
    (*t)->esquerda = NULL; /* Subárvore à esquerda é NULL */
    (*t)->direita = NULL; /* Subárvore à direita é NULL */
    (*t)->numero = num; /* Armazena a informação */
  } else {
    if(num < (*t)->numero) /* número menor entao vai pra esquerda */
    {
      insereArvore(&(*t)->esquerda, num);
    }
    if(num > (*t)->numero) /*número for maior vai pra direita */
    {
      insereArvore(&(*t)->direita, num);
    }
  }
}

int buscaArvore(Arvore* t, int num) {
  
  if(arvoreVazia(t)) {
    return 0;
  }
  return t->numero==num || buscaArvore(t->esquerda, num) || buscaArvore(t->direita, num);
}

int main(){
  Arvore* t = criaArvore();
  
  insereArvore(&t, 12); 
  insereArvore(&t, 15);
  insereArvore(&t, 13); 
  insereArvore(&t, 17);
  insereArvore(&t, 90);
   
   
/* Mostra os elementos da árvore em pré-ordem */
  mostraArvore(t); 
  
  
  if(buscaArvore(t, 15)) { 
    printf("\nO numero 15 esta na arvore!\n");
  } else {
     printf("\nO numero 15 nao esta na arvore!\n");
  }
  
  free(t);
  
  return 0;
}