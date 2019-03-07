/*
    __eqalizer_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __eqalizer_driver.h
@brief    Equalizer Driver
@mainpage Equalizer Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   EQUALIZER
@brief      Equalizer Click Driver
@{

| Global Library Prefix | **EQUALIZER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **dec 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _EQUALIZER_H_
#define _EQUALIZER_H_

/** 
 * @macro T_EQUALIZER_P
 * @brief Driver Abstract type 
 */
#define T_EQUALIZER_P    const uint8_t*

/** @defgroup EQUALIZER_COMPILE Compilation Config */              /** @{ */

//  #define   __EQUALIZER_DRV_SPI__                            /**<     @macro __EQUALIZER_DRV_SPI__  @brief SPI driver selector */
   #define   __EQUALIZER_DRV_I2C__                            /**<     @macro __EQUALIZER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __EQUALIZER_DRV_UART__                           /**<     @macro __EQUALIZER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup EQUALIZER_VAR Variables */                           /** @{ */

/* Volume */
extern const uint8_t _EQUALIZER_SET_VOLUME_1dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_10dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_20dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_2dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_30dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_3dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_40dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_4dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_50dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_5dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_60dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_6dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_70dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_7dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_0dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_8dB  ;
extern const uint8_t _EQUALIZER_SET_VOLUME_9dB  ;

/* Channel */
extern const uint8_t _EQUALIZER_CHANNEL_1   ;
extern const uint8_t _EQUALIZER_CHANNEL_2   ;
extern const uint8_t _EQUALIZER_CHANNEL_3   ;
extern const uint8_t _EQUALIZER_CHANNEL_4   ;
extern const uint8_t _EQUALIZER_CHANNEL_5   ;
extern const uint8_t _EQUALIZER_CHANNEL_6   ;
extern const uint8_t _EQUALIZER_ALL_CHANNEL ;

/* Mute / Unmute */
extern const uint8_t _EQUALIZER_ALL_CHANNEL_MUTE   ;
extern const uint8_t _EQUALIZER_ALL_CHANNEL_UNMUTE ;

/* Clear */
extern const uint8_t _EQUALIZER_CLEAR_ALL;

/* Device slave address */
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_00;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_01;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_10;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_11;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup EQUALIZER_INIT Driver Initialization */              /** @{ */

#ifdef   __EQUALIZER_DRV_SPI__
void eqalizer_spiDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P spiObj);
#endif
#ifdef   __EQUALIZER_DRV_I2C__
void eqalizer_i2cDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P i2cObj, uint8_t slave);
#endif
#ifdef   __EQUALIZER_DRV_UART__
void eqalizer_uartDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void eqalizer_gpioDriverInit(T_EQUALIZER_P gpioObj);
                                                                       /** @} */
/** @defgroup EQUALIZER_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Set volume for the channel
 *
 * @param[in] channel  Chunnel register (from _EQUALIZER_CHANNEL_1 to _EQUALIZER_CHANNEL_6)
 * @param[in] volume1  Volume (from _EQUALIZER_SET_VOLUME_1dB to _EQUALIZER_SET_VOLUME_9dB)
 * @param[in] volume2  Volume (from _EQUALIZER_SET_VOLUME_10dB to _EQUALIZER_SET_VOLUME_70dB)
 *
 * This function sets the volume for the selected channel, uses two variables.
 */
void equalizer_setVolumePart(uint8_t channel, uint8_t volume1, uint8_t volume2);

/**
 * @brief Clear register
 *
 *  The PT2258 function register does not have any default settings.
 *  After clearing the register, an initial value must send in order to each register.
 *  If a register does has not been set, it is possible that no sound will be output.
 *
 * The cleaning and settings for each registers are included in the function "defaultConfiguration()".
 */
void equalizer_clear();

/**
 * @brief Mute and Unmute
 *
 * @param[in] Mute   -  Mute register
 *
 * This function mute and unmute the sound
 */
void equalizer_mute(uint8_t mute);

/**
 * @brief Default configuration
 *
 * Calling this function clears all registers, sets each channel to 0dB and unmutes the sound.
 */
void equalizer_defaultConfiguration();

/**
 * @brief Set volume for the channel
 *
 * @param[in] channel  Chunnel register (from _EQUALIZER_CHANNEL_1 to _EQUALIZER_CHANNEL_6)
 * @param[in] volume   Volume (from 0 to -79) (int8_t value)
 *
 * This function sets the volume for the selected channel, uses one volume variables.
 */
void equalizer_setVolumeFull(uint8_t channel, int8_t volume);




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Equalizer_STM.c
    @example Click_Equalizer_TIVA.c
    @example Click_Equalizer_CEC.c
    @example Click_Equalizer_KINETIS.c
    @example Click_Equalizer_MSP.c
    @example Click_Equalizer_PIC.c
    @example Click_Equalizer_PIC32.c
    @example Click_Equalizer_DSPIC.c
    @example Click_Equalizer_AVR.c
    @example Click_Equalizer_FT90x.c
    @example Click_Equalizer_STM.mbas
    @example Click_Equalizer_TIVA.mbas
    @example Click_Equalizer_CEC.mbas
    @example Click_Equalizer_KINETIS.mbas
    @example Click_Equalizer_MSP.mbas
    @example Click_Equalizer_PIC.mbas
    @example Click_Equalizer_PIC32.mbas
    @example Click_Equalizer_DSPIC.mbas
    @example Click_Equalizer_AVR.mbas
    @example Click_Equalizer_FT90x.mbas
    @example Click_Equalizer_STM.mpas
    @example Click_Equalizer_TIVA.mpas
    @example Click_Equalizer_CEC.mpas
    @example Click_Equalizer_KINETIS.mpas
    @example Click_Equalizer_MSP.mpas
    @example Click_Equalizer_PIC.mpas
    @example Click_Equalizer_PIC32.mpas
    @example Click_Equalizer_DSPIC.mpas
    @example Click_Equalizer_AVR.mpas
    @example Click_Equalizer_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __eqalizer_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */