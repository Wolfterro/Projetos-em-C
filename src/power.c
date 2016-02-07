/*
 * power.c - Exemplificando o Funcionamento da Biblioteca 'power.h'
 *
 * Data: 07/02/2016
 * Autor: Wolfterro
 *
 */

#include <stdio.h>
#include <power.h>

int main() {

	int base;
	int expo;

	/*
	 * Resultados devem possuir o tipo 'double'
	 * para melhores resultados com números fracionados.
	 *
	 * Caso não preferir, o resultado poderá possuir o tipo 'int'.
	 *
	 */

	double result;

	printf("Insira uma base: ");
	scanf("%d", &base);

	printf("Insira um expoente: ");
	scanf("%d", &expo);

	result = power(base, expo);

	printf("O resultado de %d^%d é: %.9f\n", base, expo, result);

	return 0;
}
