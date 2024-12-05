/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 07/11/2024
	
	Listas Dinâmicas (listas encadeadas)
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
int  inserir (TLista *L, int numero);
int  remover (TLista *L, int numero);
int  alterar (TLista  L, int velho, int novo);
int  buscar  (TLista  L, int numero);
void exibir  (TLista  L);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;  //representando a lista inicialmente vazia
	int num1, num2, op, resp;

	do
	{
		system ("CLS");		//limpar tela

		//exibindo o meu ao usuário
		op = menu ();

		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == 1)   //ou apenas: if (inserir (&L, num1))
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = remover (&L, num1);
			        
					if (resp > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", resp);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        resp = alterar (L, num1, num2);
			        
			        if (resp > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", resp);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        resp = buscar (L, num1);
			        
					if (resp)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6); //6 = SAIR
}

//implementação das funções
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

int  remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0;

	//removendo o valor enquanto este estiver na primeira posição da lista
	while ((*L) && (*L)->valor == numero)
	{
		aux1 = *L;
		
		*L = aux1->prox;   //ou:  *L = (*L)->prox

		free (aux1);

		cont++;	
	}
	
	//verificando se ainda existem valores na lista
	if (*L)
	{
		//inicializando os auxiliares
		aux2 = *L;
		aux1 = aux2->prox;  //ou:   aux1 = (*L)->prox;

		//percorrendo a lista com ‘aux1’
		while (aux1)
		{
			//verificando se o valor a ser removido foi encontrado
			if (aux1->valor == numero)
			{
				aux2->prox = aux1->prox;
				free (aux1);
				cont++;
		
				aux1 = aux2->prox;		
			}
			else
			{
				aux2 = aux1;
				aux1 = aux1->prox;   //ou:  aux1 = aux2->prox;
			}
		}	
	}

	//retornando a quantidade de remoções realizadas
	return cont;
}

int  alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;
	int cont = 0;
	
	//percorrendo toda a lista
	while (aux != NULL)
	{
		//verificando se o valor a ser alterado foi encontrado
		if (velho == aux->valor)
		{
			aux->valor = novo;

			//atualizando o número de ocorrências
			cont++;
		}

		aux = aux->prox;
	}

	//retornando a quantidade de alterações realizadas
	return cont;
}

int  buscar  (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo toda a lista
	while (aux != NULL)
	{
		//verificando se o valor foi encontrado
		if (numero == aux->valor)
		{
			return 1;
		}
		else
		{
			aux = aux->prox;
		}
	}
	
	//se chegou aqui, o valor não pertence à lista
	return 0;
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

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}