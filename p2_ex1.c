/*
Feito por Luisa Kirsch Silva Zarth e Luthero Boscardin Vargas

Construa uma lista linearmente encadeada com 10 nos, o valor armazenado deve ser conhecido.
Pergunte ao usuario quantos nos deseja inserir ou remover (em qual posicao). 
Faca a insercao ou remocao. Depois imprima todos os nos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void imprimirLista(No* inicio) {
    No* atual = inicio;
    int pos = 0;
    printf("Lista: ");
    while (atual != NULL) {
        printf("[Pos %d: %d] ", pos, atual->valor);
        atual = atual->prox;
        pos++;
    }
    printf("\n");
}

No* inserir(No* inicio, int pos, int valor) {
    if (pos == 0) {
        No* novo = criarNo(valor);
        if (novo == NULL) return inicio;  
        novo->prox = inicio;
        return novo;
    }

    No* atual = inicio;
    int i = 0;

    while (atual != NULL && i < pos - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Posicao invalida!\n");
        return inicio;
    }

    No* novo = criarNo(valor);
    if (novo == NULL) return inicio;
    novo->prox = atual->prox;
    atual->prox = novo;

    return inicio;
}

No* remover(No* inicio, int pos) {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    if (pos == 0) {
        inicio = inicio->prox;
        return inicio;
    }

    No* atual = inicio;
    int i = 0;

    while (atual->prox != NULL && i < pos - 1) {
        atual = atual->prox;
        i++;
    }

    if (atual->prox == NULL) {
        printf("Posicao invalida!\n");
        return inicio;
    }

    No* temp = atual->prox;
    atual->prox = temp->prox;
    return inicio;
}

int main() {
    No* lista = NULL;
	int i;
	
    // Cria uma lista inicial com 10 n�s (valores de 1 a 10)
    for (i = 9; i >= 0; i--) {
        lista = inserir(lista, 0, i + 1);
    }

    char escolha = 's';

    while (escolha == 's') {
        imprimirLista(lista);

        char operacao;
        printf("Digite o que deseja fazer (a para adicionar, r para remover): ");
        scanf(" %c", &operacao); 
        
        if (operacao == 'a') {
            int pos, valor;
            printf("Digite a posicao onde deseja inserir: ");
            scanf("%d", &pos);
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            lista = inserir(lista, pos, valor);
            
            printf("\n--- Lista atualizada ---\n");
            imprimirLista(lista);
            
        } else if (operacao == 'r') {
            int pos;
            printf("Digite a posicao que deseja remover: ");
            scanf("%d", &pos);
            lista = remover(lista, pos);
            
            printf("\n--- Lista atualizada ---\n");
            imprimirLista(lista);
            
        } else {
            printf("Operacao invalida.\n");
        }

        printf("Deseja continuar? (s para sim, n para nao): ");
        scanf(" %c", &escolha);
    }

    return 0;
}
