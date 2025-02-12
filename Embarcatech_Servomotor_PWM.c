#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PIN 22   // Pino de conexão do servomotor para uso no Wokwi
// #define PIN 12   // Pino de conexão do LED para uso na BitDogLab
#define PERIOD 20000   // Período do PWM (valor máximo do contador)

int main() {
    stdio_init_all();
    gpio_set_function(PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PIN);
    
    pwm_set_wrap(slice_num, PERIOD);
    pwm_set_clkdiv(slice_num, 125); 
    pwm_set_enabled(slice_num, true);

            // Posição 180° (2.400µs)
            pwm_set_gpio_level(PIN, (12*PERIOD)/100); 
            sleep_ms(5000);
    
            // Posição 90° (1.470µs)
            pwm_set_gpio_level(PIN, (7.35*PERIOD)/100); 
            sleep_ms(5000);
    
            // Posição 0° (500µs)
            pwm_set_gpio_level(PIN, (2.5*PERIOD)/100); 
            sleep_ms(5000);

    while (true) {
          // Movimento de 0° a 180°
        for (uint32_t pulse = 500; pulse <= 2400; pulse += 5) {
            pwm_set_gpio_level(PIN, pulse);
            sleep_ms(10);
        } // Movimento de 180° a 0°
        for (uint32_t pulse = 2400; pulse >= 500; pulse -= 5) {
            pwm_set_gpio_level(PIN, pulse);
            sleep_ms(10);
        }
    }

}