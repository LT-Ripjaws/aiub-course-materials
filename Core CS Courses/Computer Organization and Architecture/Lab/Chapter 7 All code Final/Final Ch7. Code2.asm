; Assembly program to check if a number is odd or even using TEST instruction
.model small
.stack 100h
.data
    prompt db "Enter a single digit (0-9): $"
    not_number db 0Dh, 0Ah, "Not a digit! $"
    even_msg db 0Dh, 0Ah, "The number is even. $"
    odd_msg db 0Dh, 0Ah, "The number is odd. $"

.code
main:
    ; Initialize Data Segment
    mov ax, @data      ; Load data segment address
    mov ds, ax

    ; Display prompt for input
    lea dx, prompt     ; Load address of prompt
    mov ah, 09h        ; Function 09h: Display string
    int 21h            ; Call DOS interrupt

    ; Accept single character input
    mov ah, 01h        ; Function 01h: Input character
    int 21h
    sub al, '0'        ; Convert ASCII to numerical value (0-9)
    cmp al, 0          ; Check if less than 0
    jl invalid_input   ; If less, not a digit
    cmp al, 9          ; Check if greater than 9
    jg invalid_input   ; If greater, not a digit

    ; Check if the number is even or odd using TEST instruction
    test al, 1         ; Test LSB (Least Significant Bit)
    jz even_number     ; If LSB is 0, it is even
    jmp odd_number     ; If LSB is 1, it is odd

even_number:
    lea dx, even_msg   ; Load even message
    mov ah, 09h        ; Display string
    int 21h
    jmp exit           ; Go to exit

odd_number:
    lea dx, odd_msg    ; Load odd message
    mov ah, 09h        ; Display string
    int 21h
    jmp exit           ; Go to exit

invalid_input:
    lea dx, not_number ; Load error message
    mov ah, 09h        ; Display string
    int 21h

exit:
    mov ax, 4C00h      ; Function 4Ch: Terminate program
    int 21h
end main
