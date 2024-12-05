/*
    FAETERJ-Rio
    Fundamentos de Programação - FPR - Manhã
    Data: 29/08/2024

    Recursividade (Trabalho)

    QUESTÃO 05:
    Implementar uma função recursiva que, dado um número inteiro num, 
    preencha um vetor, de 10 posições, com as quantidades que cada possível
    algarismo aparece em num.
*/

#include <stdio.h>
#include <stdlib.h>

void contarDigitos(int num, int frequencias[]);

int main() {
    int num;
    int frequencias[10] = {0};

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    contarDigitos(num, frequencias);

    printf("Frequência de cada dígito:\n");
    for (int i = 0; i < 10; i++) {
        printf("Dígito %d: %d vezes\n", i, frequencias[i]);
    }

    return 0;
}

void contarDigitos(int num, int frequencias[]) {

    if (num == 0) {
        return;
    }

    int digito = num % 10;
    frequencias[digito]++;

    contarDigitos(num / 10, frequencias);
}
