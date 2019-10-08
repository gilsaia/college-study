	.file	"homework.cpp"
	.text
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	leaq	88(%rsp), %rbx
	movq	%rcx, %rsi
	movq	%rdx, 88(%rsp)
	xorl	%ecx, %ecx
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	movq	%rbx, 40(%rsp)
	call	*__imp___acrt_iob_func(%rip)
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	leaq	88(%rsp), %rbx
	movq	%rcx, %rsi
	movq	%rdx, 88(%rsp)
	movl	$1, %ecx
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	movq	%rbx, 40(%rsp)
	call	*__imp___acrt_iob_func(%rip)
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.text
	.p2align 4,,15
	.globl	_Z3gcdjj
	.def	_Z3gcdjj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3gcdjj
_Z3gcdjj:
	.seh_endprologue
	testl	%edx, %edx
	movl	%ecx, %eax
	movl	%edx, %r8d
	jne	.L6
	jmp	.L9
	.p2align 4,,10
.L8:
	movl	%edx, %r8d
.L6:
	xorl	%edx, %edx
	divl	%r8d
	movl	%r8d, %eax
	testl	%edx, %edx
	jne	.L8
	movl	%r8d, %eax
	ret
	.p2align 4,,10
.L9:
	movl	%ecx, %r8d
	movl	%r8d, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6modexpjjj
	.def	_Z6modexpjjj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6modexpjjj
_Z6modexpjjj:
	.seh_endprologue
	movl	$1, %r10d
	testl	%edx, %edx
	movl	%edx, %r9d
	je	.L10
	.p2align 4,,10
.L13:
	testb	$1, %r9b
	je	.L12
	movl	%r10d, %eax
	xorl	%edx, %edx
	imull	%ecx, %eax
	divl	%r8d
	movl	%edx, %r10d
.L12:
	imull	%ecx, %ecx
	xorl	%edx, %edx
	movl	%ecx, %eax
	divl	%r8d
	shrl	%r9d
	movl	%edx, %ecx
	jne	.L13
.L10:
	movl	%r10d, %eax
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "0-gcd\357\274\214"
	.ascii "1-\345\277\253\351\200\237\345\271\202\12\0"
.LC1:
	.ascii "%u\0"
.LC2:
	.ascii "\350\276\223\345\205\245a,b\350\276\223\345\207\272gcd(a,b)\12\0"
.LC3:
	.ascii "%u%u\0"
.LC4:
	.ascii "\350\276\223\345\205\245x,y,p\350\276\223\345\207\272x^y mod p\12\0"
.LC5:
	.ascii "%u%u%u\0"
.LC6:
	.ascii "%u\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	leaq	32(%rsp), %rdx
	leaq	.LC1(%rip), %rcx
	call	_Z5scanfPKcz
	movl	32(%rsp), %eax
	testl	%eax, %eax
	jne	.L20
	leaq	.LC2(%rip), %rcx
	call	_Z6printfPKcz
	leaq	44(%rsp), %r8
	leaq	.LC3(%rip), %rcx
	leaq	40(%rsp), %rdx
	call	_Z5scanfPKcz
	movl	44(%rsp), %r8d
	movl	40(%rsp), %ecx
	testl	%r8d, %r8d
	jne	.L22
.L23:
	movl	%ecx, %edx
	leaq	.LC6(%rip), %rcx
	call	_Z6printfPKcz
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.p2align 4,,10
.L27:
	movl	%edx, %r8d
.L22:
	movl	%ecx, %eax
	xorl	%edx, %edx
	movl	%r8d, %ecx
	divl	%r8d
	testl	%edx, %edx
	jne	.L27
	jmp	.L23
.L20:
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	leaq	44(%rsp), %r9
	leaq	40(%rsp), %r8
	leaq	.LC5(%rip), %rcx
	leaq	36(%rsp), %rdx
	call	_Z5scanfPKcz
	movl	40(%rsp), %r9d
	movl	$1, %ecx
	movl	44(%rsp), %r10d
	movl	36(%rsp), %r8d
	testl	%r9d, %r9d
	je	.L23
	.p2align 4,,10
.L26:
	testb	$1, %r9b
	je	.L25
	movl	%ecx, %eax
	xorl	%edx, %edx
	imull	%r8d, %eax
	divl	%r10d
	movl	%edx, %ecx
.L25:
	imull	%r8d, %r8d
	xorl	%edx, %edx
	movl	%r8d, %eax
	divl	%r10d
	shrl	%r9d
	movl	%edx, %r8d
	jne	.L26
	jmp	.L23
	.seh_endproc
	.ident	"GCC: (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
