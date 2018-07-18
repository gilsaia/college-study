DATAS SEGMENT
    db 0,0,0,0
    db '00:00:00$'
    db 0,0,0,0,0,0,0,0,1
    db 'time is over!$'
    db '                        $'
DATAS ENDS

STACKS SEGMENT
    db 128 dup(0)
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    mov es,ax
    mov ax,stacks
    mov ss,ax
   	mov sp,128
time:
	call get_time
	call check_time
	mov ah,1
	int 16h
	je time
	cmp al,27
	je over
secondclock:
	cmp al,115
	jne time
	call set_clock
	jmp time
over:
    MOV AH,4CH
    INT 21H
    
get_time:
	push ax
	push cx
	push dx
	call set_position
	mov ax,2c00h
	int 21h
	mov es:[0],ch
	mov es:[1],cl
	mov es:[2],dh
	mov ax,10
	mov es:[3],ax
	mov ax,0
	mov al,es:[0]
	div byte ptr es:[3]
	add al,30h
	add ah,30h
	mov es:[4],al
	mov es:[5],ah
	mov ax,0
	mov al,es:[1]
	div byte ptr es:[3]
	add al,30h
	add ah,30h
	mov es:[7],al
	mov es:[8],ah
	mov ax,0
	mov al,es:[2]
	div byte ptr es:[3]
	add al,30h
	add ah,30h
	mov es:[10],al
	mov es:[11],ah
	mov dx,4
	mov ax,0
	mov ah,9
	int 21h
	pop dx
	pop cx
	pop ax
	ret
	
set_position:
	push dx
	push bx
	push ax
	mov dh,12
	mov dl,35
	mov bh,0
	mov ah,2
	int 10h
	pop ax
	pop bx
	pop dx
	ret
	
set_clock:
	push ax
	push bx
	push dx
	push di
	push cx
	mov di,0
	mov dx,0
	mov es:[21],dl
	mov es:[13],dl
	jmp cin
set:
	sub dl,30h
	mov al,es:[13]
	mov ah,0
	mov bx,10
	mul bl
	add al,dl
	mov es:[13],al
cin:
	mov ax,0
	int 16h
	cmp al,115
	je cin
	mov dl,al
	mov ah,02
	int 21h
	cmp dl,13
	jne set
	call set_position
	mov dx,36
	mov ah,9
	int 21h
	mov ax,2c00h
	int 21h
	mov es:[15],ch
	mov es:[17],cl
	mov es:[19],dh
	mov dl,es:[19]
	add dl,es:[13]
	cmp dl,60
	jb setnext
	sub dl,60
setnext:
	mov es:[19],dl
	pop cx
	pop di
	pop dx
	pop bx
	pop ax
	ret
	
check_time:
	push ax
	push dx
	mov dl,0
	cmp es:[21],dl
	jne checkend
	mov al,es:[2]
	cmp al,es:[19]
	je timeout
	jmp checkend
timeout:
	mov dx,22
	mov ah,9
	int 21h
	mov dl,1
	mov es:[21],dl
	mov ax,0
	int 16h
	call set_position
	mov dx,36
	mov ah,9
	int 21h
checkend:
	pop dx
	pop ax
	ret
CODES ENDS
    END START


