.MODEL SMALL
.STACK 100H

.DATA
    helloMsg DB 'Hello World', 0Dh, 0Ah, '$'
    byeMsg   DB 'Bye world', 0Dh, 0Ah, '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV CX, 5          ; counter set to 5

print_hello:
    MOV AH, 9          ; DOS print string function
    LEA DX, helloMsg
    INT 21H

    DEC CX             ; decrease counter by 1
    CMP CX, 0          ; compare counter with 0
    JNE print_hello    ; if not zero, repeat printing Hello World

    ; After printing Hello World 5 times, print Bye world once
    MOV AH, 9
    LEA DX, byeMsg
    INT 21H

    ; Exit program gracefully
    MOV AH, 4Ch        ; DOS terminate process function
    INT 21H

MAIN ENDP
END MAIN
