
	list p = hc18p010s, r=dec
;	#include "hc18p010s.inc"
	#include "hc18p013.inc"			
	#include "reg.inc"



;********************************************
;               code start                  
;********************************************

	org     0000h	
	goto    reset  
 	goto    reset   
	goto    reset   
	goto    reset        
 	goto    reset  
 	goto    reset   
	goto    reset   
	goto    reset                
	org     0008h  	
					
int_start:		

	movwf	w_temp
	swapf	w_temp,f	; save w
	swapf	STATUS,W
	movwf	status_temp	; save status
     
	btfss	T0IF		;200us
	goto	int_exit
	bcf	T0IF
	
	movlw	T0_INI
	movwf	T0
		
int_timeflag:
	
	incf	cnt_200us,f
	movlw	d'25'		
	subwf	cnt_200us,w
	btfss	C
	goto	int_timeflag_end
	clrf	cnt_200us
	bsf	f_5ms		
int_timeflag_end:

int_exit:
    							
	swapf	status_temp, w
	movwf	STATUS				
        swapf	w_temp, w					
	retfie				

;***************************************  	  

reset:   
;       clrf    INTCON  	;010A
 	clrf	INTECON		;013
	clrf	PCON    
	clrf	INTFLAG		;013
 	clrwdt
 	call	system_init	
	bsf	f_sleep

;====================================================================	
;				主函数
;====================================================================	
mainloop:

	clrwdt	       
	btfsc	f_sleep
	call	sleep_proc
	btfss	f_5ms
	goto	mainloop
	bcf	f_5ms
	call	get_key_value
	call	key_proc
	call	time_proc
	goto	mainloop
;*******************************************************************	
time_proc:

	btfss	f_status_on
	goto	time_proc_clrf
	
	ONLED
	incf	cnt_5ms,f
	movlw	d'200'
	subwf	cnt_5ms,w
	btfss	C
	goto	time_proc_end
	clrf	cnt_5ms
	incf	cnt_1s,f
	movlw	d'90'
	subwf	cnt_1s,w
	btfss	C
	goto	time_proc_end
	clrf	cnt_1s
	OFFLED
	bcf	f_status_on
	goto	time_proc_end
	
time_proc_clrf:

	clrf	cnt_5ms
	clrf	cnt_1s
	
time_proc_end:

	return
;-----------------------------	
	#include "sleep.inc"
	#include "sub013.inc"
	#include "key.inc" 		;此包含可放在0~3ff中间任何位置

;********************************************

        org     03ffh                          
        goto    reset                           
        end


;********************************************
;               code end                    
;********************************************

