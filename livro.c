#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

void adicionaLivro(L *L, int i) {
  printf("\nDigite o titulo do livro: \n");
  getchar(); 
  fgets(L[i].titulo, 50, stdin);
  
  printf("\nDigite o autor do livro: \n");
  fgets(L[i].autor, 50, stdin);
  
  printf("\nDigite o ISBN do livro: \n");
  scanf("%li", &L[i].ISBN);
  
  printf("\nDigite o total de exemplares do livro: \n");
  scanf("%d", &L[i].total_exemplares);
  
  printf("\nDigite o total de exemplares emprestados do livro: \n");
  scanf("%d", &L[i].total_emprestados);
}

void impreInfo(L *L, int i) {
  printf("\nTitulo: %s\n", L[i].titulo);
  printf("Autor: %s\n", L[i].autor);
  printf("ISBN: %li\n", L[i].ISBN);
  
 int livros_disponiveis = L[i].total_exemplares - L[i].total_emprestados;
  printf("\nEste livro possui %d exemplares dos quais %d estão disponíveis e %d estão emprestados\n", L[i].total_exemplares, livros_disponiveis, L[i].total_emprestados);
}

void emprestaLivro(L *L, int i) {
  
  long int isbn_empresta = printf("\nDigite o ISBN do livro para emprestar: \n");
  scanf("%li", &isbn_empresta);
  for (i=0; i<5; i++){
    if (L[i].ISBN == isbn_empresta ) {
      if (L[i].total_emprestados < L[i].total_exemplares){
        L[i].total_emprestados++;
        printf("\nLivro emprestado com sucesso!\n");
        break;
      } else
      if (L[i].total_emprestados == L[i].total_exemplares){
        printf("\nO livro que procura esta indisponivel!\n");
        break;
      }
    }
  } 
  if (isbn_empresta != L[i].ISBN ){
    printf("\nISBN não encontrado\n");
  }
}
  
void devolveLivro(L *L, int i){
  
  long int isbn_devolve = printf("\nDigite o ISBN do livro que quer devolver: ");
  scanf("%li", &isbn_devolve);
  for (i=0; i<5; i++){
    if (L[i].ISBN == isbn_devolve ) {
      if (L[i].total_emprestados >= L[i].total_exemplares){
        L[i].total_emprestados--;
      printf("\nLivro devolvido com sucesso!");
        break;
      }
    }
  }
  if (isbn_devolve != L[i].ISBN ){
    printf("\nISBN não encontrado");
  }
}
  