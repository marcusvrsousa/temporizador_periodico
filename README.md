# 🚦 Semáforo com Raspberry Pi Pico W
Este projeto implementa um semáforo controlado por um Raspberry Pi Pico W usando LEDs de cores vermelha, amarela e verde. A temporização do semáforo é feita utilizando a função add_repeating_timer_ms() da ferramenta Pico SDK, com a troca de sinais a cada 3 segundos. O código foi desenvolvido e testado utilizando o ambiente de desenvolvimento integrado (IDE) Wokwi, juntamente com o Visual Studio Code.

## 🔧 Componentes Necessários
- Microcontrolador: Raspberry Pi Pico W
- LEDs: 03 LEDs (vermelho, amarelo e verde)
- Resistores: 03 resistores de 330 Ω
- Ambiente de Desenvolvimento: Wokwi + Visual Studio Code
## 🎯 Objetivos
Controle do Semáforo: O semáforo inicia com o LED vermelho aceso, seguido pelo LED amarelo e, por último, o LED verde. A troca de sinal ocorre a cada 3 segundos.

Temporização: A função add_repeating_timer_ms() é usada para ajustar um temporizador de 3 segundos, realizando a troca dos LEDs a cada intervalo.

Função Call-back: A mudança de estado dos LEDs é implementada na função de call-back do temporizador (repeating_timer_callback()).

Saída Serial: Na rotina principal, dentro do laço while, é impressa uma mensagem a cada 1 segundo (1.000 ms), enviada via porta serial.
