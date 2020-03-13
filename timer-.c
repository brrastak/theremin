// STM32F103
#include "stm32f10x.h"

// user
#include "main.h"
#include "timer.h"
#include "gpio.h"

volatile uint32_t sys_tick = 0;

// SysTick timer interrupt
void SysTick_Handler(void)
{
    sys_tick++;         // every 1ms
    if (sys_tick % 100 == 0)
        ProceedTimers();
}
void InitSysTick(void)
{
    SysTick->LOAD = SYS_TIMER_TICK;
    SysTick->VAL = 0;
    SysTick->CTRL =	SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk   |    // interrupt enable
                    SysTick_CTRL_ENABLE_Msk;
}
void InitVolumeTimer(void)
{
    // Timer
    TIM2->CR1 = TIM_CR1_ARPE    * 0 |   // Auto-reload preload disable
                TIM_CR1_CMS_0   * 0 |   // Center-aligned mode selection : edge-aligned mode
                TIM_CR1_CMS_1   * 0 |
                TIM_CR1_DIR     * 0;    // Direction : upcounter
    TIM2->PSC = 0;                      // no prescaler
    TIM2->ARR = 0xffff;                 // max
    
    // External input
    TIM2->CCMR1 =   TIM_CCMR1_CC1S_0    * 1 |   // channel 1 input on TI1
                    TIM_CCMR1_CC1S_1    * 0 |
                    TIM_CCMR1_IC1F_0    * 0 |   // input filter disable
                    TIM_CCMR1_IC1F_1    * 0 |
                    TIM_CCMR1_IC1F_2    * 0 |
                    TIM_CCMR1_IC1F_3    * 0;
    TIM2->CCER =    TIM_CCER_CC1P       * 0;    // rising edge capture
    TIM2->SMCR =    TIM_SMCR_SMS_0      * 1 |   // external clock mode 1
                    TIM_SMCR_SMS_1      * 1 |
                    TIM_SMCR_SMS_2      * 1 |
                    TIM_SMCR_TS_0       * 1 |   // TI1 input source
                    TIM_SMCR_TS_1       * 0 |
                    TIM_SMCR_TS_2       * 1;
    
    TIM2->EGR = TIM_EGR_UG;             // update
    // Interrupt
    //TIM2->DIER |= TIM_DIER_UIE;         // update interrupt enable
    // Start
    TIM2->CR1 |= TIM_CR1_CEN;
}
void InitPitchTimer(void)
{
    // Timer
    TIM3->CR1 = TIM_CR1_ARPE    * 1 |   // Auto-reload preload enable
                TIM_CR1_CMS_0   * 0 |   // Center-aligned mode selection : edge-aligned mode
                TIM_CR1_CMS_1   * 0 |
                TIM_CR1_DIR     * 0;    // Direction : upcounter
    TIM3->CR2 |= 0x20;                  // TRGO on update event
    TIM3->PSC = 3599;                   // CK_CNT = 20kHz
    TIM3->ARR = 399;                    // 50 Hz
    TIM3->EGR = TIM_EGR_UG;             // update event enable
    // Interrupt
    //TIM3->DIER |= TIM_DIER_UIE;         // update
    // Start!
    TIM3->CR1 |= TIM_CR1_CEN;
}

// Delay TIM4
void delay_ms(int time)
{
    TIM4->CR1 = 0;
    TIM4->SR = 0;
    TIM4->PSC = 35999;                  // 2kHz
    TIM4->ARR = time * 2 - 1;
    TIM4->EGR = TIM_EGR_UG;
    TIM4->SR &= ~TIM_SR_UIF;
    TIM4->CR1 |= TIM_CR1_CEN;
    while (!(TIM4->SR & TIM_SR_UIF))
        ;
    TIM4->CR1 &= ~TIM_CR1_CEN;
}
void delay_us(int time)
{
    TIM4->CR1 = 0;
    TIM4->SR = 0;
    TIM4->PSC = 35;                     // 2MHz
    TIM4->ARR = time * 2 - 1;
    TIM4->EGR = TIM_EGR_UG;
    TIM4->SR &= ~TIM_SR_UIF;
    TIM4->CR1 |= TIM_CR1_CEN;
    while (!(TIM4->SR & TIM_SR_UIF))
        ;
    TIM4->CR1 &= ~TIM_CR1_CEN;
}
