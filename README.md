# Projetos em C
#### Pequenos projetos e testes simples em linguagem C.

### Descrição:

###### Os programas apresentados neste repositório são apenas projetos simples e testes escritos na linguagem C.
###### Os programas contidos neste repositório não devem ser levados "a sério", isto é, não possuem muita utilidade prática no dia-a-dia a não ser o aprendizado e o entendimento de como a linguagem C funciona e suas sintaxes.
###### Os programas aqui contidos foram desenvolvidos pensando na plataforma Linux e UNIX em geral, podendo não funcionar na plataforma Windows!

### Programas:

#### OlaMundo - Programa de Saudação 'Avançado'!

###### Todo desenvolvedor ou aspirante a desenvolvedor, ao aprender uma nova linguagem de programação, sempre começa com uma aplicação simples para entender como a sintaxe da linguagem funciona.
###### Com a linguagem C não é diferente, mas decidi 'extrapolar' um pouco neste quesito. Decidi então criar o OlaMundo disponível em linguas diferentes: Português, Inglês, Espanhol, entre outros.

###### Aqui estão os possíveis argumentos que poderão ser inseridos na hora de executar o programa:

      Ajuda:
      '--help' ou '-h': Mostra a opção de ajuda.
      
      Saudações:
      '--pt' ou '-1': Saudação em português.
      '--en' ou '-2': Saudação em inglês.
      '--es' ou '-3': Saudação em espanhol.
      '--fr' ou '-4': Saudação em francês.
      '--it' ou '-5': Saudação em italiano.
      '--de' ou '-6': Saudação em alemão.
      '--jp' ou '-7': Saudação em japonês.
      '--ch' ou '-8': Saudação em chinês tradicional.
      '--ru' ou '-9': Saudação em russo.
      
      Versão:
      '--version' ou '-v': Mostra a versão atual do programa.

##### Download:

###### Você pode baixar o programa já compilado (x64) e executá-lo com o comando abaixo:

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/olamundo'
      chmod +x olamundo
      ./olamundo

###### Você também poderá compilar o programa em seu sistema através do comando abaixo (é necessário possuir o GCC):

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/src/olamundo.c'
      gcc olamundo.c -o olamundo
      ./olamundo

<br />

#### Power - Biblioteca de Exponenciação em C!

###### Este programa é apenas um teste para o uso de uma simples biblioteca de funções em C utilizando os arquivos de 'headers' disponíveis para o programa que você deseja criar.
###### Decidi então criar uma simples biblioteca com uma função de exponenciação como exemplo. A biblioteca 'math.h' já cumpre essa função com a função "pow(int base, int expo)", mas decidi criar uma igual por conta própria.
###### Decidi também enviar um arquivo de fonte como exemplo de uso da biblioteca.

##### Download:

###### Você pode baixar o programa já compilado (x64) e executá-lo com o comando abaixo:

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/power'
      chmod +x power
      ./power

###### Você também poderá compilar o programa em seu sistema através do comando abaixo (é necessário possuir o GCC):

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/src/power.c'
      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/lib/power.h'
      gcc power.c -o power -I .
      ./power

<br />

#### Ctemp - Conversor de Temperatura em C

###### Este é um programa básico para conversão de temperaturas, convertendo os valores para as outras unidades de temperatura, como Celsius, Fahrenheit e Kelvin.
###### Basta executar o programa via terminal e inserir os argumentos necessários. O programa então irá fazer os cálculos e irá mostrar seus valores em outras unidades de temperatura.
###### Programa similar a este e com o uso de interface gráfica pode ser encontrado neste repositório (requer Java):  [Conversor de Temperatura 2016](https://github.com/Wolfterro/Conversor-de-Temperatura-2016)

###### Aqui está uma lista com os possíveis argumentos:
      
      Unidade:
      '-c' ou '--celsius':    Converte de Celsius para Fahrenheit e Kelvin
      '-f' ou '--fahrenheit': Converte de Fahrenheit para Celsius e Kelvin
      '-k' ou '--kelvin':     Converte de Kelvin para Celsius e Fahrenheit
      '-h' ou '--help':       Mostra a tela de ajuda

##### Download:

###### Você pode baixar o programa já compilado (x64) e executá-lo com o comando abaixo:

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/ctemp'
      chmod +x ctemp
      ./ctemp [unidade] [temperatura]

###### Você também poderá compilar o programa em seu sistema através do comando abaixo (é necessário possuir o GCC):

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/src/ctemp.c'
      gcc ctemp.c -o ctemp
      ./ctemp [unidade] [temperatura]

<br />

#### Ytdlc - Download de Vídeos e Músicas com youtube-dl

###### Este é um programa simples que permite o download de vídeos e músicas utilizando o programa [youtube-dl](https://github.com/rg3/youtube-dl).
###### Possuo [scripts](https://github.com/Wolfterro/Youtube-DL-Script) que executam a mesma operação, mas decidi criar um programa em C ao invés disso.
###### É necessário possuir o youtube-dl instalado e reconhecido como comando interno para que o programa funcione!
###### Também é necessário possuir o programa ffmpeg ou libav-tools instalado para que o programa possa converter o vídeo para o formato desejado.
###### O programa é bem simples e pode ser utilizado com os seguintes comandos:

      Comandos:
      '-h' ou '--help':             Mostra esta tela de ajuda
      '-u' ou '--update':           Atualiza o youtube-dl
      '-v' ou '--version':          Mostra a versão deste programa
      
      Formatos:
      '--mp3':                      Converte o vídeo para o formato MP3
      '--wav':                      Converte o vídeo para o formato WAV
      
      '--mp4':                      Converte o vídeo para o formato MP4.
      '--webm':                     Converte o vídeo para o formato WEBM.
      '--mp4-conv':                 Converte o vídeo para o formato MP4 (conversão).
      '--webm-conv':                Converte o vídeo para o formato WEBM (conversão).

##### Download:

###### Você pode baixar o programa já compilado (x64) e executá-lo com o comando abaixo:

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/ytdlc'
      chmod +x ytdlc
      ./ytdlc [Formato] [ID do vídeo]

###### Você também poderá compilar o programa em seu sistema através do comando abaixo (é necessário possuir o GCC):

      wget 'https://raw.github.com/Wolfterro/Projetos-em-C/master/src/ytdlc.c'
      gcc ytdlc.c -o ytdlc
      ./ytdlc [Formato] [ID do vídeo]

<br />
