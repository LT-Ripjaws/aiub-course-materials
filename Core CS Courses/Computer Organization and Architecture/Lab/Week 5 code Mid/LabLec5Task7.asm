
.MODEL SMALL
.STACK 100H

.DATA
    CHAR_O DB 'o', '$'
    CHAR_E DB 'e', '$'

.CODE
MAIN PROC
    MOV AX, @DATA      ; Initialize data segment
    MOV DS, AX

    ; --- Test value in AL (you can change this) ---
    MOV AL, 2          ; Try 1, 2, 3, or 4

    ; --- Check for 1 or 3 ---
    CMP AL, 1
    JE PRINT_O

    CMP AL, 3
    JE PRINT_O

    ; --- Check for 2 or 4 ---
    CMP AL, 2
    JE PRINT_E

    CMP AL, 4
    JE PRINT_E

    JMP EXIT           ; Skip printing if not 1–4

PRINT_O:
    MOV DX, OFFSET CHAR_O
    MOV AH, 9
    INT 21H
    JMP EXIT

PRINT_E:
    MOV DX, OFFSET CHAR_E
    MOV AH, 9
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
