/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 30/10/2024
	
	Lista XII (Recursividade):
	
	Questão 08:
	Desenvolver uma função recursiva que, dada uma string, 
	exiba-a invertida.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void exibirInvertido (char s[]);
void exibirInvertidoAux (char s[], int pos);

//main
void main ()
{
	//declaração de variáveis
	char str[20];
	
	//lendo a string
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (str);
	
	//chamando a função
	exibirInvertido (str);	
}

//implementação das funções
void exibirInvertido (char s[])
{
	exibirInvertidoAux (s, strlen(s)-1);
}

void exibirInvertidoAux (char s[], int pos)
{
	if (pos >= 0)	//caso geral
	{
		printf ("%c", s[pos]);
		exibirInvertidoAux (s, pos-1);		
	}
}