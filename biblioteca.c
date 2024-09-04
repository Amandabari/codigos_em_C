#include <stdio.h>
#include <stdlib.h>
#include "livro.h"

int main(){
  L *book;
  int i;
  int escolha1;
  int escolha2;
  
  book = malloc(5 * sizeof(L));
  for (i= 0; i<5; i++)
    adicionaLivro(book, i);
  for (i=0; i<5; i++)
    impreInfo(book, i);
    emprestaLivro(book, i);
  printf("\nDeseja alugar mais algum livro?\n1 - Sim\n2 - Não\n");
  scanf("%d", &escolha1);
  
  while (escolha1 == 1){
    emprestaLivro(book, i); 
    printf("\nDeseja alugar mais algum livro?\n1 - Sim\n2 - Não\n");
    scanf("%d", &escolha1);
  }
  escolha2 = printf("\nDeseja devolver algum livro? \n1 - Sim\n2 - Não\n");
  scanf("%d", &escolha2);
    if (escolha2 == 1){
      devolveLivro(book, i);
      }
    else
      printf("\nPrograma terminado.");
  return 0;
  impreInfo(book, i);
}