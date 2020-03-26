CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I ../../demos/h -I games

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc

all: led buzzer buttons

led: led.c led.h
	${CC} ${CFLAGS} -c led.c

buzzer: buzzer.c buzzer.h ../../demos/timerLib/libTimer.h
	${CC} ${CFLAGS} -c -I../../demos/timerLib buzzer.c

buttons: buttons.h buttons.c
	${CC} ${CFLAGS} -c buttons.c

clean:
	rm -f *.o
