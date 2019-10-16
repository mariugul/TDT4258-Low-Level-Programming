# Makefile for Exercise 2, TDT4258
# Modified by Marius C. K.

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=cortex-m3  -mthumb -g -std=c99 -Wall
LDFLAGS=-mcpu=cortex-m3 -mthumb -g -lgcc -lc -lcs3 -lcs3unhosted -lefm32gg -Llib
ASFLAGS=-mcpu=cortex-m3 -mthumb -g
LINKERSCRIPT=lib/linkerscript.ld

# All the object files
OBJS   = build/main.o build/timer.o build/dac.o build/gpio.o build/interrupt.o build/low_energy.o build/melodies.o

# Build main binary
build/main.bin : build/main.elf
	${OBJCOPY} -O binary $< $@

# Build main elf 
build/main.elf : $(OBJS)
	${LD} -T ${LINKERSCRIPT} $^ -o $@ ${LDFLAGS} 

# Compile the .c files into .o files if modified
build/%.o : src/%.c 
	${CC} ${CFLAGS} -c $< -o $@


# Command for formatter
.PHONY : pretty
pretty :
	-indent *.c *.h

# Command for uploading code
.PHONY : upload
upload :
	-eACommander.sh -r --address 0x00000000 -f "build/main.bin" -r

# Command for cleaning all the build files
.PHONY : clean
clean :
	-rm -rf build/*.o build/*.elf build/*.bin build/*.hex 