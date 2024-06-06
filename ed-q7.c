/*
** Função : 
** Autor : Tauã Bernardo
** Data : 31/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dados;
    int tamanho;
    int capacidade;
} VetorDinamico;

void inicializar(VetorDinamico* v, int capacidade) {
    v->dados = (int*)malloc(capacidade * sizeof(int));
    v->tamanho = 0;
    v->capacidade = capacidade;
}

void inserir(VetorDinamico* v, int valor) {
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (int*)realloc(v->dados, v->capacidade * sizeof(int));
    }
    v->dados[v->tamanho++] = valor;
}

void remover(VetorDinamico* v) {
    if (v->tamanho == 0) {
        printf("Vetor vazio.\n");
        return;
    }
    v->tamanho--;
}

void exibir(VetorDinamico* v) {
    if (v->tamanho == 0) {
        printf("Vetor vazio.\n");
        return;
    }
    for (int i = 0; i < v->tamanho; i++) {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

int main() {
    VetorDinamico v;
    inicializar(&v, 2);
    int opcao, valor;

    do {
        printf("\n1. Inserir valor\n");
        printf("2. Remover valor\n");
        printf("3. Exibir valores\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir(&v, valor);
                break;
            case 2:
                remover(&v);
                break;
            case 3:
                exibir(&v);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    free(v.dados);
    return 0;
}
