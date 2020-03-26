# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: wdt_interrupt_handler state_machines p2_interrupt_handler

clean:
	rm -f *.o

wdt_interrupt_handler: wdt_interrupt_handler.c ../game_utils/led.h ../games/simon.h ../games/catch_red.h ../games/find_frequency.h ../games/fur_elise.h state_machines.h
	${CC} ${CFLAGS} -c -I../games -I../game_utils wdt_interrupt_handler.c

state_machines: ../game_utils/led.h state_machines.h state_machines.c ../game_utils/buttons.h ../games/simon.h ../games/find_frequency.h ../games/catch_red.h game_three_to_four_transition.s
	${CC} ${CFLAGS} -c -I../games -I../game_utils state_machines.c

p2_interrupt_handler: p2_interrupt_handler.c ../game_utils/buttons.h state_machines.h
	${CC} ${CFLAGS} -c -I../game_utils p2_interrupt_handler.c
