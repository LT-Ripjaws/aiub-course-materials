.model small
.stack 100h
.data
    inputBinary DB 10101010b         ; 8-bit binary input
    reversedBinary DB ?              ; Output of reversed binary
    onesCount DB ?                   ; Number of 1s
    zerosCount DB ?                  ; Number of 0s
    decimalNum DB 23                 ; Decimal input to check odd/even
    evenMsg DB "Even$", oddMsg DB "Odd$"

.code
main:
    mov ax, @data
    mov ds, ax

    ; Call procedure to reverse bits
    mov al, inputBinary
    call ReverseBinary
    mov reversedBinary, al           ; Store reversed result

    ; Call procedure to count 1s and 0s
    mov al, reversedBinary
    call CountBits

    ; Call procedure to check odd/even
    mov al, decimalNum
    call CheckOddEven

    mov ah, 4ch
    int 21h

; ---------------------------------------------
; ReverseBinary Procedure
; Input : AL = binary number
; Output: AL = reversed binary
ReverseBinary proc
    push cx
    push bx
    mov cl, 8
    xor bh, bh         ; Use BH as reversed result (start at 0)

ReverseLoop:
    ror al, 1          ; Rotate right input
    rcl bh, 1          ; Rotate left into result
    dec cl
    jnz ReverseLoop

    mov al, bh         ; Return reversed in AL
    pop bx
    pop cx
    ret
ReverseBinary endp

; ---------------------------------------------
; CountBits Procedure
; Input : AL = binary number
; Output: onesCount, zerosCount
CountBits proc
    push cx
    push bx
    xor cx, cx         ; Count of 1s in CL
    mov bl, al
    mov ch, 8          ; Loop 8 times

CountLoop:
    test bl, 1         ; Check LSB
    jz ZeroBit
    inc cl             ; Increment count of 1s
ZeroBit:
    shr bl, 1          ; Shift right
    dec ch
    jnz CountLoop

    mov onesCount, cl
    mov al, 8
    sub al, cl
    mov zerosCount, al
    pop bx
    pop cx
    ret
CountBits endp

; ---------------------------------------------
; CheckOddEven Procedure
; Input : AL = decimal number
; Output: Message displayed on screen
CheckOddEven proc
    push ax
    test al, 1         ; Test least significant bit
    jz Even            ; If LSB is 0 => Even

Odd:
    mov dx, offset oddMsg
    jmp Print

Even:
    mov dx, offset evenMsg

Print:
    mov ah, 09h
    int 21h
    pop ax
    ret
CheckOddEven endp

end main
