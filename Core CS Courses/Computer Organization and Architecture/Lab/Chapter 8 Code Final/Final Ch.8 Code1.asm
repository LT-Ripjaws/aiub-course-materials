; Assembly Program to Swap AX and BX using Stack (16-bit DOS)
.model small
.stack 100h
.data
    before_msg db "Before Swap:", 0Dh, 0Ah, "AX = 5, BX = 6$"
    after_msg  db 0Dh, 0Ah, "After Swap:", 0Dh, 0Ah, "AX = , BX = $"

.code
main:
    mov ax, @data      ; Initialize data segment
    mov ds, ax

    ; Initializing AX and BX
    mov ax, 5          ; AX = 5
    mov bx, 6          ; BX = 6

    ; Display Before Swap
    lea dx, before_msg
    mov ah, 09h
    int 21h

    ; Swap using Stack
    push ax            ; Push AX onto the stack
    push bx            ; Push BX onto the stack
    pop ax             ; Pop BX value (6) into AX
    pop bx             ; Pop AX value (5) into BX

    ; Display After Swap
    lea dx, after_msg
    mov ah, 09h
    int 21h

    ; Display swapped values
    mov dl, '0'        ; Initialize DL for ASCII digits
    add dl, al         ; Convert AX value to ASCII
    mov ah, 02h        ; Display AX value
    int 21h

    mov dl, ','        ; Display comma
    int 21h

    mov dl, ' '        ; Display space
    int 21h

    add dl, bl         ; Convert BX value to ASCII
    mov ah, 02h        ; Display BX value
    int 21h

    ; Exit program
    mov ax, 4C00h
    int 21h
end main
