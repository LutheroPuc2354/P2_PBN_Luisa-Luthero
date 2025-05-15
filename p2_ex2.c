/*
Feito por Luisa Kirsch Silva Zarth e Luthero Boscardin Vargas

Construa uma lista duplamente encadeada com 10 nós, o valor armazenado deve ser conhecido.
Pergunte ao usuário quantos nós deseja remover ou inserir (em qual posição). 
Faça a remoção ou inserção. Depois imprima todos os nós.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* ant;
    struct No* prox;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

void imprimirLista(No* inicio) {
    printf("Lista: ");
    No* atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void inserirNaPosicao(No** inicio, int valor, int pos) {
    No* novo = criarNo(valor);
    if (pos == 0) {
        novo->prox = *inicio;
        if (*inicio) (*inicio)->ant = novo;
        *inicio = novo;
        return;
    }

    No* atual = *inicio;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Posicao invalida.\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    novo->ant = atual;
    if (atual->prox) atual->prox->ant = novo;
    atual->prox = novo;
}

void removerNaPosicao(No** inicio, int pos) {
    if (*inicio == NULL) return;

    No* atual = *inicio;

    if (pos == 0) {
        *inicio = atual->prox;
        if (*inicio) (*inicio)->ant = NULL;
        free(atual);
        return;
    }

    for (int i = 0; atual != NULL && i < pos; i++) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Posicao invalida.\n");
        return;
    }

    if (atual->ant) atual->ant->prox = atual->prox;
    if (atual->prox) atual->prox->ant = atual->ant;
    free(atual);
}

int main() {
    No* inicio = NULL;

    for (int i = 0; i < 10; i++) {
        inserirNaPosicao(&inicio, i + 1, i);
    }

    int opcao;
    do {
        imprimirLista(inicio);

        printf("\nSelecione uma opcao: \n1: inserir \n2: remover \n3: sair\n ");
        scanf("%d", &opcao);

        int pos, val;
        if (opcao == 1) {
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &val);
            printf("Digite a posicao (0 a n): ");
            scanf("%d", &pos);
            inserirNaPosicao(&inicio, val, pos);
        } else if (opcao == 2) {
            printf("Digite a posicao a ser removida (0 a n): ");
            scanf("%d", &pos);
            removerNaPosicao(&inicio, pos);
        } else if (opcao == 3) {
            printf(" ");
        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}

