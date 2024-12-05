/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 27/11/2024
	
	Listas Dinâmicas:

	Lista de Exercícios XIII (Listas Encadeadas):
	
	QUESTÃO 08:
	Implementar uma função que crie uma lista encadeada (dinâmica) 
	com os N primeiros termos de uma PA (progressão aritmética) de 
	razão R e primeiro termo igual a A1.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
TLista criarPA (int a1, int r, int n);

void exibir  (TLista  L);

//main
void main ()
{
	//declaração de variáveis
	TLista L = criarPA (2,6,4);
		
	exibir (L);
}

//implementação das funções
TLista criarPA (int a1, int r, int n)
{
	TLista L = NULL;
	TLista aux, novo;
	int i, termo;

	for (i=1,termo=a1;i<=n;i++,termo+=r)
	{
		novo = malloc (sizeof(TNo));

		novo->valor = termo;
		novo->prox = NULL;

		if (!L)
		{
			L = novo;
			//aux = novo;

			//ou apenas:   L = aux = novo;
		}
		else
		{
			aux->prox = novo;
			//aux = novo;
		}

		aux = novo;
	}

	return L;
}

void exibir  (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	if (!L) //ou:  if (L == NULL)
	{
		printf ("\nLista vazia!\n");
	}
	else
	{
		printf ("\nElementos da lista: ");
	
		while (aux != NULL)
		{
			//printf ("%d ", (*aux).valor);
			printf ("%d ", aux->valor);
			
			//aux = (*aux).prox;
			aux = aux->prox;
		}
	}
}