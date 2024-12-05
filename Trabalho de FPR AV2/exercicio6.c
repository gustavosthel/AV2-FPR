/*
    FAETERJ-Rio
    Fundamentos de Programação - FPR - Manhã
    Data: 29/08/2024

    Recursividade (Trabalho)

    QUESTÃO 06:
    Desenvolver uma função recursiva que, dada uma lista encadeada L 
    do tipo TLista, altere todas as ocorrências do valor num1 por num2. 
    Além disso, a função deve retornar a quantidade de alterações realizadas.
    
    Nota: o tipo TLista consiste exatamente naquele trabalhado em nossas aulas.
*/

#include <stdio.h>
#include <stdlib.h>

// Declaração de tipos
typedef struct No {
    int valor;
    struct No* prox;
} TNo;

typedef TNo* TLista;

int alterarLista(TLista L, int num1, int num2);
int  inserir (TLista *L, int numero);
void imprimirLista(TLista L);

int main() {
    //declaração de variáveis
	TLista lista = NULL;

	//inserindo elementos em lista
	inserir (&lista, 2);
	inserir (&lista, 3);
	inserir (&lista, 2);
    inserir (&lista, 1);

	printf("Lista original:\n");
    imprimirLista(lista);

    int totalAlteracoes = alterarLista(lista, 2, 5);

    printf("\nLista após alterações (substituindo %d por %d):\n", 2, 5);
    imprimirLista(lista);

    printf("\nTotal de alterações realizadas: %d\n", totalAlteracoes);


    return 0;
}

int alterarLista(TLista L, int num1, int num2) {
    
    if (L == NULL) {
        return 0;
    }

    int alteracoes = 0;
    if (L->valor == num1) {
        L->valor = num2;
        alteracoes = 1;
    }

    return alteracoes + alterarLista(L->prox, num1, num2);
}

void imprimirLista(TLista L) {
    TLista aux = L;
    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

int  inserir (TLista *L, int numero) 
{
	//declaração de variáveis
	TLista aux;

	//passo 1: alocar memória para o novo nó
	aux = malloc (sizeof(TNo));		//malloc: memory allocation

	//verificando se a memória solicitada foi alocada
	if (!aux)    //ou:   if (aux == NULL)
	{
		return 0;
	}
	else
	{
		//passo 2: armazenar o valor no novo nó
		aux->valor = numero;

		//passo 3: fazer o campo ‘prox’ do novo nó apontar para o “até então 1º nó”
		aux->prox = *L;

		//passo 4: atualizar L, de forma que aponte para o novo nó
		*L = aux;

		return 1;
	}
}