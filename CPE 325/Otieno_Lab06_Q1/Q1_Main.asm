;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
           	.ref	Debounce
           	.ref	SW1_sub
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
Setup:      
			; Configure Inputs: P1.0/P1.1.
			bic.b	#002h, &P1DIR

			; Configure Outputs: P2.1/P2.2.
            bis.b 	#002h, &P2DIR			; LED 2(0x0002).
			
            bis.w 	#GIE, SR              	; Enable global interrupts.
            bis.b 	#002h, &P1IES         	; Set interrupts to call from hi to low (SW1 and SW2).
            bis.b 	#002h, &P1IE          	; Enable port interrupts from bit 0.
			bic.b 	#002h, &P1IFG         	; Clear interrupt flag.
			call 	#SW1_sub                ; Call SW1 subroutine.
			
InfLoop:    jmp $							; Loop until interrupt.
;-------------------------------------------------------------------------------
; P1_ISR: Interrupt Service Routine (ISR)
;-------------------------------------------------------------------------------
P1_ISR:
			bic.w 	#GIE, SR              	; Disable interrupts while executing subroutine.
			bic.b 	#002h, &P1IFG         	; Clear interrupt flag for SW2.

chkS2:     	bit.b 	#002h, &P1IN          	; Check if SW2 is pressed (0000_0002 on P1IN).
            jnz 	l_exit              	; If not zero, SW2 is not pressed, re-check after loop.

            call	#Debounce				; Call Debounce subroutine.

			bit.b 	#002h, &P1IN          	; Verify SW2 is still pressed.
            jnz 	l_exit              	; if not, wait until pressed.
LED_ON:    	xor.b	#002, &P2OUT			; Toggle LED 2.
			
l_exit:		reti                        	; Return from interrupt.

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
            .sect	".int20"				;P1.x vector
            .short	P1_ISR

            .end
