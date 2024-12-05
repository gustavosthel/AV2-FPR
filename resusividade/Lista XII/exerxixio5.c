/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 24/10/2024
	
	Lista XII (Recursividade):
	
	Questão 05:
	Pede-se a implementação de uma função recursiva que exiba os 
	n primeiros termos de uma PG (Progressão Geométrica), onde a1 
	é o seu primeiro termo e q a razão.
	
	Observação: uma PG consiste em uma sequência de valores, iniciadas pelo valor a1. Os demais elementos são definidos como o anterior multiplicado pela razão.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void PG (int a1, int q, int n);

//main
void main ()
{
	//declaração de variáveis
	int a1, q, n;

	//lendo os dados do usuário
	printf ("a1: ");
	scanf ("%d", &a1);

	printf ("q: ");
	scanf ("%d", &q);

	printf ("n: ");
	scanf ("%d", &n);

	//chamando a função
	PG (a1, q, n);
}

//implementação das funções
void PG (int a1, int q, int n)
{
	if (n > 0)
	{
		printf ("%d ", a1);
		PG (a1*q, q, n-1);
	}
}