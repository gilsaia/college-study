data segment
     path db 'C:/001.TXT',0,'C:/002.TXT',0,'C:/003.TXT',0,'C:/004.TXT',0,'C:/005.TXT',0
          db 'C:/006.TXT',0,'C:/007.TXT',0,'C:/008.TXT',0,'C:/009.TXT',0,'C:/010.TXT',0
          db 'C:/011.TXT',0,'C:/012.TXT',0,'C:/013.TXT',0,'C:/014.TXT',0,'C:/015.TXT',0
          db 'C:/016.TXT',0,'C:/017.TXT',0,'C:/018.TXT',0,'C:/019.TXT',0,'C:/020.TXT',0
          db 'C:/021.TXT',0,'C:/022.TXT',0,'C:/023.TXT',0,'C:/024.TXT',0,'C:/025.TXT',0
          db 'C:/026.TXT',0,'C:/027.TXT',0,'C:/028.TXT',0,'C:/029.TXT',0,'C:/030.TXT',0
          db 'C:/031.TXT',0,'C:/032.TXT',0,'C:/033.TXT',0,'C:/034.TXT',0,'C:/035.TXT',0
          db 'C:/036.TXT',0,'C:/037.TXT',0,'C:/038.TXT',0,'C:/039.TXT',0,'C:/040.TXT',0
          db 'C:/041.TXT',0,'C:/042.TXT',0,'C:/043.TXT',0,'C:/044.TXT',0,'C:/045.TXT',0
          db 'C:/046.TXT',0,'C:/047.TXT',0,'C:/048.TXT',0,'C:/049.TXT',0,'C:/050.TXT',0
          db 'C:/051.TXT',0,'C:/052.TXT',0,'C:/053.TXT',0,'C:/054.TXT',0,'C:/055.TXT',0
          db 'C:/056.TXT',0,'C:/057.TXT',0,'C:/058.TXT',0,'C:/059.TXT',0,'C:/060.TXT',0
          db 'C:/061.TXT',0,'C:/062.TXT',0,'C:/063.TXT',0,'C:/064.TXT',0,'C:/065.TXT',0
          db 'C:/066.TXT',0,'C:/067.TXT',0,'C:/068.TXT',0,'C:/069.TXT',0,'C:/070.TXT',0
          db 'C:/071.TXT',0,'C:/072.TXT',0,'C:/073.TXT',0,'C:/074.TXT',0,'C:/075.TXT',0
          db 'C:/076.TXT',0,'C:/077.TXT',0,'C:/078.TXT',0,'C:/079.TXT',0,'C:/080.TXT',0
          db 'C:/081.TXT',0,'C:/082.TXT',0,'C:/083.TXT',0,'C:/084.TXT',0,'C:/085.TXT',0
          db 'C:/086.TXT',0,'C:/087.TXT',0,'C:/088.TXT',0,'C:/089.TXT',0,'C:/090.TXT',0
          db 'C:/091.TXT',0,'C:/092.TXT',0,'C:/093.TXT',0,'C:/094.TXT',0,'C:/095.TXT',0
          db 'C:/096.TXT',0,'C:/097.TXT',0,'C:/098.TXT',0,'C:/099.TXT',0,'C:/100.TXT',0
          db 'C:/101.TXT',0,'C:/102.TXT',0,'C:/103.TXT',0,'C:/104.TXT',0	
 
     mus_freg  dw 554,659,740,659,740,659,740,880,659,740,554
               dw 554,659,740,659,740,659,740,1109,880,988,740
               dw 554,659,740,659,740,659,740,880,659,740,554,659,440,494
               dw 554,880,740,1109,988,1109,988,880,988,740
               dw 740,740,740,740,880,988,1109,740,740,740,659,659,740
               dw 740,740,740,740,880,988,1109
               dw 740,740,740,1175,1175,1109
               dw 740,740,740,740,880,988,1109
               dw 740,740,740,659,659,740
               dw 740,740,740,740,880,988,1109,1480,740,740,659,659,740,740,-1
     mus_time  dw 25,25,50,25,50,25,25,25,25,25,50
               dw 25,25,50,25,50,25,25,25,25,25,50
               dw 25,25,50,25,50,25,25,25,25,25,25,25,25,25
               dw 50,50,50,50,25,12,25,12,25,50
               dw 50,50,50,25,25,25,25,50,50,25,25,25,25
               dw 50,50,50,25,25,25,25,50,50,25,25,25,25
               dw 50,50,50,25,25,25,25,50,50,25,25,25,25
               dw 50,50,50,25,25,25,25,25,25,25,25,25,25,25
               
      buffer db 8000 dup(0)
data ends

 

stack segment stack
      db 200 dup(?)
stack ends
 

SHOWBM MACRO b
     LEA DX,b
     MOV AH,9
     INT 21H
 ENDM
 
;----------音乐地址宏-----------
ADDRESS MACRO A,B
     LEA SI,A
     LEA BP,DS:B
ENDM
;-------------------------------
 
code segment
     assume ds:data, ss:stack, cs:code
start:
     mov ax, data
     mov ds, ax
     mov ax, stack
     mov ss, ax
     mov sp, 200
     lea dx,path
     push dx
     address mus_freg, mus_time
     call music
 
exit:     
     mov ah, 4cH
     int 21h
 
;------------发声-------------
gensound proc near
     push ax
     push bx
     push cx
     push dx
     push di
 
     mov al, 0b6H
     out 43h, al
     mov dx, 12h
     mov ax, 348ch
     div di
     out 42h, al
 
     mov al, ah
     out 42h, al
 
     in al, 61h
     mov ah, al
     or al, 3
     out 61h, al
wait1:
     mov cx, 3314
     call waitf
delay1:
     dec bx
     jnz wait1
 
     mov al, ah
     out 61h, al
 
     pop di
     pop dx
     pop cx
     pop bx
     pop ax
     ret 
gensound endp
 
;--------------------------
waitf proc near
      push ax
waitf1:
      in al,61h
      and al,10h
      cmp al,ah
      je waitf1
      mov ah,al
      loop waitf1
      pop ax
      ret
waitf endp
;--------------发声调用函数----------------
music proc near
      xor ax, ax
freg:
      mov di, [si]
      cmp di, 0FFFFH
      je end_mus
      mov bx, ds:[bp]
      call gensound
      add si, 2
      add bp, 2
      jmp freg
end_mus:
      ret
music endp
 
show:
	push ax
	push cx
	push bx
	push si
	push di
	MOV AH,3DH
 	MOV AL,2
 	INT 21H
 	add dx,11
 	push dx
 	LEA DX,buffer
 	MOV BX,AX
 	MOV CX,8000
 	MOV AH,3FH
 	INT 21H
	MOV CX,AX                
	LEA SI,buffer
NEXT:
	MOV DL,[SI]
 	MOV AH,2
 	INT 21H
	INC SI
	LOOP NEXT
 	MOV AH,3EH
 	INT 21H
 	pop dx
 	pop di
 	pop si
 	pop bx
 	pop cx
 	pop ax
 	ret
 	 
code ends
     end start











