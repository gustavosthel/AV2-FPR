/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR - Turma: Manhã
	Data: 30/10/2024
	
	Lista XII (Recursividade):
	
	Questão 07:
	Desenvolver uma função recursiva que determine o número de 
	caracteres comuns entre duas strings s1 e s2.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int caracteresComuns (char s1[], char s2[]);
int caracteresComunsAux (char s1[], char s2[], int pos1, int pos2);

//main
void main ()
{
	//declaração de variáveis
	char str1[20], str2[20];
	int resp;
	
	//lendo a primeira string
	printf ("Primeira string: ");
	fflush (stdin);
	gets (str1);
	
	//lendo a segunda string
	printf ("\n\nSegunda string: ");
	fflush (stdin);
	gets (str2);
	
	//chamando a função
	resp = caracteresComuns (str1, str2);
	
	//exibindo o resultado
	printf ("\n\nHa %d caracteres comuns entre %s e %s.\n", resp, str1, str2);
}

//implementação das funções
int caracteresComuns (char s1[], char s2[])
{
	return caracteresComunsAux (s1, s2, 0, 0);
}

int caracteresComunsAux (char s1[], char s2[], int pos1, int pos2)
{
	if (s1[pos1] == '\0')	//caso base
	{
		return 0;
	}
	else			//caso geral
	{
		if (s2[pos2] == '\0')
		{
			return caracteresComunsAux (s1, s2, pos1+1, 0);
		}
		else
		{
			//verificando se os caracteres são iguais
			if (s1[pos1] == s2[pos2])
			{
				return 1 + caracteresComunsAux (s1, s2, pos1+1, 0);
			}
			else
			{
				return caracteresComunsAux (s1, s2, pos1, pos2+1);	
			}
		}
	}
}