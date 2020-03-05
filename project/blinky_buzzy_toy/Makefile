# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink.elf 

#additional rules for files
blink.elf: ${COMMON_OBJECTS} blinky_buzzy_toy.o stateMachines.o led.o buzzer.o buttons.o p2_interrupt_handler.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blink.elf
	msp430loader.sh blink.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h buzzer.h wdInterruptHandler.c wdInterruptHandler.h

stateMachines.o: led.h stateMachines.h

buzzer.o: buzzer.c buzzer.h

p1_interrupt_handler.o: p1_interrupt_handler.c buttons.h wdInterruptHandler.h stateMachines.h

buttons.o: buttons.h led.h buttons.c
