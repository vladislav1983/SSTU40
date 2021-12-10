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
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  .generated_files/bb5b58ae411c54b9c5a2782b6277885d71bc54d9.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  .generated_files/9e4f48bd32cdb171ee03f2e539f680ac53150894.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  .generated_files/1fc6d5a499bdd3c588789e43345c966cc363de2c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/74db5ded538918b07341aa0521e0cb807d959d6d.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  .generated_files/97571e71a924a80b74b90af2e38ced9fd422e74.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/f990f058140888ee4acd0a09c7a81aa6c97726f1.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/886b4a0a47dcc18b08c65fd4adfc92cda954238c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  .generated_files/a3c49c4729f6474e3d74fe3e75f314eeec1958fe.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  .generated_files/a6b6624d698e6a7d30f77b7bb52c9c696f07b12a.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  .generated_files/48de795f2b7b18efad2951ed81f14c02e17106f5.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  .generated_files/bba51d859d5de04158be6a311512ec3b4e02a60a.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  .generated_files/13be3b9d34379f46a7a4401afdd681579e26c6e6.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  .generated_files/71ecada43a97c8a2dad279b62236184a9bc7997e.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  .generated_files/29ad8e5ff869d25f579dec76051ea50a0efa30db.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  .generated_files/514ce38fd2db24a15cc0173401ecb61af702d510.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  .generated_files/b2e5ee3e800a1d74a47b16240b4e919b79b01d97.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  .generated_files/f7ffdf29cbe4621f810a247ed12286e1da659477.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  .generated_files/ddf32eae0a8314111b638a35c6aeb0b0cb86a55d.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  .generated_files/d6d5e95106f29f226205941a7d3214c54a07cf6c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  .generated_files/402092936f597171f5a3ae6dc0ee1b28698f6609.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  .generated_files/bc55eb885aa16f02fd09b0d01666fd614c287c6d.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  .generated_files/2d7e9a2c2cadb3c9bafc3c7e172e38483e85131c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  .generated_files/20d182171059b4611f351a118da327aa3dd3d2f9.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/edf60f91c3f132014adee49d106704fcd6fe5c09.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  .generated_files/8dc3027e53bdb440c6136772c9f18250182df7d9.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/a4497837ff72613d8dc81e1cf81bb04f4f114e0.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/d9693846108ede452cc2ee7ca37408cb8b166fca.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  .generated_files/ff0b4eaaa17ddc555803779605bc0fa28b54cf62.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  .generated_files/c2bfb7b1b26d2416b9ad150e6ac7eee5cdb5bab3.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  .generated_files/4da77f412baace879d9172f39b6ca6e41559e7a1.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  .generated_files/8efba34955cc67fbc0bedaf1b56f997ee4eaadae.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  .generated_files/29e21bde63a6b3c1a2eb7c929ad3238827d8f75c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  .generated_files/e0df911f0baae584d3897073c811348e29db475f.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  .generated_files/4774e6a9bdc92751f5788a2dff09dea8bfb3538f.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  .generated_files/84278c83d1d74e8f41f3e6cd296a2db0e381d993.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  .generated_files/76e3ccd500d0aad9b3cbcb45b05a843c32c4e283.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  .generated_files/98db136cb37222ca843c105414eb18375daa27ea.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  .generated_files/ca566183301a3acdc7aad06083ae33477ccca884.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  .generated_files/d7f20ceee96e4d41d3f5f6e288ce54f67f5f8f69.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  .generated_files/49d2c312f9e350075458a35cd987967adb8f1efd.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -msmall-data -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
