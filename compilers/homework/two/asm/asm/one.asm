.386
.model flat, stdcall
option casemap:none
includelib      msvcrt.lib
printf	PROTO C :ptr sbyte, :VARARG
scanf	PROTO C :ptr sbyte, :VARARG
fib	PROTO C,x:SDWORD
hi	PROTO C,x:SDWORD
.data
a	SDWORD	0
b	SDWORD	0
e	SDWORD	0
D	SDWORD	0
R0	SDWORD	0
R1	SDWORD	0
R2	SDWORD	0
C0	BYTE	"%d ",0
C1	BYTE	"%d ",0
C2	BYTE	"%d ",0
C3	BYTE	"%d ",0
T1	SDWORD	0
T2	SDWORD	0
T3	SDWORD	0
T4	SDWORD	0
T5	SDWORD	0
T6	SDWORD	0
T7	SDWORD	0
T8	SDWORD	0
T9	SDWORD	0
T10	SDWORD	0
T11	SDWORD	0
T12	SDWORD	0
T13	SDWORD	0
.code
fib PROC C,x:SDWORD
invoke	printf,addr C0,[x]
mov eax,[x]
sub eax,1
mov [T3],eax
mov eax,[T3]
mov [x],eax
mov [T3],eax
mov eax,[x]
mov [R0],eax
ret
fib ENDP
hi PROC C,x:SDWORD
invoke	printf,addr C1,[x]
push [T1]
push [T2]
push [T3]
invoke	fib,[x]
mov eax,[R0]
mov [T6],eax
pop [T3]
pop [T2]
pop [T1]
mov eax,[T6]
mov [x],eax
mov [T6],eax
mov eax,[x]
mov [R1],eax
ret
hi ENDP
main:
mov eax,5
mov [a],eax
mov [T7],eax
mov eax,7
mov [e],eax
mov [T8],eax
push [T4]
push [T5]
push [T6]
invoke	hi,[e]
mov eax,[R1]
mov [T9],eax
pop [T6]
pop [T5]
pop [T4]
mov eax,7
imul [T9]
mov [T9],eax
mov eax,2
add eax,[T9]
mov [T9],eax
mov eax,[T9]
mov [e],eax
mov [T9],eax
mov eax,[T9]
mov [a],eax
mov [T9],eax
invoke	printf,addr C2,[e]
invoke	printf,addr C3,[a]
ret
end	main
