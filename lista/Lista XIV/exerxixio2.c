/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Noite
	Data: 30/11/2024
	
	Lista de Exercícios XIV (Listas, Pilhas e Filas):
	
	QUESTÃO 02:
	Dada uma fila F, do tipo TLista, implementar uma função que remova de F todos os divisores do número 
	inteiro N e, ao final, retorne a quantidade de remoções realizadas.

	Notas: 
		i. as regras de manipulação de uma fila clássica devem ser respeitadas; 
		ii. Caso alguma estrutura auxiliar seja necessária, esta deverá ser uma fila ou uma pilha.
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
int removerDivisoresFila (TLista *F, TLista *U, int numero);

int enfilar (TLista *F, TLista *U, int numero);   	
int desenfilar (TLista *F, TLista *U, int *numero);	
int primeiro (TLista F, int *numero);

int menu ();

//main
void main ()
{
}

//implementação de funções
int removerDivisoresFila (TLista *F, TLista *U, int numero)
{
	//declaração de variáveis
	TLista Faux = NULL, Uaux = NULL;
	int valor, cont = 0;
	
	//copiando para a fila auxiliar os elementos de F que não são divisores de 'numero'
	while (*F)
	{
		//removendo o primeiro elemento de 'F'
		desenfilar (F, U, &valor);
		
		//verificando se 'valor' não é divisor de 'numero'
		if (numero%valor!=0)
		{
			enfilar (&Faux, &Uaux, valor);
		}
		else
		{
			cont++;
		}
	}
	
	//fazendo 'F' apontar para o mesmo nó que aponta 'Faux'
	*F = Faux;
	*U = Uaux;
	
	//retornando a quantidade de remoções
	return cont;
}

int enfilar (TLista *F, TLista *U, int numero)
{
	//declaração de variáveis
	TLista novo;
	
	//alocar memória para novo
	novo = malloc (sizeof(TNo));  //memory allocation
		
	//verificando se houve erro na alocação de memória
	if (novo == NULL)  //ou:   if (!novo)
	{
		return 0;
	}
	else
	{
		//armazenando 'numero' na memória alocada
		novo->valor = numero;

		//caso exista elemento na fila
		if (*U)
		{
			//fazendo o 'antigo último nó' apontar para o novo nó		
			(*U)->prox = novo;
		}
		else
		{
			//a fila está vazia; portanto, 'F' deve apontar pra o novo nó
			*F = novo;
		}
		
		//fazendo o novo nó apontar para NULL (afinal, está sendo inserido no final da fila)
		novo->prox = NULL;
		
		//atualizando 'U'
		*U = novo;
			
		return 1;	
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se há elementos na fila
	if (*F)
	{
		//armazenando em 'numero' o primeiro elemento da fila
		*numero = (*F)->valor;
		
		//fazer 'aux' apontar para o primeiro nó (que é o primeiro elemento)
		aux = *F;
		
		//fazer 'F' apontar para o 'segundo' nó, que passará a ser o primeiro da fila
		*F = aux->prox;  //ou:  *F = (*F)->prox;
		
		//se 'F' passou a apontar para NULL, a fila tinha apenas um elemento
		if (!(*F)) // (*F == NULL)
		{
			*U = NULL;
		}
		
		//liberando a memória do nó
		free (aux);
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int primeiro (TLista F, int *numero)
{
	//verificando se há elementos na fila (e, portanto, há o primeiro elemento)
	if (F) //ou: if (F != NULL)
	{
		//armazenando em 'numero' o primeiro elemento da fila
		*numero = F->valor;
				
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
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}