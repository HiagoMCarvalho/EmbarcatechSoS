#include <stdio.h>
#include "pico/stdlib.h"

#define PONTO 200
#define TRACO 800
#define GAP 125
#define INTERVALO_LETRA 250
#define INTERVALO_CICLO 3000
#define LED_PIN 13

// Função para enviar um sinal (ponto ou traço)
void enviarSinal(int duracao) {
    gpio_put(LED_PIN, true);  // Liga o LED
    sleep_ms(duracao);              // Mantém o LED ligado pelo tempo especificado
    gpio_put(LED_PIN, false);  // Desliga o LED
    sleep_ms(GAP);                  // Pausa entre sinais dentro de uma letra
}

// Função para enviar o sinal SOS
void enviarSOS() {
    // Três pontos (S)
    for (int i = 0; i < 3; i++) {
        enviarSinal(PONTO);
    }
    sleep_ms(INTERVALO_LETRA);

    // Três traços (O)
    for (int i = 0; i < 3; i++) {
        enviarSinal(TRACO);
    }
    sleep_ms(INTERVALO_LETRA);

    // Três pontos (S)
    for (int i = 0; i < 3; i++) {
        enviarSinal(PONTO);
    }
    sleep_ms(INTERVALO_CICLO); // Pausa antes de reiniciar o ciclo
}


int main()
{
   gpio_init(LED_PIN);
   gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) 
    {
         enviarSOS();
    }
}
