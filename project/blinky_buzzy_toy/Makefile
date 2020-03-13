# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../../demos/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinky_buzzy_toy.elf 

#additional rules for files
blinky_buzzy_toy.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o simon.o catch_red.o find_frequency.o fur_elise.o ../../demos/lib/libTimer.a game_three_to_four_transition.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy_toy.elf
	msp430loader.sh blinky_buzzy_toy.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: wdInterruptHandler.c led.h simon.h catch_red.h find_frequency.h fur_elise.h stateMachines.h

stateMachines.o: led.h stateMachines.h stateMachines.c led.h buttons.h simon.h find_frequency.h

buzzer.o: buzzer.c buzzer.h

p2_interrupt_handler.o: p2_interrupt_handler.c buttons.h stateMachines.h led.h

buttons.o: buttons.h led.h buttons.c

simon.o: simon.h simon.c led.h buzzer.h

catch_red.o: catch_red.h catch_red.c led.h buzzer.h

find_frequency.o: find_frequency.h find_frequency.c buzzer.h

fur_elise.o: fur_elise.h fur_elise.c buzzer.h led.h
