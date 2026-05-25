.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC
    ; Example: put a test value in AL
    MOV AL, -5          ; You can change this to test with other values

    ; Compare AL with 0 (signed comparison)
    CMP AL, 0           
    JL SET_FF           ; If AL < 0 (signed), jump to SET_FF

    ; ELSE part
    MOV AH, 0
    JMP END_IF

SET_FF:
    MOV AH, 0FFh        ; Set AH = FFh

END_IF:
    MOV AH, 4CH         ; Exit program
    INT 21H

MAIN ENDP
END MAIN
