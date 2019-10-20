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

.PHONY : upload
upload :
	-eACommander.sh -r --address 0x00000000 -f "build/main.bin" -r

.PHONY : clean
clean :
	-rm -rf build/*.o build/*.elf build/*.bin build/*.hex
