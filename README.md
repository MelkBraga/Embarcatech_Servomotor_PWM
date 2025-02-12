# Embarcatech_Interrupcoes_LedMatrix
Repositório criado para a Tarefa 2 - Aula Síncrona 06/02 - PWM

Aluno: Melk Silva Braga

# Instruções de compilação para o simulador

Para compilar e rodar o código, são necessárias as seguintes extensões: 

*Raspberry Pi Pico*

*Cmake*

*Cmake Tools*

*Wokwi simulator*

Após a compilação, clicar no arquivo "diagram.json" e iniciar a simulação no wokwi.

# Instruções de compilação para a BitDogLab

Para rodar o programa na BitDogLob, é preciso comentar ou apagar a linha 5 do código principal (#define PIN 22), 
remover as barras de comentário da linha 6 (// #define PIN 12) e compilar o código novamente. Após isso, conectar 
a placa via cabo usb em modo bootsel (necessário ter instalado o driver WinUSB (v6.1.7600.16385) na interface 1) e 
só então clicar em "Run Project", na extensão Raspberry Pi Pico.

O LED azul vai inicialmente assumir 3 intensidades (forte, médio e fraco) com intervalos de 5 segundos entre cada estado.
Em seguida, o brilho azul começará a aumentar e diminuir de forma contínua e suave.

# Vídeo demonstrando e explicando o funcionamento da tarefa
https://youtu.be/1X-0sHo4APA
