// STM32F103
#include "stm32f10x.h"

// user
#include "init.h"
#include "main.h"
#include "gpio.h"

void InitRcc(void)
{
    // port A
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    // port B
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    // port C
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    // TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    // TIM4
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    // SPI1
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    // USART2
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    // AFIO
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
}
void InitInterrupt(void)
{
    // TIM2
    //NVIC_EnableIRQ(TIM2_IRQn);
    // TIM3
    //NVIC_EnableIRQ(TIM3_IRQn);
    // ADC1
    //NVIC_EnableIRQ(ADC1_2_IRQn);
    // USART2
    NVIC_EnableIRQ(USART2_IRQn);
}
void InitGpio(void)
{
    // Remap A15
    AFIO->MAPR |=   AFIO_MAPR_SWJ_CFG_2 * 0 |
                    AFIO_MAPR_SWJ_CFG_1 * 1 |
                    AFIO_MAPR_SWJ_CFG_0 * 0;
    
    // Generator inputs 
    SetGpioMode(VOLUME_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(PITCH_PIN, PIN_MODE_IFLOAT);
    // USART
    SetGpioMode(USART_TX_PIN, PIN_MODE_2MHZ_AFPP);
    SetGpioMode(USART_RX_PIN, PIN_MODE_IFLOAT);
    // SPI
    SetGpioMode(SPI_NSS_PIN, PIN_MODE_2MHZ_OPP);
    SetGpioMode(SPI_SCK_PIN, PIN_MODE_2MHZ_AFPP);
    SetGpioMode(SPI_MOSI_PIN, PIN_MODE_2MHZ_AFPP);
    // Audio amplifier control
    SetGpioMode(ST_BY_PIN, PIN_MODE_2MHZ_OPP);
    SetGpioMode(MUTE_PIN, PIN_MODE_2MHZ_OPP);
    // Encoders
    SetGpioMode(VOLUME_A_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(VOLUME_B_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(PITCH_A_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(PITCH_B_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(REG_A_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(REG_B_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(TIMBRE_A_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(TIMBRE_B_PIN, PIN_MODE_IFLOAT);
    // Buttons (in encoders)
    SetGpioMode(VOLUME_BTN_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(PITCH_BTN_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(REG_BTN_PIN, PIN_MODE_IFLOAT);
    SetGpioMode(TIMBRE_BTN_PIN, PIN_MODE_IFLOAT);
    // LEDs: left and right; red and green
    SetGpioMode(LED_LEFT_R_PIN, PIN_MODE_2MHZ_OPP);
    SetGpioMode(LED_LEFT_G_PIN, PIN_MODE_2MHZ_OPP);
    SetGpioMode(LED_RIGHT_R_PIN, PIN_MODE_2MHZ_OPP);
    SetGpioMode(LED_RIGHT_G_PIN, PIN_MODE_2MHZ_OPP);
    // Battery voltage measurement
    //SetGpioMode(VBAT_PIN, PIN_MODE_IANALOG);
    // Onboard LED
    SetGpioMode(LED_PIN, PIN_MODE_2MHZ_OPP);
}
