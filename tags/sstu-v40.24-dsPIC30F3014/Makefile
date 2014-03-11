# MPLAB IDE generated this makefile for use with GNU make.
# Project: SST40 V4.0.mcp
# Date: Sat Apr 24 20:22:36 2010

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

./src/hex/SST40\ V4.0.hex : ./src/hex/SST40\ V4.0.cof
	$(HX) ".\src\hex\SST40 V4.0.cof"

./src/hex/SST40\ V4.0.cof : src/hex/DigitalIO.o src/hex/main.o src/hex/systmr.o src/hex/task.o src/hex/sirem.o src/hex/PARLIST.o src/hex/trace.o src/hex/vuart.o src/hex/vADC.o src/hex/statemachine.o src/hex/LCD.o src/hex/eeprom.o src/hex/triac_control.o src/hex/IDENT.o src/hex/tempctrl.o src/hex/measure.o src/hex/traps.o
	$(CC) -mcpu=30F3014 "src\hex\DigitalIO.o" "src\hex\main.o" "src\hex\systmr.o" "src\hex\task.o" "src\hex\sirem.o" "src\hex\PARLIST.o" "src\hex\trace.o" "src\hex\vuart.o" "src\hex\vADC.o" "src\hex\statemachine.o" "src\hex\LCD.o" "src\hex\eeprom.o" "src\hex\triac_control.o" "src\hex\IDENT.o" "src\hex\tempctrl.o" "src\hex\measure.o" "src\hex\traps.o" -o".\src\hex\SST40 V4.0.cof" -Wl,--script="C:\Program Files\Microchip\MPLAB C30\support\dsPIC30F\gld\p30f3014.gld",--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,-Map=".\src\hex\SST40 V4.0.map",--report-mem

