/**
 * Marlin 3D Printer Firmware
 *
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (c) 2016 Bob Cousins bobcousins42@googlemail.com
 * Copyright (c) 2015-2016 Nico Tonnhofer wurstnase.reprap@gmail.com
 * Copyright (c) 2017 Victor Perez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define CPU_32_BIT

#include "../../core/macros.h"
#include "../shared/Marduino.h"
#include "../shared/math_32bit.h"
#include "../shared/HAL_SPI.h"
#include "fastio.h"
#include "watchdog.h"

#include "../../inc/MarlinConfigPre.h"

#include <stdint.h>

#ifdef USBCON
  #include <USBSerial.h>
#endif

// ------------------------
// Defines
// ------------------------
#define _MSERIAL(X) Serial##X
#define MSERIAL(X) _MSERIAL(X)

#if WITHIN(SERIAL_PORT, 1, 6)
  #define MYSERIAL0 MSERIAL(SERIAL_PORT)
#else
  #error "SERIAL_PORT must be -1 or from 1 to 6. Please update your configuration."
#endif


#ifdef LCD_SERIAL_PORT
  #if WITHIN(LCD_SERIAL_PORT, 1, 6)
    #define LCD_SERIAL MSERIAL(LCD_SERIAL_PORT)
  #else
    #error "LCD_SERIAL_PORT must be -1 or from 1 to 6. Please update your configuration."
  #endif
#endif

/**
 * TODO: review this to return 1 for pins that are not analog input
 */
#ifndef analogInputToDigitalPin
  #define analogInputToDigitalPin(p) (p)
#endif
inline void __enable_irq(void)
{
  __asm volatile ("cpsie i");
}

inline unsigned long __disable_irq(void)
{
  unsigned long result;
  __asm volatile ("mrs %0, primask" : "=r" (result));
  __asm volatile ("cpsid i");
  return(result & 1);
}


#define CRITICAL_SECTION_START()  NOOP//uint32_t primask = __get_PRIMASK(); __disable_irq()
#define CRITICAL_SECTION_END()    NOOP//if (!primask) __enable_irq()
#define ISRS_ENABLED() NOOP//(!__get_PRIMASK())
#define ENABLE_ISRS  __enable_irq
#define DISABLE_ISRS __disable_irq
#define cli __disable_irq
#define sei __enable_irq

// On AVR this is in math.h?
#define square(x) ((x)*(x))

#ifndef strncpy_P
  #define strncpy_P(dest, src, num) strncpy((dest), (src), (num))
#endif

// Fix bug in pgm_read_ptr
#undef pgm_read_ptr
#define pgm_read_ptr(addr) (*(addr))

// ------------------------
// Types
// ------------------------

typedef int16_t pin_t;

//#define HAL_SERVO_LIB libServo
//#define PAUSE_SERVO_OUTPUT() libServo::pause_all_servos()
//#define RESUME_SERVO_OUTPUT() libServo::resume_all_servos()

// ------------------------
// Public Variables
// ------------------------

// result of last ADC conversion
extern uint16_t HAL_adc_result;

extern uint16_t g_adc_value[3];
extern uint8_t g_adc_idx;

// ------------------------
// Public functions
// ------------------------

// Memory related
#define __bss_end __bss_end__

// Enable hooks into  setup for HAL
void HAL_init();

// Clear reset reason
void HAL_clear_reset_source();

// Reset reason
uint8_t HAL_get_reset_source();

inline void HAL_reboot() {}  // reboot the board or restart the bootloader

void _delay_ms(const int delay);

extern "C" char* _sbrk(int incr);

//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wunused-function"

static inline int freeMemory() {
  volatile char top;
  return top;
}

//#pragma GCC diagnostic pop

//
// ADC
//

void HAL_adc_init();

inline static void HAL_adc_start(uint32_t pin)
{
    if       (pin == TEMP_BED_PIN) {
        g_adc_idx = 0;
    } else if(pin == TEMP_0_PIN) {
        g_adc_idx = 1;
    } else if(pin == POWER_MONITOR_VOLTAGE_PIN) {
        g_adc_idx = 2;
    } else {
  	    g_adc_idx = 0x0;
    }
}


inline static uint32_t HAL_adc_read()
{
  return g_adc_value[g_adc_idx];
}


#define ADC_RESOLUTION		12
#define HAL_ADC_VREF        3.3
#define HAL_ADC_RESOLUTION  ADC_RESOLUTION // 12
#define HAL_START_ADC(pin)  HAL_adc_start(pin)
#define HAL_READ_ADC()      HAL_adc_read()
#define HAL_ADC_READY()     true

//inline void HAL_adc_init() { analogReadResolution(HAL_ADC_RESOLUTION); }

void HAL_adc_start_conversion(const uint8_t adc_pin);

uint16_t HAL_adc_get_result();

#define GET_PIN_MAP_PIN(index) index
#define GET_PIN_MAP_INDEX(pin) pin
#define PARSED_PIN_INDEX(code, dval) parser.intval(code, dval)

#ifdef STM32F1xx
  #define JTAG_DISABLE() AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_JTAGDISABLE)
  #define JTAGSWD_DISABLE() AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_DISABLE)
#endif

#define PLATFORM_M997_SUPPORT
void flashFirmware(const int16_t);

#define HAL_CAN_SET_PWM_FREQ   // This HAL supports PWM Frequency adjustment

/**
 * set_pwm_frequency
 *  Set the frequency of the timer corresponding to the provided pin
 *  All Timer PWM pins run at the same frequency
 */
void set_pwm_frequency(const pin_t pin, int f_desired);

/**
 * set_pwm_duty
 *  Set the PWM duty cycle of the provided pin to the provided value
 *  Optionally allows inverting the duty cycle [default = false]
 *  Optionally allows changing the maximum size of the provided value to enable finer PWM duty control [default = 255]
 */
void set_pwm_duty(const pin_t pin, const uint16_t v, const uint16_t v_size=255, const bool invert=false);
