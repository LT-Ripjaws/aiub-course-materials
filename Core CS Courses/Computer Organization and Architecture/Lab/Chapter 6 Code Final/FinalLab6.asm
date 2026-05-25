.MODEL SMALL
.STACK 100H

.DATA
    STAR DB '*'

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Initialize CX to 80 (loop counter)
    MOV CX, 80

PRINT_LOOP:
    ; Print the star
    MOV AH, 02H
    MOV DL, STAR
    INT 21H

    ; Decrement CX and loop
    LOOP PRINT_LOOP

    ; Exit program
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
