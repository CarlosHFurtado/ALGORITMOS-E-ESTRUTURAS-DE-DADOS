#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_INICIAL 10
#define TAMANHO_INCREMENTO 5

typedef struct {
    char **nomes;
    int capacidade;
    int tamanho;
} ListaNomes;

void CriarLista(ListaNomes *lista);
void InserirNome(ListaNomes *lista, const char *nome);
void RemoverNome(ListaNomes *lista, const char *nome);
void EscreverLista(const ListaNomes *lista);
void ExcluirLista(ListaNomes *lista);


int main() {
    ListaNomes lista;
    CriarLista(&lista);

    int op;
    char nome[100];

    do {
        printf("\nMENU:\n");
        printf("1. Adicionar nome\n");
        printf("2. Remover nome\n");
        printf("3. Listar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o nome a ser adicionado: ");
                scanf("%s", nome);
                InserirNome(&lista, nome);
                break;
            case 2:
                printf("Digite o nome a ser removido: ");
                scanf("%s", nome);
                RemoverNome(&lista, nome);
                break;
            case 3:
                EscreverLista(&lista);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 4);

    ExcluirLista(&lista);

    return 0;
}

void CriarLista(ListaNomes *lista) {
    lista->nomes = (char **)malloc(TAMANHO_INICIAL * sizeof(char *));
    if (lista->nomes == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    lista->capacidade = TAMANHO_INICIAL;
    lista->tamanho = 0;
}

void InserirNome(ListaNomes *lista, const char *nome) {
    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade += TAMANHO_INCREMENTO;
        lista->nomes = (char **)realloc(lista->nomes, lista->capacidade * sizeof(char *));
        if (lista->nomes == NULL) {
            printf("Erro de alocação de memória.\n");
            exit(1);
        }
    }
    lista->nomes[lista->tamanho] = strdup(nome);
    if (lista->nomes[lista->tamanho] == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    lista->tamanho++;
}

void RemoverNome(ListaNomes *lista, const char *nome) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->nomes[i], nome) == 0) {
            free(lista->nomes[i]);
            for (int j = i; j < lista->tamanho - 1; j++) {
                lista->nomes[j] = lista->nomes[j + 1];
            }
            lista->tamanho--;
            return;
        }
    }
    printf("Nome não encontrado na lista.\n");
}

void EscreverLista(const ListaNomes *lista) {
    printf("Nomes na lista:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%s", lista->nomes[i]);
    }
}

void ExcluirLista(ListaNomes *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        free(lista->nomes[i]);
    }
    free(lista->nomes);
    lista->nomes = NULL;
    lista->capacidade = 0;
    lista->tamanho = 0;
}
