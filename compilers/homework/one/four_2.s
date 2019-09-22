	.file	"four.cpp"
	.text
	.def	_main._omp_fn.0;	.scl	3;	.type	32;	.endef
_main._omp_fn.0:
LFB1:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %edx
	movl	8(%edx), %ecx
	movl	12(%edx), %ebx
	movl	(%edx), %esi
	movl	4(%edx), %edi
	movl	$100000000, %eax
L2:
	subl	$1, %eax
	jne	L2
	addl	%esi, %ecx
	adcl	%edi, %ebx
	movl	%ecx, 16(%edx)
	movl	%ebx, 20(%edx)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1:
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$1, 32(%esp)
	movl	$0, 36(%esp)
	movl	$0, 24(%esp)
	movl	$0, 28(%esp)
	movl	$0, 40(%esp)
	movl	$0, 44(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$_main._omp_fn.0, (%esp)
	call	_GOMP_parallel
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	_GOMP_parallel;	.scl	2;	.type	32;	.endef
