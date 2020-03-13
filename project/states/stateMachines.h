#ifndef stateMachine_included
#define stateMachine_included

extern char game_num;

unsigned char game_three_interrupt_handler(unsigned char light_speed);
void frequency_recovery();
void game_four_interrupt_handler();
void game_one_interrupt_handler();

#endif // included
