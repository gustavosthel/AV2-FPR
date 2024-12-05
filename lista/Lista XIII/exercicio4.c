/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 14/11/2024
	
	Listas Dinâmicas:

	Lista de Exercícios XIII (Listas Encadeadas):
	
	QUESTÃO 04:
	Implementar uma função que, dadas duas listas dinâmicas do 
	tipo TLista, verifique se estas são iguais; isto é, contêm 
	os mesmos elementos, na mesma ordem.
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
int verificarIgualdade (TLista L1, TLista L2);

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
	inserir (&lista2, 1);
	inserir (&lista2, 2);
	inserir (&lista2, 3);

	//inserindo elementos em lista3
	inserir (&lista3, 0);
	inserir (&lista3, 1);
	inserir (&lista3, 2);
	inserir (&lista3, 3);


	//exibindo as listas
	exibir (lista1);
	exibir (lista2);
	exibir (lista3);

	//chamando a função para lista1 e lista2
	if (verificarIgualdade (lista1, lista2) == 1)
	{
		printf ("\n\nAs listas 1 e 2 sao iguais!\n\n");
	}
	else
	{
		printf ("\n\nAs listas 1 e 2 NAO sao iguais!\n\n");
	}

	//chamando a função para lista1 e lista3
	if (verificarIgualdade (lista1, lista3) == 1)
	{
		printf ("\n\nAs listas 1 e 3 sao iguais!\n\n");
	}
	else
	{
		printf ("\n\nAs listas 1 e 3 NAO sao iguais!\n\n");
	}
}

//implementação das funções
int verificarIgualdade (TLista L1, TLista L2)
{
	//declaração de variáveis
	TLista aux1 = L1, aux2 = L2;

	//percorrendo as listas até uma ou as duas chegarem ao fim
	while (aux1 && aux2)  //while ((aux1 != NULL) && (aux2 != NULL))
	{
		//comparando os elementos apontados pelos auxiliares
		if (aux1->valor != aux2->valor)
		{
			return 0;
		}
		else
		{
			//atualizando os auxiliares, de forma que eles apontem para os próximos nós
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
	}

	//verificando se as duas listas foram percorridas integralmente
	if (!aux1 && !aux2)  //if ((aux1 == NULL) && (aux2 == NULL)) 
	{
		return 1;
}
else
{
	return 0;
}
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