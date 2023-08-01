;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                           	; make it known to linker.
			.ref	HW_linear
			.ref    SW_linear
;-------------------------------------------------------------------------------
;							USER DATA
;-------------------------------------------------------------------------------
					.data
;var_C:		.int	111
var_M:		.int	13
arrayX:		.int	1,2,4,7,31,-29,-5,100		; Input: Array X.
arraY:		.int	0,0,0,0,0,0,0,0,0,0
arraySW:	.int	0,0,0,0,0,0,0,0,0,0
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
main:
			mov.w	#var_M, R6
			;mov.w	#var_C, R7

			push	#10
			push 	#arrayX					; Push the number of elements.
			push	#arraY
			call	#HW_linear				; Call HW_linear.
			inc.w	R8
			add.w	#8, SP					; Collapse the stack.

			push	#10
			push 	#arrayX					; Push the number of elements.
			push	#arraySW
			call	#SW_linear				; Call HW_linear.
			inc.w	R8
			add.w	#8, SP					; Collapse the stack.

			jmp		$
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
            
