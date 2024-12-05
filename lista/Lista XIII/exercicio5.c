/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 14/11/2024
	
	Listas Dinâmicas:

	Lista de Exercícios XIII (Listas Encadeadas):
	
	QUESTÃO 05:
	Implementar uma função que, dadas duas listas dinâmicas 
	do tipo TLista, verifique se elas possuem os mesmos elementos, 
	independente da ordem na qual apareçam.
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
int verificarMesmosElementos (TLista L1, TLista L2);
int estaContida (TLista L1, TLista L2);

int  inserir (TLista *L, int numero);
void exibir  (TLista  L);

//main
void main ()
{
	//declaração de variáveis
	TLista lista1 = NULL, lista2 = NULL, lista3 = NULL;

	//inserindo elementos em lista1
	inserir (&lista1, 1);
	inserir (&lista1, 2);
	inserir (&lista1, 3);

	//inserindo elementos em lista2
	inserir (&lista2, 3);
	inserir (&lista2, 2);
	inserir (&lista2, 1);
	inserir (&lista2, 3);
	inserir (&lista2, 1);
	inserir (&lista2, 3);

	//inserindo elementos em lista3
	inserir (&lista3, 1);
	inserir (&lista3, 2);
	inserir (&lista3, 3);
	inserir (&lista3, 0);
	inserir (&lista3, 1);

	//exibindo as listas
	exibir (lista1);
	exibir (lista2);
	exibir (lista3);

	//chamando a função para lista1 e lista2
	if (verificarMesmosElementos (lista1, lista2) == 1)
	{
		printf ("\n\nAs listas 1 e 2 possuem os mesmos elementos!\n\n");
	}
	else
	{
		printf ("\n\nAs listas 1 e 2 NAO possuem os mesmos elementos!\n\n");
	}

	//chamando a função para lista1 e lista3
	if (verificarMesmosElementos (lista1, lista3) == 1)
	{
		printf ("\n\nAs listas 1 e 3 possuem os mesmos elementos!\n\n");
	}
	else
	{
		printf ("\n\nAs listas 1 e 3 NAO possuem os mesmos elementos!\n\n");
	}
}

//implementação das funções
int verificarMesmosElementos (TLista L1, TLista L2)
{
	if ((estaContida (L1, L2) == 1) && (estaContida (L2, L1) == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int estaContida (TLista L1, TLista L2)
{
	//declaração de variáveis
	TLista aux1 = L1, aux2;
	int achou;

	//percorrendo toda a lista L1
	while (aux1 != NULL)
	{
		//comparando cada elemento de L1 com todos de L2
		aux2 = L2;

		//sinalizando que, até o momento, o elemento de L1 não foi encontrado em L2
		achou = 0;

		//percorrendo toda a lista L2
		while (aux2 != NULL)
		{
			//verificando se o elemento de L1 foi encontrado em L2
			if (aux1->valor == aux2->valor)
			{
				achou = 1;
				break;
			}
			else
			{
				aux2 = aux2->prox;
			}
		}

		//se um dos elementos de L1 não existir em L2, a função já deve retornar falso
		if (achou == 0)
		{
			return 0;
		}
		else
		{
			aux1 = aux1->prox;
		}
	}

	//se chegou neste ponto, todos os elementos de L1 estão em L2
	return 1;
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