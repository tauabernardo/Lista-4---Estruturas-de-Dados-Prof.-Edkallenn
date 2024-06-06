/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char escritor[100];
    char nome[100];
    char publicacao[100];
    int anoPublicacao;
} Livro;

typedef struct Nodo {
    Livro livro;
    struct Nodo* seguinte;
} Nodo;

Nodo* criarNodo(Livro livro) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->livro = livro;
    novo->seguinte = NULL;
    return novo;
}

void inserirLivro(Nodo** cabeca, Livro livro) {
    Nodo* novo = criarNodo(livro);
    if (*cabeca == NULL || strcmp((*cabeca)->livro.nome, livro.nome) > 0) {
        novo->seguinte = *cabeca;
        *cabeca = novo;
    } else {
        Nodo* atual = *cabeca;
        while (atual->seguinte != NULL && strcmp(atual->seguinte->livro.nome, livro.nome) < 0) {
            atual = atual->seguinte;
        }
        novo->seguinte = atual->seguinte;
        atual->seguinte = novo;
    }
}

void removerLivro(Nodo** cabeca, char* nome) {
    Nodo* atual = *cabeca;
    Nodo* anterior = NULL;

    while (atual != NULL && strcmp(atual->livro.nome, nome) != 0) {
        anterior = atual;
        atual = atual->seguinte;
    }

    if (atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->seguinte;
    } else {
        anterior->seguinte = atual->seguinte;
    }

    free(atual);
    printf("Livro removido com sucesso.\n");
}

void alterarLivro(Nodo* cabeca, char* nome) {
    Nodo* atual = cabeca;

    while (atual != NULL && strcmp(atual->livro.nome, nome) != 0) {
        atual = atual->seguinte;
    }

    if (atual == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Entre com os novos dados do livro:\n");
    printf("Escritor: ");
    scanf(" %[^\n]", atual->livro.escritor);
    printf("Nome: ");
    scanf(" %[^\n]", atual->livro.nome);
    printf("Publicação: ");
    scanf(" %[^\n]", atual->livro.publicacao);
    printf("Ano de Publicação: ");
    scanf("%d", &atual->livro.anoPublicacao);
    printf("Livro alterado com sucesso.\n");
}

void buscarPorNome(Nodo* cabeca, char* nome) {
    Nodo* atual = cabeca;

    while (atual != NULL) {
        if (strcmp(atual->livro.nome, nome) == 0) {
            printf("Livro encontrado:\n");
            printf("Escritor: %s\n", atual->livro.escritor);
            printf("Nome: %s\n", atual->livro.nome);
            printf("Publicação: %s\n", atual->livro.publicacao);
            printf("Ano de Publicação: %d\n", atual->livro.anoPublicacao);
            return;
        }
        atual = atual->seguinte;
    }
    printf("Livro não encontrado.\n");
}

void buscarPorEscritor(Nodo* cabeca, char* escritor) {
    Nodo* atual = cabeca;
    int encontrado = 0;

    while (atual != NULL) {
        if (strcmp(atual->livro.escritor, escritor) == 0) {
            if (!encontrado) {
                printf("Livros encontrados:\n");
                encontrado = 1;
            }
            printf("Nome: %s\n", atual->livro.nome);
            printf("Publicação: %s\n", atual->livro.publicacao);
            printf("Ano de Publicação: %d\n", atual->livro.anoPublicacao);
        }
        atual = atual->seguinte;
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado para o escritor %s.\n", escritor);
    }
}

void exibirLivros(Nodo* cabeca) {
    Nodo* atual = cabeca;
    if (atual == NULL) {
        printf("Nenhum livro na biblioteca.\n");
        return;
    }

    printf("Lista de livros:\n");
    while (atual != NULL) {
        printf("Escritor: %s\n", atual->livro.escritor);
        printf("Nome: %s\n", atual->livro.nome);
        printf("Publicação: %s\n", atual->livro.publicacao);
        printf("Ano de Publicação: %d\n\n", atual->livro.anoPublicacao);
        atual = atual->seguinte;
    }
}

int main() {
    Nodo* cabeca = NULL;
    int escolha;
    Livro livro;
    char nome[100];
    char escritor[100];

    do {
        printf("\nBiblioteca\n");
        printf("1. Inserir livro\n");
        printf("2. Remover livro\n");
        printf("3. Alterar livro\n");
        printf("4. Buscar livro por nome\n");
        printf("5. Buscar livro por escritor\n");
        printf("6. Exibir todos os livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Entre com os dados do livro:\n");
                printf("Escritor: ");
                scanf(" %[^\n]", livro.escritor);
                printf("Nome: ");
                scanf(" %[^\n]", livro.nome);
                printf("Publicação: ");
                scanf(" %[^\n]", livro.publicacao);
                printf("Ano de Publicação: ");
                scanf("%d", &livro.anoPublicacao);
                inserirLivro(&cabeca, livro);
                break;
            case 2:
                printf("Entre com o nome do livro a ser removido: ");
                scanf(" %[^\n]", nome);
                removerLivro(&cabeca, nome);
                break;
            case 3:
                printf("Entre com o nome do livro a ser alterado: ");
                scanf(" %[^\n]", nome);
                alterarLivro(cabeca, nome);
                break;
            case 4:
                printf("Entre com o nome do livro a ser buscado: ");
                scanf(" %[^\n]", nome);
                buscarPorNome(cabeca, nome);
                break;
            case 5:
                printf("Entre com o nome do escritor: ");
                scanf(" %[^\n]", escritor);
                buscarPorEscritor(cabeca, escritor);
                break;
            case 6:
                exibirLivros(cabeca);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    Nodo* atual = cabeca;
    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->seguinte;
        free(temp);
    }

    return 0;
}
