.model small
.stack 100h
.data
    msg1 db 'Enter a character: $'
    newline db 0Dh, 0Ah, '$'
    thanks db 0Dh, 0Ah, 'Thank you.$'
.code
main proc
    mov ax, @data
    mov ds, ax

    ; Show prompt
    mov ah, 9
    lea dx, msg1
    int 21h

    ; Read character
    mov ah, 1
    int 21h
    mov bl, al         ; Save character to BL

    ; Print newline
    mov ah, 9
    lea dx, newline
    int 21h

    ; Set counter to 50
    mov cx, 50

print_loop:
    mov ah, 2
    mov dl, bl         ; Character in DL
    int 21h

    dec cx
    jnz print_loop     ; Jump if CX not zero

    ; New line and thank you
    mov ah, 9
    lea dx, newline
    int 21h

    lea dx, thanks
    int 21h

    ; Exit program
    mov ah, 4Ch
    int 21h
main endp
end main
