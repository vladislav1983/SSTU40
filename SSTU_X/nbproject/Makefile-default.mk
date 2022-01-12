#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/Crc16.c ../src/DigitalIO.c ../src/IDENT.c ../src/LCD.c ../src/PARLIST.c ../src/eeprom.c ../src/main.c ../src/measure.c ../src/sirem.c ../src/statemachine.c ../src/systmr.c ../src/task.c ../src/tempctrl.c ../src/trace.c ../src/traps.c ../src/triac_control.c ../src/vADC.c ../src/vuart.c ../src/RotaryEncoder/RotaryEncoder.c ../src/RotaryEncoder/RotaryEncoder_cfg.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/Crc16.o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ${OBJECTDIR}/_ext/1360937237/IDENT.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/measure.o ${OBJECTDIR}/_ext/1360937237/sirem.o ${OBJECTDIR}/_ext/1360937237/statemachine.o ${OBJECTDIR}/_ext/1360937237/systmr.o ${OBJECTDIR}/_ext/1360937237/task.o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ${OBJECTDIR}/_ext/1360937237/trace.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/1360937237/triac_control.o ${OBJECTDIR}/_ext/1360937237/vADC.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/Crc16.o.d ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d ${OBJECTDIR}/_ext/1360937237/IDENT.o.d ${OBJECTDIR}/_ext/1360937237/LCD.o.d ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d ${OBJECTDIR}/_ext/1360937237/eeprom.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/measure.o.d ${OBJECTDIR}/_ext/1360937237/sirem.o.d ${OBJECTDIR}/_ext/1360937237/statemachine.o.d ${OBJECTDIR}/_ext/1360937237/systmr.o.d ${OBJECTDIR}/_ext/1360937237/task.o.d ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d ${OBJECTDIR}/_ext/1360937237/trace.o.d ${OBJECTDIR}/_ext/1360937237/traps.o.d ${OBJECTDIR}/_ext/1360937237/triac_control.o.d ${OBJECTDIR}/_ext/1360937237/vADC.o.d ${OBJECTDIR}/_ext/1360937237/vuart.o.d ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/Crc16.o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ${OBJECTDIR}/_ext/1360937237/IDENT.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/measure.o ${OBJECTDIR}/_ext/1360937237/sirem.o ${OBJECTDIR}/_ext/1360937237/statemachine.o ${OBJECTDIR}/_ext/1360937237/systmr.o ${OBJECTDIR}/_ext/1360937237/task.o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ${OBJECTDIR}/_ext/1360937237/trace.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/1360937237/triac_control.o ${OBJECTDIR}/_ext/1360937237/vADC.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o

# Source Files
SOURCEFILES=../src/Crc16.c ../src/DigitalIO.c ../src/IDENT.c ../src/LCD.c ../src/PARLIST.c ../src/eeprom.c ../src/main.c ../src/measure.c ../src/sirem.c ../src/statemachine.c ../src/systmr.c ../src/task.c ../src/tempctrl.c ../src/trace.c ../src/traps.c ../src/triac_control.c ../src/vADC.c ../src/vuart.c ../src/RotaryEncoder/RotaryEncoder.c ../src/RotaryEncoder/RotaryEncoder_cfg.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4013
MP_LINKER_FILE_OPTION=,--script="C:\Program Files\Microchip\MPLABX\v5.45\packs\Microchip\dsPIC30F_DFP\1.3.82\xc16\bin\..\support\dsPIC30F\gld\p30F4013.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/measure.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sirem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/systmr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/trace.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/measure.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sirem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/systmr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/trace.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/Program\ Files/Microchip/MPLABX/v5.45/packs/Microchip/dsPIC30F_DFP/1.3.82/xc16/bin/../support/dsPIC30F/gld/p30F4013.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/Program\ Files/Microchip/MPLABX/v5.45/packs/Microchip/dsPIC30F_DFP/1.3.82/xc16/bin/../support/dsPIC30F/gld/p30F4013.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
