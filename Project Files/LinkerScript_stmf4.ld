_estack = ORIGIN(RAM) + LENGTH(RAM);

MEMORY 
{
    RAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 256K
}

SECTIONS
{
	.isr_vector :
	{
		*(.isr_vector)
		*(.isr_vector*)
	} > FLASH
	
	.init :
	{
		*(.init)	
		*(.init*)  
	} > FLASH
	
	.text :
	{
		*(.text)
		*(.text*)
	} > FLASH

	_sdata_flash = LOADADDR (.data);
	
	

	.data :
	{
		_sdata = . ;  
		*(.data)
		*(.data*)
		_edata = . ;
	} > RAM AT > FLASH
	
	.bss :
	{
		_sbss = . ;
		*(.bss)
		*(.bss*)
		_ebss = . ;
	} > RAM
	
	.rodata :
	{
		*(.rodata)
		*(.rodata*)
	} > FLASH
	
}