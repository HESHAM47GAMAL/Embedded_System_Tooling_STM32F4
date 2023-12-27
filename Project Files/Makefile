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
	$(ToolChain)ld -Map app.map -T  $(LinkerScript) $(OBJ_Files) -o $@

app.hex : app.elf 
	$(ToolChain)objcopy -O ihex app.elf $@


clean : 
	@rm *.o *.hex *.elf *.map *.asm
 