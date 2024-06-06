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
    struct Nodo* seguinte;
} Nodo;

void push(Nodo** topo, int dado) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo->dado = dado;
    novo->seguinte = *topo;
    *topo = novo;
}

int pop(Nodo** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia.\n");
        return -1;
    }
    Nodo* temp = *topo;
    int dado = temp->dado;
    *topo = (*topo)->seguinte;
    free(temp);
    return dado;
}

void moverDisco(Nodo** origem, Nodo** destino, char a, char b) {
    int disco = pop(origem);
    push(destino, disco);
    printf("Mover disco %d de %c para %c\n", disco, a, b);
}

void torreHanoi(int n, Nodo** origem, Nodo** auxiliar, Nodo** destino, char a, char b, char c) {
    if (n == 1) {
        moverDisco(origem, destino, a, c);
        return;
    }
    torreHanoi(n - 1, origem, destino, auxiliar, a, c, b);
    moverDisco(origem, destino, a, c);
    torreHanoi(n - 1, auxiliar, origem, destino, b, a, c);
}

int main() {
    int n, i;
    Nodo* origem = NULL;
    Nodo* auxiliar = NULL;
    Nodo* destino = NULL;

    printf("Entre com o número de discos: ");
    scanf("%d", &n);

    for (i = n; i >= 1; i--) {
        push(&origem, i);
    }

    torreHanoi(n, &origem, &auxiliar, &destino, 'A', 'B', 'C');

    return 0;
}