src/hex/DigitalIO.o : src/include/statemachine.h src/Common/basedef.h src/include/DigitalIO.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/DigitalIO.c
	$(CC) -mcpu=30F3014 -x c -c "src\DigitalIO.c" -o".\src\hex\DigitalIO.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/main.o : src/include/sirem.h src/include/trace.h src/include/tempctrl.h src/include/measure.h src/include/triac_control.h src/include/LCD.h src/include/PARLIST.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libpic30.h src/include/eeprom.h src/include/statemachine.h src/include/task.h src/include/vADC.h src/include/vuart.h src/include/systmr.h src/include/systmr.h src/include/task.h src/Common/basedef.h src/include/DigitalIO.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/main.c
	$(CC) -mcpu=30F3014 -x c -c "src\main.c" -o".\src\hex\main.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/systmr.o : src/include/statemachine.h src/Common/basedef.h src/include/systmr.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/systmr.c
	$(CC) -mcpu=30F3014 -x c -c "src\systmr.c" -o".\src\hex\systmr.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/task.o : src/include/vuart.h src/include/tempctrl.h src/include/task.h src/include/vADC.h src/include/DigitalIO.h src/include/trace.h src/include/statemachine.h src/include/measure.h src/include/triac_control.h src/include/sirem.h src/include/systmr.h src/include/systmr.h src/Common/basedef.h src/include/task.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/task.c
	$(CC) -mcpu=30F3014 -x c -c "src\task.c" -o".\src\hex\task.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/sirem.o : src/include/trace.h src/include/vuart.h src/include/parlist.h src/Common/basedef.h src/include/sirem.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/string.h src/Common/p30F3014.h src/sirem.c
	$(CC) -mcpu=30F3014 -x c -c "src\sirem.c" -o".\src\hex\sirem.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/PARLIST.o : src/include/PARLIST.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libpic30.h src/include/eeprom.h src/include/ident.h src/include/tempctrl.h src/include/statemachine.h src/include/measure.h src/include/task.h src/include/trace.h src/include/systmr.h src/include/task.h src/include/vADC.h src/include/systmr.h src/Common/basedef.h src/include/PARLIST.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/PARLIST.c
	$(CC) -mcpu=30F3014 -x c -c "src\PARLIST.c" -o".\src\hex\PARLIST.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/trace.o : src/include/systmr.h src/include/ident.h src/include/tempctrl.h src/include/measure.h src/include/systmr.h src/include/task.h src/include/vADC.h src/include/vuart.h src/include/parlist.h src/include/sirem.h src/Common/basedef.h src/include/trace.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/string.h src/Common/p30F3014.h src/trace.c
	$(CC) -mcpu=30F3014 -x c -c "src\trace.c" -o".\src\hex\trace.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/vuart.o : src/include/systmr.h src/Common/basedef.h src/include/vuart.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/vuart.c
	$(CC) -mcpu=30F3014 -x c -c "src\vuart.c" -o".\src\hex\vuart.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/vADC.o : src/include/systmr.h src/include/task.h src/Common/basedef.h src/include/vADC.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30f3014.h src/vADC.c
	$(CC) -mcpu=30F3014 -x c -c "src\vADC.c" -o".\src\hex\vADC.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/statemachine.o : src/include/triac_control.h src/include/tempctrl.h src/include/ident.h src/include/measure.h src/include/PARLIST.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libpic30.h src/include/eeprom.h src/include/trace.h src/include/systmr.h src/include/task.h src/include/vADC.h src/include/vuart.h src/include/PARLIST.h src/include/sirem.h src/include/systmr.h src/include/LCD.h src/include/DigitalIO.h src/Common/basedef.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/include/statemachine.h src/Common/p30F3014.h src/statemachine.c
	$(CC) -mcpu=30F3014 -x c -c "src\statemachine.c" -o".\src\hex\statemachine.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/LCD.o : src/include/systmr.h c:/program\ files/microchip/mplab\ c30/include/stdio.h c:/program\ files/microchip/mplab\ c30/include/stdarg.h c:/program\ files/microchip/mplab\ c30/include/yvals.h c:/program\ files/microchip/mplab\ c30/include/string.h src/Common/basedef.h src/include/LCD.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/LCD.c
	$(CC) -mcpu=30F3014 -x c -c "src\LCD.c" -o".\src\hex\LCD.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/eeprom.o : src/include/statemachine.h src/include/PARLIST.h src/include/eeprom.h src/Common/basedef.h src/include/parlist.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libpic30.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/eeprom.c
	$(CC) -mcpu=30F3014 -x c -c "src\eeprom.c" -o".\src\hex\eeprom.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/triac_control.o : src/include/statemachine.h src/include/tempctrl.h src/Common/basedef.h src/include/triac_control.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/triac_control.c
	$(CC) -mcpu=30F3014 -x c -c "src\triac_control.c" -o".\src\hex\triac_control.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/IDENT.o : src/include/trace.h src/include/measure.h src/include/DigitalIO.h src/include/triac_control.h src/include/statemachine.h src/include/tempctrl.h src/Common/basedef.h src/include/ident.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/IDENT.C
	$(CC) -mcpu=30F3014 -x c -c "src\IDENT.C" -o".\src\hex\IDENT.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/tempctrl.o : src/include/ident.h src/include/triac_control.h src/include/statemachine.h src/include/measure.h src/include/tempctrl.h src/include/systmr.h src/Common/basedef.h src/include/task.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/tempctrl.c
	$(CC) -mcpu=30F3014 -x c -c "src\tempctrl.c" -o".\src\hex\tempctrl.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/measure.o : src/include/DigitalIO.h src/include/statemachine.h src/include/tempctrl.h src/include/task.h src/include/systmr.h src/include/task.h src/include/vADC.h src/Common/basedef.h src/include/measure.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h src/measure.c
	$(CC) -mcpu=30F3014 -x c -c "src\measure.c" -o".\src\hex\measure.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

src/hex/traps.o : src/Common/basedef.h src/include/LCD.h src/Common/basedef.h src/Common/DigitalIoCfg.h src/Common/basedef.h src/Common/p30F3014.h ../../../../PLL/src/traps.c
	$(CC) -mcpu=30F3014 -x c -c "D:\My Documents\Projects\PLL\src\traps.c" -o".\src\hex\traps.o" -I".\src\include" -I".\src\Common" -D__DEBUG -g -Wall -O1

clean : 
	$(RM) "src\hex\DigitalIO.o" "src\hex\main.o" "src\hex\systmr.o" "src\hex\task.o" "src\hex\sirem.o" "src\hex\PARLIST.o" "src\hex\trace.o" "src\hex\vuart.o" "src\hex\vADC.o" "src\hex\statemachine.o" "src\hex\LCD.o" "src\hex\eeprom.o" "src\hex\triac_control.o" "src\hex\IDENT.o" "src\hex\tempctrl.o" "src\hex\measure.o" "src\hex\traps.o" ".\src\hex\SST40 V4.0.cof" ".\src\hex\SST40 V4.0.hex"

