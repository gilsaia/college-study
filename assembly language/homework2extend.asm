DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
   sta:mov ah,01h
   int 21h
   cmp al,1bh
   je en
   jmp sta
   en: MOV AH,4CH
    INT 21H
CODES ENDS
    END START