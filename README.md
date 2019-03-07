![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Equalizer Click

- **CIC Prefix**  : EQUALIZER
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : dec 2018.

---

### Software Support

We provide a library for the Equalizer Click on our [LibStock](https://libstock.mikroe.com/projects/view/2691/equalizer-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library includes function sets the volume for the selected channel, uses two variables or one volume variable.
The user has a function for mute/unmute sounds, default settings and function for clears all registers.

Key functions :

- ``` void equalizer_setVolumeFull(uint8_t channel, int8_t volume) ``` - Set volume for the channel 
- ``` void equalizer_defaultConfiguration() ``` - Default configuration
- ``` void equalizer_mute(uint8_t mute) ``` - Mute and Unmute

**Examples Description**

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


```.c

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
```

Additional Functions :

- void _getCurrentChannel( )  - Return current channel
- void _play( )               - Start new settings of the channel
- void _mute( )               - mute and unmute

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2691/equalizer-click) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
