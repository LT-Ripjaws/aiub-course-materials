.MODEL SMALL
.STACK 100H

.DATA
    MSG_WELCOME DB 0AH,0DH, "HELLO WORLD!$"
    MSG_INPUT1  DB 0AH,0DH, "ENTER FIRST NUMBER: $"
    MSG_INPUT2  DB 0AH,0DH, "ENTER SECOND NUMBER: $"
    MSG_OUTPUT  DB 0AH,0DH, "YOU ENTERED: $"

    NUM1 DB 0, 0   ; Two digits for first number (e.g., '1' and '0')
    NUM2 DB 0, 0   ; Two digits for second number
    ; Define Byte — it reserves 1 byte of memory for each value you specify.
    ; DB 0, 0 means reserve 2 bytes and initialize both to 0.
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Show welcome
    MOV AH, 9
    LEA DX, MSG_WELCOME
    INT 21H

    ; ---------- Input First Number ----------
    MOV AH, 9
    LEA DX, MSG_INPUT1
    INT 21H

    ; Read first digit
    MOV AH, 1
    INT 21H
    MOV NUM1, AL       ; Store first digit (e.g., '1')

    ; Read second digit
    MOV AH, 1
    INT 21H
    MOV NUM1+1, AL     ; Store second digit (e.g., '0')

    ; Read Enter (optional)
    MOV AH, 1
    INT 21H            ; Eat the Enter key (carriage return)

    ; ---------- Input Second Number ----------
    MOV AH, 9
    LEA DX, MSG_INPUT2
    INT 21H

    ; Read first digit
    MOV AH, 1
    INT 21H
    MOV NUM2, AL       ; Store first digit

    ; Read second digit
    MOV AH, 1
    INT 21H
    MOV NUM2+1, AL     ; Store second digit

    ; Read Enter (optional)
    MOV AH, 1
    INT 21H

    ; ---------- Show the result ----------
    MOV AH, 9
    LEA DX, MSG_OUTPUT
    INT 21H

    ; Print NUM1 digits
    MOV AH, 2
    MOV DL, NUM1
    INT 21H
    MOV DL, NUM1+1
    INT 21H

    ; Print space
    MOV DL, 20H
    INT 21H

    ; Print NUM2 digits
    MOV DL, NUM2
    INT 21H
    MOV DL, NUM2+1
    INT 21H

    ; Exit program
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
