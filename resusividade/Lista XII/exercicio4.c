/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 24/10/2024
	
	Lista XII (Recursividade):
	
	Questão 04: 
	Fazer uma função recursiva que, dado um número inteiro N, 
	exiba o mesmo na base 2 (binária).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void binario (int n);

//main
void main ()
{
	//declaração de variáveis
	int numero;

	//lendo os valores
	printf ("Numero: ");
	scanf ("%d", &numero); 

	//chamando a função
	binario (numero);
}

//implementação das funções
void binario (int n)
{
	if (n != 0)
	{
		binario (n/2);
		printf ("%d", n%2);
	}
}