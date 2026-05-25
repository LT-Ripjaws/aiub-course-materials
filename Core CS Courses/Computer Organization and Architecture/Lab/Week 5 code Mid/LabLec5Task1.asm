
.MODEL SMALL
.STACK 100H

.CODE
MAIN PROC
    MOV AX, -5      ; Example value (you can change this)
    
    CMP AX, 0       ; Compare AX with 0
    JL LESS_THAN_0  ; Jump if AX < 0 (signed)

    JMP END_PROGRAM ; Skip BX = -1 if AX is not less than 0

LESS_THAN_0:
    MOV BX, -1      ; Set BX = -1

END_PROGRAM:
    MOV AH, 4CH     ; Exit program
    INT 21H

MAIN ENDP
END MAIN
