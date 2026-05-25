.MODEL SMALL
.STACK 100H

.DATA
    A DB "HELLO WORLD$"  ; String to display
    B DB "HELLO$"        ; Another string to display
    NEWLINE DB 0AH, 0DH, '$'  ; Newline (Carriage return + Line feed)

.CODE
MAIN PROC
    MOV AX, @DATA   ; Load data segment
    MOV DS, AX

    ; 1. Take single input from user
    MOV AH, 1       ; DOS Interrupt 21h, function 1 (input single character)
    MOV AL, AH
    INT 21H         ; Read character from keyboard (stores in AL) 
     
    

    ; 2. Show single output
    MOV DL, AL      ; Move input character to DL for output
    MOV AH, 2       ; DOS Interrupt 21h, function 2 (output single character)
    INT 21H         ; Display character

    ; 9. Display string output
    LEA DX, NEWLINE  ; Print a newline
    MOV AH, 9
    INT 21H

    LEA DX, A  ; Load address of A (HELLO WORLD)
    MOV AH, 9         ; DOS Interrupt 21h, function 9 (print string)
    INT 21H           ; Print string

    LEA DX, NEWLINE  ; Print another newline
    MOV AH, 9
    INT 21H

    LEA DX, B  ; Load address of B (HELLO)
    MOV AH, 9         ; DOS Interrupt 21h, function 9
    INT 21H           ; Print string

    ; Exit program
    MOV AH, 4CH       ; DOS Interrupt 21h, function 4Ch (exit program)
    INT 21H

MAIN ENDP
END MAIN