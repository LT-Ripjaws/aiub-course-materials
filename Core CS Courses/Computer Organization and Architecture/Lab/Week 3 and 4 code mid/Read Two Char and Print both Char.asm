.model small
.stack 100h

.data
msg db 10,13,'$'     ; New line and carriage return for output formatting

.code
main proc
    mov ax, @data    ; Initialize data segment
    mov ds, ax

    ; Read first character
    mov ah, 1
    int 21h          ; Character entered is in AL
    mov bl, al       ; Store first character in BL

    ; Read second character
    mov ah, 1
    int 21h
    mov bh, al       ; Store second character in BH

    ; Move to new line
    mov ah, 9
    lea dx, msg
    int 21h

    ; Print first character
    mov dl, bl
    mov ah, 2
    int 21h

    ; Print second character
    mov dl, bh
    mov ah, 2
    int 21h

    ; Exit
    mov ah, 4ch
    int 21h
main endp
end main
