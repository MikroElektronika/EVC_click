#line 1 "D:/Clicks_git/E/Equalizer_click/SW/example/c/ARM/STM/Click_Equalizer_STM.c"
#line 1 "d:/clicks_git/e/equalizer_click/sw/example/c/arm/stm/click_equalizer_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/e/equalizer_click/sw/example/c/arm/stm/click_equalizer_config.h"
#line 1 "d:/clicks_git/e/equalizer_click/sw/example/c/arm/stm/click_equalizer_types.h"
#line 19 "d:/clicks_git/e/equalizer_click/sw/example/c/arm/stm/click_equalizer_config.h"
const uint32_t _EQUALIZER_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
extern const uint8_t _EQUALIZER_SET_VOLUME_1dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_10dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_20dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_2dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_30dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_3dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_40dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_4dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_50dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_5dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_60dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_6dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_70dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_7dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_0dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_8dB ;
extern const uint8_t _EQUALIZER_SET_VOLUME_9dB ;


extern const uint8_t _EQUALIZER_CHANNEL_1 ;
extern const uint8_t _EQUALIZER_CHANNEL_2 ;
extern const uint8_t _EQUALIZER_CHANNEL_3 ;
extern const uint8_t _EQUALIZER_CHANNEL_4 ;
extern const uint8_t _EQUALIZER_CHANNEL_5 ;
extern const uint8_t _EQUALIZER_CHANNEL_6 ;
extern const uint8_t _EQUALIZER_ALL_CHANNEL ;


extern const uint8_t _EQUALIZER_ALL_CHANNEL_MUTE ;
extern const uint8_t _EQUALIZER_ALL_CHANNEL_UNMUTE ;


extern const uint8_t _EQUALIZER_CLEAR_ALL;


extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_00;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_01;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_10;
extern const uint8_t _EQUALIZER_DEVICE_SLAVE_ADDRESS_11;
#line 110 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void eqalizer_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 117 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void eqalizer_gpioDriverInit( const uint8_t*  gpioObj);
#line 130 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void equalizer_setVolumePart(uint8_t channel, uint8_t volume1, uint8_t volume2);
#line 141 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void equalizer_clear();
#line 150 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void equalizer_mute(uint8_t mute);
#line 157 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void equalizer_defaultConfiguration();
#line 167 "d:/clicks_git/e/equalizer_click/sw/library/__eqalizer_driver.h"
void equalizer_setVolumeFull(uint8_t channel, int8_t volume);
#line 42 "D:/Clicks_git/E/Equalizer_click/SW/example/c/ARM/STM/Click_Equalizer_STM.c"
uint8_t _muteFlag = 0;
uint8_t _playFlag = 0;
int8_t _volume = 0;
uint8_t _channel = 1;
uint8_t _currentChannel;

char demoText[ 20 ];

uint8_t _getCurrentChannel(uint8_t ch)
{
 if(ch == 1)
 {
 return _EQUALIZER_CHANNEL_1;
 }
 else if( ch == 2 )
 {
 return _EQUALIZER_CHANNEL_2;
 }
 else if( ch == 3 )
 {
 return _EQUALIZER_CHANNEL_3;
 }
 else if( ch == 4 )
 {
 return _EQUALIZER_CHANNEL_4;
 }
 else if( ch == 5 )
 {
 return _EQUALIZER_CHANNEL_5;
 }
 else if( ch == 6 )
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
 eqalizer_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _EQUALIZER_DEVICE_SLAVE_ADDRESS_11 );
 equalizer_defaultConfiguration();
 mikrobus_logWrite(" --- START EQUALIZER --- ", _LOG_LINE);


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
