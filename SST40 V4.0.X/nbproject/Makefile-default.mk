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
FINAL_IMAGE=${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/pid/pid.c ../src/pid/pid_cfg.c ../src/DigitalIO.c ../src/main.c ../src/systmr.c ../src/task.c ../src/sirem.c ../src/PARLIST.c ../src/trace.c ../src/vuart.c ../src/statemachine.c ../src/LCD.c ../src/eeprom.c ../src/triac_control.c ../src/IDENT.c ../src/tempctrl.c ../src/measure.c ../src/traps.c ../src/RotaryEncoder/RotaryEncoder.c ../src/RotaryEncoder/RotaryEncoder_cfg.c ../src/Crc16.c ../src/MathTools.c ../src/adc_drv.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/659864977/pid.o ${OBJECTDIR}/_ext/659864977/pid_cfg.o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/systmr.o ${OBJECTDIR}/_ext/1360937237/task.o ${OBJECTDIR}/_ext/1360937237/sirem.o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ${OBJECTDIR}/_ext/1360937237/trace.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/1360937237/statemachine.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/triac_control.o ${OBJECTDIR}/_ext/1360937237/IDENT.o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ${OBJECTDIR}/_ext/1360937237/measure.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o ${OBJECTDIR}/_ext/1360937237/Crc16.o ${OBJECTDIR}/_ext/1360937237/MathTools.o ${OBJECTDIR}/_ext/1360937237/adc_drv.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/659864977/pid.o.d ${OBJECTDIR}/_ext/659864977/pid_cfg.o.d ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/systmr.o.d ${OBJECTDIR}/_ext/1360937237/task.o.d ${OBJECTDIR}/_ext/1360937237/sirem.o.d ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d ${OBJECTDIR}/_ext/1360937237/trace.o.d ${OBJECTDIR}/_ext/1360937237/vuart.o.d ${OBJECTDIR}/_ext/1360937237/statemachine.o.d ${OBJECTDIR}/_ext/1360937237/LCD.o.d ${OBJECTDIR}/_ext/1360937237/eeprom.o.d ${OBJECTDIR}/_ext/1360937237/triac_control.o.d ${OBJECTDIR}/_ext/1360937237/IDENT.o.d ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d ${OBJECTDIR}/_ext/1360937237/measure.o.d ${OBJECTDIR}/_ext/1360937237/traps.o.d ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d ${OBJECTDIR}/_ext/1360937237/Crc16.o.d ${OBJECTDIR}/_ext/1360937237/MathTools.o.d ${OBJECTDIR}/_ext/1360937237/adc_drv.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/659864977/pid.o ${OBJECTDIR}/_ext/659864977/pid_cfg.o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/systmr.o ${OBJECTDIR}/_ext/1360937237/task.o ${OBJECTDIR}/_ext/1360937237/sirem.o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ${OBJECTDIR}/_ext/1360937237/trace.o ${OBJECTDIR}/_ext/1360937237/vuart.o ${OBJECTDIR}/_ext/1360937237/statemachine.o ${OBJECTDIR}/_ext/1360937237/LCD.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/triac_control.o ${OBJECTDIR}/_ext/1360937237/IDENT.o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ${OBJECTDIR}/_ext/1360937237/measure.o ${OBJECTDIR}/_ext/1360937237/traps.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o ${OBJECTDIR}/_ext/1360937237/Crc16.o ${OBJECTDIR}/_ext/1360937237/MathTools.o ${OBJECTDIR}/_ext/1360937237/adc_drv.o

# Source Files
SOURCEFILES=../src/pid/pid.c ../src/pid/pid_cfg.c ../src/DigitalIO.c ../src/main.c ../src/systmr.c ../src/task.c ../src/sirem.c ../src/PARLIST.c ../src/trace.c ../src/vuart.c ../src/statemachine.c ../src/LCD.c ../src/eeprom.c ../src/triac_control.c ../src/IDENT.c ../src/tempctrl.c ../src/measure.c ../src/traps.c ../src/RotaryEncoder/RotaryEncoder.c ../src/RotaryEncoder/RotaryEncoder_cfg.c ../src/Crc16.c ../src/MathTools.c ../src/adc_drv.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4013
MP_LINKER_FILE_OPTION=,-Tp30F4013.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/659864977/pid.o: ../src/pid/pid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/659864977" 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o.d 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o.ok ${OBJECTDIR}/_ext/659864977/pid.o.err 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659864977/pid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/659864977/pid.o.d" -o ${OBJECTDIR}/_ext/659864977/pid.o ../src/pid/pid.c     -save-temps
	
${OBJECTDIR}/_ext/659864977/pid_cfg.o: ../src/pid/pid_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/659864977" 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o.ok ${OBJECTDIR}/_ext/659864977/pid_cfg.o.err 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659864977/pid_cfg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/659864977/pid_cfg.o.d" -o ${OBJECTDIR}/_ext/659864977/pid_cfg.o ../src/pid/pid_cfg.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.ok ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ../src/DigitalIO.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.ok ${OBJECTDIR}/_ext/1360937237/main.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.ok ${OBJECTDIR}/_ext/1360937237/systmr.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/systmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d" -o ${OBJECTDIR}/_ext/1360937237/systmr.o ../src/systmr.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.ok ${OBJECTDIR}/_ext/1360937237/task.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d" -o ${OBJECTDIR}/_ext/1360937237/task.o ../src/task.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.ok ${OBJECTDIR}/_ext/1360937237/sirem.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sirem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d" -o ${OBJECTDIR}/_ext/1360937237/sirem.o ../src/sirem.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.ok ${OBJECTDIR}/_ext/1360937237/PARLIST.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ../src/PARLIST.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.ok ${OBJECTDIR}/_ext/1360937237/trace.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/trace.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d" -o ${OBJECTDIR}/_ext/1360937237/trace.o ../src/trace.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.ok ${OBJECTDIR}/_ext/1360937237/vuart.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/vuart.o ../src/vuart.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.ok ${OBJECTDIR}/_ext/1360937237/statemachine.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" -o ${OBJECTDIR}/_ext/1360937237/statemachine.o ../src/statemachine.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.ok ${OBJECTDIR}/_ext/1360937237/LCD.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCD.o ../src/LCD.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.ok ${OBJECTDIR}/_ext/1360937237/eeprom.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.ok ${OBJECTDIR}/_ext/1360937237/triac_control.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" -o ${OBJECTDIR}/_ext/1360937237/triac_control.o ../src/triac_control.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.ok ${OBJECTDIR}/_ext/1360937237/IDENT.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" -o ${OBJECTDIR}/_ext/1360937237/IDENT.o ../src/IDENT.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.ok ${OBJECTDIR}/_ext/1360937237/tempctrl.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ../src/tempctrl.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.ok ${OBJECTDIR}/_ext/1360937237/measure.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/measure.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d" -o ${OBJECTDIR}/_ext/1360937237/measure.o ../src/measure.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.ok ${OBJECTDIR}/_ext/1360937237/traps.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d" -o ${OBJECTDIR}/_ext/1360937237/traps.o ../src/traps.c     -save-temps
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.ok ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.err 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ../src/RotaryEncoder/RotaryEncoder.c     -save-temps
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.ok ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.err 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o ../src/RotaryEncoder/RotaryEncoder_cfg.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.ok ${OBJECTDIR}/_ext/1360937237/Crc16.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" -o ${OBJECTDIR}/_ext/1360937237/Crc16.o ../src/Crc16.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/MathTools.o: ../src/MathTools.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o.ok ${OBJECTDIR}/_ext/1360937237/MathTools.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/MathTools.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/MathTools.o.d" -o ${OBJECTDIR}/_ext/1360937237/MathTools.o ../src/MathTools.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/adc_drv.o: ../src/adc_drv.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o.ok ${OBJECTDIR}/_ext/1360937237/adc_drv.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc_drv.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc_drv.o ../src/adc_drv.c     -save-temps
	
else
${OBJECTDIR}/_ext/659864977/pid.o: ../src/pid/pid.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/659864977" 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o.d 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o.ok ${OBJECTDIR}/_ext/659864977/pid.o.err 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659864977/pid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/659864977/pid.o.d" -o ${OBJECTDIR}/_ext/659864977/pid.o ../src/pid/pid.c     -save-temps
	
${OBJECTDIR}/_ext/659864977/pid_cfg.o: ../src/pid/pid_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/659864977" 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o.ok ${OBJECTDIR}/_ext/659864977/pid_cfg.o.err 
	@${RM} ${OBJECTDIR}/_ext/659864977/pid_cfg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/659864977/pid_cfg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/659864977/pid_cfg.o.d" -o ${OBJECTDIR}/_ext/659864977/pid_cfg.o ../src/pid/pid_cfg.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.ok ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d" -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o ../src/DigitalIO.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.ok ${OBJECTDIR}/_ext/1360937237/main.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.ok ${OBJECTDIR}/_ext/1360937237/systmr.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/systmr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d" -o ${OBJECTDIR}/_ext/1360937237/systmr.o ../src/systmr.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.ok ${OBJECTDIR}/_ext/1360937237/task.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d" -o ${OBJECTDIR}/_ext/1360937237/task.o ../src/task.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.ok ${OBJECTDIR}/_ext/1360937237/sirem.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sirem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d" -o ${OBJECTDIR}/_ext/1360937237/sirem.o ../src/sirem.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.ok ${OBJECTDIR}/_ext/1360937237/PARLIST.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d" -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o ../src/PARLIST.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.ok ${OBJECTDIR}/_ext/1360937237/trace.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/trace.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d" -o ${OBJECTDIR}/_ext/1360937237/trace.o ../src/trace.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.ok ${OBJECTDIR}/_ext/1360937237/vuart.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/vuart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d" -o ${OBJECTDIR}/_ext/1360937237/vuart.o ../src/vuart.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.ok ${OBJECTDIR}/_ext/1360937237/statemachine.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d" -o ${OBJECTDIR}/_ext/1360937237/statemachine.o ../src/statemachine.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.ok ${OBJECTDIR}/_ext/1360937237/LCD.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d" -o ${OBJECTDIR}/_ext/1360937237/LCD.o ../src/LCD.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.ok ${OBJECTDIR}/_ext/1360937237/eeprom.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.ok ${OBJECTDIR}/_ext/1360937237/triac_control.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d" -o ${OBJECTDIR}/_ext/1360937237/triac_control.o ../src/triac_control.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.ok ${OBJECTDIR}/_ext/1360937237/IDENT.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d" -o ${OBJECTDIR}/_ext/1360937237/IDENT.o ../src/IDENT.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.ok ${OBJECTDIR}/_ext/1360937237/tempctrl.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d" -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o ../src/tempctrl.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.ok ${OBJECTDIR}/_ext/1360937237/measure.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/measure.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d" -o ${OBJECTDIR}/_ext/1360937237/measure.o ../src/measure.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.ok ${OBJECTDIR}/_ext/1360937237/traps.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/traps.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d" -o ${OBJECTDIR}/_ext/1360937237/traps.o ../src/traps.c     -save-temps
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.ok ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.err 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d" -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o ../src/RotaryEncoder/RotaryEncoder.c     -save-temps
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.ok ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.err 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d" -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o ../src/RotaryEncoder/RotaryEncoder_cfg.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.ok ${OBJECTDIR}/_ext/1360937237/Crc16.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d" -o ${OBJECTDIR}/_ext/1360937237/Crc16.o ../src/Crc16.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/MathTools.o: ../src/MathTools.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o.ok ${OBJECTDIR}/_ext/1360937237/MathTools.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/MathTools.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/MathTools.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/MathTools.o.d" -o ${OBJECTDIR}/_ext/1360937237/MathTools.o ../src/MathTools.c     -save-temps
	
${OBJECTDIR}/_ext/1360937237/adc_drv.o: ../src/adc_drv.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o.ok ${OBJECTDIR}/_ext/1360937237/adc_drv.o.err 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc_drv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -DROTARY_ENCODER_USED -I"../src/Common" -I"../src/include" -I"." -I"../src/RotaryEncoder" -I"../src/pid" -mlarge-code -mlarge-data -mconst-in-code -O1 -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc_drv.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc_drv.o ../src/adc_drv.c     -save-temps
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -o ${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-L".",-Map="${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.map",--report-mem,--cref$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
else
${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf -mcpu=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-L".",-Map="${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.map",--report-mem,--cref$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex ${DISTDIR}/SST40_V4.0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -omf=elf
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
