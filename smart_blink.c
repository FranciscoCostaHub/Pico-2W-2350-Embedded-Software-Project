#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <math.h>

int main() {
    stdio_init_all();
    cyw43_arch_init();

    uint32_t counter = 0;
    
    while (true) {
  
        // Padrão 1: Respiração suave (onda sinusoidal)
        for (int i = 0; i < 100; i++) {
            float angle = (float)i / 100.0f * 3.14159f * 2.0f;
            uint32_t delay = (uint32_t)(50 + 200 * (sin(angle) + 1) / 2);
            
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(delay);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(delay);
        }


        // Padrão 2: Aceleração gradual
        for (int delay = 500; delay > 50; delay -= 10) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(delay);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(delay);
        }

        
        // Padrão 3: Desaceleração gradual
        for (int delay = 50; delay < 500; delay += 10) {
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(delay);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(delay);
        }

        
        // Padrão 4: Batimento cardíaco
        for (int i = 0; i < 5; i++) {
            // Batida dupla rápida
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(80);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(80);
            
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(80);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(400);
        }

        
        // Padrão 5: Morse "SOS"
        for (int i = 0; i < 3; i++) {
            // S (3 curtos)
            for (int j = 0; j < 3; j++) {
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
                sleep_ms(100);
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
                sleep_ms(100);
            }
            sleep_ms(200);
            
            // O (3 longos)
            for (int j = 0; j < 3; j++) {
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
                sleep_ms(300);
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
                sleep_ms(100);
            }
            sleep_ms(200);
            
            // S (3 curtos)
            for (int j = 0; j < 3; j++) {
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
                sleep_ms(100);
                cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
                sleep_ms(100);
            }
                
            
            sleep_ms(1000);
        }
        
        // Pausa antes de repetir todos os padrões
        sleep_ms(2000);
        
    }
}