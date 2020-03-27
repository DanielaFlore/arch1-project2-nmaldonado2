// Nichole Maldonado and Previous Commits
// This file is the header file for led.c
// that contains functions to initialize the
// leds and turn the green and red lights on
// or off.

#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.6
#define LED_GREEN BIT0             // P1.0
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;

// Initialize the red and green lights.
void led_init();

// Turn the lights on, based on the flags
// red_on and green_on.
void led_change();

// Turns on the green light.
void turn_on_green();

// Turns off the green light.
void turn_off_green();

// Turns on the red light.
void turn_on_red();

// Turns off the red light.
void turn_off_red();

// Turns off the green and red light.
void turn_off_green_red();

#endif // included
