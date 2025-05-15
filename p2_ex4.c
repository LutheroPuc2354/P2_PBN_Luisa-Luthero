/*
Feito por Luisa Kirsch Silva Zarth e Luthero Boscardin Vargas

Construa uma lista simplesmente encadeada com 10 nós,
com valores conhecidos e um descritor com os seguintes requisitos: 
Número de nós, quantos nós foram inseridos e quantos nós foram excluídos. 
Pergunte ao usuário quantos nós quer inserir ou remover.
Após imprima a lista completa e o descritor.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;
// s
typedef struct
{
    No *inicio;
    int total;
    int inseridos;
    int removidos;
} Descritor;

// Funcao para criar um novo no
No *criarNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Insercao no final da lista
void inserirNoFinal(Descritor *d, int valor)
{
    No *novo = criarNo(valor);
    if (d->inicio == NULL)
    {
        d->inicio = novo;
    }
    else
    {
        No *atual = d->inicio;
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    d->total++;
    d->inseridos++;
}

// Remocao por posicao
void removerNaPosicao(Descritor *d, int pos)
{
    if (d->inicio == NULL || pos < 0 || pos >= d->total)
    {
        printf("Posicao invalida.\n");
        return;
    }

    No *atual = d->inicio;
    No *anterior = NULL;

    for (int i = 0; i < pos; i++)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL)
    {
        d->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    d->total--;
    d->removidos++;
}

// Impressao da lista com posicoes
void imprimirLista(Descritor d)
{
    printf("Lista:\n");
    No *atual = d.inicio;
    int i = 0;
    while (atual != NULL)
    {
        printf("Posicao %d: %d\n", i, atual->valor);
        atual = atual->prox;
        i++;
    }
}

// Impressao do descritor
void imprimirDescritor(Descritor d)
{
    printf("\nDescritor:\n");
    printf("Total de nos: %d\n", d.total);
    printf("Nos inseridos: %d\n", d.inseridos);
    printf("Nos removidos: %d\n", d.removidos);
}

// Funcao principal
int main()
{
    Descritor d;
    d.inicio = NULL;
    d.total = 0;
    d.inseridos = 0;
    d.removidos = 0;

    // Criar 10 nos com valores conhecidos
    for (int i = 1; i <= 10; i++)
    {
        inserirNoFinal(&d, i);
    }

    // Imprimir lista inicial
    printf("Lista inicial:\n");
    imprimirLista(d);

    int opcao, val, qtd, pos;

    do
    {
        printf("\nSelecione uma opcao:\n");
        printf("1 - Inserir nos\n");
        printf("2 - Remover nos\n");
        printf("3 - Encerrar e imprimir lista\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Quantos nos quer inserir? ");
            scanf("%d", &qtd);
            for (int i = 0; i < qtd; i++)
            {
                printf("Digite o valor do no %d: ", i + 1);
                scanf("%d", &val);
                inserirNoFinal(&d, val);
            }
            break;

        case 2:
            printf("Quantos nos quer remover? ");
            scanf("%d", &qtd);
            for (int i = 0; i < qtd; i++)
            {
                printf("Digite a posicao do no a ser removido (0 a n): ");
                scanf("%d", &pos);
                removerNaPosicao(&d, pos);
            }
            break;

        case 3:
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    // Imprimir resultado final
    printf("\nLista final:\n");
    imprimirLista(d);
    imprimirDescritor(d);

    return 0;
}
