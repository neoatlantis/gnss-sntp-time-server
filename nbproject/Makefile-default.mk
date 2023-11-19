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
FINAL_IMAGE=${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=gnss/ubx_message_parser.c gnss/ubx_message_process.c interrupt/init.c interrupt/isr_uart1rx.c w5500/new.c w5500/spi.c w5500/udp_socket.c main.c uart.c spi.c coretime.c sntp/sntp.c interrupt/isr_int1.c w5500_control.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/gnss/ubx_message_parser.o ${OBJECTDIR}/gnss/ubx_message_process.o ${OBJECTDIR}/interrupt/init.o ${OBJECTDIR}/interrupt/isr_uart1rx.o ${OBJECTDIR}/w5500/new.o ${OBJECTDIR}/w5500/spi.o ${OBJECTDIR}/w5500/udp_socket.o ${OBJECTDIR}/main.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/coretime.o ${OBJECTDIR}/sntp/sntp.o ${OBJECTDIR}/interrupt/isr_int1.o ${OBJECTDIR}/w5500_control.o
POSSIBLE_DEPFILES=${OBJECTDIR}/gnss/ubx_message_parser.o.d ${OBJECTDIR}/gnss/ubx_message_process.o.d ${OBJECTDIR}/interrupt/init.o.d ${OBJECTDIR}/interrupt/isr_uart1rx.o.d ${OBJECTDIR}/w5500/new.o.d ${OBJECTDIR}/w5500/spi.o.d ${OBJECTDIR}/w5500/udp_socket.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/spi.o.d ${OBJECTDIR}/coretime.o.d ${OBJECTDIR}/sntp/sntp.o.d ${OBJECTDIR}/interrupt/isr_int1.o.d ${OBJECTDIR}/w5500_control.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/gnss/ubx_message_parser.o ${OBJECTDIR}/gnss/ubx_message_process.o ${OBJECTDIR}/interrupt/init.o ${OBJECTDIR}/interrupt/isr_uart1rx.o ${OBJECTDIR}/w5500/new.o ${OBJECTDIR}/w5500/spi.o ${OBJECTDIR}/w5500/udp_socket.o ${OBJECTDIR}/main.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/spi.o ${OBJECTDIR}/coretime.o ${OBJECTDIR}/sntp/sntp.o ${OBJECTDIR}/interrupt/isr_int1.o ${OBJECTDIR}/w5500_control.o

# Source Files
SOURCEFILES=gnss/ubx_message_parser.c gnss/ubx_message_process.c interrupt/init.c interrupt/isr_uart1rx.c w5500/new.c w5500/spi.c w5500/udp_socket.c main.c uart.c spi.c coretime.c sntp/sntp.c interrupt/isr_int1.c w5500_control.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=
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
${OBJECTDIR}/gnss/ubx_message_parser.o: gnss/ubx_message_parser.c  .generated_files/flags/default/dc2573ef1096ff67a0600312bc18c1737ecc1b7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/gnss" 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_parser.o.d 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/gnss/ubx_message_parser.o.d" -o ${OBJECTDIR}/gnss/ubx_message_parser.o gnss/ubx_message_parser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/gnss/ubx_message_process.o: gnss/ubx_message_process.c  .generated_files/flags/default/c808a7c9c5baa233dc05f6a756b080c953de4417 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/gnss" 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_process.o.d 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_process.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/gnss/ubx_message_process.o.d" -o ${OBJECTDIR}/gnss/ubx_message_process.o gnss/ubx_message_process.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/init.o: interrupt/init.c  .generated_files/flags/default/1f91782c6aa8dadfb135732756cc2f25171d9be2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/init.o.d 
	@${RM} ${OBJECTDIR}/interrupt/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/init.o.d" -o ${OBJECTDIR}/interrupt/init.o interrupt/init.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/isr_uart1rx.o: interrupt/isr_uart1rx.c  .generated_files/flags/default/13949f9d10194f59cf1c9bf55b6be58c64597a77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/isr_uart1rx.o.d 
	@${RM} ${OBJECTDIR}/interrupt/isr_uart1rx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/isr_uart1rx.o.d" -o ${OBJECTDIR}/interrupt/isr_uart1rx.o interrupt/isr_uart1rx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/new.o: w5500/new.c  .generated_files/flags/default/31fd336fa3cdea11e08fe90ca3687db8a47d8a1b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/new.o.d 
	@${RM} ${OBJECTDIR}/w5500/new.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/new.o.d" -o ${OBJECTDIR}/w5500/new.o w5500/new.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/spi.o: w5500/spi.c  .generated_files/flags/default/20d76ff8d94ba13e201f66956ab42853c7c4f0fd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/spi.o.d 
	@${RM} ${OBJECTDIR}/w5500/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/spi.o.d" -o ${OBJECTDIR}/w5500/spi.o w5500/spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/udp_socket.o: w5500/udp_socket.c  .generated_files/flags/default/479af62b8ff3011efab50009fe47a605b52f1fdc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o.d 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/udp_socket.o.d" -o ${OBJECTDIR}/w5500/udp_socket.o w5500/udp_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/6fe6c5503d8ea322d61217c0b5fcda752fbc2417 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/b8b6e250cc8f94a1863546d8ec11f2b606cb3a91 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/spi.o: spi.c  .generated_files/flags/default/c739eca7ec6362c610764657b91b7d76590eb03f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/coretime.o: coretime.c  .generated_files/flags/default/990777629e5ccbd9c2b34e6ad346d60ea4758e62 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/coretime.o.d 
	@${RM} ${OBJECTDIR}/coretime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/coretime.o.d" -o ${OBJECTDIR}/coretime.o coretime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/sntp/sntp.o: sntp/sntp.c  .generated_files/flags/default/c68f0d2b1db435a8aaf740ca8c44f3e0a2d903f8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sntp" 
	@${RM} ${OBJECTDIR}/sntp/sntp.o.d 
	@${RM} ${OBJECTDIR}/sntp/sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/sntp/sntp.o.d" -o ${OBJECTDIR}/sntp/sntp.o sntp/sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/isr_int1.o: interrupt/isr_int1.c  .generated_files/flags/default/9d7a9048db1593069e061f4acf3ebb1dcb08cfd5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/isr_int1.o.d 
	@${RM} ${OBJECTDIR}/interrupt/isr_int1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/isr_int1.o.d" -o ${OBJECTDIR}/interrupt/isr_int1.o interrupt/isr_int1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500_control.o: w5500_control.c  .generated_files/flags/default/da66d57dc54c308a026c1ba4e26821fda50d8ba7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/w5500_control.o.d 
	@${RM} ${OBJECTDIR}/w5500_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500_control.o.d" -o ${OBJECTDIR}/w5500_control.o w5500_control.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/gnss/ubx_message_parser.o: gnss/ubx_message_parser.c  .generated_files/flags/default/45cc951f65afd072e79ccea7613ba389dd5e511d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/gnss" 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_parser.o.d 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_parser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/gnss/ubx_message_parser.o.d" -o ${OBJECTDIR}/gnss/ubx_message_parser.o gnss/ubx_message_parser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/gnss/ubx_message_process.o: gnss/ubx_message_process.c  .generated_files/flags/default/aefefb2ff22ac6a9eb5b8277cdc45cf138251f77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/gnss" 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_process.o.d 
	@${RM} ${OBJECTDIR}/gnss/ubx_message_process.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/gnss/ubx_message_process.o.d" -o ${OBJECTDIR}/gnss/ubx_message_process.o gnss/ubx_message_process.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/init.o: interrupt/init.c  .generated_files/flags/default/1b577081b3641091916b49c4d1cdf3d9d4a0e262 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/init.o.d 
	@${RM} ${OBJECTDIR}/interrupt/init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/init.o.d" -o ${OBJECTDIR}/interrupt/init.o interrupt/init.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/isr_uart1rx.o: interrupt/isr_uart1rx.c  .generated_files/flags/default/419607cb42d91d222dbea2e486cc50feee05c8d3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/isr_uart1rx.o.d 
	@${RM} ${OBJECTDIR}/interrupt/isr_uart1rx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/isr_uart1rx.o.d" -o ${OBJECTDIR}/interrupt/isr_uart1rx.o interrupt/isr_uart1rx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/new.o: w5500/new.c  .generated_files/flags/default/69ce42e1eea42f6c91f7bde70251519003c97cf2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/new.o.d 
	@${RM} ${OBJECTDIR}/w5500/new.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/new.o.d" -o ${OBJECTDIR}/w5500/new.o w5500/new.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/spi.o: w5500/spi.c  .generated_files/flags/default/e22252111ff657783cc60d875345f946bae73539 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/spi.o.d 
	@${RM} ${OBJECTDIR}/w5500/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/spi.o.d" -o ${OBJECTDIR}/w5500/spi.o w5500/spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500/udp_socket.o: w5500/udp_socket.c  .generated_files/flags/default/76c63e0a8cd7abf2ac1d7d5546506d71ae9aa786 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/w5500" 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o.d 
	@${RM} ${OBJECTDIR}/w5500/udp_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500/udp_socket.o.d" -o ${OBJECTDIR}/w5500/udp_socket.o w5500/udp_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f7a6bfd7681bce3bbc1c47bfa32fb9dc98c639d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/8347a0e013733d35b5c39fa7a7e1754b834514ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/uart.o.d" -o ${OBJECTDIR}/uart.o uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/spi.o: spi.c  .generated_files/flags/default/2ffb063402968282c65c939147aff30d9cfcd2d8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/spi.o.d 
	@${RM} ${OBJECTDIR}/spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/spi.o.d" -o ${OBJECTDIR}/spi.o spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/coretime.o: coretime.c  .generated_files/flags/default/5694b4d3db89903866b89abaafa2f7acb51337a0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/coretime.o.d 
	@${RM} ${OBJECTDIR}/coretime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/coretime.o.d" -o ${OBJECTDIR}/coretime.o coretime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/sntp/sntp.o: sntp/sntp.c  .generated_files/flags/default/db14a0364b7b6caa024b745d03746e35da379414 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/sntp" 
	@${RM} ${OBJECTDIR}/sntp/sntp.o.d 
	@${RM} ${OBJECTDIR}/sntp/sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/sntp/sntp.o.d" -o ${OBJECTDIR}/sntp/sntp.o sntp/sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/interrupt/isr_int1.o: interrupt/isr_int1.c  .generated_files/flags/default/82b8d8ff257dced01233003dc45d8e15639c1097 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/interrupt" 
	@${RM} ${OBJECTDIR}/interrupt/isr_int1.o.d 
	@${RM} ${OBJECTDIR}/interrupt/isr_int1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/interrupt/isr_int1.o.d" -o ${OBJECTDIR}/interrupt/isr_int1.o interrupt/isr_int1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/w5500_control.o: w5500_control.c  .generated_files/flags/default/a191828185559d98eef82c8a6baaf87ce47c3056 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/w5500_control.o.d 
	@${RM} ${OBJECTDIR}/w5500_control.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/w5500_control.o.d" -o ${OBJECTDIR}/w5500_control.o w5500_control.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/0006-gnss-sntp-server.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
