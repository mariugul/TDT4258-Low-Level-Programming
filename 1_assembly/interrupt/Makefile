# Makefile
#
# Exercise 1, TDT4258
# Modified by Marius C. K.

LD=arm-none-eabi-gcc
AS=arm-none-eabi-as
OBJCOPY=arm-none-eabi-objcopy

LDFLAGS=-nostdlib
ASFLAGS=-mcpu=cortex-m3 -mthumb -g

LINKERSCRIPT=lib/linkerscript.ld

build/main.bin : build/main.elf
	${OBJCOPY} -j .text -O binary $< $@

build/main.elf : build/main.o 
	${LD} -T ${LINKERSCRIPT} $^ -o $@ ${LDFLAGS} 

build/main.o : main.s
	${AS} ${ASFLAGS} $< -o $@


.PHONY : All of my rules
upload :
	commander flash build/main.bin --address 0x0

clean :
	-rm -rf build/\*.o build/\*.elf build/\*.bin build/\*.hex
