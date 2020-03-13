# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../demos/h -I games
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinky_buzzy_toy.elf 

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o simon.o catch_red.o find_frequency.o fur_elise.o ../demos/lib/libTimer.a game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: wdInterruptHandler.c led.h games/simon.h games/catch_red.h games/find_frequency.h games/fur_elise.h stateMachines.h

stateMachines.o: led.h stateMachines.h stateMachines.c led.h buttons.h games/simon.h games/find_frequency.h game_three_to_four_transition.s

buzzer.o: buzzer.c buzzer.h

p2_interrupt_handler.o: p2_interrupt_handler.c buttons.h stateMachines.h led.h

buttons.o: buttons.h led.h buttons.c

simon.o: games/simon.h games/simon.c led.h buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ games/simon.c

catch_red.o: games/catch_red.h games/catch_red.c led.h buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ games/catch_red.c

find_frequency.o: games/find_frequency.h games/find_frequency.c buzzer.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ games/find_frequency.c

fur_elise.o: games/fur_elise.h games/fur_elise.c buzzer.h led.h
	msp430-elf-gcc -mmcu=msp430g2553 -c -I./ games/fur_elise.c
