/*
 * OlaMundo - Programa de Saudação 'Avançado'!
 *
 * Data: 30/01/2016
 * Autor: Wolfterro
 *
 */

#include <stdio.h>
#include <string.h>

#define VERSAO		"1.0"
#define DATAREL		"30/01/2016"

#define VAZIO		NULL

#define PORTUGUES 	"Olá, mundo!\n"
#define INGLES		"Hello, world!\n"
#define ESPANHOL	"¡Hola, mundo!\n"
#define FRANCES		"Bonjour tout le monde!\n"
#define ITALIANO	"Ciao, mondo!\n"
#define ALEMAO		"Hallo, Welt!\n"
#define JAPONES		"こんにちは、世界! (Kon'nichiwa, sekai!)\n"
#define CHINES_TRAD	"世界，你好！(Shìjiè, nǐ hǎo!)\n"
#define RUSSO		"Привет, мир! (Privet, mir!)\n"

int escolha;

void olamundo(int escolha) {

	switch(escolha) {

		case 1:
			printf(PORTUGUES);
			break;
		case 2:
			printf(INGLES);
			break;
		case 3:
			printf(ESPANHOL);
			break;
		case 4:
			printf(FRANCES);
			break;
		case 5:
			printf(ITALIANO);
			break;
		case 6:
			printf(ALEMAO);
			break;
		case 7:
			printf(JAPONES);
			break;
		case 8:
			printf(CHINES_TRAD);
			break;
		case 9:
			printf(RUSSO);
			break;
		default:
			printf("\nOpção inválida! Saindo...\n\n");
			break;
	}
}

void menu() {
	printf("====================\n");
	printf("OlaMundo! Versão %s\n", VERSAO);
	printf("====================\n\n");

	printf("Digite a lingua desejada:\n");
	printf("-------------------------\n");

	printf("(1) Português\n");
	printf("(2) Inglês\n");
	printf("(3) Espanhol\n");
	printf("(4) Francês\n");
	printf("(5) Italiano\n");
	printf("(6) Alemão\n");
	printf("(7) Japonês\n");
	printf("(8) Chinês Tradicional\n");
	printf("(9) Russo\n");

	printf("Faça sua escolha: ");
	scanf("%d", &escolha);
	olamundo(escolha);
}

void help() {
	printf("Use os seguintes argumentos (sem aspas):\n");
	printf("----------------------------------------\n\n");

	printf("Ajuda:\n");
	printf("'--help' ou '-h': Mostra esta opção de ajuda.\n\n");

	printf("Saudações:\n");
	printf("'--pt' ou '-1': Saudação em português.\n");
	printf("'--en' ou '-2': Saudação em inglês.\n");
	printf("'--es' ou '-3': Saudação em espanhol.\n");
	printf("'--fr' ou '-4': Saudação em francês.\n");
	printf("'--it' ou '-5': Saudação em italiano.\n");
	printf("'--de' ou '-6': Saudação em alemão.\n");
	printf("'--jp' ou '-7': Saudação em japonês.\n");
	printf("'--ch' ou '-8': Saudação em chinês tradicional.\n");
	printf("'--ru' ou '-9': Saudação em russo.\n\n");

	printf("Versão:\n");
	printf("'--version' ou '-v': Mostra a versão atual do programa.\n\n");
}

void version() {
	printf("OlaMundo --- Versão: ");
	printf(VERSAO);
	printf(" --- Data de lançamento: ");
	printf(DATAREL);
	printf("\n");
}

int main(int argc, char *argv[]) {

	if (argv[1] == VAZIO) {
		menu();
	}
	else {
		if (argc > 2) {
			printf("Erro, muitos argumentos! Use apenas um!\n");
		}
		else {

			if (0 == strcmp(argv[1], "--pt") || 0 == strcmp(argv[1], "-1")) {
				olamundo(1);
			}
			else if (0 == strcmp(argv[1], "--en") || 0 == strcmp(argv[1], "-2")) {
				olamundo(2);
			}
			else if (0 == strcmp(argv[1], "--es") || 0 == strcmp(argv[1], "-3")) {
				olamundo(3);
			}
			else if (0 == strcmp(argv[1], "--fr") || 0 == strcmp(argv[1], "-4")) {
				olamundo(4);
			}
			else if (0 == strcmp(argv[1], "--it") || 0 == strcmp(argv[1], "-5")) {
				olamundo(5);
			}
			else if (0 == strcmp(argv[1], "--de") || 0 == strcmp(argv[1], "-6")) {
				olamundo(6);
			}
			else if (0 == strcmp(argv[1], "--jp") || 0 == strcmp(argv[1], "-7")) {
				olamundo(7);
			}
			else if (0 == strcmp(argv[1], "--ch") || 0 == strcmp(argv[1], "-8")) {
				olamundo(8);
			}
			else if (0 == strcmp(argv[1], "--ru") || 0 == strcmp(argv[1], "-9")) {
				olamundo(9);
			}
			else if (0 == strcmp(argv[1], "--help") || 0 == strcmp(argv[1], "-h")) {
				help();
			}
			else if(0 == strcmp(argv[1], "--version") || 0 == strcmp(argv[1], "-v")) {
				version();
			}
			else {
				printf("Argumento Inválido! Use --help ou -h para ajuda.\n");
			}
		}
	}
	return 0;
}
