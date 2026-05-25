.MODEL SMALL     ; Use the small memory model (code and data in one segment)
.STACK 100H      ; Reserve 256 bytes for the stack

.DATA            ; Data section starts here

MSG_WELCOME DB 0AH,0DH, "HELLO WORLD!$"      ; Welcome message
MSG_ENTER1  DB 0AH,0DH, "ENTER NUMBER 1: $"  ; Prompt for first number
MSG_ENTER2  DB 0AH,0DH, "ENTER NUMBER 2: $"  ; Prompt for second number
MSG_RESULT  DB 0AH,0DH, "RESULT IS: $"       ; Message before displaying result

.CODE  ; Code section starts here
MAIN PROC
    ; Initialize data segment
    MOV AX, @DATA
    MOV DS, AX  

    ; Display welcome message
    MOV AH, 9          ; DOS function: Print string
    LEA DX, MSG_WELCOME 
    INT 21H            ; Call DOS interrupt

    ; Prompt for first number
    MOV AH, 9          ; DOS function: Print string
    LEA DX, MSG_ENTER1
    INT 21H            ; Call DOS interrupt

    ; Read first number from user
    MOV AH, 1          ; DOS function: Read character
    INT 21H            ; Call DOS interrupt
    MOV BH, AL         ; Store first number in BH

    ; Prompt for second number
    MOV AH, 9          ; DOS function: Print string
    LEA DX, MSG_ENTER2
    INT 21H            ; Call DOS interrupt

    ; Read second number from user
    MOV AH, 1          ; DOS function: Read character
    INT 21H            ; Call DOS interrupt
    MOV CH, AL         ; Store second number in CH

    ; Display "RESULT IS:" message
    MOV AH, 9          ; DOS function: Print string
    LEA DX, MSG_RESULT
    INT 21H            ; Call DOS interrupt

    ; Convert ASCII to integer (Subtract 30H)
    SUB BH, 30H        ; Convert first number from ASCII to integer
    SUB CH, 30H        ; Convert second number from ASCII to integer

    ; Perform subtraction
    SUB BH, CH         ; BH = BH - CH

    ; Convert result back to ASCII (Add 30H)
    ADD BH, 30H        ; Convert result to ASCII

    ; Display the result
    MOV AH, 2          ; DOS function: Print character
    MOV DL, BH         ; Load result into DL
    INT 21H            ; Call DOS interrupt

    ; Exit program
    MOV AH, 4CH        ; DOS function: Terminate program
    INT 21H            ; Call DOS interrupt

MAIN ENDP
END MAIN