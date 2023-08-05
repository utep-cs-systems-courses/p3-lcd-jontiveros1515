# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 
#additional rules for files
button.elf: ${COMMON_OBJECTS} main.o buzzerHandle.o wdInterruptHandler.o led.o stateMachine.o switchInterrputHandler.o lcddraw.o lcdutils.o switch.o  font-11x16.o font-5x7.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

button2.elf: ${COMMON_OBJECTS} main.o buzzerHandle.o wdInterruptHandler.o led.o stateMachine.o switchInterrputHandler.o lcddraw.o lcdutils.o switch-s.o  font-11x16.o font-5x7.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh $^

load2: button2.elf
	msp430loader.sh $^


clean:
	rm -f *.o *.elf

buzzerHandle.o: buzzer.h

wdInterruptHandler.o: buzzer.h led.h

led.o: led.h

stateMachine.o: stateMachine.h lcddraw.h lcdutils.h

switchInterruptHandler.o: stateMachine.h

lcddraw.o: lcddraw.h lcdutils.h

