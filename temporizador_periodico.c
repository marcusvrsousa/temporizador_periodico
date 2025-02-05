#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Variável para controlar o estado atual do semáforo
volatile int traffic_light_state = 0;

// Função chamada pelo temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os estados do semáforo
    switch (traffic_light_state) {
        case 0: // Vermelho
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            printf("Estado alterado para Vermelho\n"); // Mensagem de depuração
            traffic_light_state = 1;
            break;
        case 1: // Amarelo
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            printf("Estado alterado para Amarelo\n"); // Mensagem de depuração
            traffic_light_state = 2;
            break;
        case 2: // Verde
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            printf("Estado alterado para Verde\n"); // Mensagem de depuração
            traffic_light_state = 0;
            break;
    }
    return true; // Mantém o temporizador ativo
}

// Função de teste para garantir que os LEDs e o temporizador estão funcionando corretamente
void test_traffic_light() {
    printf("\n🚀 Iniciando o Teste...\n");

    // Estado inicial deve ser vermelho, e o LED vermelho deve estar aceso
    if (gpio_get(LED_RED) == 1) {
        printf("✅ Teste aprovado: LED Vermelho está ACESO no início.\n");
    } else {
        printf("❌ Teste falhou: LED Vermelho NÃO está ACESO no início.\n");
    }

    // Espera pelo temporizador para mudar os estados (simula o tick do temporizador)
    sleep_ms(3000); // Aguarda 3 segundos para deixar o temporizador disparar

    // Verifica o estado amarelo
    if (gpio_get(LED_YELLOW) == 1) {
        printf("✅ Teste aprovado: LED Amarelo está ACESO após 3 segundos.\n");
    } else {
        printf("❌ Teste falhou: LED Amarelo NÃO está ACESO após 3 segundos.\n");
    }

    // Aguarda mais 3 segundos para mudar para o verde
    sleep_ms(3000);

    // Verifica o estado verde
    if (gpio_get(LED_GREEN) == 1) {
        printf("✅ Teste aprovado: LED Verde está ACESO após 6 segundos.\n");
    } else {
        printf("❌ Teste falhou: LED Verde NÃO está ACESO após 6 segundos.\n");
    }

    // Aguarda mais 3 segundos para voltar ao vermelho
    sleep_ms(3000);

    // Verifica se o estado voltou para vermelho
    if (gpio_get(LED_RED) == 1) {
        printf("✅ Teste aprovado: LED Vermelho está ACESO após 9 segundos (ciclo completo).\n");
    } else {
        printf("❌ Teste falhou: LED Vermelho NÃO está ACESO após 9 segundos (ciclo completo).\n");
    }
}

int main() {

    // Inicializa os pinos dos LEDs
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Liga o LED vermelho inicialmente
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);
    traffic_light_state = 1; // O próximo estado será o amarelo

    // Configura o temporizador repetitivo com intervalo de 3000ms (3 segundos)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Chama a função de teste para verificar se tudo está funcionando
    test_traffic_light();

    // Loop principal para imprimir o estado atual a cada segundo
    while (1) {
        printf("Semáforo ativo - Estado atual: %d\n", traffic_light_state);
        sleep_ms(1000);
    }
}
