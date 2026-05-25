.MODEL SMALL
.STACK 100H

.DATA
    MSG_WELCOME DB 0AH,0DH, "HELLO WORLD!$"
    MSG_ENTER1  DB 0AH,0DH, "ENTER NUMBER 1: $"
    MSG_ENTER2  DB 0AH,0DH, "ENTER NUMBER 2: $"
    MSG_SHOW    DB 0AH,0DH, "YOU ENTERED: $"

.CODE
MAIN PROC
    MOV AX, @DATA     ; Set up data segment
    MOV DS, AX

    ; Show welcome message
    MOV AH, 9
    LEA DX, MSG_WELCOME
    INT 21H

    ; Ask for first number
    MOV AH, 9
    LEA DX, MSG_ENTER1
    INT 21H

    MOV AH, 1         ; Read first number
    INT 21H
    MOV BH, AL        ; Store in BH

    ; Ask for second number
    MOV AH, 9
    LEA DX, MSG_ENTER2
    INT 21H

    MOV AH, 1         ; Read second number
    INT 21H
    MOV CH, AL        ; Store in CH

    ; Show the message "YOU ENTERED:"
    MOV AH, 9
    LEA DX, MSG_SHOW
    INT 21H

    ; Display first number
    MOV AH, 2
    MOV DL, BH
    INT 21H

    ; Display space between numbers
    MOV DL, 20H       ; ASCII for space
    INT 21H

    ; Display second number
    MOV AH, 2
    MOV DL, CH
    INT 21H

    ; Exit program
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
