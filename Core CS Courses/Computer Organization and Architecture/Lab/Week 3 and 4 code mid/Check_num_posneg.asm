.model small
.stack 100h
.data  
e db 'Enter a number: $'
p db 10,13,'Positive$'  
q db 10,13,'Negative$' 
i db 10,13,'Invalid number$'
.code
main proc
    mov ax,@data
    mov ds,ax   
     
    mov ah,9
    lea dx,e
    int 21h
     
    mov ah,1
    int 21h
    mov bl,al
    
    cmp bl,30h
    jg pos 
    jl nega
    
    pos:
    cmp bl,39h
    jg inv 
    mov ah,9
    lea dx,p
    int 21h
    jmp exit 
    
    nega: 
    mov ah,1
    int 21h
    mov bh,al
    
    cmp bh,30h 
    jl inv
    cmp bh, 39h
    jg inv 
    
    mov ah,9
    lea dx,q
    int 21h 
    jmp exit
    
    inv:
    mov ah,9
    lea dx,i
    int 21h
    
    exit: 
    mov ah,4ch
    int 21h
    main endp
end main
