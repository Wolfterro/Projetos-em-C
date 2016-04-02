/*
 * Ytdlc - Download de Vídeos e Músicas com youtube-dl
 *
 * Data: 02/04/2016
 * Autor: Wolfterro
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char id_video[1024];

// Menu de ajuda do programa
void help() {
	printf("ytdlc: Download de Vídeos e Músicas com youtube-dl\n");
	printf("--------------------------------------------------\n");
	printf("Uso: ytdlc [Formato] [ID do vídeo]\n\n");

	printf("Comandos:\n");
	printf("---------\n");
	printf("  -h || --help\t\tMostra esta tela de ajuda\n");
	printf("  -u || --update\tAtualiza o youtube-dl\n");
	printf("  -v || --version\tMostra a versão deste programa\n\n");

	printf("Formatos:\n");
	printf("---------\n");
	printf("  --mp3\t\t\tConverte o vídeo para o formato MP3.\n");
	printf("  --wav\t\t\tConverte o vídeo para o formato WAV.\n\n");

	printf("  --mp4\t\t\tConverte o vídeo para o formato MP4.\n");
	printf("  --webm\t\tConverte o vídeo para o formato WEBM.\n");
	printf("  --mp4-conv\t\tConverte o vídeo para o formato MP4 (conversão).\n");
	printf("  --webm-conv\t\tConverte o vídeo para o formato WEBM (conversão).\n");

	return;
}

// Mostra a versão do programa e do youtube-dl
void version() {

	char version[100] = "1.0";

	printf("Versão (ytdlc): \n%s\n", version);
	printf("Versão (youtube-dl): \n");
	system("youtube-dl --version");

	return;
}

// Intro do programa
void intro() {

	char current_dir[1024];
	getcwd(current_dir);

	printf("======================================================\n");
	printf("# ytdlc: Download de Vídeos e Músicas com youtube-dl #\n");
	printf("======================================================\n");

	printf("* Este programa requer o youtube-dl instalado e reconhecido como comando interno!\n");
	printf("* Este programa requer o ffmpeg ou libav-tools instalado para possíveis conversões!\n\n");

	printf("Fazendo download de vídeo: (ID: %s) para o caminho: %s\n\n", id_video, current_dir);

	return;
}

// Conversão do vídeo para MP3
void download_mp3(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --extract-audio --audio-format mp3 https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Conversão do vídeo para WAV
void download_wav(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --extract-audio --audio-format wav https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Download do vídeo para MP4
void download_mp4(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --format mp4 https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Conversão do vídeo para MP4
void download_mp4_conv(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --recode-video mp4 https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Download do vídeo para WEBM
void download_webm(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --format webm https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Conversão do vídeo para WEBM
void download_webm_conv(char id_video[]) {

	char youtube_dl_command[1024];

	sprintf(youtube_dl_command, "youtube-dl --recode-video webm https://www.youtube.com/watch?v=%s", id_video);
	system(youtube_dl_command);
	
	return;
}

// Atualização do youtube-dl
void youtube_dl_update() {

	char youtube_dl_command[1024];

	printf("Atualizando youtube-dl...\n");

	sprintf(youtube_dl_command, "youtube-dl --update");
	system(youtube_dl_command);
	
	return;
}

// Método principal do programa
int main(int argc, char *argv[]) {

	// Alterando o caminho para a pasta 'home' do usuário
	chdir(getenv("HOME"));

	if (argv[1] == NULL) {
		printf("Erro! Falta argumentos! Use --help ou -h para ajuda.\n");
		printf("Uso: ytdlc [Formato] [ID do vídeo]\n");
	}
	else if (0 == strcmp(argv[1], "-h") || 0 == strcmp(argv[1], "--help")) {
		help();
	}
	else if (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--version")) {
		version();
	}
	else if (0 == strcmp(argv[1], "-u") || 0 == strcmp(argv[1], "--update")) {
		youtube_dl_update();
	}
	else {
		if (argc > 3) {	
			printf("Erro! Muitos argumentos! Use --help ou -h para ajuda.\n");
			printf("Uso: ytdlc [Formato] [ID do vídeo]\n");
		}
		else {
			if (argv[2] == NULL) {
			printf("Erro! Falta argumentos! Use --help ou -h para ajuda.\n");
			printf("Uso: ytdlc [Formato] [ID do vídeo]\n");
			}
			else {
				sscanf(argv[2], "%s", id_video);

				if (0 == strcmp(argv[1], "--mp3")) {
					intro();
					download_mp3(id_video);
				}
				else if (0 == strcmp(argv[1], "--wav")) {
					intro();
					download_wav(id_video);
				}
				else if (0 == strcmp(argv[1], "--mp4")) {
					intro();
					download_mp4(id_video);
				}
				else if (0 == strcmp(argv[1], "--mp4-conv")) {
					intro();
					download_mp4_conv(id_video);
				}
				else if (0 == strcmp(argv[1], "--webm")) {
					intro();
					download_webm(id_video);
				}
				else if (0 == strcmp(argv[1], "--webm-conv")) {
					intro();
					download_webm_conv(id_video);
				}
				else {
					printf("Argumento Inválido! Use --help ou -h para ajuda.\n");
				}
			}
		}
	}

	return 0;
}