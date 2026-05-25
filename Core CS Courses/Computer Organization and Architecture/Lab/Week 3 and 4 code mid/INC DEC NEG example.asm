.MODEL SMALL
.STACK 100H

.DATA
    msgPositive DB 0Dh, 0Ah, 'You entered a positive number.$'
    msgZero     DB 0Dh, 0Ah, 'You entered zero.$'
    msgNegated  DB 0Dh, 0Ah, 'Negated value calculated.$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Read a single-digit number
    MOV AH, 1
    INT 21H         ; AL = ASCII of input
    SUB AL, '0'     ; Convert to numeric (0-9)

    ; Save original in BL
    MOV BL, AL

    ; Increment
    INC AL          ; AL = AL + 1
    ; Decrement (go back to original)
    DEC AL          ; AL = AL - 1

    ; Check for zero
    CMP AL, 0
    JZ SHOW_ZERO

    ; Otherwise it's positive
    MOV AH, 9
    LEA DX, msgPositive
    INT 21H
    JMP DO_NEG

SHOW_ZERO:
    MOV AH, 9
    LEA DX, msgZero
    INT 21H

DO_NEG:
    ; Now do NEG on BL (original value)
    MOV AL, BL
    NEG AL          ; AL = -AL

    ; Just to show we did negation
    MOV AH, 9
    LEA DX, msgNegated
    INT 21H

    ; Exit
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
