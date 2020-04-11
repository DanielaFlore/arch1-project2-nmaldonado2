# makfile configuration
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as -mcpu=msp430 --tranditional-format -mP

all: wdt_interrupt_handler state_machine_interrupt_handlers p2_interrupt_handler games_two_three_interrupt_handlers

clean:
	rm -f *.o

wdt_interrupt_handler: wdt_interrupt_handler.c ../game_utils/led.h ../games/simon.h ../games/catch_red.h ../games/find_frequency.h ../games/fur_elise.h state_machine_interrupt_handlers.h
	${CC} ${CFLAGS} -c -I../games -I../game_utils wdt_interrupt_handler.c

state_machine_interrupt_handlers: ../game_utils/led.h state_machine_interrupt_handlers.h state_machine_interrupt_handlers.c ../game_utils/buttons.h ../games/simon.h
	${CC} ${CFLAGS} -c -I../games -I../game_utils state_machine_interrupt_handlers.c

p2_interrupt_handler: p2_interrupt_handler.c ../game_utils/buttons.h state_machine_interrupt_handlers.h games_two_three_interrupt_handlers.h
	${CC} ${CFLAGS} -c -I../game_utils p2_interrupt_handler.c

games_two_three_interrupt_handlers: games_two_three_interrupt_handlers.h games_two_three_interrupt_handlers.s state_machine_interrupt_handlers.h ../games/catch_red.h ../games/find_frequency.h ../game_utils/led.h
	${CC} ${CFLAGS} -c -I../games -I../game_utils games_two_three_interrupt_handlers.s
