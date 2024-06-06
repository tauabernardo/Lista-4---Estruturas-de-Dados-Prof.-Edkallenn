/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char palavra[MAX][50];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int estaVazia(Pilha* p) {
    return p->topo == -1;
}

int estaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void push(Pilha* p, char* palavra) {
    if (estaCheia(p)) {
        printf("Pilha cheia.\n");
        return;
    }
    strcpy(p->palavra[++(p->topo)], palavra);
}

void pop(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    p->topo--;
}

void exibir(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    for (int i = p->topo; i >= 0; i--) {
        printf("%s\n", p->palavra[i]);
    }
}

int main() {
    Pilha p;
    inicializar(&p);
    char palavra[50];
    int opcao;

    do {
        printf("\n1. Inserir palavra\n");
        printf("2. Remover palavra\n");
        printf("3. Exibir palavras\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite uma palavra: ");
                scanf("%s", palavra);
                push(&p, palavra);
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                exibir(&p);
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
