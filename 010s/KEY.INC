;**********************************************************
;KEY扫描，出口参数:key_byte
;使用细则：目前只用到了两个按键的识别，最多可以识别六个按键的长按短按，
;此处未涉及到按键与其它功能复用
;长按标志在按键长按识别到后直接置一，短按标志在释放按键的函数中置一
;************************m_key_scan_proc*****************

get_key_value:

	btfss	S1
	bsf	f_key0

	movf	key_byte,w
	btfsc	Z
	goto	key_release		;无按键
	movwf	current_key		;有按键，保存当前的按键值
	xorwf	last_key,f		;与上一次按键值进行比较
	btfss	Z
	clrf	cnt_key_press		;前后按键值不相等，重新开始计数
	incf	cnt_key_press,f		;前后按键值相等，计数加1
	movwf	last_key		;将当前按键值赋值给上一次按键值
	
key_debounce:

	btfsc	f_keylock
	goto	get_key_value_end
	movlw	KEY_DEBOUNCE_TICK
	subwf	cnt_key_press,w
	btfss	C
	goto	get_key_value_end	
	clrf	cnt_key_press		;消抖完毕
	bsf	f_keylock		;短按锁定，或者按键消抖完成标志
	bsf	f_short_press
	goto	get_key_value_end
	
key_release:

	incf	cnt_key_release,f
	movlw	CONST_KEY_RELEASE
	subwf	cnt_key_release,w
	btfss	C
	goto	get_key_value_end
	clrf	cnt_key_release		;按键释放消抖
	btfss	f_status_on		;防止睡眠后按键才松开，造成系统即即刻被唤醒
	bsf	f_sleep
	btfss	f_keylock
	goto	get_key_value_end
	bcf	f_keylock
	
	movf	last_key,w
	iorwf	key_byte,f		;带上last_key的键值
	goto	get_key_value_end
	
get_key_value_end:

	return
;----------------------------------------------------------

;**********************************************************
;KEY处理函数，出口参数:mode，f_status_on
;	      入口参数:key_byte
;使用细则：	
;************************m_key_scan_proc*****************	
key_proc:

	btfsc	f_key0
	goto	key0_proc
	goto	key_proc_end
	
;---key0处理	
key0_proc:
	
	;档位按键
	btfss	f_short_press
	goto	key_proc_end
	
power_on_off_judge:

	btfss	f_status_on
	goto	power_on
	
power_off:
	
	bcf	f_status_on
	OFFLED
	goto	key_proc_end
	
power_on:

	bsf	f_status_on
	ONLED	
	
key_proc_end:

	clrf	key_byte		;按键处理完后清零按键值
	return	
;-------------------------------------------------