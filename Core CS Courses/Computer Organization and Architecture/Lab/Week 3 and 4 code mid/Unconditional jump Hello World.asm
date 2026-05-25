.MODEL SMALL
.STACK 100H

.DATA
    msg DB 'Hello World', 0Dh, 0Ah, '$'  ; message with newline and string terminator

.CODE
MAIN PROC
    MOV AX, @DATA    ; initialize DS
    MOV DS, AX

start:
    MOV AH, 9        ; DOS function to print string
    LEA DX, msg      ; load address of msg
    INT 21H          ; call DOS interrupt to print string

    JMP start        ; unconditional jump back to start to print again infinitely

MAIN ENDP
END MAIN
