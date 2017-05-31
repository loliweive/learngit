;**********************************************************
;宏定义和寄存器初始化
;
;
;	
;版本：	v01 2016年6月18日17:52:41
;**********************************************************


;CONST defined here
#define	KEY_DEBOUNCE_TICK	d'8'		;40ms
;#define	KEY_LONGPRESS_TICK	d'250'		;1s+40ms
#define	CONST_KEY_RELEASE	d'8'	
;;IO口初始化        
#define PORTA_INI	b'00000000'	; PORTA端口初值 
#define PORTB_INI	b'00000000'	; PORTB端口初值  

#define TRISA_INI	b'00000000'	; PORTA方向初值  0 输出 1输入
#define TRISB_INI	b'00111010'	; PORTB方向初值
;;;;;010
;#define WPUB_INI	b'11101011'	; 上拉 0 使能 1禁止
;#define WPD_INI	b'11111111'	; 下拉 0 使能 1禁止 
;;;;013
#Define PHCON_INI	b'11111101'	; 上拉 0 使能 1禁止
#Define PDCON_INI	b'11111111'	; 下拉 0 使能 1禁止 
#Define ODCON_INI	b'00000000'	; 开漏输出      1 使能 0禁止	

#define	OPTION_INI	b'10000000'	; X 上升沿下降沿 T0时钟源 T0计数沿选择 分频器派送 T0预分频1:2
#define T0_INI		165		;156+1	4M/4T 200US	  

#define	PCON_INI	B'10111000'     ;WDT使能   外部int禁止	        
#define	IOCB_INI	B'00000000'     ;PB 中断和唤醒 0 禁止
;;;010
;#define	INTCON_INI	B'10100000'     ;B0=1，TM0中断使能   外部int禁止
;;;;013
#DEFINE	INTECON_INI	B'10000001'     ;WDT使能   外部int禁止	 

;-------IO define------------------
#define	S1	PORTB,1
#DEFINE	LED	PORTB,0
#DEFINE	UVLED	PORTB,2

;;;;;;010A
;#define c_ram_start		0x20
;#define c_ram_end		0x50
;;;;;013
#define c_ram_start		0x10
#define c_ram_end		0xC0

;;;;;;;ram start here,20~3f优先使用
flag		equ		0x20
#define	f_mode			flag,0
#define	f_keylock_double	flag,1
#define	f_duty_update		flag,2
cnt_15ms	equ		0x21
cnt_vol_duty	equ	0x22			
set_vol_duty	equ	0x23			;为0 LED全灭，为100  LED全亮
cnt_200us	equ	0x24				;200us中断一次
flag_byte	equ	0x25
#define		f_5ms		flag_byte,0	;5ms标志位
#define		f_led1_on	flag_byte,1	;500ms标志位
#define		f_sleep		flag_byte,2	;睡眠标志位
#define		f_keylock	flag_byte,3	;按键短按锁定或者按键消抖完成标志
#define		f_status_on	flag_byte,4	;开关机标志
#define		f_down_breathe	flag_byte,5	;正向和反向呼吸
#define		f_keylock_long	flag_byte,6	;按键长按标志，防止长按后重复触发
#define		f_flash		flag_byte,7	;10hz爆闪标志位
key_byte	equ	0x26
#define		f_key0		key_byte,0
#define		f_key1		key_byte,1
#define		f_key2		key_byte,2
#define		f_key3		key_byte,3
#define		f_short_press	key_byte,4
#define		f_long_press	key_byte,5
#define		f_double_press	key_byte,6
cnt_led_duty		equ	0x27		
set_red_led_duty	equ	0x28	;为0 LED全灭，为64  LED全亮	
current_key		equ	0x29		;当前按键的值
last_key		equ	0x2a		;上一次按键的值
cnt_key_press		equ	0x2b		;按键按下计时，用于消抖
cnt_1s			equ	0x2c		;工作模式1
mode2			equ	0x2d		;工作模式2
set_green_led_duty	equ	0x2e		;为0 LED全灭，为64  LED全亮	
set_blue_led_duty	equ	0x2f		;为0 LED全灭，为64  LED全亮	
cnt_5ms			equ	0x30		
cnt_key_release		equ	0x31		;按键释放消抖
cnt_delay		equ	0x32		;300us延时
cnt_key2_h		equ	0x33		
cnt_key2_l		equ	0x34
cnt_5ms2		equ	0x35

pclath_temp	    	equ       0x3d 
status_temp     	equ       0x3e
w_temp          	equ       0x3f        
;;;;;ram ends here	


;MACRO define here
ONLED	macro	
	bsf	LED
	bsf	UVLED
	endm
	
OFFLED	macro	
	bcf	LED
	bcf	UVLED
	endm	
		
