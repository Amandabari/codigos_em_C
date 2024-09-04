#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

struct EntradaDicionario {
    char vetor[MAX];
};

void arquivaTexto(int k, struct EntradaDicionario dicionario[]) {
    FILE *arquivo;
    arquivo = fopen("dicionario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (int i = 0; i < k; i++) {
        fprintf(arquivo, "%s\n", dicionario[i].vetor);
    }
    fclose(arquivo);
}

int comparaStrings(const void *a, const void *b) {
    return strcasecmp(((struct EntradaDicionario *)a)->vetor, ((struct EntradaDicionario *)b)->vetor);
}

void ordenaTexto(struct EntradaDicionario dicionario[], int indice) {
    qsort(dicionario, indice, sizeof(struct EntradaDicionario), comparaStrings);

    // Remover palavras duplicadas
    int novoIndice = 0;
    for (int i = 0; i < indice; i++) {
        if (i == 0 || strcasecmp(dicionario[i].vetor, dicionario[i - 1].vetor) != 0) {
            strcpy(dicionario[novoIndice].vetor, dicionario[i].vetor);
            novoIndice++;
        }
    }

    // Atualizar o índice com o número de palavras únicas
    indice = novoIndice;

    printf("\nDicionario:\n");
    for (int k = 0; k < indice; k++) {
        printf("%s\n", dicionario[k].vetor);
    }

    arquivaTexto(indice, dicionario);

    printf("Total de palavras encontradas: %d\n", indice);
}

void vetoreTexto() {
    struct EntradaDicionario dicionario[MAX]; 
    int indice = 0;

    printf("Digite as palavras a serem lidas (digite '.' em uma linha separada para finalizar):\n");

    while (1) {
        char texto[1000];
        scanf(" %[^\n]", texto);
        if (strcmp(texto, ".") == 0) {
            break;
        }

        char temp[MAX];

        for (int i = 0, j = 0; texto[i] != '\0'; i++) {
            for (j = 0; texto[i] != ' ' && texto[i] != '\n' && texto[i] != '\0'; i++, j++) {
                temp[j] = tolower(texto[i]);
            }
            temp[j] = '\0';

            if (j > 0 && indice < MAX) {
                strcpy(dicionario[indice].vetor, temp);
                indice++;
            }
        }
    }

    ordenaTexto(dicionario, indice);
}

int main() {
    vetoreTexto();
    return 0;
}