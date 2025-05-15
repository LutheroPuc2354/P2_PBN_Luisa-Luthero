/*
Feito por Luisa Kirsch Silva Zarth e Luthero Boscardin Vargas

Construa uma lista circular duplamente encadeada com 50 nos e o valor armazenado deve ser rand�mico.
Imprima toda a lista percorrendo a lista do primeiro no para o ultimo e vice-versa.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No* proximo;
    struct No* anterior;
} No;

int main() {
    No* inicio = NULL;
    No* ultimo = NULL;
    int i;

    // Inicializa o gerador de numeros aleatorios
    srand(time(NULL));

    // Cria os 50 n�s
    for (i = 0; i < 50; i++) {
        No* novo = (No*)malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            return 1;
        }

        novo->valor = rand() % 100; 
        novo->proximo = NULL;
        novo->anterior = NULL;

        if (inicio == NULL) {
            inicio = novo;
            ultimo = novo;
        } else {
            ultimo->proximo = novo;
            novo->anterior = ultimo;
            ultimo = novo;
        }
    }

    ultimo->proximo = inicio;
    inicio->anterior = ultimo;

    // lista do primeiro pro �ltimo
    printf("Lista do primeiro ao ultimo:\n");
    No* atual = inicio;
    for (i = 0; i < 50; i++) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    // lista do �ltimo pro primeiro
    printf("\n\nLista do ultimo ao primeiro:\n");
    atual = ultimo;
    for (i = 0; i < 50; i++) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }

    printf("\n");

    return 0;
}

