/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Noite
	Data: 30/11/2024
	
	Lista de Exercícios XIV (Listas, Pilhas e Filas):
	
	QUESTÃO 01:
	Desenvolver uma função que remova todos os elementos de uma pilha P do tipo TLista e retorne a 
	quantidade de elementos que existiam em P.

	Nota: as regras de manipulação de uma pilha clássica devem ser respeitadas.
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
int apagarPilha (TLista *P);

int empilhar (TLista *P, int numero);   	//push
int desempilhar (TLista *P, int *numero);	//pop
int topo (TLista P, int *numero);

//main
void main ()
{
}

int apagarPilha (TLista *P)
{
	//declaração de variáveis
	int cont = 0, valor;
	
	//enquanto existirem elementos na pilha
	while (*P != NULL)  //ou:    while (*P)
	{
		desempilhar (P, &valor);
		
		cont++;
	}
	
	//retornando a quantidade de elementos que existiam na pilha
	return cont;
}

//implementação de funções
int empilhar (TLista *P, int numero)   	//push
{
	//declaração de variáveis
	TLista novo;
	
	//passo 1: alocar memória para novo
	novo = malloc (sizeof(TNo));  //memory allocation
		
	//verificando se houve erro na alocação de memória
	if (novo == NULL)  //ou:   if (!novo)
	{
		return 0;
	}
	else
	{
		//passo 2: armazenando 'numero' na memória alocada
		novo->valor = numero;
		
		//passo 3: fazer o campo 'prox' do novo nó apontar
		//para o 'antigo topo da pilha'
		novo->prox = *P;
		
		//passo 4: fazer 'P' apontar para o novo nó
		*P = novo;
			
		return 1;	
	}	
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se há elementos na pilha
	if (*P)
	{
		//armazenando em 'numero' o elemento que está no topo da pilha
		*numero = (*P)->valor;
		
		//fazer 'aux' apontar para o primeiro nó (que é o topo)
		aux = *P;
		
		//fazer 'P' apontar para o 'segundo' nó, que passará a ser o topo
		*P = aux->prox;  //ou:  *P = (*P)->prox;
		
		//liberando a memória do nó
		free (aux);
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int topo (TLista P, int *numero)
{
	//verificando se há elementos na pilha (e, portanto, há topo)
	if (P) //ou: if (P != NULL)
	{
		//armazenando em 'numero' o topo da pilha
		*numero = P->valor;
		
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}