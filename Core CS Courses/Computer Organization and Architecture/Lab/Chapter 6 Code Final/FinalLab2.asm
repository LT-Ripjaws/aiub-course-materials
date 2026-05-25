.MODEL SMALL
.STACK 100H

.DATA
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Set test value in AL (you can change this to try different cases)
    MOV AL, -5         ; Example: negative value to trigger AH = FFh

    ; Check: IF AL < 0
    CMP AL, 0
    JGE ELSE_BRANCH    ; Jump if AL >= 0 (i.e., NOT less than)

    ; THEN: AL < 0 ? AH = FFh
    MOV AH, 0FFh
    JMP END_IF

ELSE_BRANCH:
    ; ELSE: AH = 00h
    MOV AH, 00h

END_IF:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
