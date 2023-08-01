;*------------------------------------------------------------------------------
;* File:        Lab4Asm2.asm
;* Function:    This assembly code will read a string and evaluate it as a math expression.
;* Description: This program reads a string, determines add or subtract characters and
;*              performs the corresponding operation (addition or subtraction).
;* Input:       None.
;* Output:      Caluclation result in P2OUT.
;* Author(s):   Dan Otieno, dpo0002@uah.edu
;* Date:        February 5th, 2022.
;* ---------------------------------------------------------------------------
;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.

myStr:		.cstring "6-3+5+3"
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer

;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
main:		; bis.b	#0FFh,&P2DIR
			mov.w 	#myStr, R4				; Load starting address of the string into R4.
			mov.b	@R4+, R5				; Result will be stored in R5.
			sub.b	#48, R5					; Read R5 as int data type, set to 0.


gnext:		mov.b	@R4+, R6				; Get a new character.
			cmp		#0, R6					; Check if null character.
			jeq		lend					; If it is, go to the end.
			mov.b	@R4+, R7				; Get next character and store in R7.
			sub.b	#48, R7					; Read character as integer data type, set to 0.
			cmp		#'+', R6				; Check if Character is '+'.
			jeq		SumS					; If it is, jump to SumS function (for addition).
			cmp		#'-', R6				; Check if character is '-'.
			jeq		DiffS					; If it is, jump to DiffS function (for subtraction).

SumS:		add.b	R7, R5					; Perform addition, store result in R5.
			jmp		gnext

DiffS:		sub.b	R7, R5					; Perform subtraction, store result in R5.
			jmp		gnext

lend:		mov.b 	R5,&P2OUT				; Output in P2OUT;
			bis.w	#LPM4, SR				; LPM4
			nop								; required for debugger

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
