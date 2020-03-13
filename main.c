// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//user
#include "main.h"
#include "init.h"
#include "gpio.h"
#include "timer.h"
#include "button.h"
#include "UART.h"
#include "debug_led.h"



char buf[20];


int main()
{    
    // System init
    InitRcc();
    InitGpio();
    InitSysTick();
    InitUart();
    InitInterrupt();
    
    // Turn LEDs off
    SetPin(LED_LEFT_R_PIN);
    SetPin(LED_LEFT_G_PIN);
    SetPin(LED_RIGHT_R_PIN);
    SetPin(LED_RIGHT_G_PIN);
    TurnLedOff();
    
    // Buttons
    btn_t VolumeBtn = {VOLUME_BTN_PIN,  0, 20, false, false, false};
    btn_t PitchBtn  = {PITCH_BTN_PIN,   0, 20, false, false, false};
    btn_t RegBtn    = {REG_BTN_PIN,     0, 20, false, false, false};
    btn_t TimbreBtn = {TIMBRE_BTN_PIN,  0, 20, false, false, false};
    
    // Timings
    uint32_t BtnCounter;
    
    BtnCounter = sys_tick;
    
    while (true) {
        
        // Check buttons state
        if (sys_tick - BtnCounter > 1) {
            BtnCounter = sys_tick;
            
            CheckBtn(&VolumeBtn);
            CheckBtn(&PitchBtn);
            CheckBtn(&RegBtn);
            CheckBtn(&TimbreBtn);
        }
        
        if (WasPressed(&VolumeBtn))
            SwitchPin(LED_LEFT_R_PIN);
        if (WasPressed(&PitchBtn))
            SwitchPin(LED_RIGHT_R_PIN);
        if (WasPressed(&RegBtn))
            SwitchPin(LED_LEFT_G_PIN);
        if (WasPressed(&TimbreBtn))
            SwitchPin(LED_RIGHT_G_PIN);
        
    }
    
 
}



