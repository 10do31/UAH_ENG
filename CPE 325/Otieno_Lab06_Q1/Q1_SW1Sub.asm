;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    SW1_sub

            .text                           ; Assemble into program memory.
						
;-------------------------------------------------------------------------------
; Switch 1 Subroutine
;-------------------------------------------------------------------------------
SW1_sub:
           bis.b	#004h,&P2DIR           ; Set P2OUT to 0x0000_0100 (LEDS off)
InfLoop:   mov.w  	#0xFFFF, R5            ; Software delay (65,535*16cc/2^20 ~ 1s)

SWDelay1:   nop                             ; 1cc (total delay is 16 cc)
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            nop
            dec.w  R5                       ; 1cc
            jnz    SWDelay1                 ; 2cc

            xor.b  #004h, P2OUT             ; toggle LED 1.
            jmp    InfLoop                  ; goto InfLoop

            ret                         ; return from Subroutine.

            .end
