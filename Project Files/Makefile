ToolChain 	 	:= arm-none-eabi-
Target		 	:= -mcpu=cortex-m4 -mthumb
LinkerScript 	:= LinkerScript_stmf4.ld
SRC_Files 		:= $(wildcard *.c)
OBJ_Files 		:= $(SRC_Files:.c=.o)


all : app.hex
	@echo "--------- Hex file Generated Successfully ---------"

%.o : %.c
	$(ToolChain)gcc -c $(Target)  $< -o $@

app.elf : $(OBJ_Files)
	$(ToolChain)ld -Map app.map -T  $(LinkerScript) $< -o $@

app.hex : app.elf 
	$(ToolChain)objcopy -O ihex $< $@


clean : 
	@rm *.o *.hex *.elf *.map *.asm
 