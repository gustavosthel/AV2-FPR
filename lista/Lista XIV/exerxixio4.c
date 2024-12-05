/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Noite
	Data: 30/11/2024
	
	Lista de Exercícios XIV (Listas, Pilhas e Filas):
	
	QUESTÃO 04:
	Pede-se o desenvolvimento de uma função recursiva que determine o número de ocorrências de um 
	número inteiro x em uma lista L, do tipo TLista.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
typedef struct No {
	int valor;
	struct No *prox;
} TNo;

typedef TNo* TLista;

//definição de protótipos
int numOcorrencias (TLista L, int numero);

//main
void main ()
{
}

//implementação de funções
int numOcorrencias (TLista L, int numero)
{
	//verificando se a lista está vazia
	if (L == NULL)	//caso base
	{
		return 0;
	}
	else
	{
		//verificando se 'numero' foi encontrado
		if (L->valor == numero)		
		{
			return 1 + numOcorrencias (L->prox, numero);
		}
		else
		{
			return numOcorrencias (L->prox, numero);
		}
	}	
}

//versão iterativa
int numOcorrencias (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	int cont = 0;
	
	//percorrendo toda a lista 'L'
	while (aux)
	{
		//veridicando se 'numero' foi encontrado
		if (aux->valor == numero)
		{
			cont++;
		}
		
		//seguindo para o próximo nó
		aux = aux->prox;
	}
	
	//retornando a quantidade de ocorrências
	return cont;
}