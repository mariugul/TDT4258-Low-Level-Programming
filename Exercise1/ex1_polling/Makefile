# Example Makefile
#
# Exercise 1, TDT4258

LD=arm-none-eabi-gcc
AS=arm-none-eabi-as
OBJCOPY=arm-none-eabi-objcopy

LDFLAGS=-nostdlib
ASFLAGS=-mcpu=cortex-m3 -mthumb -g

LINKERSCRIPT=efm32gg.ld

polling.bin : polling.elf
	${OBJCOPY} -j .text -O binary $< $@

polling.elf : polling.o 
	${LD} -T ${LINKERSCRIPT} $^ -o $@ ${LDFLAGS} 

polling.o : polling.s
	${AS} ${ASFLAGS} $< -o $@

.PHONY : upload
upload :
	-eACommander.sh -r --address 0x00000000 -f "polling.bin" -r

.PHONY : clean
clean :
	-rm -rf *.o *.elf *.bin *.hex
