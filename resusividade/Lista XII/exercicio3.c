/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 23/10/2024
	
	Lista XII (Recursividade):
	
	Questão 03:
	Desenvolver uma função recursiva que exiba todos os múltiplos 
	do número N, inferiores ou iguais ao valor V.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibirMultiplos (int n, int v, int multiplo);

//main
void main ()
{
	//declaração de variáveis
	int numero, limite;

	//lendo os valores
	printf ("Numero: ");
	scanf ("%d", &numero);
 
	printf ("Limite: ");
	scanf ("%d", &limite);

	//chamando a função
	exibirMultiplos (numero, limite, 0);
}

//implementação das funções
void exibirMultiplos (int n, int v, int multiplo)
{
	if (multiplo <= v)
	{
		printf ("%d ", multiplo);
		exibirMultiplos (n, v, multiplo+n);
	}	
}