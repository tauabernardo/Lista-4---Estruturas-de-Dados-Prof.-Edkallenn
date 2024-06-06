/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[100];
    char telefone[20];
} Contato;

typedef struct Nodo {
    Contato contato;
    struct Nodo* seguinte;
} Nodo;

Nodo* criarNodo(Contato contato) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->contato = contato;
    novo->seguinte = NULL;
    return novo;
}

void inserirContato(Nodo** cabeca, Contato contato) {
    Nodo* novo = criarNodo(contato);
    novo->seguinte = *cabeca;
    *cabeca = novo;
}

void removerContato(Nodo** cabeca, char* nome) {
    Nodo* atual = *cabeca;
    Nodo* anterior = NULL;

    while (atual != NULL && strcmp(atual->contato.nome, nome) != 0) {
        anterior = atual;
        atual = atual->seguinte;
    }

    if (atual == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->seguinte;
    } else {
        anterior->seguinte = atual->seguinte;
    }

    free(atual);
    printf("Contato removido com sucesso.\n");
}

void alterarContato(Nodo* cabeca, char* nome) {
    Nodo* atual = cabeca;

    while (atual != NULL && strcmp(atual->contato.nome, nome) != 0) {
        atual = atual->seguinte;
    }

    if (atual == NULL) {
        printf("Contato não encontrado.\n");
        return;
    }

    printf("Entre com os novos dados do contato:\n");
    printf("Nome: ");
    scanf(" %[^\n]", atual->contato.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", atual->contato.telefone);
    printf("Contato alterado com sucesso.\n");
}

void buscarContato(Nodo* cabeca, char* nome) {
    Nodo* atual = cabeca;

    while (atual != NULL) {
        if (strcmp(atual->contato.nome, nome) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", atual->contato.nome);
            printf("Telefone: %s\n", atual->contato.telefone);
            return;
        }
        atual = atual->seguinte;
    }
    printf("Contato não encontrado.\n");
}

void exibirContatos(Nodo* cabeca) {
    Nodo* atual = cabeca;
    if (atual == NULL) {
        printf("Nenhum contato na lista.\n");
        return;
    }

    printf("Lista de contatos:\n");
    while (atual != NULL) {
        printf("Nome: %s\n", atual->contato.nome);
        printf("Telefone: %s\n\n", atual->contato.telefone);
        atual = atual->seguinte;
    }
}

int main() {
    Nodo* cabeca = NULL;
    int escolha;
    Contato contato;
    char nome[100];

    do {
        printf("\nLista de Contatos\n");
        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Alterar contato\n");
        printf("4. Buscar contato\n");
        printf("5. Exibir todos os contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Entre com os dados do contato:\n");
                printf("Nome: ");
                scanf(" %[^\n]", contato.nome);
                printf("Telefone: ");
                scanf(" %[^\n]", contato.telefone);
                inserirContato(&cabeca, contato);
                break;
            case 2:
                printf("Entre com o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removerContato(&cabeca, nome);
                break;
            case 3:
                printf("Entre com o nome do contato a ser alterado: ");
                scanf(" %[^\n]", nome);
                alterarContato(cabeca, nome);
                break;
            case 4:
                printf("Entre com o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                buscarContato(cabeca, nome);
                break;
            case 5:
                exibirContatos(cabeca);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    while (cabeca != NULL) {
        Nodo* temp = cabeca;
        cabeca = cabeca->seguinte;
        free(temp);
    }

    return 0;
}
