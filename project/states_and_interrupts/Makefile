# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: wdInterruptHandler stateMachines p2_interrupt_handler

clean:
	rm -f *.o

wdInterruptHandler: wdInterruptHandler.c ../game_utils/led.h ../games/simon.h ../games/catch_red.h ../games/find_frequency.h ../games/fur_elise.h stateMachines.h
	${CC} ${CFLAGS} -c -I../games -I../game_utils wdInterruptHandler.c

stateMachines: ../game_utils/led.h stateMachines.h stateMachines.c ../game_utils/buttons.h ../games/simon.h ../games/find_frequency.h ../games/catch_red.h game_three_to_four_transition.s
	${CC} ${CFLAGS} -c -I../games -I../game_utils stateMachines.c

p2_interrupt_handler: p2_interrupt_handler.c ../game_utils/buttons.h stateMachines.h
	${CC} ${CFLAGS} -c -I../game_utils p2_interrupt_handler.c
