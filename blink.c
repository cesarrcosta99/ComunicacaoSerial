#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

// Definição dos GPIOs
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Função para inicializar os GPIOs
void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(BUZZER);

    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Inicializar todos os GPIOs desligados
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
    gpio_put(BUZZER, 0);
}

// Função para desligar todos os LEDs
void turn_off_leds() {
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

// Função para executar o comando
void execute_command(const char *command) {

    
    
    if (strcmp(command, "green") == 0) {
        turn_off_leds();
        gpio_put(LED_GREEN, 1);
    } else if (strcmp(command, "blue") == 0) {
        turn_off_leds();
        gpio_put(LED_BLUE, 1);
    } else if (strcmp(command, "red") == 0) {
        turn_off_leds();
        gpio_put(LED_RED, 1);
    } else if (strcmp(command, "white") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
    } else if (strcmp(command, "off") == 0) {
        turn_off_leds();
    } else if (strcmp(command, "buzzer") == 0) {
        gpio_put(BUZZER, 1);
        sleep_ms(2000);  // Emissão de som por 2 segundos
        gpio_put(BUZZER, 0);
    } else {
        printf("Comando inválido: %s\n", command);
    }
}

int main() {
    // Inicializar UART e GPIOs
    stdio_init_all();
    init_gpio();

    char command[16];

    printf("Sistema iniciado. Digite comandos para controlar os LEDs e o buzzer.\n");

    while (true) {
        // Ler comando da UART
        if (scanf("%15s", command) > 0) {
            execute_command(command);
        }
    }

    return 0;
}
