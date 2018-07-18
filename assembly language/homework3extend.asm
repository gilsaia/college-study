codes segment
			assume	cs:codes,ds:codes
			org		100h
start:
	jmp		install
	OLDCUR		DW		?			
	OLD1C		DW		2 DUP(?)
	TIME        db      0,0,0,0
	CLOCK       db      '00:00:00'
 
newint1c:																												
	mov		ah,03h
	xor		bh,bh
	int		10h					
	mov		OLDCUR,dx
get_time:
	push ax
	push cx
	push dx
	call set_position
	mov ax,2c00h
	int 21h
	mov TIME[0],ch
	mov TIME[1],cl
	mov TIME[2],dh
	mov ax,10
	mov TIME[3],al
	mov ax,0
	mov al,TIME[0]
	div byte ptr TIME[3]
	add al,30h
	add ah,30h
	mov cx,ax
	mov dl,al
	mov ah,2
	int 21h
	mov dl,ch
	int 21h
	mov dl,58
	int 21h
	mov ax,0
	mov al,TIME[1]
	div byte ptr TIME[3]
	add al,30h
	add ah,30h
	mov cx,ax
	mov dl,al
	mov ah,2
	int 21h
	mov dl,ch
	int 21h
	mov dl,58
	int 21h
	mov ax,0
	mov al,TIME[2]
	div byte ptr TIME[3]
	add al,30h
	add ah,30h
	mov cx,ax
	mov dl,al
	mov ah,2
	int 21h
	mov dl,ch
	int 21h
	pop dx
	pop cx
	pop ax
	mov		ah,02h				
	mov		dx,OLDCUR
	xor		bh,bh
	int		10h
	iret
			
set_position:
	push dx
	push bx
	push ax
	mov dh,0
	mov dl,71
	mov bh,0
	mov ah,2
	int 10h
	pop ax
	pop bx
	pop dx
	ret
															
install:
	push	cs
	pop		ds
	mov		ah,35h
	mov		al,1ch
	int		21h					;取旧的int1c向量并保存
	mov		OLD1C,bx
	mov		bx,es
	mov		OLD1C+2,bx
			
	mov		dx,offset newint1c
	mov		ah,25h					;设置新的int1c向量			                               					 						
	mov		al,1ch
	int		21h
			
	mov		dX,offset install
	mov		cl,4
	shr		dx,cl					;计算驻留区大小
	add		dx,11h
			
	mov		ah,31h
	xor		al,al					;驻留并结束
	int		21h
 
codes ends
    		end	start
