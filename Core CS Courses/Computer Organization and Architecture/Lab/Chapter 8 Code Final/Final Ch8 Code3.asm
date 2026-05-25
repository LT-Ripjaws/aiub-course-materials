; Assembly Program to Reverse Three Characters Using Stack (16-bit DOS)
.model small
.stack 100h
.data
    before_msg db "Before Reverse:", 0Dh, 0Ah, "123$"
    after_msg  db 0Dh, 0Ah, "After Reverse:", 0Dh, 0Ah, "$"

.code
main:
    mov ax, @data      ; Initialize data segment
    mov ds, ax

    ; Display Before Reverse
    lea dx, before_msg
    mov ah, 09h
    int 21h

    ; Initialize the three characters
    mov al, '1'       ; Character 1
    push ax            ; Push 1 to stack

    mov al, '2'       ; Character 2
    push ax            ; Push 2 to stack

    mov al, '3'       ; Character 3
    push ax            ; Push 3 to stack

    ; Display After Reverse
    lea dx, after_msg
    mov ah, 09h
    int 21h

    ; Reverse using Stack
    pop ax             ; Pop 3 into AX
    mov dl, al         ; Move 3 to DL
    mov ah, 02h        ; Display DL
    int 21h

    pop ax             ; Pop 2 into AX
    mov dl, al         ; Move 2 to DL
    mov ah, 02h        ; Display DL
    int 21h

    pop ax             ; Pop 1 into AX
    mov dl, al         ; Move 1 to DL
    mov ah, 02h        ; Display DL
    int 21h

    ; Exit program
    mov ax, 4C00h
    int 21h
end main
