;*------------------------------------------------------------------------------
;* File:        Lab4Asm1.asm
;* Function:    This assembly code will count the words and sentences in a given string.
;* Description: This program counts and returns the number of words and sentences in a given string
;*              which is hard-coded.
;* Input:       None.
;* Output:      Number of words, in P1OUT, number of sentences, in P2OUT.
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

myStr:		.cstring	"Sentence one. Sentence two? Sentence three!"
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.
			.data
w_count:	.int		0
s_count:	.int		0

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
main:		; bis.b		#OFFh, &P1DIR		; Do not output result on port pins.
			mov.w	#myStr, R4			; Load starting address of the string into R4.
			mov.w	#w_count, R7
			mov.w	#s_count, R8
			clr.b	R7					; Clear bit for Words counter.
			clr.b	R8					; Clear bit for Sentence counter.

gnext:		mov.b	@R4+, R6			; Get a new character.
			cmp		#0,R6				; Check if null character.
			jeq		lend				; If yes, jump to the end.
			cmp.b	#' ',R6				; Check if character is a space.
			jne		Dot					; If it is not, jump to loop to check for '.'.
			inc.w	R7					; If it is increment word count.
			jmp		gnext				; Go to the next character.

Dot:		cmp.b	#'.',R6				; Check for '.' character.
			jne		Qmark				; If is not, check next character.
			inc.w	R7					; Count as full word, incerement word count.
			inc.w	R8			  		; If it is, increment sentence count.
			jmp		gnext				; Go to the next character.

Qmark:		cmp.b	#'?',R6				; Check for '?' character.
			jne		Exclam				; If not, check next character.
			inc.w	R8					; If it is, increment sentence count.
			jmp		gnext				; Go to the next character.


Exclam:		cmp.b	#'!',R6				; Check for '!' character.
			jne		gnext				; If not, check next character.
			inc.w	R8					; If it is, increment sentence count.
			jmp		gnext				; Go to the next character.

lend:		mov.b	&P1OUT, R7			; Write word count result in P1OUT.
 			mov.b	&P2OUT, R8			; Write sentence count result in P2OUT.
 			bis.w	#LPM4,SR			; LPM4.
 			nop							; For debugger.

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
            
