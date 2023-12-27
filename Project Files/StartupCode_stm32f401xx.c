/**************** Startup Code ************/

#define Null (void * ) 0

void __attribute__((weak))                                  Reset_Handler(void);
void __attribute__((weak))                                  Default_Handler (void);
void __attribute__((weak , alias("Default_Handler")))       NMI_Handler(void);      
void __attribute__((weak , alias("Default_Handler")))       HardFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       MemManage_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       BusFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       UsageFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SVCall_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DebugMonitor_Handeler(void);
void __attribute__((weak , alias("Default_Handler")))       PendSV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       Systick_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       WWDG_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       PVD_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TAMP_STAMP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RTC_WKUP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       FLASH_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RCC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream6_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       ADC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI9_5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_BRK_TIM9_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_UP_TIM10_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_TRG_COM_TIM11_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_CC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C1_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C1_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C2_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C2_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI15_10_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RTC_Alarm_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       OTG_FS_WKUP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream7_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SDIO_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       OTG_FS_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream6_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream7_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART6_handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C3_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C3_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       FPU_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI4_Handler(void);
    






//  1.Setup Interrupt vector table

extern int main();
extern int _estack;
extern int _sdata_flash;
extern int _sdata;
extern int _edata;
extern int _sbss;
extern int _ebss;

// void (* const PF [] ) (void) = { ,  , };
//      OR
typedef void (* const PF_Handler) (void);  //PF abbereviation pointer to function
//used constant pointer --> as this pointer used to point to function and this function no need to change as make pointer to point to another one

//I need to make this table stored in .isr_vector -->  __attribute__((section(".isr_vector")))
//I need to force compiler to don't make any change in this table even used or not  so use --> __attribute__((used))
__attribute__((section(".isr_vector"),used))
PF_Handler Vector_Table [] = 
{
//2.Intialize Stack Pointer (SP)
    (PF_Handler) & _estack , 
    Reset_Handler ,
    NMI_Handler ,
    HardFault_Handler ,
    MemManage_Handler ,
    BusFault_Handler , 
    UsageFault_Handler ,
    0 , //Reserved
    0 , //Reserved
    0 , //Reserved
    0 , //Reserved
    SVCall_Handler ,
    DebugMonitor_Handeler ,
    0 ,
    PendSV_Handler ,
    Systick_Handler ,
    WWDG_Handler ,
    PVD_Handler ,
    TAMP_STAMP_Handler ,
    RTC_WKUP_Handler ,
    FLASH_Handler ,
    RCC_Handler ,
    EXTI0_Handler ,
    EXTI1_Handler ,
    EXTI2_Handler ,
    EXTI3_Handler ,
    EXTI4_Handler ,
    DMA1_Stream0_Handler ,
    DMA1_Stream1_Handler ,
    DMA1_Stream2_Handler ,
    DMA1_Stream3_Handler ,
    DMA1_Stream4_Handler ,
    DMA1_Stream5_Handler ,
    DMA1_Stream6_Handler ,
    ADC_Handler ,
    0 ,
    0 , 
    0 , 
    0 ,
    0 ,
    EXTI9_5_Handler ,
    TIM1_BRK_TIM9_Handler ,
    TIM1_UP_TIM10_Handler ,
    TIM1_TRG_COM_TIM11_Handler ,
    TIM1_CC_Handler ,
    TIM2_Handler ,
    TIM3_Handler ,
    TIM4_Handler ,
    I2C1_EV_Handler ,
    I2C1_ER_Handler ,
    I2C2_EV_Handler ,
    I2C2_ER_Handler ,
    SPI1_Handler ,
    SPI2_Handler ,
    USART1_Handler ,
    USART2_Handler ,
    0 ,
    EXTI15_10_Handler , 
    RTC_Alarm_Handler ,
    OTG_FS_WKUP_Handler ,
    0 , 
    0 ,
    0 , 
    0 ,
    DMA1_Stream7_Handler ,
    0 ,
    SDIO_Handler ,
    TIM5_Handler ,
    SPI3_Handler ,
    0 ,
    0 ,
    0 ,
    0 ,
    DMA2_Stream0_Handler , 
    DMA2_Stream1_Handler ,
    DMA2_Stream2_Handler ,
    DMA2_Stream3_Handler ,
    DMA2_Stream4_Handler ,
    0 ,
    0 ,
    0 ,
    0 ,
    0 ,
    0 ,
    OTG_FS_Handler ,
    DMA2_Stream5_Handler ,
    DMA2_Stream6_Handler ,
    DMA2_Stream7_Handler ,
    USART6_handler ,
    I2C3_EV_Handler ,
    I2C3_ER_Handler ,
    0 , 
    0 ,
    0 ,
    0 ,
    0 ,
    0 ,
    0 ,
    FPU_Handler ,
    0 ,
    0 ,
    SPI4_Handler ,



};


void __attribute__((section(".init"),used)) Reset_Handler(void)
{
    unsigned long * MemoSource = Null;
    unsigned long * MemoDestenation = Null;
    unsigned long Section_size = 0;

    //3.Copy .data from FLASH to RAM 
    MemoSource      =(unsigned long *) &_sdata_flash;
    MemoDestenation =(unsigned long *) &_sdata;
    Section_size    = (&_edata) - (&_sdata) ;
    for(unsigned long i = 0 ; i < Section_size ; i++) // actually copy addresses not values 
    {
        *MemoDestenation++ = *MemoSource++;
    }


    //4.Reserve .bss in RAM
    MemoDestenation = (unsigned long * ) &_sbss ;
    Section_size = (&_ebss) - (&_sbss) ;
    for(unsigned long i = 0 ; i < Section_size ; i++) // actually copy addresses not values 
    {
        *MemoDestenation++ = 0;
    }


    //5.Call main function 
    main();

}

void __attribute__((section(".init"),used))Default_Handler(void)
{
    while(1){}
}


