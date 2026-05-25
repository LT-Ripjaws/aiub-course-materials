.MODEL SMALL
.STACK 100H

.DATA
    msgLess DB 0Dh, 0Ah, 'Less than 5.$'
    msgGreater DB 0Dh, 0Ah, 'Greater than 5.$'
    msgEqual DB 0Dh, 0Ah, 'Equal to 5.$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Read 1-digit number from user
    MOV AH, 1
    INT 21H        ; AL = ASCII code of entered digit
    SUB AL, '0'    ; Convert ASCII to number (0–9)

    ; Compare with 5
    MOV CL, 5
    CMP AL, CL
    JL LESS
    JG GREATER
    JE EQUAL

EQUAL:
    MOV AH, 9
    LEA DX, msgEqual
    INT 21H
    JMP ENDING

LESS:
    MOV AH, 9
    LEA DX, msgLess
    INT 21H
    JMP ENDING

GREATER:
    MOV AH, 9
    LEA DX, msgGreater
    INT 21H

ENDING:
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
