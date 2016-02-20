/*
 * Ctemp: Conversor de Temperatura em C
 *
 * Data: 20/02/2016
 * Autor: Wolfterro
 *
 */

#include <stdio.h>
#include <string.h>

float input;

void CelsiusConv(float input) {
	float result_fahrenheit;
	float result_kelvin;

	result_fahrenheit = input * 9/5 + 32;
	result_kelvin = input + 273.15;

	printf("Temperatura em Fahrenheit: %.2f °F\n", result_fahrenheit);
	printf("Temperatura em Kelvin: %.2f K\n", result_kelvin);
}

void FahrenheitConv(float input) {
	float result_celsius;
	float result_kelvin;

	result_celsius = (input - 32) * 5/9;
	result_kelvin = (input  + 459.67) * 5/9;

	printf("Temperatura em Celsius: %.2f °C\n", result_celsius);
	printf("Temperatura em Kelvin: %.2f K\n", result_kelvin);
}

void KelvinConv(float input) {
	float result_celsius;
	float result_fahrenheit;

	result_celsius = input - 273.15;
	result_fahrenheit = input * 9/5 - 459.67;

	printf("Temperatura em Celsius: %.2f °C\n", result_celsius);
	printf("Temperatura em Fahrenheit: %.2f °F\n", result_fahrenheit);
}

void help() {
	printf("Ctemp: Conversor de Temperatura em C\n");
	printf("------------------------------------\n");
	printf("Uso: ctemp [unidade] [temperatura]\n\n");

	printf("Unidade:\n");
	printf("  -c || --celsius\t\tConverte de Celsius para Fahrenheit e Kelvin\n");
	printf("  -f || --fahrenheit\t\tConverte de Fahrenheit para Celsius e Kelvin\n");
	printf("  -k || --kelvin\t\tConverte de Kelvin para Celsius e Fahrenheit\n");
	printf("  -h || --help\t\t\tMostra esta tela de ajuda\n");
}

int main(int argc, char *argv[]) {

	if (argv[1] == NULL) {
		printf("Erro! Falta argumentos! Use --help ou -h para ajuda.\n");
		printf("Uso: ctemp [unidade] [temperatura]\n");
	}
	else if (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
		help();
	}
	else {
		if (argc > 3) {
			printf("Erro! Muitos argumentos! Use --help ou -h para ajuda.\n");
			printf("Uso: ctemp [unidade] [temperatura]\n");
		}
		else {

			if (argv[2] == NULL) {
				printf("Erro! Falta argumentos! Use --help ou -h para ajuda.\n");
				printf("Uso: ctemp [unidade] [temperatura]\n");
			}
			else {

				sscanf(argv[2], "%f", &input);

				if (0 == strcmp(argv[1], "-c") || 0 == strcmp(argv[1], "--celsius")) {
					CelsiusConv(input);
				}
				else if (0 == strcmp(argv[1], "-f") || 0 == strcmp(argv[1], "--fahrenheit")) {
					FahrenheitConv(input);
				}
				else if (0 == strcmp(argv[1], "-k") || 0 == strcmp(argv[1], "--kelvin")) {
					KelvinConv(input);
				}
				else {
					printf("Argumento Inválido! Use --help ou -h para ajuda.\n");
				}
			}
		}
	}

	return 0;
}