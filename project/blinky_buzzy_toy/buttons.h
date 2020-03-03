#ifndef buttons_included
#define buttons_included

#define BTN1 BIT0
#define BTN2 BIT1
#define BTN3 BIT2
#define BTN4 BIT3/* switch1 is p1.3 */

#define BUTTONS BTN1 | BTN2 | BTN3 | BTN4/* only 1 switch on this board */

void buttons_init();
void buttons_interrupt_handler();

extern char button_state_down, button_state_changed; /* effectively boolean */

#endif // included
