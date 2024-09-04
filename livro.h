#include <stdio.h>
#include <stdlib.h>

typedef struct Livro{
    char titulo[50];
    char autor[50];
    long int ISBN;
    int total_exemplares;
    int total_emprestados;
} L;


void adicionaLivro(L *L, int i);
void impreInfo(L *L, int i);
void emprestaLivro(L *L, int i);
void devolveLivro(L *L, int i);