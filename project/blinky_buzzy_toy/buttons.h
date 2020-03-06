#ifndef buttons_included
#define buttons_included

#define BTN1 BIT0
#define BTN2 BIT1
#define BTN3 BIT2
#define BTN4 BIT3

#define BUTTONS 0xf

void buttons_init();
void buttons_interrupt_handler();

extern char button_state_down, button_state_changed; 

#endif // included
