
main.o : main.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb main.c -o main.o

GPIO_Program.o : GPIO_Program.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb GPIO_Program.c -o GPIO_Program.o

RCC_Program.o : RCC_Program.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb RCC_Program.c -o RCC_Program.o

SYSTICK_Program.o : SYSTICK_Program.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb SYSTICK_Program.c -o SYSTICK_Program.o

StartupCode_stm32f401xx.o : StartupCode_stm32f401xx.c
	arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb StartupCode_stm32f401xx.c -o StartupCode_stm32f401xx.o

app.elf : main.o GPIO_Program.o RCC_Program.o StartupCode_stm32f401xx.o SYSTICK_Program.o LinkerScript_stmf4.ld
	arm-none-eabi-ld -Map app.map -T LinkerScript_stmf4.ld  main.o GPIO_Program.o RCC_Program.o StartupCode_stm32f401xx.o SYSTICK_Program.o -o app.elf

app.hex : app.elf 
	arm-none-eabi-objcopy -O ihex app.elf app.hex


clean : 
	@rm *.o *.hex *.elf *.map *.asm
 