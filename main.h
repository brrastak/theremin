// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>

#ifndef __MAIN_H__
#define __MAIN_H__


// Ports and pin numbers
// Generator inputs           
#define VOLUME_PIN              GPIOB, 10
#define PITCH_PIN               GPIOB, 11
// USART
#define USART_TX_PIN            GPIOB, 6
#define USART_RX_PIN            GPIOB, 7
// SPI
#define SPI_NSS_PIN             GPIOB, 12
#define SPI_SCK_PIN             GPIOB, 13
//#define SPI_MISO_PIN            GPIOB, 14
#define SPI_MOSI_PIN            GPIOB, 15
// Audio amplifier control
#define ST_BY_PIN               GPIOA, 11
#define MUTE_PIN                GPIOA, 12
// Encoders
#define VOLUME_A_PIN            GPIOB, 1
#define VOLUME_B_PIN            GPIOB, 0
#define PITCH_A_PIN             GPIOA, 6
#define PITCH_B_PIN             GPIOA, 5
#define REG_A_PIN               GPIOA, 3
#define REG_B_PIN               GPIOA, 2
#define TIMBRE_A_PIN            GPIOB, 5
#define TIMBRE_B_PIN            GPIOB, 8
// Buttons (in encoders)
#define VOLUME_BTN_PIN          GPIOA, 7
#define PITCH_BTN_PIN           GPIOA, 4
#define REG_BTN_PIN             GPIOA, 1
#define TIMBRE_BTN_PIN          GPIOB, 9
// LEDs: left and right; red and green
#define LED_LEFT_R_PIN          GPIOA, 9
#define LED_LEFT_G_PIN          GPIOA, 8
#define LED_RIGHT_R_PIN         GPIOA, 15
#define LED_RIGHT_G_PIN         GPIOA, 10
// Battery voltage measurement
#define VBAT_PIN                GPIOA, 0
// Onboard LED
#define LED_PIN                 GPIOC, 13

// Reset volume and pitch timers and save its values
void ProceedTimers(void);

// Temporary
extern uint16_t volume_freq;


#endif
