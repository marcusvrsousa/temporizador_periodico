# 🚦 Semáforo com Raspberry Pi Pico W
Este projeto implementa um semáforo controlado por um Raspberry Pi Pico W usando LEDs de cores vermelha, amarela e verde. A temporização do semáforo é feita utilizando a função add_repeating_timer_ms() da ferramenta Pico SDK, com a troca de sinais a cada 3 segundos. O código foi desenvolvido e testado utilizando o ambiente de desenvolvimento integrado (IDE) Wokwi, juntamente com o Visual Studio Code.

## 🔧 Componentes Necessários
- Microcontrolador: Raspberry Pi Pico W
- LEDs: 03 LEDs (vermelho, amarelo e verde)
- Resistores: 03 resistores de 330 Ω
- Ambiente de Desenvolvimento: Wokwi + Visual Studio Code
- 
## 📝 Descrição do Projeto
Este código utiliza a função add_repeating_timer_ms() do Pico SDK para alternar os LEDs de um semáforo a cada 3 segundos. Ele simula o comportamento de um semáforo com as cores vermelho, amarelo e verde.

Funcionamento:
1. LED vermelho acende e os outros dois LEDs (amarelo e verde) estão apagados.
2. LED amarelo acende enquanto o LED vermelho é apagado.
3. LED verde acende enquanto os LEDs vermelho e amarelo estão apagados.
O temporizador de 3 segundos é configurado para alternar entre esses estados.

## 🎯 Objetivos
Controle do Semáforo: O semáforo inicia com o LED vermelho aceso, seguido pelo LED amarelo e, por último, o LED verde. A troca de sinal ocorre a cada 3 segundos.

Temporização: A função add_repeating_timer_ms() é usada para ajustar um temporizador de 3 segundos, realizando a troca dos LEDs a cada intervalo.

Função Call-back: A mudança de estado dos LEDs é implementada na função de call-back do temporizador (repeating_timer_callback()).

Saída Serial: Na rotina principal, dentro do laço while, é impressa uma mensagem a cada 1 segundo (1.000 ms), enviada via porta serial.

## 🌐 Execução no WOKWI
Este projeto pode ser facilmente simulado utilizando a plataforma WOKWI, que permite a simulação do código para o RP2040 (Raspberry Pi Pico).

Passos para rodar o código no WOKWI:
Acesse o site WOKWI.
Crie um novo projeto e selecione o modelo de Raspberry Pi Pico.
Copie o código que está no arquivo temporizador_periodico.c e cole-o no arquivo main.c do WOKWI, bem como o código que está no diagram.json.
Simule a execução do código clicando no botão "Start".
Os LEDs serão acionados conforme a lógica do semáforo, e você poderá visualizar o comportamento do sistema diretamente na interface de simulação.

