/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 31/10/2024
	
	Lista XII (Recursividade):
	
	Questão 09:
	Desenvolver uma função recursiva que, dado um vetor V com 
	quant números inteiros, determine se seus elementos estão dispostos 
	de maneira a representar uma progressão aritmética.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int verificaPA (int vetor[], int quant);
int verificaPA_aux (int vetor[], int quant, int pos, int razao);

//main
void main ()
{
	//declaração de variáveis
	int vetor1[6] = {10,13,16,19,22,25};	//representa uma PA de razão 3
	int vetor2[10] = {1,3,5,8,10,12,14,16,18,20};	//não representa uma PA
	
	//chamando a função para o vetor 1
	if (verificaPA (vetor1, 6) == 1)
	{
		printf ("\nO vetor 1 representa uma PA!\n");
	}
	else
	{
		printf ("\nO vetor 1 nao representa uma PA!\n");
	}

	//chamando a função para o vetor 2
	if (verificaPA (vetor2, 10) == 1)
	{
		printf ("\nO vetor 2 representa uma PA!\n");
	}
	else
	{
		printf ("\nO vetor 2 nao representa uma PA!\n");
	}	
}

//implementação das funções
int verificaPA (int vetor[], int quant)
{
	return verificaPA_aux (vetor, quant, 1, vetor[1]-vetor[0]);
}

int verificaPA_aux (int vetor[], int quant, int pos, int razao)
{
	if (pos < quant-1) //se ainda existirem posições a serem comparadas
	{
		if (vetor[pos+1]-vetor[pos] == razao) //verificando se a razão é mantida
		{
			return verificaPA_aux (vetor, quant, pos+1, razao);
		}
		else
		{
			return 0;	//Caso base: o vetor não representa uma PA	
		}
	}
	else
	{
		return 1; //Caso base: o vetor representa uma PA	
	}
}