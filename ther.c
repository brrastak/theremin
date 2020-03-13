// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>

// user
#include "main.h"

// Volume and pitch frequency values
uint16_t volume_freq = 0;
uint16_t pitch_freq = 0;

// Reset volume and pitch timers and save its values
void ProceedTimers()
{
    volume_freq = TIM2->CNT;
    pitch_freq = TIM3->CNT;
    // Reset
    TIM2->EGR = TIM_EGR_UG;
    TIM3->EGR = TIM_EGR_UG;
}
