
; PICBASIC PRO(TM) Compiler 3.0.7.4, (c) 1998, 2013 microEngineering Labs, Inc. All Rights Reserved. 
MPASMX_USED			EQU	1

#define	PBP_PATH	C:\PROGRAM FILES (X86)\PBP3\




        NOLIST
    ifdef PM_USED
        LIST
        "Error: PM does not support this device.  Use MPASM."
        NOLIST
    else
        LIST
        LIST p = 18F46K80, r = dec, w = -311, f = inhx32
        INCLUDE "P18F46K80.INC"	; MPASM  Header
        NOLIST
    endif
        LIST
GO_DONE        EQU  H'0001'     ;named GO_NOT_DONE in the MPASM header file
EEPROM_START   EQU	0F00000h
BLOCK_SIZE     EQU	64


    #define HPWM_OVERRIDE 1
PBP_HARDWAREDEF  macro
    #include PBP_PATH\HPWM_K80_1.HWLIB
  endm


    CONFIG  RETEN = ON            ; Ultra low-power regulator is Enabled (Controlled by SRETEN bit)
    CONFIG  INTOSCSEL = HIGH      ; LF-INTOSC in High-power mode during Sleep
    CONFIG  SOSCSEL = HIGH        ; High Power SOSC circuit selected
    CONFIG  XINST = OFF           ; Disabled
    CONFIG  FOSC = HS1            ; HS oscillator (Medium power, 4 MHz - 16 MHz)
    CONFIG  PLLCFG = ON           ; Enabled
    CONFIG  FCMEN = OFF           ; Disabled
    CONFIG  IESO = OFF            ; Disabled
    CONFIG  PWRTEN = OFF          ; Disabled
    CONFIG  BOREN = SBORDIS       ; Enabled in hardware, SBOREN disabled
    CONFIG  BORV = 3              ; 1.8V
    CONFIG  BORPWR = ZPBORMV      ; ZPBORMV instead of BORMV is selected
    CONFIG  WDTEN = SWDTDIS       ; WDT enabled in hardware; SWDTEN bit disabled
    CONFIG  WDTPS = 512           ; 1:512
    CONFIG  CANMX = PORTB         ; ECAN TX and RX pins are located on RB2 and RB3, respectively
    CONFIG  MSSPMSK = MSK7        ; 7 Bit address masking mode
    CONFIG  MCLRE = ON            ; MCLR Enabled, RE3 Disabled
    CONFIG  STVREN = ON           ; Enabled
    CONFIG  BBSIZ = BB2K          ; 2K word Boot Block size
    CONFIG  CP0 = OFF             ; Disabled
    CONFIG  CP1 = OFF             ; Disabled
    CONFIG  CP2 = OFF             ; Disabled
    CONFIG  CP3 = OFF             ; Disabled
    CONFIG  CPB = OFF             ; Disabled
    CONFIG  CPD = OFF             ; Disabled
    CONFIG  WRT0 = OFF            ; Disabled
    CONFIG  WRT1 = OFF            ; Disabled
    CONFIG  WRT2 = OFF            ; Disabled
    CONFIG  WRT3 = OFF            ; Disabled
    CONFIG  WRTC = OFF            ; Disabled
    CONFIG  WRTB = OFF            ; Disabled
    CONFIG  WRTD = OFF            ; Disabled
    CONFIG  EBTR0 = OFF           ; Disabled
    CONFIG  EBTR1 = OFF           ; Disabled
    CONFIG  EBTR2 = OFF           ; Disabled
    CONFIG  EBTR3 = OFF           ; Disabled
    CONFIG  EBTRB = OFF           ; Disabled



; Define statements.
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00610	DEFINE  ADC_CHANNELS 1
#define		ADC_CHANNELS		 1

