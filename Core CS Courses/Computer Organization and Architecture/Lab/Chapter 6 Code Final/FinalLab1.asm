.MODEL SMALL
.STACK 100H

.DATA
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Simulate a test value
    MOV AX, -5          ; Set AX to a negative number (try 0 or positive to test else path)

    ; IF AX < 0
    CMP AX, 0           ; Compare AX with 0
    JGE ELSE_BRANCH     ; Jump if AX >= 0 (i.e., not less than)

    ; THEN: AX < 0, so set BX = -1
    MOV BX, -1
    JMP END_IF

ELSE_BRANCH:
    ; ELSE: BX = 0
    MOV BX, 0

END_IF:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
