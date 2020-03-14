// Nichole Maldonado and Previous Commits
// Header file for buttons.c which prepares the
// buttons for use and changes the IES based
// on the current transition.

#ifndef buttons_included
#define buttons_included

#define BTN1 BIT0
#define BTN2 BIT1
#define BTN3 BIT2
#define BTN4 BIT3

#define BUTTONS (BTN1 | BTN2 | BTN3 | BTN4)

// Sets buttons for use.
void buttons_init();

// Changes IES from the current transition
// sensed to the reversed transition to sense.
// For example if sensing low to high, then
// sense high to low.
void buttons_update_interrupt_sense();

#endif // included