RAM_START       		EQU	00000h
RAM_END         		EQU	00E40h
RAM_BANKS       		EQU	0000Fh
BANK0_START     		EQU	00060h
BANK0_END       		EQU	000FFh
BANK1_START     		EQU	00100h
BANK1_END       		EQU	001FFh
BANK2_START     		EQU	00200h
BANK2_END       		EQU	002FFh
BANK3_START     		EQU	00300h
BANK3_END       		EQU	003FFh
BANK4_START     		EQU	00400h
BANK4_END       		EQU	004FFh
BANK5_START     		EQU	00500h
BANK5_END       		EQU	005FFh
BANK6_START     		EQU	00600h
BANK6_END       		EQU	006FFh
BANK7_START     		EQU	00700h
BANK7_END       		EQU	007FFh
BANK8_START     		EQU	00800h
BANK8_END       		EQU	008FFh
BANK9_START     		EQU	00900h
BANK9_END       		EQU	009FFh
BANK10_START    		EQU	00A00h
BANK10_END      		EQU	00AFFh
BANK11_START    		EQU	00B00h
BANK11_END      		EQU	00BFFh
BANK12_START    		EQU	00C00h
BANK12_END      		EQU	00CFFh
BANK13_START    		EQU	00D00h
BANK13_END      		EQU	00DFFh
BANK14_START    		EQU	00E00h
BANK14_END      		EQU	00E40h
BANKA_START     		EQU	00000h
BANKA_END       		EQU	0005Fh

; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00028	A00000	FLAGS   VAR     BYTE BANKA SYSTEM       ' Static flags
FLAGS           		EQU	RAM_START + 000h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00027	A00001	GOP     VAR     BYTE BANKA SYSTEM       ' Gen Op Parameter
GOP             		EQU	RAM_START + 001h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00016	A00002	R4      VAR     WORD BANKA SYSTEM       ' System Register
R4              		EQU	RAM_START + 002h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00017	A00004	R5      VAR     WORD BANKA SYSTEM       ' System Register
R5              		EQU	RAM_START + 004h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00018	A00006	R6      VAR     WORD BANKA SYSTEM       ' System Register
R6              		EQU	RAM_START + 006h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00019	A00008	R7      VAR     WORD BANKA SYSTEM       ' System Register
R7              		EQU	RAM_START + 008h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00020	A0000A	R8      VAR     WORD BANKA SYSTEM       ' System Register
R8              		EQU	RAM_START + 00Ah
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00023	A0000C	RM1     VAR     BYTE BANKA SYSTEM       ' Pin 1 Mask
RM1             		EQU	RAM_START + 00Ch
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00026	A0000D	RM2     VAR     BYTE BANKA SYSTEM       ' Pin 2 Mask
RM2             		EQU	RAM_START + 00Dh
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00021	A0000E	RR1     VAR     BYTE BANKA SYSTEM       ' Pin 1 Register
RR1             		EQU	RAM_START + 00Eh
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00024	A0000F	RR2     VAR     BYTE BANKA SYSTEM       ' Pin 2 Register
RR2             		EQU	RAM_START + 00Fh
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00022	A00010	RS1     VAR     BYTE BANKA SYSTEM       ' Pin 1 Bank
RS1             		EQU	RAM_START + 010h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00025	A00011	RS2     VAR     BYTE BANKA SYSTEM       ' Pin 2 Bank
RS2             		EQU	RAM_START + 011h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00012	A00012	R0      VAR     LONG BANKA SYSTEM       ' System Register
R0              		EQU	RAM_START + 012h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00013	A00016	R1      VAR     LONG BANKA SYSTEM       ' System Register
R1              		EQU	RAM_START + 016h
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00014	A0001A	R2      VAR     LONG BANKA SYSTEM       ' System Register
R2              		EQU	RAM_START + 01Ah
; C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.RAM	00015	A0001E	R3      VAR     LONG BANKA SYSTEM       ' System Register
R3              		EQU	RAM_START + 01Eh
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00611	PORTL   VAR     PORTB
_PORTL           		EQU	 PORTB
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00612	PORTH   VAR     PORTC
_PORTH           		EQU	 PORTC
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00613	TRISL   VAR     TRISB
_TRISL           		EQU	 TRISB
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00614	TRISH   VAR     TRISC
_TRISH           		EQU	 TRISC
#define _GIE             	_INTCON??7
#define _PEIE            	_INTCON??6
#define _TMR0IE          	_INTCON??5
#define _INT0IE          	_INTCON??4
#define _TMR0IF          	_INTCON??2
#define _INT0IF          	_INTCON??1
#define _IPEN            	_RCON??7
#define _RBPU_           	_INTCON2??7
#define _INT1IE          	_INTCON3??3
#define _INT2IE          	_INTCON3??4
#define _INT3IE          	_INTCON3??5
#define _INTEDG0         	_INTCON2??6
#define _INTEDG1         	_INTCON2??5
#define _INTEDG2         	_INTCON2??4
#define _INTEDG3         	_INTCON2??3
#define _INT1IF          	_INTCON3??0
#define _INT2IF          	_INTCON3??1
#define _INT3IF          	_INTCON3??2
#define _RC1IE           	_PIE1??5
#define _RC1IF           	_PIR1??5
#define _RC2IE           	_PIE3??5
#define _RC2IF           	_PIR3??5
#define _ADCgo           	_ADCON0??1
#define _OERR1           	_RCSTA1??1
#define _OERR2           	_RCSTA2??1
#define _FERR1           	_RCSTA1??2
#define _FERR2           	_RCSTA2??2
#define _CREN1           	_RCSTA1??4
#define _CREN2           	_RCSTA2??4
#define _TMR0ON          	_T0CON??7
#define _T08BIT          	_T0CON??6
#define _T0CS            	_T0CON??5
#define _T0SE            	_T0CON??4
#define _PSA             	_T0CON??3
#define _TOPS2           	_T0CON??2
#define _TOPS1           	_T0CON??1
#define _TOPS0           	_T0CON??0
#define _TMR0MD          	_PMD1??0
#define _TMR1CS1         	_T1CON??7
#define _TMR1CS0         	_T1CON??6
#define _T1CKPS1         	_T1CON??5
#define _T1CKPS0         	_T1CON??4
#define _T1SOSCEN        	_T1CON??3
#define _T1SYNC_         	_T1CON??2
#define _T1RD16          	_T1CON??1
#define _TMR1ON          	_T1CON??0
#define _TMR1GE          	_T1GCON??7
#define _T1GPOL          	_T1GCON??6
#define _T1GTM           	_T1GCON??5
#define _T1GSPM          	_T1GCON??4
#define _T1GGO           	_T1GCON??3
#define _T1GVAL          	_T1GCON??2
#define _T1GSS1          	_T1GCON??1
#define _T1GSS0          	_T1GCON??0
#define _TMR3CS1         	_T3CON??7
#define _TMR3CS0         	_T3CON??6
#define _T3CKPS1         	_T3CON??5
#define _T3CKPS0         	_T3CON??4
#define _T3SOSCEN        	_T3CON??3
#define _T3SYNC_         	_T3CON??2
#define _T3RD16          	_T3CON??1
#define _TMR3ON          	_T3CON??0
#define _TMR3GE          	_T3GCON??7
#define _T3GPOL          	_T3GCON??6
#define _T3GTM           	_T3GCON??5
#define _T3GSPM          	_T3GCON??4
#define _T3GGO           	_T3GCON??3
#define _T3GVAL          	_T3GCON??2
#define _T3GSS1          	_T3GCON??1
#define _T3GSS0          	_T3GCON??0
#define _INTCON??7       	 INTCON, 007h
#define _INTCON??6       	 INTCON, 006h
#define _INTCON??5       	 INTCON, 005h
#define _INTCON??4       	 INTCON, 004h
#define _INTCON??2       	 INTCON, 002h
#define _INTCON??1       	 INTCON, 001h
#define _RCON??7         	 RCON, 007h
#define _INTCON2??7      	 INTCON2, 007h
#define _INTCON3??3      	 INTCON3, 003h
#define _INTCON3??4      	 INTCON3, 004h
#define _INTCON3??5      	 INTCON3, 005h
#define _INTCON2??6      	 INTCON2, 006h
#define _INTCON2??5      	 INTCON2, 005h
#define _INTCON2??4      	 INTCON2, 004h
#define _INTCON2??3      	 INTCON2, 003h
#define _INTCON3??0      	 INTCON3, 000h
#define _INTCON3??1      	 INTCON3, 001h
#define _INTCON3??2      	 INTCON3, 002h
#define _PIE1??5         	 PIE1, 005h
#define _PIR1??5         	 PIR1, 005h
#define _PIE3??5         	 PIE3, 005h
#define _PIR3??5         	 PIR3, 005h
#define _ADCON0??1       	 ADCON0, 001h
#define _RCSTA1??1       	 RCSTA1, 001h
#define _RCSTA2??1       	 RCSTA2, 001h
#define _RCSTA1??2       	 RCSTA1, 002h
#define _RCSTA2??2       	 RCSTA2, 002h
#define _RCSTA1??4       	 RCSTA1, 004h
#define _RCSTA2??4       	 RCSTA2, 004h
#define _T0CON??7        	 T0CON, 007h
#define _T0CON??6        	 T0CON, 006h
#define _T0CON??5        	 T0CON, 005h
#define _T0CON??4        	 T0CON, 004h
#define _T0CON??3        	 T0CON, 003h
#define _T0CON??2        	 T0CON, 002h
#define _T0CON??1        	 T0CON, 001h
#define _T0CON??0        	 T0CON, 000h
#define _PMD1??0         	 PMD1, 000h
#define _T1CON??7        	 T1CON, 007h
#define _T1CON??6        	 T1CON, 006h
#define _T1CON??5        	 T1CON, 005h
#define _T1CON??4        	 T1CON, 004h
#define _T1CON??3        	 T1CON, 003h
#define _T1CON??2        	 T1CON, 002h
#define _T1CON??1        	 T1CON, 001h
#define _T1CON??0        	 T1CON, 000h
#define _T1GCON??7       	 T1GCON, 007h
#define _T1GCON??6       	 T1GCON, 006h
#define _T1GCON??5       	 T1GCON, 005h
#define _T1GCON??4       	 T1GCON, 004h
#define _T1GCON??3       	 T1GCON, 003h
#define _T1GCON??2       	 T1GCON, 002h
#define _T1GCON??1       	 T1GCON, 001h
#define _T1GCON??0       	 T1GCON, 000h
#define _T3CON??7        	 T3CON, 007h
#define _T3CON??6        	 T3CON, 006h
#define _T3CON??5        	 T3CON, 005h
#define _T3CON??4        	 T3CON, 004h
#define _T3CON??3        	 T3CON, 003h
#define _T3CON??2        	 T3CON, 002h
#define _T3CON??1        	 T3CON, 001h
#define _T3CON??0        	 T3CON, 000h
#define _T3GCON??7       	 T3GCON, 007h
#define _T3GCON??6       	 T3GCON, 006h
#define _T3GCON??5       	 T3GCON, 005h
#define _T3GCON??4       	 T3GCON, 004h
#define _T3GCON??3       	 T3GCON, 003h
#define _T3GCON??2       	 T3GCON, 002h
#define _T3GCON??1       	 T3GCON, 001h
#define _T3GCON??0       	 T3GCON, 000h

