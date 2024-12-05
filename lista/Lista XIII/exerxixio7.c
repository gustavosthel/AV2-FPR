/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 27/11/2024
	
	Listas Dinâmicas:

	Lista de Exercícios XIII (Listas Encadeadas):
	
	QUESTÃO 07:
	Desenvolver uma função que insira um número inteiro N na 
	i-ésima posição de uma lista encadeada L. 

	Observação: caso a posição i informada seja inválida, a função 
	deverá retornar o valor 0; caso contrário, o retorno será 
	igual a 1.
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
int inserirPosicao (TLista *L, int numero, int posicao);

void exibir  (TLista  L);

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	
	inserirPosicao (&L, 10, 1);
	inserirPosicao (&L, 20, 1);
	inserirPosicao (&L, 30, 4);
	inserirPosicao (&L, 40, 2);
	inserirPosicao (&L, 50, 3);
	
	exibir (L);
}

//implementação das funções
int inserirPosicao (TLista *L, int numero, int posicao)
{
	//declaração de variáveis
	TLista aux1, aux2, novo;
	int cont;

	//verificando se a posição é inferior a 1 (e, portanto, inválida)
	if (posicao < 1)
	{
		return 0;
	}
else
{
	//verificando se ‘numero’ será inserido na primeira posição da lista
	if (posicao == 1)
	{
		//alocando memória para o novo nó
		novo = malloc (sizeof(TNo));

		//verificando se houve erro na alocação de memória
		if (!novo)
		{
			return 0;
		}
		else
		{
			//inserindo o valor no novo nó
			novo->valor = numero;

			novo->prox = *L;

			*L = novo;

			return 1;
		}
	}
else   //deseja-se inserir o novo valor em posição posterior a 1
{
	//posicionando auxiliares nos dois primeiros nós 
	aux1 = *L;
	aux2 = aux1->prox;
	
	//iniciando ‘cont’ com 2, pois se chegou neste ponto, a posição desejada é, no mínimo, igual a 2
	cont = 2;

	//enquanto não chegar à posição desejada 
	while (cont < posicao)
	{
		//caminhando com os dois auxiliares
		aux1 = aux2;

		//verificando se ‘aux1’ chegou a NULL. Caso tenha, ‘posicao’ não é válida
		if (!aux1)
		{
			return 0;
		}
		aux2 = aux2->prox;

		//atualizando o contador
		cont++;
	}

	//alocando memória para o novo nó
		novo = malloc (sizeof(TNo));

		//verificando se houve erro na alocação de memória
		if (!novo)
		{
			return 0;
		}
		else
		{
			//inserindo o valor no novo nó
			novo->valor = numero;

			aux1->prox = novo;
			novo->prox = aux2;

			return 1;
	}
}
}
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