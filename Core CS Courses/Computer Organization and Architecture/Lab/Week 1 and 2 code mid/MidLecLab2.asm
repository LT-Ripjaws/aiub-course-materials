
.MODEL SMALL            ;data segments each <= 64KB
.STACK 100H              ; Allocate 256 bytes (100H) for the stack

.DATA                    ; Start of the data segment

    MSG1 DB 'Hello, World!', 13, 10, '$'         ; First message with newline (CR = 13, LF = 10)
    MSG2 DB 'Welcome to Assembly!', '$'          ; Second message without newline (already printed after line break)

.CODE                    ; Start of code segment

MAIN PROC                ; Define the main procedure (entry point)

    MOV AX, @DATA        ; Load the address of the data segment into AX
    MOV DS, AX           ; Initialize DS with AX so we can access data variables

    ; ----- Print first line -----
    MOV AH, 9          
    LEA DX, MSG1        
    INT 21H             

    ; ----- Print second line -----
    MOV AH, 9            
    LEA DX, MSG2         
    INT 21H              

    ; ----- Exit program -----
    MOV AH, 4CH          
    INT 21H              

MAIN ENDP                ; End of the main procedure
END MAIN                 ; End of program (execution starts at MAIN)