; EEPROM data.


	INCLUDE	"BITDEFINITIONS.MAC"
	INCLUDE	"C:\PROGRAM FILES (X86)\PBP3\PBPPI18L.LIB"


; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00036	Z00002	#HEADER
Z00002
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00063	Z00003	#CONFIG
Z00003
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00584	Z00004	BANKA   $0000, $005F
Z00004
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00585	Z00005	BANK0   $0060, $00FF
Z00005
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00586	Z00006	BANK1   $0100, $01FF
Z00006
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00587	Z00007	BANK2   $0200, $02FF
Z00007
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00588	Z00008	BANK3   $0300, $03FF
Z00008
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00589	Z00009	BANK4   $0400, $04FF
Z00009
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00590	Z0000A	BANK5   $0500, $05FF
Z0000A
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00591	Z0000B	BANK6   $0600, $06FF
Z0000B
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00592	Z0000C	BANK7   $0700, $07FF
Z0000C
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00593	Z0000D	BANK8   $0800, $08FF
Z0000D
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00594	Z0000E	BANK9   $0900, $09FF
Z0000E
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00595	Z0000F	BANK10  $0A00, $0AFF
Z0000F
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00596	Z00010	BANK11  $0B00, $0BFF
Z00010
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00597	Z00011	BANK12  $0C00, $0CFF
Z00011
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00598	Z00012	BANK13  $0D00, $0DFF
Z00012
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00599	Z00013	BANK14  $0E00, $0E40
Z00013
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00601	Z00014	'EEPROM  $F00000, $F003FF
Z00014
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00603	Z00015	    #MSG "LONG Variables enabled (PBPL used)"
Z00015
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00604	Z00016	    LIBRARY  "PBPPI18L"
Z00016

; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00605	Z00017	    INCLUDE "PBPPI18L.RAM"
Z00017
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00608	Z00018	    INCLUDE "PBPPIC18.RAM"
Z00018
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00609	Z00019	#ENDIF
Z00019
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00610	Z0001A	DEFINE  ADC_CHANNELS 1
Z0001A
; C:\PROGRAM FILES (X86)\PBP3\DEVICES\PIC18F46K80.PBPINC	00618	Z0001B	#header
Z0001B

	END
