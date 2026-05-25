.model small
.stack 100h
.data
    prompt db "Enter a number (0-9): $"
    power_msg db 0Dh,0Ah,"Number is a power of two.$"
    not_power_msg db 0Dh,0Ah,"Number is NOT a power of two.$"
    invalid db 0Dh,0Ah,"Invalid input.$"

.code
main:
    mov ax, @data
    mov ds, ax

    lea dx, prompt
    mov ah, 09h
    int 21h

    mov ah, 01h
    int 21h
    sub al, '0'
    cmp al, 0
    jl invalid_input
    cmp al, 9
    jg invalid_input

    ; Check if al is power of two
    ; power of two: n != 0 and (n & (n-1)) == 0

    cmp al, 0
    je not_power

    mov bl, al
    dec bl             ; bl = al - 1

    and al, bl         ; al = al & (al - 1)
    cmp al, 0
    je power
    jmp not_power

invalid_input:
    lea dx, invalid
    mov ah, 09h
    int 21h
    jmp exit

power:
    lea dx, power_msg
    mov ah, 09h
    int 21h
    jmp exit

not_power:
    lea dx, not_power_msg
    mov ah, 09h
    int 21h

exit:
    mov ax, 4C00h
    int 21h
end main
