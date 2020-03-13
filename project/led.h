#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.0
#define LED_GREEN BIT0             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;

void led_init();
void led_change();
void turn_on_green();
void turn_off_green();
void turn_on_red();
void turn_off_red();
void turn_off_green_red();

#endif // included
