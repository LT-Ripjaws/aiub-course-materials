.MODEL SMALL
.STACK 100h

.DATA
binmsg  db 'Enter binary bits (0/1) then press Enter:$'
outmsg  db 13,10,'You entered: $'

.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    ; Prompt user
    mov ah, 9
    lea dx, binmsg
    int 21h

    ; --- Read binary input ---
    mov bx, 0          ; will store binary number

read_loop:
    mov ah, 1
    int 21h             ; read char from keyboard
    cmp al, 13           ; Enter key?
    je done_input
    sub al, '0'          ; convert ASCII '0'/'1' to 0/1
    shl bx, 1             ; make space for new bit, shifts existing bits in BX left by 1 to make space.
    or bl, al              ; add the bit; inserts the new bit into the lowest position.
    jmp read_loop    
    ;cmp al, 13 checks if the user has pressed Enter (ASCII 13). 
    ;When the user presses Enter, the keyboard actually sends the ASCII carriage return character (CR), 
    ;which has the decimal value 13 (hex 0Dh)
    ;If so, the program ends input and moves on to output the binary number.
    
    ;If user types 1, 0, 1

;After 1 ? BX = 00000001

;After 0 ? shift ? 00000010 then OR 0 ? 00000010

;After 1 ? shift ? 00000100 then OR 1 ? 00000101

done_input:
    ; Show output label
    mov ah, 9
    lea dx, outmsg
    int 21h

    ; --- Print binary output ---
    mov cx, 8            ; show 8 bits;will print exactly 8 bits.
    mov dx, bx            ; copy to DX for output;copy the binary number to DX because we will be shifting it.

print_loop:
    shl dx, 1     ;shifts the top bit into the Carry Flag.
    jc print_1      ;if Carry = 1, print '1', else print '0'.
    mov dl, '0'
    jmp print_it
print_1:
    mov dl, '1'
print_it:
    mov ah, 2
    int 21h
    loop print_loop

    ; --- Exit ---
    mov ah, 4ch
    int 21h

MAIN ENDP
END MAIN
