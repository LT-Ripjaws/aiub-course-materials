.MODEL SMALL
.STACK 100H
.DATA 
 
C DB ?
D DB ?

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    
    
    MOV AH,1
    INT 21H
    MOV C,AL
    
    MOV AH,1
    INT 21H
    MOV D,AL
     
     MOV BH,C
     XCHG BH,D
     MOV C,BH
   
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    MOV AH,2
    MOV DL,10
    INT 21H
    MOV DL,13
    INT 21H
    
    MOV AH,2
    MOV DL,C
    INT 21H
    
     
    
    MOV AH,2
    MOV DL,D
    INT 21H    
    
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN