.MODEL SMALL
.STACK 100h

.DATA
hexmsg  db 'Enter hex digits (0-9,A-F) then press Enter:$'
outmsg  db 13,10,'You entered: $'

.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    ; Prompt user
    mov ah, 9
    lea dx, hexmsg
    int 21h

    ; --- Read hex input ---
    mov bx, 0

hex_in:
    mov ah, 1
    int 21h
    cmp al, 13
    je hex_done
    shl bx, 4             ;shifts current value left 4 bits to make room for the new hex digit.; make space for next nibble
    cmp al, '9'
    jbe num_digit
    sub al, 7              ; convert A-F
    ;f it is 'A'–'F':

;sub al, 7 before sub al,'0' ? because 'A'=65 and '0'=48
;? 65-7-48 = 10 which is correct for A.
num_digit:
    sub al, '0'
    or bl, al  ; inserts the new 4-bit value (0–15) into the low nibble of BX.
    jmp hex_in  
    
    ; Example: If user types 1A3:

;Start: BX=0

;Type 1 ? shift 0 ? add 1 ? BX=0001h

;Type A ? shift ? 0010h then add 0Ah BX=001Ah

;Type 3 ? shift ? 01A0h then add 03h ? BX=01A3h

hex_done:
    ; Show output label
    mov ah, 9
    lea dx, outmsg
    int 21h

    ; --- Print hex (4 nibbles) ---
    mov cx, 4      ;there are 4 hex digits (16 bits = 4 nibbles).
    mov dx, bx      ;copy the entered number.

hex_out:
    mov ax, dx
    and ax, 0F000h  ;mask the top 4 bits of DX
    shr ax, 12       ;moves all bits in AX 12 places to the right.shift that nibble to the rightmost position. Since AX is 16 bits, shifting by 12 keeps only the top 4 bits (bits 15–12) and moves them into the lowest 4 bits (bits 3–0).
    cmp al, 9
    jbe hex_num
    add al, 7    
    ;Convert it to ASCII:

;if <=9 ? add '0'

;else ? add 7 then '0' (to go from 10–15 ? 'A'–'F')
hex_num:
    add al, '0'
    mov dl, al
    mov ah, 2
    int 21h
    shl dx, 4   ;bring the next nibble into the top position.
    loop hex_out     ;repeat for 4 digits

    ; --- Exit ---
    mov ah, 4ch
    int 21h

MAIN ENDP
END MAIN
