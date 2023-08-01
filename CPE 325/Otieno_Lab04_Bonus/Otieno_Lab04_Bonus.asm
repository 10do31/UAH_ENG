/*------------------------------------------------------------------------------
 * File:        Lab04_Bonus.asm
 * Function:    This assembly code will read a string and convert lowercase charcters to uppercase.
 * Description: This program reads and converts the lowercase characters in a hard-coded string to
 *              uppercase. Result is displayed in memory browser window.
 * Input:       None.
 * Output:      Demo conversion from lower to upper in memory browser.
 * Author(s):   Dan Otieno, dpo0002@uah.edu
 * Date:        February 5th, 2022.
 * ---------------------------------------------------------------------------*/
;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                           	; make it known to linker.
			.data
myStr: 		.cstring 	"I enjoy learning msp430"
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
main:		; bis.b   #0FFh,&P1DIR          ; do not output the result on port pins.
			mov		#myStr, R4				; Load starting address of the string into R4.

gnext:		mov.b	@R4+, R6				; Get a new character.
			cmp		#0, R6					; Check if null character.
			jeq		lend					; If yes, go to the end.
			cmp.b	#91, R6					; Use ASCII value to check if character is uppercase.
			jl		gnext					; If value is less than last uppercase character, check next character.
			jmp		low2up					; Jump to loop to check for lowercase.

low2up:		cmp.b	#97, R6					; Check if character is lowercase.
			jl		gnext					; If not, check next character.
			sub.b	#32, R6					; If yes, convert lowercase to uppercase.
			mov.b	R6, -1(R4)				; Store result back to R4.
			jmp		gnext



lend:		mov.b 	R4, &P2OUT				; Send output to P2OUT but display result in memory browser.
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
            
