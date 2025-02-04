#include <stdio.h>
#include "pico/stdlib.h"


// Definição dos pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// Variável para controlar o estado atual do semáforo
volatile int estado = 0;

// Função chamada pelo temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os estados do semáforo
    if (estado == 0) { // Vermelho
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
        estado = 1;
    } else if (estado == 1) { // Amarelo
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
        estado = 2;
    } else { // Verde
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 1);
        estado = 0;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AMARELO);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);


    // Liga o LED vermelho imediatamente
    gpio_put(LED_VERMELHO, 1);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    estado = 1; // Próximo estado será o amarelo

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Semáforo ativo - Estado atual: %d\n", estado);
        sleep_ms(1000);
    }
}


