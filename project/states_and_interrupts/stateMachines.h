// Nichole Maldonado
// This is the header file for stateMachines.c
// which determines which function to call to
// handle the interrupt based on the game number.

#ifndef stateMachine_included
#define stateMachine_included

extern char game_num;

// Interrupt handlers for the corresponding
// game numbers.

// Interrupt handler for Fur Elise
void game_three_interrupt_handler();

// Interrupt handler for Find Frequency
void game_two_interrupt_handler();

// Interrupt handler for Simon.
void game_four_interrupt_handler();

// Interrupt handler for Catch Red.
void game_one_interrupt_handler();

#endif // included
