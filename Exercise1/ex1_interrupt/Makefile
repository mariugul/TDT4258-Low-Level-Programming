# Example Makefile
#
# Exercise 1, TDT4258

LD=arm-none-eabi-gcc
AS=arm-none-eabi-as
OBJCOPY=arm-none-eabi-objcopy

LDFLAGS=-nostdlib
ASFLAGS=-mcpu=cortex-m3 -mthumb -g

LINKERSCRIPT=efm32gg.ld

interrupt.bin : interrupt.elf
	${OBJCOPY} -j .text -O binary $< $@

interrupt.elf : interrupt.o 
	${LD} -T ${LINKERSCRIPT} $^ -o $@ ${LDFLAGS} 

interrupt.o : interrupt.s
	${AS} ${ASFLAGS} $< -o $@

.PHONY : upload
upload :
	-eACommander.sh -r --address 0x00000000 -f "interrupt.bin" -r

.PHONY : clean
clean :
	-rm -rf *.o *.elf *.bin *.hex
