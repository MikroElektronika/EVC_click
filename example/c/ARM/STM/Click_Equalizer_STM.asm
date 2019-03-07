__getCurrentChannel:
;Click_Equalizer_STM.c,50 :: 		uint8_t _getCurrentChannel(uint8_t ch)
; ch start address is: 0 (R0)
; ch end address is: 0 (R0)
; ch start address is: 0 (R0)
;Click_Equalizer_STM.c,52 :: 		if(ch == 1)
CMP	R0, #1
IT	NE
BNE	L__getCurrentChannel0
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,54 :: 		return _EQUALIZER_CHANNEL_1;
MOVS	R0, __EQUALIZER_CHANNEL_1
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,55 :: 		}
L__getCurrentChannel0:
;Click_Equalizer_STM.c,56 :: 		else if( ch == 2 )
; ch start address is: 0 (R0)
CMP	R0, #2
IT	NE
BNE	L__getCurrentChannel2
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,58 :: 		return _EQUALIZER_CHANNEL_2;
MOVS	R0, __EQUALIZER_CHANNEL_2
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,59 :: 		}
L__getCurrentChannel2:
;Click_Equalizer_STM.c,60 :: 		else if( ch == 3 )
; ch start address is: 0 (R0)
CMP	R0, #3
IT	NE
BNE	L__getCurrentChannel4
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,62 :: 		return _EQUALIZER_CHANNEL_3;
MOVS	R0, __EQUALIZER_CHANNEL_3
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,63 :: 		}
L__getCurrentChannel4:
;Click_Equalizer_STM.c,64 :: 		else if( ch == 4 )
; ch start address is: 0 (R0)
CMP	R0, #4
IT	NE
BNE	L__getCurrentChannel6
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,66 :: 		return _EQUALIZER_CHANNEL_4;
MOVS	R0, __EQUALIZER_CHANNEL_4
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,67 :: 		}
L__getCurrentChannel6:
;Click_Equalizer_STM.c,68 :: 		else if( ch == 5 )
; ch start address is: 0 (R0)
CMP	R0, #5
IT	NE
BNE	L__getCurrentChannel8
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,70 :: 		return _EQUALIZER_CHANNEL_5;
MOVS	R0, __EQUALIZER_CHANNEL_5
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,71 :: 		}
L__getCurrentChannel8:
;Click_Equalizer_STM.c,72 :: 		else if( ch == 6 )
; ch start address is: 0 (R0)
CMP	R0, #6
IT	NE
BNE	L__getCurrentChannel10
; ch end address is: 0 (R0)
;Click_Equalizer_STM.c,74 :: 		return _EQUALIZER_CHANNEL_6;
MOVS	R0, __EQUALIZER_CHANNEL_6
IT	AL
BAL	L_end__getCurrentChannel
;Click_Equalizer_STM.c,75 :: 		}
L__getCurrentChannel10:
;Click_Equalizer_STM.c,76 :: 		return _EQUALIZER_CHANNEL_1;
MOVS	R0, __EQUALIZER_CHANNEL_1
;Click_Equalizer_STM.c,77 :: 		}
L_end__getCurrentChannel:
BX	LR
; end of __getCurrentChannel
__play:
;Click_Equalizer_STM.c,79 :: 		void _play()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Equalizer_STM.c,81 :: 		if((_playFlag == 1) && (_muteFlag != 1))
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	NE
BNE	L___play38
MOVW	R0, #lo_addr(__muteFlag+0)
MOVT	R0, #hi_addr(__muteFlag+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L___play37
L___play36:
;Click_Equalizer_STM.c,83 :: 		_currentChannel = _getCurrentChannel(_channel);
MOVW	R0, #lo_addr(__channel+0)
MOVT	R0, #hi_addr(__channel+0)
LDRB	R0, [R0, #0]
BL	__getCurrentChannel+0
MOVW	R1, #lo_addr(__currentChannel+0)
MOVT	R1, #hi_addr(__currentChannel+0)
STRB	R0, [R1, #0]
;Click_Equalizer_STM.c,84 :: 		equalizer_setVolumeFull(_currentChannel, _volume);
MOVW	R1, #lo_addr(__volume+0)
MOVT	R1, #hi_addr(__volume+0)
LDRSB	R1, [R1, #0]
BL	_equalizer_setVolumeFull+0
;Click_Equalizer_STM.c,86 :: 		mikrobus_logWrite(" Channel [  ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr1_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Equalizer_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,87 :: 		IntToStr(_channel, demoText);
MOVW	R0, #lo_addr(__channel+0)
MOVT	R0, #hi_addr(__channel+0)
LDRB	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Equalizer_STM.c,88 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,89 :: 		mikrobus_logWrite(" ] -- Volume [ ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Equalizer_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,90 :: 		IntToStr(_volume, demoText);
MOVW	R0, #lo_addr(__volume+0)
MOVT	R0, #hi_addr(__volume+0)
LDRSB	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_IntToStr+0
;Click_Equalizer_STM.c,91 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,92 :: 		mikrobus_logWrite(" ] ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Equalizer_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,94 :: 		_playFlag = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,81 :: 		if((_playFlag == 1) && (_muteFlag != 1))
L___play38:
L___play37:
;Click_Equalizer_STM.c,96 :: 		}
L_end__play:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of __play
__mute:
;Click_Equalizer_STM.c,98 :: 		void _mute()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Equalizer_STM.c,101 :: 		if(_muteFlag == 0)
MOVW	R0, #lo_addr(__muteFlag+0)
MOVT	R0, #hi_addr(__muteFlag+0)
LDRB	R0, [R0, #0]
CMP	R0, #0
IT	NE
BNE	L__mute14
;Click_Equalizer_STM.c,103 :: 		_muteFlag = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__muteFlag+0)
MOVT	R0, #hi_addr(__muteFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,104 :: 		equalizer_mute(_EQUALIZER_ALL_CHANNEL_MUTE);
MOVS	R0, __EQUALIZER_ALL_CHANNEL_MUTE
BL	_equalizer_mute+0
;Click_Equalizer_STM.c,105 :: 		mikrobus_logWrite(" All channels MUTE !!!", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr4_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Equalizer_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,106 :: 		}
IT	AL
BAL	L__mute15
L__mute14:
;Click_Equalizer_STM.c,109 :: 		_muteFlag = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(__muteFlag+0)
MOVT	R0, #hi_addr(__muteFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,110 :: 		equalizer_mute(_EQUALIZER_ALL_CHANNEL_UNMUTE);
MOVS	R0, __EQUALIZER_ALL_CHANNEL_UNMUTE
BL	_equalizer_mute+0
;Click_Equalizer_STM.c,111 :: 		mikrobus_logWrite(" All channels UNMUTE !!!", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Equalizer_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,112 :: 		}
L__mute15:
;Click_Equalizer_STM.c,113 :: 		}
L_end__mute:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of __mute
_systemInit:
;Click_Equalizer_STM.c,115 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Equalizer_STM.c,117 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_systemInit16:
SUBS	R7, R7, #1
BNE	L_systemInit16
NOP
NOP
NOP
;Click_Equalizer_STM.c,119 :: 		mikrobus_i2cInit( _MIKROBUS1, &_EQUALIZER_I2C_CFG[0] );
MOVW	R0, #lo_addr(__EQUALIZER_I2C_CFG+0)
MOVT	R0, #hi_addr(__EQUALIZER_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_Equalizer_STM.c,120 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Equalizer_STM.c,121 :: 		mikrobus_logWrite(" --- System Init --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr6_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Equalizer_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,122 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit18:
SUBS	R7, R7, #1
BNE	L_systemInit18
NOP
NOP
NOP
;Click_Equalizer_STM.c,123 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Equalizer_STM.c,125 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Equalizer_STM.c,127 :: 		eqalizer_i2cDriverInit( (T_EQUALIZER_P)&_MIKROBUS1_GPIO, (T_EQUALIZER_P)&_MIKROBUS1_I2C, _EQUALIZER_DEVICE_SLAVE_ADDRESS_11 );
MOVS	R2, __EQUALIZER_DEVICE_SLAVE_ADDRESS_11
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_eqalizer_i2cDriverInit+0
;Click_Equalizer_STM.c,128 :: 		equalizer_defaultConfiguration();
BL	_equalizer_defaultConfiguration+0
;Click_Equalizer_STM.c,129 :: 		mikrobus_logWrite(" --- START EQUALIZER --- ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr7_Click_Equalizer_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_Equalizer_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Equalizer_STM.c,132 :: 		equalizer_setVolumePart(_EQUALIZER_CHANNEL_1, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
MOVS	R2, __EQUALIZER_SET_VOLUME_0dB
MOVS	R1, __EQUALIZER_SET_VOLUME_0dB
MOVS	R0, __EQUALIZER_CHANNEL_1
BL	_equalizer_setVolumePart+0
;Click_Equalizer_STM.c,133 :: 		equalizer_setVolumePart(_EQUALIZER_CHANNEL_2, _EQUALIZER_SET_VOLUME_0dB, _EQUALIZER_SET_VOLUME_0dB);
MOVS	R2, __EQUALIZER_SET_VOLUME_0dB
MOVS	R1, __EQUALIZER_SET_VOLUME_0dB
MOVS	R0, __EQUALIZER_CHANNEL_2
BL	_equalizer_setVolumePart+0
;Click_Equalizer_STM.c,134 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationInit20:
SUBS	R7, R7, #1
BNE	L_applicationInit20
NOP
NOP
NOP
;Click_Equalizer_STM.c,135 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Equalizer_STM.c,137 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Equalizer_STM.c,142 :: 		dataReady_ = UART_Rdy_Ptr( );
MOVW	R4, #lo_addr(_UART_Rdy_Ptr+0)
MOVT	R4, #hi_addr(_UART_Rdy_Ptr+0)
LDR	R4, [R4, #0]
BLX	R4
;Click_Equalizer_STM.c,144 :: 		if (dataReady_ != 0)
UXTB	R4, R0
CMP	R4, #0
IT	EQ
BEQ	L_applicationTask22
;Click_Equalizer_STM.c,146 :: 		receivedData_ = UART_Rd_Ptr( );
MOVW	R4, #lo_addr(_UART_Rd_Ptr+0)
MOVT	R4, #hi_addr(_UART_Rd_Ptr+0)
LDR	R4, [R4, #0]
BLX	R4
; receivedData_ start address is: 0 (R0)
UXTB	R0, R0
;Click_Equalizer_STM.c,148 :: 		switch (receivedData_)
IT	AL
BAL	L_applicationTask23
; receivedData_ end address is: 0 (R0)
;Click_Equalizer_STM.c,150 :: 		case 'z' :
L_applicationTask25:
;Click_Equalizer_STM.c,153 :: 		_channel --;
MOVW	R1, #lo_addr(__channel+0)
MOVT	R1, #hi_addr(__channel+0)
LDRB	R0, [R1, #0]
SUBS	R0, R0, #1
UXTB	R0, R0
STRB	R0, [R1, #0]
;Click_Equalizer_STM.c,154 :: 		if(_channel < 1)
CMP	R0, #1
IT	CS
BCS	L_applicationTask26
;Click_Equalizer_STM.c,156 :: 		_channel = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__channel+0)
MOVT	R0, #hi_addr(__channel+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,157 :: 		}
L_applicationTask26:
;Click_Equalizer_STM.c,158 :: 		_playFlag = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,159 :: 		break;
IT	AL
BAL	L_applicationTask24
;Click_Equalizer_STM.c,161 :: 		case 'x' :
L_applicationTask27:
;Click_Equalizer_STM.c,164 :: 		_channel ++;
MOVW	R1, #lo_addr(__channel+0)
MOVT	R1, #hi_addr(__channel+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
UXTB	R0, R0
STRB	R0, [R1, #0]
;Click_Equalizer_STM.c,165 :: 		if(_channel > 6)
CMP	R0, #6
IT	LS
BLS	L_applicationTask28
;Click_Equalizer_STM.c,167 :: 		_channel = 6;
MOVS	R1, #6
MOVW	R0, #lo_addr(__channel+0)
MOVT	R0, #hi_addr(__channel+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,168 :: 		}
L_applicationTask28:
;Click_Equalizer_STM.c,169 :: 		_playFlag = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,170 :: 		break;
IT	AL
BAL	L_applicationTask24
;Click_Equalizer_STM.c,172 :: 		case '+' :
L_applicationTask29:
;Click_Equalizer_STM.c,175 :: 		_volume++;
MOVW	R1, #lo_addr(__volume+0)
MOVT	R1, #hi_addr(__volume+0)
LDRSB	R0, [R1, #0]
ADDS	R0, R0, #1
SXTB	R0, R0
STRB	R0, [R1, #0]
;Click_Equalizer_STM.c,176 :: 		if(_volume > 0)
CMP	R0, #0
IT	LE
BLE	L_applicationTask30
;Click_Equalizer_STM.c,178 :: 		_volume = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(__volume+0)
MOVT	R0, #hi_addr(__volume+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,179 :: 		}
L_applicationTask30:
;Click_Equalizer_STM.c,180 :: 		_playFlag = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,181 :: 		break;
IT	AL
BAL	L_applicationTask24
;Click_Equalizer_STM.c,183 :: 		case '-' :
L_applicationTask31:
;Click_Equalizer_STM.c,186 :: 		_volume--;
MOVW	R2, #lo_addr(__volume+0)
MOVT	R2, #hi_addr(__volume+0)
LDRSB	R0, [R2, #0]
SUBS	R1, R0, #1
SXTB	R1, R1
STRB	R1, [R2, #0]
;Click_Equalizer_STM.c,187 :: 		if(_volume < -79)
MVN	R0, #78
CMP	R1, R0
IT	GE
BGE	L_applicationTask32
;Click_Equalizer_STM.c,189 :: 		_volume = -79;
MOVS	R1, #-79
SXTB	R1, R1
MOVW	R0, #lo_addr(__volume+0)
MOVT	R0, #hi_addr(__volume+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,190 :: 		}
L_applicationTask32:
;Click_Equalizer_STM.c,191 :: 		_playFlag = 1;
MOVS	R1, #1
MOVW	R0, #lo_addr(__playFlag+0)
MOVT	R0, #hi_addr(__playFlag+0)
STRB	R1, [R0, #0]
;Click_Equalizer_STM.c,192 :: 		break;
IT	AL
BAL	L_applicationTask24
;Click_Equalizer_STM.c,194 :: 		case 'm' :
L_applicationTask33:
;Click_Equalizer_STM.c,196 :: 		_mute();
BL	__mute+0
;Click_Equalizer_STM.c,197 :: 		break;
IT	AL
BAL	L_applicationTask24
;Click_Equalizer_STM.c,199 :: 		}
L_applicationTask23:
; receivedData_ start address is: 0 (R0)
CMP	R0, #122
IT	EQ
BEQ	L_applicationTask25
CMP	R0, #120
IT	EQ
BEQ	L_applicationTask27
CMP	R0, #43
IT	EQ
BEQ	L_applicationTask29
CMP	R0, #45
IT	EQ
BEQ	L_applicationTask31
CMP	R0, #109
IT	EQ
BEQ	L_applicationTask33
; receivedData_ end address is: 0 (R0)
L_applicationTask24:
;Click_Equalizer_STM.c,200 :: 		_play();
BL	__play+0
;Click_Equalizer_STM.c,201 :: 		}
L_applicationTask22:
;Click_Equalizer_STM.c,202 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Equalizer_STM.c,204 :: 		void main()
;Click_Equalizer_STM.c,206 :: 		systemInit();
BL	_systemInit+0
;Click_Equalizer_STM.c,207 :: 		applicationInit();
BL	_applicationInit+0
;Click_Equalizer_STM.c,209 :: 		while (1)
L_main34:
;Click_Equalizer_STM.c,211 :: 		applicationTask();
BL	_applicationTask+0
;Click_Equalizer_STM.c,212 :: 		}
IT	AL
BAL	L_main34
;Click_Equalizer_STM.c,213 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
