;*********************************************************
;		˯�ߺ���������
;�˺���ֻ����˯��ָ��f_sleep���жϣ�����˯�ߣ���˯�߻���
;Ҳ�ɼ���˯��ǰ��IO�ڽ��д����ĺ�������䣬�Խ�һ�����͹���
;*********************************************************
sleep_proc:

	BCF	f_sleep	
	;�ػ�˯��ǰ����������ͱ�־λ	

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