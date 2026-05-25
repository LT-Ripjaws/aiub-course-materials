.model small
.stack 100h
.data
    str db 'Hello World!$', 0
    msg db 0Dh,0Ah, "Converted string: $"

.code
main:
    mov ax, @data
    mov ds, ax

    lea si, str
convert_loop:
    mov al, [si]
    cmp al, '$'           ; end of string
    je done

    ; Check if AL is uppercase letter (A-Z: 65-90)
    cmp al, 'A'
    jb check_lower
    cmp al, 'Z'
    ja check_lower

    ; Toggle bit 5 (0x20) to make uppercase to lowercase
    xor al, 20h
    mov [si], al
    inc si
    jmp convert_loop

check_lower:
    ; Check if AL is lowercase letter (a-z: 97-122)
    cmp al, 'a'
    jb next_char
    cmp al, 'z'
    ja next_char

    ; Toggle bit 5 to make lowercase to uppercase
    xor al, 20h
    mov [si], al

next_char:
    inc si
    jmp convert_loop

done:
    lea dx, msg
    mov ah, 09h
    int 21h

    lea dx, str
    mov ah, 09h
    int 21h

    mov ax, 4C00h
    int 21h
end main
