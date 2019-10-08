.386
.model flat, stdcall
option casemap:none
includelib      msvcrt.lib
printf          PROTO C :ptr sbyte, :VARARG
scanf			PROTO C :ptr sbyte, :vararg
.data
szMsg           byte    "输入a,b输出gcd(a,b)", 0ah, 0
powMsg			byte	"输入x,y,p输出x^y mod p",0ah,0
choosestr		byte	"0-gcd，1-快速幂",0ah,0
twonumstring	byte	"%u %u",0
onenumstring	byte	"%u",0
op				dd	0
a				dd	0
b				dd	0
x				dd	0
y				dd	0
p				dd	0
.code
gcd:
	cmp ebx,0
	jnz	compute
	ret	
compute:
	mov edx,0
	div ebx
	mov eax,ebx
	mov ebx,edx
	call gcd	
	ret	
modpow:
	mov ecx,[y]
	cmp ecx,0
	jz	powend
	push eax
	and	ecx,1
	cmp ecx,1
	jnz powsingle
	pop eax
	mov ebx,[x]
	xor edx,edx
	mul ebx
	mov ebx,[p]
	div ebx
	mov eax,edx
	push eax
powsingle:
	mov eax,[y]
	xor edx,edx
	mov ecx,2
	div ecx
	mov [y],eax
	mov eax,[x]
	xor edx,edx
	mul eax
	mov ebx,[p]
	div ebx
	mov [x],edx
	pop eax
	jmp modpow	
powend:
	ret	
main:
	invoke	printf,addr choosestr
	invoke scanf,addr onenumstring,addr op
	cmp op,1
	jz modpowop
	invoke printf,addr szMsg
	invoke	scanf,addr twonumstring,addr a,addr b
	mov eax,[a]
	mov ebx,[b]
	call gcd
	jmp proend	
modpowop:
	invoke printf,addr powMsg
	invoke	scanf,addr twonumstring,addr x,addr y
	invoke scanf,addr onenumstring,addr p
	mov eax,1
	call modpow
proend:
	invoke	printf,offset	onenumstring,eax
	ret
end             main
