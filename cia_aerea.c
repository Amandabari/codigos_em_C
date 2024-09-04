#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESTINOS 5
#define MAX_ASSENTOS 200

typedef struct {
    char destino[50];
    int assentos_disponiveis;
    bool assentos_ocupados[MAX_ASSENTOS];
} Voo;

Voo voos[MAX_DESTINOS];
float valor_passagem;

// Protótipos das funções
void inicializar_voos();
void menu();
void mostrar_mapa(int indice_voo);
void realizar_reserva(int indice_voo);
void cancelar_reserva(int indice_voo, int num_reserva);
void confirmar_venda(int indice_voo, int num_reserva);
float calcula_passagem(int idade);

int main() {
    inicializar_voos();

    printf("Digite o valor da passagem: ");
    scanf("%f", &valor_passagem);

    menu();

    return 0;
}

void inicializar_voos() {
    strcpy(voos[0].destino, "Nova York");
    voos[0].assentos_disponiveis = 150;
    memset(voos[0].assentos_ocupados, false, sizeof(voos[0].assentos_ocupados));

    // Inicializar os demais voos
}

void menu() {
    int opcao, indice_voo;

    do {
        printf("\n===== Menu =====\n");
        printf("1 - Verificar ocupacao de um voo\n");
        printf("2 - Efetuar reserva\n");
        printf("3 - Cancelar reserva\n");
        printf("4 - Confirmar venda\n");
        printf("5 - Mostrar quantidade de assentos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o indice do voo: ");
                scanf("%d", &indice_voo);
                mostrar_mapa(indice_voo);
                break;
            case 2:
                printf("Digite o indice do voo: ");
                scanf("%d", &indice_voo);
                realizar_reserva(indice_voo);
                break;
            case 3:
                printf("Digite o indice do voo: ");
                scanf("%d", &indice_voo);
                int num_reserva;
                printf("Digite o numero da reserva: ");
                scanf("%d", &num_reserva);
                cancelar_reserva(indice_voo, num_reserva);
                break;
            case 4:
                printf("Digite o indice do voo: ");
                scanf("%d", &indice_voo);
                printf("Digite o numero da reserva: ");
                scanf("%d", &num_reserva);
                confirmar_venda(indice_voo, num_reserva);
                break;
            case 5:
                // Implementar função para mostrar quantidade de assentos
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);
}

void mostrar_mapa(int indice_voo) {
    printf("Mapa de ocupacao do voo para %s:\n", voos[indice_voo].destino);
    for (int i = 0; i < voos[indice_voo].assentos_disponiveis; i++) {
        if (voos[indice_voo].assentos_ocupados[i]) {
            printf("Assento %d: ocupado\n", i + 1);
        } else {
            printf("Assento %d: disponivel\n", i + 1);
        }
    }
}

void realizar_reserva(int indice_voo) {
    int assento;

    do {
        printf("Digite o numero do assento disponivel: ");
        scanf("%d", &assento);
        assento--; // Ajuste para o indice do vetor
        if (assento < 0 || assento >= voos[indice_voo].assentos_disponiveis) {
            printf("Assento invalido. Tente novamente.\n");
        } else if (voos[indice_voo].assentos_ocupados[assento]) {
            printf("Assento ja ocupado. Escolha outro assento.\n");
        } else {
            voos[indice_voo].assentos_ocupados[assento] = true;
            printf("Reserva efetuada com sucesso.\n");
            printf("Valor da passagem: R$ %.2f\n", valor_passagem);
        }
    } while (assento < 0 || assento >= voos[indice_voo].assentos_disponiveis);
}

void cancelar_reserva(int indice_voo, int num_reserva) {
    if (voos[indice_voo].assentos_ocupados[num_reserva - 1]) {
        voos[indice_voo].assentos_ocupados[num_reserva - 1] = false;
        printf("Reserva cancelada com sucesso.\n");
    } else {
        printf("Reserva nao encontrada.\n");
    }
}

void confirmar_venda(int indice_voo, int num_reserva) {
    if (voos[indice_voo].assentos_ocupados[num_reserva - 1]) {
        voos[indice_voo].assentos_ocupados[num_reserva - 1] = false;
        printf("Venda confirmada com sucesso.\n");
    } else {
        printf("Reserva nao encontrada.\n");
    }
}

float calcula_passagem(int idade) {
    float valor_total = valor_passagem;

    if (idade <= 5) {
        valor_total *= 0.5; // 50% de desconto para crianças até 5 anos
    }

    return valor_total;
}