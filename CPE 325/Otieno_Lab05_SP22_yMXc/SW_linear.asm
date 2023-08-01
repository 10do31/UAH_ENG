;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    SW_linear
            .text                           ; Assemble into program memory.
SW_linear:
				push 	R9
				push 	R10
				push 	R11
				push 	R12
									; Retrieve parameters from stack
				mov.w 	16(SP), R4	; Retrieve array length.
				mov.w 	14(SP), R5	; ArrayX address.
				mov.w 	12(SP), R7	; ArraySW address.

gnext:			clr.w 	R12
				mov.w 	@R5+, R9 		; point array X address to R9.
				mov.w 	@R6+, R10		; point R6 to R10.

sw_mul:			bit.w	#1, R10
				jz		sft
				add.w	R9,R12

sft:			rla.w	R9
				rra.w	R10
				dec.w	R11
				jnz		sw_mul
				bit.w	#1, R10
				jz		lend

lend:			mov.w	R12, 0(R7)
				dec.w	R4
				jnz		gnext

				pop 	R12				;
				pop 	R11				;
				pop 	R10
				pop 	R9

				ret

				.end
