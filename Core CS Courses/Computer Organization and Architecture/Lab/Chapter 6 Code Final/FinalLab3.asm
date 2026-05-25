.MODEL SMALL          ; Define memory model, SMALL means small memory model
.STACK 100H           ; Define stack size of 256 bytes (100H = 256 in decimal)
.DATA                 ; Start of data section (used for storing variables)

.CODE                 ; Start of code section
MAIN PROC             ; Define main procedure (entry point)

    MOV AX, @DATA     ; Load the address of data segment into AX register
    MOV DS, AX        ; Move the address from AX into DS (data segment register) to access the data segment
    
    ; Read a character for AX
    MOV AH, 1          ; Prepare to read a character (INT 21h, AH=1 is for reading input)
    INT 21h            ; Interrupt 21h is used for reading input from the user, result in AL
    MOV CL, AL         ; Store the input character in CL register
    MOV CH, 0          ; Clear CH register (reset it to 0)
    MOV AX, CX         ; Store the value from CX into AX

    ; Read a character for BX
    MOV AH, 1          ; Prepare to read a character (INT 21h, AH=1 is for reading input)
    INT 21h            ; Interrupt 21h is used for reading input from the user, result in AL
    MOV BL, AL         ; Store the input character in BL register
    MOV BH, 0          ; Clear BH register (reset it to 0)
    
    ; Read a character for CX
    MOV AH, 1          ; Prepare to read a character (INT 21h, AH=1 is for reading input)
    INT 21h            ; Interrupt 21h is used for reading input from the user, result in AL
    MOV CL, AL         ; Store the input character in CL register
    
    ; Compare AX with BX
    CMP AX, BX         ; Compare the values in AX and BX registers
    JGE SKIP_INNER     ; If AX >= BX (greater or equal), jump to SKIP_INNER and skip the inner logic
    
    ; Compare BX with CX
    CMP BX, CX         ; Compare the values in BX and CX registers
    JGE ELSE2          ; If BX >= CX (greater or equal), jump to ELSE2 to set BX to 0
    
    MOV AX, 0          ; If BX < CX, set AX to 0 (as per the logic requirement)
    JMP END_PROGRAM    ; Jump to END_PROGRAM to skip ELSE2 and finish the program
    
ELSE2:
    MOV BX, 0          ; If BX >= CX, set BX to 0

SKIP_INNER:           ; Label for skipping the inner condition logic (if AX >= BX)
END_PROGRAM:
    MOV AH, 4CH        ; Prepare to terminate the program (INT 21h, AH=4Ch is for program termination)
    INT 21H            ; Call interrupt 21h to exit the program

MAIN ENDP             ; End of the MAIN procedure
END MAIN              ; End of the program
