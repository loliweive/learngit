;*********************************************************
;		睡眠函数主函数
;此函数只进行睡眠指令f_sleep的判断，进入睡眠，和睡眠唤醒
;也可加入睡眠前对IO口进行处理的函数和语句，以进一步降低功耗
;*********************************************************
sleep_proc:

	BCF	f_sleep	
	;关机睡眠前清零计数器和标志位	

	OFFLED
	clrf	cnt_5ms
	clrf	cnt_1s
	
	CLRWDT
	BCF	WDTENS		;WDTEN
	BCF	GIE	
	MOVLW	B'00000010'
	MOVWF	IOCB
	MOVF	PORTB,W
	BCF	RBIF		;PBIF
	BSF	RBIE
	NOP
	NOP
	NOP
	NOP
	SLEEP
	NOP
	NOP
	NOP
	NOP
	CLRWDT
	CLRF	IOCB
	BCF	RBIE
	BCF	RBIF		;PBIF
	BSF	WDTENS		;WDTEN
	BSF	GIE	
;	bsf	f_status_on
;	BTFSS	S1
;	bsf	f_keylock
	
sleep_proc_end:

	RETURN	
;---------------------------------------------------------