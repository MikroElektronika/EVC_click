/*
    __eqalizer_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__eqalizer_driver.h"
#include "__eqalizer_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Volume */
const uint8_t _EQUALIZER_SET_VOLUME_1dB  = 0x11;
const uint8_t _EQUALIZER_SET_VOLUME_10dB = 0x01;
const uint8_t _EQUALIZER_SET_VOLUME_20dB = 0x02;
const uint8_t _EQUALIZER_SET_VOLUME_2dB  = 0x12;
const uint8_t _EQUALIZER_SET_VOLUME_30dB = 0x03;
const uint8_t _EQUALIZER_SET_VOLUME_3dB  = 0x13;
const uint8_t _EQUALIZER_SET_VOLUME_40dB = 0x04;
const uint8_t _EQUALIZER_SET_VOLUME_4dB  = 0x14;
const uint8_t _EQUALIZER_SET_VOLUME_50dB = 0x05;
const uint8_t _EQUALIZER_SET_VOLUME_5dB  = 0x15;
const uint8_t _EQUALIZER_SET_VOLUME_60dB = 0x06;
const uint8_t _EQUALIZER_SET_VOLUME_6dB  = 0x16;
const uint8_t _EQUALIZER_SET_VOLUME_70dB = 0x07;
const uint8_t _EQUALIZER_SET_VOLUME_7dB  = 0x17;
const uint8_t _EQUALIZER_SET_VOLUME_0dB  = 0x00;
const uint8_t _EQUALIZER_SET_VOLUME_8dB  = 0x18;
const uint8_t _EQUALIZER_SET_VOLUME_9dB  = 0x19;

/* Channel */
const uint8_t _EQUALIZER_CHANNEL_1  = 0x80;
const uint8_t _EQUALIZER_CHANNEL_2  = 0x40;
const uint8_t _EQUALIZER_CHANNEL_3  = 0x00;
const uint8_t _EQUALIZER_CHANNEL_4  = 0x20;
const uint8_t _EQUALIZER_CHANNEL_5  = 0x60;
const uint8_t _EQUALIZER_CHANNEL_6  = 0xA0;
const uint8_t _EQUALIZER_ALL_CHANNEL = 0xC0;

/* Mute / Unmute */
const uint8_t _EQUALIZER_ALL_CHANNEL_MUTE   = 0xF9;
const uint8_t _EQUALIZER_ALL_CHANNEL_UNMUTE = 0xF8;

/* Clear */
const uint8_t _EQUALIZER_CLEAR_ALL = 0xC0;

/* Device slave address */
const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_00 = 0x40;
const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_01 = 0x42;
const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_10 = 0x44;
const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_11 = 0x46;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __EQUALIZER_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __EQUALIZER_DRV_SPI__

void eqalizer_spiDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __EQUALIZER_DRV_I2C__

void eqalizer_i2cDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __EQUALIZER_DRV_UART__

void eqalizer_uartDriverInit(T_EQUALIZER_P gpioObj, T_EQUALIZER_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void equalizer_setVolumePart(uint8_t channel, uint8_t volume1, uint8_t volume2)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = channel | volume1;
    writeReg[ 1 ] = channel | volume2;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

void equalizer_setVolumeFull(uint8_t channel, int8_t volume)
{
    uint8_t writeReg[ 2 ];
    uint8_t Volume1;
    uint8_t Volume2;

    Volume2 = (-volume) % 10;
    Volume1 = (-volume) / 10;

    writeReg[ 0 ] = channel | (0x10 | volume2);
    writeReg[ 1 ] = channel | volume1;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

void equalizer_clear()
{
    uint8_t writeReg[ 1 ];

    writeReg[ 0 ] = _EQUALIZER_CLEAR_ALL;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_STOP);
}

void equalizer_mute(uint8_t mute)
{
    uint8_t writeReg[ 1 ];

    writeReg[ 0 ] = mute;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_STOP);
}

void equalizer_defaultConfiguration()
{
    Delay_100ms();
	Delay_100ms();
	Delay_100ms();
	
    equalizer_clear();
    
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_1, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_2, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_3, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_4, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_5, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_6, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_ALL_CHANNEL, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    
    equalizer_mute(_EQUALIZER_ALL_CHANNEL_UNMUTE);
}

/* -------------------------------------------------------------------------- */
/*
  __eqalizer_driver.c

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