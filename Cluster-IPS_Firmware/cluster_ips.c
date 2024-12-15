#include QMK_KEYBOARD_H
#include <cluster_ips.h>
#include <gpio.h>
#include <keyboard.h>
#include <string.h>
#include <ch.h>


void keyboard_pre_init_kb(void){
    // Ensuring each GND pin is set
    gpio_set_pin_output_push_pull(GP10);
    gpio_set_pin_output_push_pull(GP11);
    gpio_set_pin_output_push_pull(GP12);
    gpio_set_pin_output_push_pull(GP13);

    // Resetting the GND pins as a precaution
    gpio_write_pin_low(GP10);
    gpio_write_pin_high(GP11);
    gpio_write_pin_low(GP12);
    gpio_write_pin_high(GP13);

    keyboard_post_init_kb();
}

void keyboard_post_init_kb(void){
    gpio_write_pin_low(GP10);
    gpio_write_pin_high(GP11);
    gpio_write_pin_low(GP12);
    gpio_write_pin_high(GP13);
}
