/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 30/10/2024
	
	Lista XII (Recursividade):
	
	Questão 06:
	Dada uma string s, desenvolver uma função recursiva que 
	determine se s é ou não um palíndromo.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int palindromo (char s[]);
int palindromoAux (char s[], int inicio, int fim);

//main
void main ()
{
	//declaração de variáveis
	char str[20];
	int resp;

	//obtendo a string
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (str);

	//chamando a função
	resp = palindromo (str);

	//verificando o retorno
	if (resp == 1)
	{
		printf ("\nA string %s e um palindromo!", str);
	}
	else
{
	printf ("\nA string %s NAO e um palindromo!", str);
}	
}

//implementação das funções
int palindromo (char s[])
{
	return palindromoAux (s, 0, strlen(s)-1);
}

int palindromoAux (char s[], int inicio, int fim)
{
	if (inicio < fim)		//caso geral
	{
		if (s[inicio] != s[fim])	//caso base 2
		{
			return 0;
		}
		else
		{
			return palindromoAux (s, inicio+1, fim-1);
		}
	}
	else	//caso base 1
	{
		return 1;
	}
}