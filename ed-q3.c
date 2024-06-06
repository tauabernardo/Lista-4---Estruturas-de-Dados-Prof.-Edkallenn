/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo* esquerda;
    struct Nodo* direita;
} Nodo;

Nodo* criarNodo(int dado) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

Nodo* inserir(Nodo* raiz, int dado) {
    if (raiz == NULL) {
        return criarNodo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

void inOrder(Nodo* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esquerda);
        printf("%d ", raiz->dado);
        inOrder(raiz->direita);
    }
}

void preOrder(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}

void postOrder(Nodo* raiz) {
    if (raiz != NULL) {
        postOrder(raiz->esquerda);
        postOrder(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

Nodo* buscar(Nodo* raiz, int dado) {
    if (raiz == NULL || raiz->dado == dado) {
        return raiz;
    }
    if (dado < raiz->dado) {
        return buscar(raiz->esquerda, dado);
    }
    return buscar(raiz->direita, dado);
}

Nodo* encontrarMinimo(Nodo* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

Nodo* remover(Nodo* raiz, int dado) {
    if (raiz == NULL) {
        return raiz;
    }
    if (dado < raiz->dado) {
        raiz->esquerda = remover(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = remover(raiz->direita, dado);
    } else {
        if (raiz->esquerda == NULL) {
            Nodo* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            Nodo* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Nodo* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
    }
    return raiz;
}

int main() {
    Nodo* raiz = NULL;
    int opcao, dado;

    do {
        printf("\nÁrvore Binária\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Exibir In-Order\n");
        printf("5. Exibir Pre-Order\n");
        printf("6. Exibir Post-Order\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor a ser inserido: ");
                scanf("%d", &dado);
                raiz = inserir(raiz, dado);
                break;
            case 2:
                printf("Entre com o valor a ser removido: ");
                scanf("%d", &dado);
                raiz = remover(raiz, dado);
                break;
            case 3:
                printf("Entre com o valor a ser buscado: ");
                scanf("%d", &dado);
                Nodo* resultado = buscar(raiz, dado);
                if (resultado != NULL) {
                    printf("Valor %d encontrado na árvore.\n", dado);
                } else {
                    printf("Valor %d não encontrado na árvore.\n", dado);
                }
                break;
            case 4:
                printf("Exibição In-Order: ");
                inOrder(raiz);
                printf("\n");
                break;
            case 5:
                printf("Exibição Pre-Order: ");
                preOrder(raiz);
                printf("\n");
                break;
            case 6:
                printf("Exibição Post-Order: ");
                postOrder(raiz);
                printf("\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
