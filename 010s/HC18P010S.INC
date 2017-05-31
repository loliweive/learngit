;==========================================================================
;
; HOLYCHIP HC18P010S HEAD FILES
; DATE:     2011-2-20
;
;==========================================================================

;==========================================================================
;
;       REGISTER DEFINITIONS
;
;==========================================================================

W			EQU     H'0000'
F                       EQU     H'0001'

;----- REGISTER FILES------------------------------------------------------
;BANK0
INDF                    EQU     H'0000'
T0                      EQU     H'0001'
PCL                     EQU     H'0002'
STATUS                  EQU     H'0003'
FSR                     EQU     H'0004'
PORTA                   EQU     H'0005'
PORTB                   EQU     H'0006'
TRISA                   EQU     H'0007'
TRISB                   EQU     H'0008'
OPTION                  EQU     H'0009'				
PCLATH                  EQU     H'000A'
INTCON                  EQU     H'000B'
T2INTCON                EQU     H'000C'
PCON                    EQU     H'000E'
OSCCON		        EQU     H'0010'
T2  		        EQU     H'0011'
T2CON			EQU     H'0012'
WPUB	  	        EQU     H'0013'
WPUA			EQU     H'0014'
WPD			EQU     H'0015'
IOCB			EQU     H'0016'
PR2			EQU     H'0018'
PWM			EQU     H'001B'

;----- STATUS BITS --------------------------------------------------------

#DEFINE IRP     STATUS,H'0007'
#DEFINE RP1     STATUS,H'0006'
#DEFINE RP0     STATUS,H'0005'
#DEFINE TO      STATUS,H'0004'
#DEFINE PD      STATUS,H'0003'
#DEFINE Z       STATUS,H'0002'
#DEFINE DC      STATUS,H'0001'
#DEFINE C       STATUS,H'0000'

;----- OPTION BITS --------------------------------------------------------
#DEFINE RBPUB   OPTION,H'0007'
#DEFINE INTEDG  OPTION,H'0006'
#DEFINE T0CS    OPTION,H'0005'
#DEFINE T0SE    OPTION,H'0004'
#DEFINE PSA     OPTION,H'0003'
#DEFINE PS2     OPTION,H'0002'
#DEFINE PS1     OPTION,H'0001'
#DEFINE PS0     OPTION,H'0000'

;----- INTCON BITS --------------------------------------------------------

#DEFINE GIE      INTCON ,    H'0007'
#DEFINE T0IE     INTCON  ,   H'0005'
#DEFINE INTE     INTCON  ,   H'0004'
#DEFINE RBIE     INTCON  ,   H'0003'
#DEFINE T0IF   	 INTCON  ,   H'0002'
#DEFINE INTF     INTCON  ,   H'0001'
#DEFINE RBIF     INTCON  ,   H'0000'

;----- T2INTCON BITS ----------------------------------------------------------

#DEFINE T2IE                    T2INTCON   ,  H'0005'
#DEFINE T2IF                    T2INTCON  ,   H'0001'

;----- PCON BITS ----------------------------------------------------------

#DEFINE WDTENS                  PCON  ,   H'0004'	
#DEFINE POR                     PCON ,    H'0001'
#DEFINE BOR                     PCON ,    H'0000'

;----- OSCCON BITS ----------------------------------------------------------

T0OSCEN                 EQU     H'0007'
HXEN                    EQU     H'0001'
SCS                     EQU     H'0000'

;----- T2CON BITS ----------------------------------------------------------

PWMEN                   EQU     H'0007'
T2CKPS3                 EQU     H'0006'
T2CKPS2                 EQU     H'0005'
T2CKPS1                 EQU     H'0004'
T2CKPS0                 EQU     H'0003'
T2ON                  	EQU     H'0002'
PMW1	                EQU     H'0001'
PMW0	                EQU     H'0000'

;----- WPUA BITS ----------------------------------------------------------

;WPUA7	                EQU     H'0007'
;WPUA6	                EQU     H'0006'
;WPUA5	                EQU     H'0005'
;WPUA4	                EQU     H'0004'
WPUA3                	EQU     H'0003'
WPUA2	                EQU     H'0002'
WPUA1	                EQU     H'0001'
WPUA0	                EQU     H'0000'

;----- WPUB BITS ----------------------------------------------------------

WPUB7	                EQU     H'0007'
WPUB6	                EQU     H'0006'
WPUB5	                EQU     H'0005'
WPUB4	                EQU     H'0004'
;WPUB3                	EQU     H'0003'
WPUB2	                EQU     H'0002'
WPUB1	                EQU     H'0001'
WPUB0	                EQU     H'0000'

;----- WPD BITS ----------------------------------------------------------

WPDA2	                EQU     H'0007'
WPDA1	                EQU     H'0006'
WPDA0	                EQU     H'0005'
WPDB4	                EQU     H'0004'
WPDB3                	EQU     H'0003'
WPDB2	                EQU     H'0002'
WPDB1	                EQU     H'0001'
WPDB0	                EQU     H'0000'

;----- IOCB BITS ----------------------------------------------------------

IOCB7	                EQU     H'0007'
IOCB6	                EQU     H'0006'
IOCB5	                EQU     H'0005'
IOCB4	                EQU     H'0004'
IOCB3                	EQU     H'0003'
IOCB2	                EQU     H'0002'
IOCB1	                EQU     H'0001'
IOCB0	                EQU     H'0000'

;==========================================================================
;
; FILE END
;
;==========================================================================