echo off heiheihei
call ../test.bat
@del .\010s\*.bat
@del .\010s\*.out
@del .\010s\*.ini
@del .\010s\*.cod
@del .\010s\*.cof
@del .\010s\*.cofv
@del .\010s\*.err
@del .\010s\*.hex
@del .\010s\*.lst
@del .\010s\*.map
@del .\010s\*.o
@del .\010s\*.bak

@echo off
@del .\013\*.bat
@del .\013\*.out
@del .\013\*.ini
@del .\013\*.cod
@del .\013\*.cof
@del .\013\*.cofv
@del .\013\*.err
@del .\013\*.hex
@del .\013\*.lst
@del .\013\*.map
@del .\013\*.o
@del .\013\*.bak

@md "mfg"
@copy .\013\*.hc  .\mfg\
@copy .\013\*.pro .\mfg\

@del .\010s\*.hc
@del .\010s\*.pro

@del .\013\*.hc
@del .\013\*.pro
pause