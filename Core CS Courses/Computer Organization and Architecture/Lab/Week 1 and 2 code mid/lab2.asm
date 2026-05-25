
.MODEL SMALL
.STACK 100H
.DATA ;VARIABLE
A DB 0AH,0DH,"HELLO WORLD$" 
B DB 0AH,0DH, "ENTER NUMBER 1: $"   
C DB 0AH,0DH, "ENTER NUMBER 2: $" 
D DB 0AH,0DH, "RESULT IS: $"   


.CODE
MAIN PROC
    ;1 FOR SINGLE USER INPUT
    ;2 FOR SINGLE OUTPUT
    ;9 FOR STRING OUTPUT
    
    MOV AX,@DATA
    MOV DS,AX  
    
     ;STRING 1 
    MOV AH,9
    LEA DX,A
    INT 21H
    
     ;STRING 2 
    MOV AH,9
    LEA DX,B
    INT 21H
    
    ;INPUT
    MOV AH,1; CIN
    INT 21H 
    MOV BH,AL
     
     ;STRING 3 
    MOV AH,9
    LEA DX,C
    INT 21H 
    
    ;INPUT
    MOV AH,1; CIN
    INT 21H 
    MOV CH,AL 
    
    ;STRING 4 
    MOV AH,9
    LEA DX,D
    INT 21H 
    
    ;ADD BH,CH ;BH=BH+CH
    ;SUB BH,30H ;BH=BH-30H 
    
    SUB BH,CH
    ADD BH,30H
    
    MOV AH,2
    MOV DL, BH
    INT 21H  
     
     ;EXIT
    MOV AH,4CH 
    INT 21H
    MAIN ENDP
END
    
    
   
   
    
    
    