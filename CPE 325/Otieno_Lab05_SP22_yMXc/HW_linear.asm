;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    HW_linear
            .text                           ; Assemble into program memory.
HW_linear:
			push	R8
			push	R6
			push	R5
			push	R4

			mov.w 	12(SP), R4 		; Retrieve array lengths
			mov.w 	10(SP), R5 		; Array X, input array starting address
			mov.w 	8(SP), R8 		; Array Y to store result, starting address

hw_mul:		mov.w 	@R5+, &MPY 		; HW multiplier operation, retrieve element from array X.
			mov.w 	R6, &OP2 		; Retrieve integer register.
			nop
			nop
			nop
			mov.w 	&RESLO, 0(R8)	; Multiplication result into array Y.
			dec.w 	R4
			jnz 	hw_mul

			pop 	R4				; Collapse stack and
			pop 	R5
			pop		R6
			pop		R8

			ret

			.end
