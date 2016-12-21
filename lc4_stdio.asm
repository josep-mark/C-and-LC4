;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Description: 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; This file has 1 big job:
;;;
;;; It defines "wrapper" subroutines for the TRAPS
;;; in os.asm.  The purpose of which is to provide
;;; a standard way of passing arguments to and from 
;;; the TRAPS in os.asm
;;;
;;; NOTE: each time we add a trap to os.asm
;;; we must create a 'wrapper' in this file
;;; if we wish to call that trap from our C programs
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;; WRAPPER SUBROUTINES FOLLOW ;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
.CODE
.ADDR x0010    ;; we start after line 10, to preserve USER_START


;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTC Wrapper ;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_putc

	;; prologue
	STR R7, R6, #-2	; save caller’s return address
	STR R5, R6, #-3	; save caller’s frame pointer
	ADD R6, R6, #-3 ; update stack pointer
	ADD R5, R6, #0	; update frame pointer
	; no local variables, so no need to allocate for them

	;; function body 

	; setup arguments for TRAP_PUTC:
	LDR R0, R5, #3	; copy param (c) from stack, into register R0
	TRAP x01        ; R0 has been set, so we can call TRAP_PUTC
	
	; TRAP_PUTC has no return value, so nothing to copy back to stack

	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_GETC Wrapper ;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;R6 is the user stack address at start of program

.FALIGN
lc4_getc
	;; prologue
	;; TO-DO: CIT 593 students, you must write the prologue
	STR R7, R6, #-2	;;Store callers return address
	STR R5, R6, #-3 ;;Store callers frame pointer
	ADD R6, R6, #-3	;;Update stack pointer
	ADD R5, R6, #0	;;Update frame pointer

	;; function body 
	;; TO-DO: CIT 593 students, you must write the body
	;;        1) call TRAP_GETC
	;;        2) Return the character in R0 back to the caller 
	;;	     by copying it to R7...see lc4_putc epilogue
	ADD R0, R5, #0	;;Set R0 equal to R5, to store R5's address
	TRAP x00		;;Call get_c
	ADD R7, R5, #0	;;Store Return of Getc in R7
	ADD R5, R0, #0	;;Reset value of R5
	
	;; epilogue
	;; TO-DO: CIT 593 students, you must write the epilogue
	
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_PUTS Wrapper ;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_puts
	;; prologue
	;; TO-DO: CIT 593 students, you must write the prologue
	STR R7, R6, #-2	;;Store callers return address
	STR R5, R6, #-3 ;;Store callers frame pointer
	ADD R6, R6, #-3	;;Update stack pointer
	ADD R5, R6, #0	;;Update frame pointer

	;; function body 
	;; TO-DO: CIT 593 students, you must write the body
	;;        1) copy address passed to lc4_puts() from stack
	;;	     to R0
	;;        2) call TRAP_PUTS
	LDR R0, R5, #3 	;;Get my_string1 pointer from the stack
	TRAP x08		;;Call TRAP_PUTS

	;; epilogue
	;; TO-DO: CIT 593 students, you must write the epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; TRAP_DRAW_BOX Wrapper ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.FALIGN
lc4_draw_box
	;; prologue
	;; TO-DO: CIT 593 students, you must write the prologue
	STR R7, R6, #-2	;;Store callers return address
	STR R5, R6, #-3 ;;Store callers frame pointer
	ADD R6, R6, #-3	;;Update stack pointer
	ADD R5, R6, #0	;;Update frame pointer

	;; function body 
	;; TO-DO: CIT 593 students, you must write the body
	;;        1) copy arguments to lc4_draw_box() 
	;;	     into the registers TRAP_DRAW_BOX expects
	;;	  		2) Save R5 and R6 to data memory
	;;        3) call TRAP_DRAW_BOX
	
	
	LDR R0,	R5, #3		;;x coord from frame
	LDR R1, R5, #4		;;y coord from frame
	LDR R2, R5, #5		;;length from frame
	LDR R3, R5, #6		;;2D array address from frame
	CONST R4,x01		;;set R4 to x2001 where we store R5
	HICONST R4, x20
	STR R5, R4, #0		;;Store R5
	STR R6, R4, #2		;;Store R6
	TRAP x0A			;;Call DrawBox Trap
	CONST R0, x01		;;Set R0 to x2001
	HICONST R0, x20		
	LDR R5, R0, #0		;;Reset R5
	LDR R6, R6, #2		;;Reset R6
	
	
	;; epilogue
	;; TO-DO: CIT 593 students, you must write the epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TRAP_GETS Wrapper ;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;R6 is the user stack address at start of program

.FALIGN
lc4_gets_asm
	;; prologue
	;; TO-DO: CIT 593 students, you must write the prologue
	STR R7, R6, #-2	
	STR R5, R6, #-3 
	ADD R6, R6, #-3	
	ADD R5, R6, #0	

	;; function body 
	LDR R1, R5, #3
	TRAP x10		;;Call get_s
	ADD R7, R1, #0	;;Store Return of Gets in R7
	
	
	;; epilogue
	;; TO-DO: CIT 593 students, you must write the epilogue
	
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET
