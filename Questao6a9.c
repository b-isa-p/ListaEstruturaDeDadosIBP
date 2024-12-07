#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//6
typedef struct voo {
    int numeroVoo;
    int dataVoo;
    int hora;
    int minuto;
    int aeroportoSaida;
    int aeroportoChegada;
    int rota;
    float tempoEstimado;
    int passageiros;
    struct voo* prox; // Ponteiro p prox vooo
} Voo;

void cadastrarVoo(Voo** lista);
void consultaVoo(Voo* lista);
void removeVoo(Voo** lista);
int somaRecursiva(int n);

int main() {
    Voo* listaVoos = NULL; //lista vazia
    int opcao, n;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarVoo(&listaVoos); //questao 7
                break;
            case 2:
                consultaVoo(listaVoos); //questao 8
                break;
            case 3:
                removeVoo(&listaVoos); //questao 9
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    while (listaVoos != NULL) {
        Voo* temp = listaVoos;
        listaVoos = listaVoos->prox;
        free(temp);
    }

    return 0;
}

//CRUD
//7
void cadastrarVoo(Voo** lista) {
    Voo* novo = (Voo*)malloc(sizeof(Voo));
    if (novo == NULL) {
        printf("Não foi  poss[ivel alocar memória\n");
        return;
    }

    printf("Nº do voo: ");
    scanf("%d", &novo->numeroVoo);
    printf("Data do voo (1 - seg): ");
    scanf("%d", &novo->dataVoo);
    printf("Horário do voo (HH:MM): ");
    scanf("%d %d", &novo->hora, &novo->minuto);
    printf("Aeroporto de saída (ID): ");
    scanf("%d", &novo->aeroportoSaida);
    printf("Aeroporto de chegada (ID): ");
    scanf("%d", &novo->aeroportoChegada);
    printf("Rota (ID): ");
    scanf("%d", &novo->rota);
    printf("Tempo estimado de voo (H): ");
    scanf("%f", &novo->tempoEstimado);
    printf("Passageiros a bordo: ");
    scanf("%d", &novo->passageiros);

    novo->prox = *lista;
    *lista = novo;

    printf("Voo cadastrado com sucesso\n");
}

//8
void consultaVoo(Voo* lista) {
    int numero;
    printf("Digite o número do voo: ");
    scanf("%d", &numero);

    while (lista != NULL) {
        if (lista->numeroVoo == numero) {
            printf("\nInformações do Voo:\n");
            printf("Número do voo: %d\n", lista->numeroVoo);
            printf("Data do voo: %d\n", lista->dataVoo);
            printf("Horário do voo: %02d:%02d\n", lista->hora, lista->minuto);
            printf("Aeroporto de saída: %d\n", lista->aeroportoSaida);
            printf("Aeroporto de chegada: %d\n", lista->aeroportoChegada);
            printf("Rota: %d\n", lista->rota);
            printf("Tempo estimado: %.2f horas\n", lista->tempoEstimado);
            printf("Passageiros a bordo: %d\n", lista->passageiros);
            return;
        }
        lista = lista->prox;
    }

    printf("Voo não encontrado :|\n");
}

// Função para remover um voo (Questão 9)
void removeVoo(Voo** lista) {
    int numero;
    printf("Nº do voo removido: ");
    scanf("%d", &numero);

    Voo* atual = *lista;
    Voo* anterior = NULL;

    while (atual != NULL) {
        if (atual->numeroVoo == numero) {
            if (anterior == NULL) {
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Voo removido com sucesso\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Voo não encontrado!\n");
}