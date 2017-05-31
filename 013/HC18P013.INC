;==========================================================================
;
; Holychip HC18P013 Head Files
; Date:     2011-10-07
;
;==========================================================================

;==========================================================================
;
;       Register Definitions
;
;==========================================================================

W			EQU     H'0000'
F                       EQU     H'0001'

;----- Register Files------------------------------------------------------
;BANK0
INDF                    EQU     H'0000'
T0                      EQU     H'0001'
PCL                     EQU     H'0002'
STATUS                  EQU     H'0003'
FSR                     EQU     H'0004'
PORTA                   EQU     H'0005'
PORTB                   EQU     H'0006'
GPR						EQU		H'0007'
PCON                    EQU     H'0008'
IOCB                    EQU     H'0009'
PCLATH                  EQU     H'000A'
PDCON                   EQU     H'000B'
ODCON 	                EQU     H'000C'
PHCON 	                EQU     H'000D'
INTECON	                EQU     H'000E'
INTFLAG	                EQU     H'000F'
OPTION	                EQU     H'0041'
TRISA			  		EQU     H'0045'
TRISB					EQU     H'0046'

;----- STATUS Bits --------------------------------------------------------
#DEFINE RST     STATUS,H'0007'
#DEFINE GP1     STATUS,H'0006'
#DEFINE GP0     STATUS,H'0005'
#DEFINE TO      STATUS,H'0004'
#DEFINE PD      STATUS,H'0003'
#DEFINE Z       STATUS,H'0002'
#DEFINE DC      STATUS,H'0001'
#DEFINE C       STATUS,H'0000'

;----- PCON Bits --------------------------------------------------------
#DEFINE WDTENS  PCON,H'0007'
#DEFINE EIS     PCON,H'0006'

;----- INTECON Bits --------------------------------------------------------
#DEFINE GIE     INTECON,H'0007'
#DEFINE INTE    INTECON,H'0002'                                   
#DEFINE RBIE    INTECON,H'0001'                                   
#DEFINE T0IE    INTECON,H'0000'                                   
                                                      

;----- INTFLAG Bits --------------------------------------------------------
#DEFINE INTF    INTFLAG,H'0002'
#DEFINE RBIF    INTFLAG,H'0001'
#DEFINE T0IF    INTFLAG,H'0000'

;----- OPTION Bits --------------------------------------------------------
#DEFINE INTEDG  OPTION,H'0006'
#DEFINE T0CS    OPTION,H'0005'
#DEFINE T0SE    OPTION,H'0004'
#DEFINE PSA     OPTION,H'0003'
#DEFINE PS2     OPTION,H'0002'
#DEFINE PS1     OPTION,H'0001'
#DEFINE PS0     OPTION,H'0000'

;----- PORTA Bits --------------------------------------------------------
#DEFINE PORTA7  PORTA,H'0007'
#DEFINE PORTA6  PORTA,H'0006'
#DEFINE PORTA5  PORTA,H'0005'
#DEFINE PORTA4  PORTA,H'0004'
#DEFINE PORTA3  PORTA,H'0003'
#DEFINE PORTA2  PORTA,H'0002'
#DEFINE PORTA1  PORTA,H'0001'
#DEFINE PORTA0  PORTA,H'0000'

;----- PORTB Bits --------------------------------------------------------
#DEFINE PORTB7  PORTB,H'0007'
#DEFINE PORTB6  PORTB,H'0006'
#DEFINE PORTB5  PORTB,H'0005'
#DEFINE PORTB4  PORTB,H'0004'
#DEFINE PORTB3  PORTB,H'0003'
#DEFINE PORTB2  PORTB,H'0002'
#DEFINE PORTB1  PORTB,H'0001'
#DEFINE PORTB0  PORTB,H'0000'

;----- TRISA Bits --------------------------------------------------------
#DEFINE TRISA7  TRISA,H'0007'
#DEFINE TRISA6  TRISA,H'0006'
#DEFINE TRISA5  TRISA,H'0005'
#DEFINE TRISA4  TRISA,H'0004'
#DEFINE TRISA3  TRISA,H'0003'
#DEFINE TRISA2  TRISA,H'0002'
#DEFINE TRISA1  TRISA,H'0001'
#DEFINE TRISA0  TRISA,H'0000'

;----- TRISB Bits --------------------------------------------------------
#DEFINE TRISB7  TRISB,H'0007'
#DEFINE TRISB6  TRISB,H'0006'
#DEFINE TRISB5  TRISB,H'0005'
#DEFINE TRISB4  TRISB,H'0004'
#DEFINE TRISB3  TRISB,H'0003'
#DEFINE TRISB2  TRISB,H'0002'
#DEFINE TRISB1  TRISB,H'0001'
#DEFINE TRISB0  TRISB,H'0000'

;----- IOCB Bits --------------------------------------------------------
#DEFINE IOCB7  IOCB,H'0007'
#DEFINE IOCB6  IOCB,H'0006'
#DEFINE IOCB5  IOCB,H'0005'
#DEFINE IOCB4  IOCB,H'0004'
#DEFINE IOCB3  IOCB,H'0003'
#DEFINE IOCB2  IOCB,H'0002'
#DEFINE IOCB1  IOCB,H'0001'
#DEFINE IOCB0  IOCB,H'0000'

;----- PDCON Bits --------------------------------------------------------
#DEFINE PDB3  PDCON,H'0007'
#DEFINE PDB2  PDCON,H'0006'
#DEFINE PDB1  PDCON,H'0005'
#DEFINE PDB0  PDCON,H'0004'
#DEFINE PDA3  PDCON,H'0003'
#DEFINE PDA2  PDCON,H'0002'
#DEFINE PDA1  PDCON,H'0001'
#DEFINE PDA0  PDCON,H'0000'

;----- PHCON Bits --------------------------------------------------------
#DEFINE PHB7  PHCON,H'0007'
#DEFINE PHB6  PHCON,H'0006'
#DEFINE PHB5  PHCON,H'0005'
#DEFINE PHB4  PHCON,H'0004'
#DEFINE PHB3  PHCON,H'0003'
#DEFINE PHB2  PHCON,H'0002'
#DEFINE PHB1  PHCON,H'0001'
#DEFINE PHB0  PHCON,H'0000'

;----- ODCON Bits --------------------------------------------------------
#DEFINE ODB7  ODCON,H'0007'
#DEFINE ODB6  ODCON,H'0006'
#DEFINE ODB5  ODCON,H'0005'
#DEFINE ODB4  ODCON,H'0004'
#DEFINE ODB3  ODCON,H'0003'
#DEFINE ODB2  ODCON,H'0002'
#DEFINE ODB1  ODCON,H'0001'
#DEFINE ODB0  ODCON,H'0000'
;==========================================================================
;
; File End
;
;==========================================================================