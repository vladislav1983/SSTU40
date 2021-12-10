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
MP_LINKER_FILE_OPTION=,--script=p30F4013.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  .generated_files/cd25a11eab301d5bc5151f89fa23a1e8a2769a97.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  .generated_files/91c295e1b18e92ee807b396acf35fc3d24a966bb.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  .generated_files/6c03211c0ae7da400a31ef119de7dee8abb79042.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/821bc4e0cdaee7546b900a6654423e02f6a4780c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  .generated_files/65bf5341a5a85810fab9ebabcbdaeec49a0f32b0.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/fabc771735694d3c51becd8cd89a56293a07c67a.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/87d97911abf10ead28873c3e5ccdb4f21eae0d1f.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  .generated_files/9717762aecfd166ba192d9ff1731b40f1696e43c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  .generated_files/4c1abf4a9a7fa871a0f87834fe1b78c50a5ee920.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  .generated_files/1e3a65ac2b0f1457fd5288c5474134b01dda6ca4.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  .generated_files/8e645d2340342e0511c55f5ba3342dc15931b85a.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  .generated_files/9e83c7140f3e81fdd4b1333227303e1eeb8b0b0f.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  .generated_files/8026f6756e1ac0c6f60ffb66bbc427b25dc83dea.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  .generated_files/c53c782524deab047d7a88f68aa2851ed3cec4f0.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  .generated_files/1d3fef8c4f067a4af82331fbda7e22ee59f6fe70.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  .generated_files/c2d2d84162fe4ed23afbb6cc5f1ce69da50b0bf4.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  .generated_files/6f4f6bd127ab9a96166acb6827322000f8aac9f0.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  .generated_files/98bbd4dba7c7f201c77b7f723794c2ac258de438.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  .generated_files/16689e75d4131dcb45012aefe32badf649f378b3.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  .generated_files/50eab63932934912e1cd8b1ee6a953fd5e8bf305.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1360937237/Crc16.o: ../src/Crc16.c  .generated_files/f74213c84bd5589c3311058a8cab4ccf1b9450d8.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Crc16.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Crc16.c  -o ${OBJECTDIR}/_ext/1360937237/Crc16.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Crc16.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/DigitalIO.o: ../src/DigitalIO.c  .generated_files/3748827926ea5e97fe3b13a730c970d7827319dd.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DigitalIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/DigitalIO.c  -o ${OBJECTDIR}/_ext/1360937237/DigitalIO.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/DigitalIO.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/IDENT.o: ../src/IDENT.c  .generated_files/de985c4a16f98527b7704adf759ebf14126690fc.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/IDENT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/IDENT.c  -o ${OBJECTDIR}/_ext/1360937237/IDENT.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/IDENT.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/LCD.o: ../src/LCD.c  .generated_files/9f9a886093d11c54078ce713e2dd37214f8aa41c.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/LCD.c  -o ${OBJECTDIR}/_ext/1360937237/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/LCD.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/PARLIST.o: ../src/PARLIST.c  .generated_files/e09379bd0f52c0c48eb77b1e5d8082e7aa1c064.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/PARLIST.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/PARLIST.c  -o ${OBJECTDIR}/_ext/1360937237/PARLIST.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/PARLIST.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  .generated_files/19c9cf35314c5fba1680e61f5ba1fcf0835c56e9.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/eeprom.c  -o ${OBJECTDIR}/_ext/1360937237/eeprom.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/e7e71d0299f4e86e770e6c23e48113fed75e87f2.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/measure.o: ../src/measure.c  .generated_files/e75fe4926c11f1a38b684572f62eb56a3d5db276.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/measure.c  -o ${OBJECTDIR}/_ext/1360937237/measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/measure.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/sirem.o: ../src/sirem.c  .generated_files/ecbd355f05189402fe2ec9200558200bcf589d12.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sirem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/sirem.c  -o ${OBJECTDIR}/_ext/1360937237/sirem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sirem.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/statemachine.o: ../src/statemachine.c  .generated_files/3ae8e13df6e4bcc68d44199f8ac8ca608fa232a4.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/statemachine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/statemachine.c  -o ${OBJECTDIR}/_ext/1360937237/statemachine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/statemachine.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/systmr.o: ../src/systmr.c  .generated_files/8665c00837c734005361c76710152609d957335e.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/systmr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/systmr.c  -o ${OBJECTDIR}/_ext/1360937237/systmr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/systmr.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/task.o: ../src/task.c  .generated_files/cf9a6317f6572eea3a8bde75fdeb73062745a6f3.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task.c  -o ${OBJECTDIR}/_ext/1360937237/task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/task.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/tempctrl.o: ../src/tempctrl.c  .generated_files/54a93c9e1c624756139a43202d6a0c3417154869.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tempctrl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/tempctrl.c  -o ${OBJECTDIR}/_ext/1360937237/tempctrl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/tempctrl.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/trace.o: ../src/trace.c  .generated_files/3fa87c9b737873a3d7d03918d437b5a1b6ac26ea.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/trace.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/trace.c  -o ${OBJECTDIR}/_ext/1360937237/trace.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/trace.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/traps.o: ../src/traps.c  .generated_files/c7087380dc162fa61495b1c63d95aa62319f52c1.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/traps.c  -o ${OBJECTDIR}/_ext/1360937237/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/traps.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/triac_control.o: ../src/triac_control.c  .generated_files/c083371fcbacc0c69381ea31674109c6eaf6e883.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/triac_control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/triac_control.c  -o ${OBJECTDIR}/_ext/1360937237/triac_control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/triac_control.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vADC.o: ../src/vADC.c  .generated_files/7c3dd6b5d95bc9e0b5bc61d719bafa5e629e7736.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vADC.c  -o ${OBJECTDIR}/_ext/1360937237/vADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vADC.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/vuart.o: ../src/vuart.c  .generated_files/5fb9c7f4aef9a7fe1d9ac552c5a4a6514a8f67ec.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vuart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/vuart.c  -o ${OBJECTDIR}/_ext/1360937237/vuart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vuart.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o: ../src/RotaryEncoder/RotaryEncoder.c  .generated_files/c26049cdfda6ccb9ed406efed5a5e29caa162329.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o: ../src/RotaryEncoder/RotaryEncoder_cfg.c  .generated_files/4d57f1e1c4b26f688447cee49061cdc7fec7612e.flag .generated_files/1f86111673f91e2931a693fcfeca40bc5621ed0.flag
	@${MKDIR} "${OBJECTDIR}/_ext/2014683921" 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d 
	@${RM} ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/RotaryEncoder/RotaryEncoder_cfg.c  -o ${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/2014683921/RotaryEncoder_cfg.o.d"        -g -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include" -O1 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DROTARY_ENCODER_USED -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -I"../src" -I"../src/Common" -I"../src/RotaryEncoder" -I"../src/include"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SSTU_X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
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
