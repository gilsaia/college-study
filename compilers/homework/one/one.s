	.file	"one.cpp"
	.text
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
	subl	$16, %esp
	call	___main
	movl	$1, 12(%esp)
	movl	$1, 8(%esp)
	movl	12(%esp), %edx
	movl	8(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	12(%esp), %edx
	movl	8(%esp), %eax
	addl	%eax, %edx
	movl	8(%esp), %eax
	addl	%edx, %eax
	movl	%eax, (%esp)
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
