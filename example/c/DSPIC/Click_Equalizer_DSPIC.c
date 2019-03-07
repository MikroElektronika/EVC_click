/*
Example for Equalizer Click

    Date          : dec 2018.
    Author        : Katarina Perendic

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.1.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initialzes I2C module
- Application Initialization - Initialization driver init, default configuration and sets first volume.
- Application Task - Waits for valid user input and executes functions based on set of valid commands

- Commands :
  '+' - volume up
  '-' - volume down
  'x' - channel up
  'z' - channel down
  'm' - mute and unmute
  
Additional Functions :

- void _getCurrentChannel( )  - Return current channel
- void _play( )               - Start new settings of the channel
- void _mute( )               - mute and unmute
*/

#include "Click_Equalizer_types.h"
#include "Click_Equalizer_config.h"

static uint8_t _muteFlag = 0;
static uint8_t _playFlag = 0;
static int8_t _volume = 0;
static uint8_t _channel = 1;
static uint8_t _currentChannel;
static char demoText[ 20 ];

uint8_t _getCurrentChannel(uint8_t ch)
{
    if(ch == 1)
    {
        return _EQUALIZER_CHANNEL_1;
    }
    if( ch == 2 )
    {
        return _EQUALIZER_CHANNEL_2;
    }
    if( ch == 3 )
    {
        return _EQUALIZER_CHANNEL_3;
    }
    if( ch == 4 )
    {
        return _EQUALIZER_CHANNEL_4;
    }
    if( ch == 5 )
    {
        return _EQUALIZER_CHANNEL_5;
    }
    if( ch == 6 )
    {
        return _EQUALIZER_CHANNEL_6;
    }
    return _EQUALIZER_CHANNEL_1;
}

void _play()
{
    if((_playFlag == 1) && (_muteFlag != 1))
    {
        _currentChannel = _getCurrentChannel(_channel);
        equalizer_setVolumeFull(_currentChannel, _volume);

        mikrobus_logWrite(" Channel [  ", _LOG_TEXT);
        IntToStr(_channel, demoText);
        mikrobus_logWrite(demoText, _LOG_TEXT);
        mikrobus_logWrite(" ] -- Volume [ ", _LOG_TEXT);
        IntToStr(_volume, demoText);
        mikrobus_logWrite(demoText, _LOG_TEXT);
        mikrobus_logWrite(" ] ", _LOG_LINE);
        
        _playFlag = 0;
    }
}

void _mute()
{
    /* Mute and Unmute */
    if(_muteFlag == 0)
    {
        _muteFlag = 1;
        equalizer_mute(_EQUALIZER_ALL_CHANNEL_MUTE);
        mikrobus_logWrite(" All channels MUTE !!!", _LOG_LINE);
    }
    else
    {
        _muteFlag = 0;
        equalizer_mute(_EQUALIZER_ALL_CHANNEL_UNMUTE);
        mikrobus_logWrite(" All channels UNMUTE !!!", _LOG_LINE);
    }
}

void systemInit()
{
    Delay_ms( 300 );
    
    mikrobus_i2cInit( _MIKROBUS1, &_EQUALIZER_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    eqalizer_i2cDriverInit( (T_EQUALIZER_P)&_MIKROBUS1_GPIO, (T_EQUALIZER_P)&_MIKROBUS1_I2C, _EQUALIZER_DEVICE_SLAVE_ADDRESS_11 );
    equalizer_defaultConfiguration();
    mikrobus_logWrite(" --- START EQUALIZER --- ", _LOG_LINE);
    
    /* First set volume */
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_1, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    equalizer_setVolumePart(_EQUALIZER_CHANNEL_2, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
    Delay_ms( 1000 );
}

void applicationTask()
{
    uint8_t dataReady_;
    char receivedData_;
    
    dataReady_ = UART_Rdy_Ptr( );

    if (dataReady_ != 0)
    {
        receivedData_ = UART_Rd_Ptr( );

        switch (receivedData_)
        {
            case 'z' :
            {
                /* Change channel */
                _channel --;
                if(_channel < 1)
                {
                    _channel = 1;
                }
                _playFlag = 1;
                break;
            }
            case 'x' :
            {
                /* Change channel */
                _channel ++;
                if(_channel > 6)
                {
                    _channel = 6;
                }
                _playFlag = 1;
                break;
            }
            case '+' :
            {
                /* Set volume */
                _volume++;
                if(_volume > 0)
                {
                    _volume = 0;
                }
                _playFlag = 1;
                break;
            }
            case '-' :
            {
                /* Set volume */
                _volume--;
                if(_volume < -79)
                {
                    _volume = -79;
                }
                _playFlag = 1;
                break;
            }
            case 'm' :
            {
                _mute();
                break;
            }
        }
        _play();
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}