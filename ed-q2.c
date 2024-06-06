/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    float dado;
    struct Nodo* seguinte;
} Nodo;

Nodo* criarNodo(float dado) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo->dado = dado;
    novo->seguinte = NULL;
    return novo;
}

void push(Nodo** topo, float dado) {
    Nodo* novo = criarNodo(dado);
    novo->seguinte = *topo;
    *topo = novo;
}

void pop(Nodo** topo) {
    if (*topo == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }
    Nodo* temp = *topo;
    *topo = (*topo)->seguinte;
    printf("Elemento removido: %.2f\n", temp->dado);
    free(temp);
}

int estaVazia(Nodo* topo) {
    return topo == NULL;
}

void exibirPilha(Nodo* topo) {
    if (estaVazia(topo)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos na pilha:\n");
    Nodo* atual = topo;
    while (atual != NULL) {
        printf("%.2f\n", atual->dado);
        atual = atual->seguinte;
    }
}

int main() {
    Nodo* topo = NULL;
    int opcao;
    float dado;

    do {
        printf("\nMenu\n");
        printf("1. Inserir (push)\n");
        printf("2. Retirar (pop)\n");
        printf("3. Verificar se a pilha está vazia\n");
        printf("4. Exibir a pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor a ser inserido: ");
                scanf("%f", &dado);
                push(&topo, dado);
                break;
            case 2:
                pop(&topo);
                break;
            case 3:
                if (estaVazia(topo)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;
            case 4:
                exibirPilha(topo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    while (topo != NULL) {
        Nodo* temp = topo;
        topo = topo->seguinte;
        free(temp);
    }

    return 0;
}
