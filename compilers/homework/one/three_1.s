	.file	"three.cpp"
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
LFB371:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE371:
	.section .rdata,"dr"
__ZStL13allocator_arg:
	.space 1
	.align 4
__ZL4maxn:
	.long	1020
	.align 4
__ZL3inf:
	.long	1061109567
	.section	.text$_ZN4EdgeC1Eiii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4EdgeC1Eiii
	.def	__ZN4EdgeC1Eiii;	.scl	2;	.type	32;	.endef
__ZN4EdgeC1Eiii:
LFB1645:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-4(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE1645:
	.section	.text$_ZN8Dijkstra4initEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Dijkstra4initEi
	.def	__ZN8Dijkstra4initEi;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra4initEi:
LFB1646:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	$0, -12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jge	L5
	movl	-12(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE5clearEv
	addl	$1, -12(%ebp)
	jmp	L6
L5:
	movl	-28(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE5clearEv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1646:
	.section	.text$_ZN8Dijkstra7AddEdgeEiii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Dijkstra7AddEdgeEiii
	.def	__ZN8Dijkstra7AddEdgeEiii;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra7AddEdgeEiii:
LFB1647:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	8(%eax), %ebx
	leal	-24(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN4EdgeC1Eiii
	subl	$12, %esp
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE9push_backEOS0_
	subl	$4, %esp
	movl	-28(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	16(%eax), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	leal	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	subl	$1, %eax
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt6vectorIiSaIiEE9push_backEOi
	subl	$4, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE1647:
	.section	.text$_ZNK8Dijkstra8HeapNodeltERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK8Dijkstra8HeapNodeltERKS0_
	.def	__ZNK8Dijkstra8HeapNodeltERKS0_;	.scl	2;	.type	32;	.endef
__ZNK8Dijkstra8HeapNodeltERKS0_:
LFB1648:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	setg	%al
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1648:
	.section	.text$_ZN8Dijkstra8HeapNodeC1Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Dijkstra8HeapNodeC1Eii
	.def	__ZN8Dijkstra8HeapNodeC1Eii;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra8HeapNodeC1Eii:
LFB1651:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1651:
	.section	.text$_ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev
	.def	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev:
LFB1655:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1655:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8Dijkstra8dijkstraEi
	.def	__ZN8Dijkstra8dijkstraEi;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra8dijkstraEi:
LFB1652:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1652
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$100, %esp
	.cfi_offset 3, -12
	movl	%ecx, -76(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EEC1IS4_vEEv
	movl	$0, -12(%ebp)
L14:
	movl	-76(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, -12(%ebp)
	jge	L13
	movl	-76(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	$3320, %edx
	movl	$1061109567, (%eax,%edx,4)
	addl	$1, -12(%ebp)
	jmp	L14
L13:
	movl	-76(%ebp), %eax
	movl	8(%ebp), %edx
	addl	$3320, %edx
	movl	$0, (%eax,%edx,4)
	movl	-76(%ebp), %eax
	addl	$12260, %eax
	movl	$1020, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	leal	-32(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	__ZN8Dijkstra8HeapNodeC1Eii
	subl	$8, %esp
	leal	-48(%ebp), %eax
	leal	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB0:
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
	subl	$4, %esp
L21:
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE5emptyEv
	xorl	$1, %eax
	testb	%al, %al
	je	L15
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3topEv
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -56(%ebp)
	movl	%edx, -52(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3popEv
	movl	-52(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	-76(%ebp), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	addl	$12260, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L25
	movl	-76(%ebp), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	addl	$12260, %eax
	movb	$1, (%eax)
	movl	$0, -16(%ebp)
L20:
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	16(%eax), %edx
	movl	-76(%ebp), %eax
	addl	%edx, %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE4sizeEv
	movl	%eax, %edx
	movl	-16(%ebp), %eax
	cmpl	%eax, %edx
	seta	%al
	testb	%al, %al
	je	L21
	movl	-16(%ebp), %ecx
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	16(%eax), %edx
	movl	-76(%ebp), %eax
	addl	%edx, %eax
	addl	$4, %eax
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEEixEj
	subl	$4, %esp
	movl	(%eax), %eax
	movl	%eax, %edx
	movl	-76(%ebp), %eax
	addl	$8, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EEixEj
	subl	$4, %esp
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	4(%eax), %edx
	movl	-76(%ebp), %eax
	addl	$3320, %edx
	movl	(%eax,%edx,4), %edx
	movl	-76(%ebp), %eax
	movl	-20(%ebp), %ecx
	addl	$3320, %ecx
	movl	(%eax,%ecx,4), %ecx
	movl	-24(%ebp), %eax
	movl	8(%eax), %eax
	addl	%ecx, %eax
	cmpl	%eax, %edx
	jle	L19
	movl	-76(%ebp), %eax
	movl	-20(%ebp), %edx
	addl	$3320, %edx
	movl	(%eax,%edx,4), %ebx
	movl	-24(%ebp), %eax
	movl	8(%eax), %ecx
	movl	-24(%ebp), %eax
	movl	4(%eax), %edx
	addl	%ebx, %ecx
	movl	-76(%ebp), %eax
	addl	$3320, %edx
	movl	%ecx, (%eax,%edx,4)
	movl	-16(%ebp), %ecx
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	16(%eax), %edx
	movl	-76(%ebp), %eax
	addl	%edx, %eax
	addl	$4, %eax
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEEixEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	movl	4(%eax), %ecx
	movl	(%edx), %edx
	movl	-76(%ebp), %eax
	addl	$4340, %ecx
	movl	%edx, (%eax,%ecx,4)
	movl	-24(%ebp), %eax
	movl	4(%eax), %ecx
	movl	-24(%ebp), %eax
	movl	4(%eax), %edx
	movl	-76(%ebp), %eax
	addl	$3320, %edx
	movl	(%eax,%edx,4), %edx
	leal	-64(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN8Dijkstra8HeapNodeC1Eii
	subl	$8, %esp
	leal	-48(%ebp), %eax
	leal	-64(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushERKS1_
LEHE0:
	subl	$4, %esp
L19:
	addl	$1, -16(%ebp)
	jmp	L20
L25:
	nop
	jmp	L21
L15:
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev
	jmp	L24
L23:
	movl	%eax, %ebx
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EED1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
L24:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1652:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1652:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1652-LLSDACSB1652
LLSDACSB1652:
	.uleb128 LEHB0-LFB1652
	.uleb128 LEHE0-LEHB0
	.uleb128 L23-LFB1652
	.uleb128 0
	.uleb128 LEHB1-LFB1652
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE1652:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.section	.text$_ZN8DijkstraC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8DijkstraC1Ev
	.def	__ZN8DijkstraC1Ev;	.scl	2;	.type	32;	.endef
__ZN8DijkstraC1Ev:
LFB1658:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EEC1Ev
	movl	-12(%ebp), %eax
	addl	$20, %eax
	movl	$1019, %ebx
	movl	%eax, %esi
L28:
	testl	%ebx, %ebx
	js	L29
	movl	%esi, %ecx
	call	__ZNSt6vectorIiSaIiEEC1Ev
	addl	$12, %esi
	subl	$1, %ebx
	jmp	L28
L29:
	nop
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1658:
	.globl	_dijkstra
	.bss
	.align 32
_dijkstra:
	.space 21440
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d%d\0"
LC1:
	.ascii "%d%d%d\0"
LC2:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1659:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$52, %esp
	call	___main
	leal	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$_dijkstra, %ecx
	call	__ZN8Dijkstra4initEi
	subl	$4, %esp
	movl	$0, -12(%ebp)
L32:
	movl	-20(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jge	L31
	leal	-32(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	-24(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -24(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -28(%ebp)
	movl	-32(%ebp), %ecx
	movl	-28(%ebp), %edx
	movl	-24(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$_dijkstra, %ecx
	call	__ZN8Dijkstra7AddEdgeEiii
	subl	$12, %esp
	movl	-32(%ebp), %ecx
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$_dijkstra, %ecx
	call	__ZN8Dijkstra7AddEdgeEiii
	subl	$12, %esp
	addl	$1, -12(%ebp)
	jmp	L32
L31:
	movl	-16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	movl	$_dijkstra, %ecx
	call	__ZN8Dijkstra8dijkstraEi
	subl	$4, %esp
	movl	_dijkstra+13280, %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1659:
	.section	.text$_ZNSt6vectorIiSaIiEE5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE5clearEv
	.def	__ZNSt6vectorIiSaIiEE5clearEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE5clearEv:
LFB1662:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1662:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE5clearEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE5clearEv
	.def	__ZNSt6vectorI4EdgeSaIS0_EE5clearEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE5clearEv:
LFB1663:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1663:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE9push_backEOS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE9push_backEOS0_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE9push_backEOS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE9push_backEOS0_:
LFB1664:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIR4EdgeEONSt16remove_referenceIT_E4typeEOS3_
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1664:
	.section	.text$_ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	.def	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv:
LFB1665:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1665:
	.section	.text$_ZNSt6vectorIiSaIiEE9push_backEOi,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE9push_backEOi
	.def	__ZNSt6vectorIiSaIiEE9push_backEOi;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE9push_backEOi:
LFB1666:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1666:
	.section	.text$_ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EEC1IS4_vEEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EEC1IS4_vEEv
	.def	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EEC1IS4_vEEv;	.scl	2;	.type	32;	.endef
__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EEC1IS4_vEEv:
LFB1669:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1669:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev:
LFB1672:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1672
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1672:
	.section	.gcc_except_table,"w"
LLSDA1672:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1672-LLSDACSB1672
LLSDACSB1672:
LLSDACSE1672:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_
	.def	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushEOS1_:
LFB1673:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backEOS1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movzbl	-13(%ebp), %edx
	movb	%dl, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1673:
	.section	.text$_ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE5emptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE5emptyEv
	.def	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE5emptyEv;	.scl	2;	.type	32;	.endef
__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE5emptyEv:
LFB1674:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5emptyEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1674:
	.section	.text$_ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3topEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3topEv
	.def	__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3topEv;	.scl	2;	.type	32;	.endef
__ZNKSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3topEv:
LFB1675:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5frontEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1675:
	.section	.text$_ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3popEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3popEv
	.def	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3popEv;	.scl	2;	.type	32;	.endef
__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE3popEv:
LFB1676:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movzbl	-13(%ebp), %edx
	movb	%dl, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt8pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1676:
	.section	.text$_ZNKSt6vectorIiSaIiEE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIiSaIiEE4sizeEv
	.def	__ZNKSt6vectorIiSaIiEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIiSaIiEE4sizeEv:
LFB1677:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1677:
	.section	.text$_ZNSt6vectorIiSaIiEEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEEixEj
	.def	__ZNSt6vectorIiSaIiEEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEEixEj:
LFB1678:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$2, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1678:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EEixEj
	.def	__ZNSt6vectorI4EdgeSaIS0_EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EEixEj:
LFB1679:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1679:
	.section	.text$_ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushERKS1_
	.def	__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt14priority_queueIN8Dijkstra8HeapNodeESt6vectorIS1_SaIS1_EESt4lessIS1_EE4pushERKS1_:
LFB1680:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backERKS1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movzbl	-13(%ebp), %edx
	movb	%dl, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1680:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EEC1Ev
	.def	__ZNSt6vectorI4EdgeSaIS0_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EEC1Ev:
LFB1683:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1683
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1683:
	.section	.gcc_except_table,"w"
LLSDA1683:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1683-LLSDACSB1683
LLSDACSB1683:
LLSDACSE1683:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EED1Ev
	.def	__ZNSt6vectorI4EdgeSaIS0_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EED1Ev:
LFB1686:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1686
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1686:
	.section	.gcc_except_table,"w"
LLSDA1686:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1686-LLSDACSB1686
LLSDACSB1686:
LLSDACSE1686:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorIiSaIiEEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEEC1Ev
	.def	__ZNSt6vectorIiSaIiEEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEEC1Ev:
LFB1689:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1689
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1689:
	.section	.gcc_except_table,"w"
LLSDA1689:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1689-LLSDACSB1689
LLSDACSB1689:
LLSDACSE1689:
	.section	.text$_ZNSt6vectorIiSaIiEEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorIiSaIiEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEED1Ev
	.def	__ZNSt6vectorIiSaIiEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEED1Ev:
LFB1692:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1692
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1692:
	.section	.gcc_except_table,"w"
LLSDA1692:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1692-LLSDACSB1692
LLSDACSB1692:
LLSDACSE1692:
	.section	.text$_ZNSt6vectorIiSaIiEED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi
	.def	__ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi:
LFB1693:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1693
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L61
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
L61:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1693:
	.section	.gcc_except_table,"w"
LLSDA1693:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1693-LLSDACSB1693
LLSDACSB1693:
LLSDACSE1693:
	.section	.text$_ZNSt6vectorIiSaIiEE15_M_erase_at_endEPi,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_:
LFB1694:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1694
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L64
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%eax)
L64:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1694:
	.section	.gcc_except_table,"w"
LLSDA1694:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1694-LLSDACSB1694
LLSDACSB1694:
LLSDACSE1694:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE15_M_erase_at_endEPS0_,"x"
	.linkonce discard
	.section	.text$_ZSt4moveIR4EdgeEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIR4EdgeEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIR4EdgeEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIR4EdgeEONSt16remove_referenceIT_E4typeEOS3_:
LFB1695:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1695:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_:
LFB1696:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L68
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	12(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L70
L68:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE3endEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	subl	$8, %esp
L70:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1696:
	.section	.text$_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.def	__ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_:
LFB1697:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1697:
	.section	.text$_ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_
	.def	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_:
LFB1698:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L74
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L76
L74:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE3endEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	subl	$8, %esp
L76:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1698:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev:
LFB1701:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1701
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1701:
	.section	.gcc_except_table,"w"
LLSDA1701:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1701-LLSDACSB1701
LLSDACSB1701:
LLSDACSE1701:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EEC1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implD1Ev:
LFB1705:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIN8Dijkstra8HeapNodeEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1705:
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev:
LFB1706:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1706
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$3, %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implD1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1706:
	.section	.gcc_except_table,"w"
LLSDA1706:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1706-LLSDACSB1706
LLSDACSB1706:
LLSDACSE1706:
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv:
LFB1708:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1708:
	.section	.text$_ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
	.def	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E:
LFB1709:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1709:
	.section	.text$_ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	.def	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_:
LFB1710:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1710:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backEOS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backEOS1_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backEOS1_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backEOS1_:
LFB1711:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12emplace_backIJS1_EEEvDpOT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1711:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv:
LFB1712:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1712:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv:
LFB1713:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1713:
	.section	.text$_ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_,"x"
	.linkonce discard
	.globl	__ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_
	.def	__ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_;	.scl	2;	.type	32;	.endef
__ZSt9push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_:
LFB1714:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_
	leal	-13(%ebp), %eax
	movb	%bl, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1ES5_
	subl	$4, %esp
	leal	12(%ebp), %eax
	movl	$1, (%esp)
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmiEi
	subl	$4, %esp
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	leal	-1(%eax), %ecx
	leal	-13(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	$0, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1714:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5emptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5emptyEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5emptyEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5emptyEv:
LFB1715:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, -16(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxeqIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1715:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5frontEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5frontEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5frontEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5frontEv:
LFB1716:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1716:
	.section	.text$_ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_
	.def	__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_:
LFB1721:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1721:
	.section	.text$_ZSt8pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_,"x"
	.linkonce discard
	.globl	__ZSt8pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_
	.def	__ZSt8pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_;	.scl	2;	.type	32;	.endef
__ZSt8pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEESt4lessIS3_EEvT_SB_T0_:
LFB1717:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	cmpl	$1, %eax
	setg	%al
	testb	%al, %al
	je	L99
	leal	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmmEv
	leal	-9(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt10__pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_SE_SE_RT0_
L99:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1717:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv:
LFB1722:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1722
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	-8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1722:
	.section	.gcc_except_table,"w"
LLSDA1722:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1722-LLSDACSB1722
LLSDACSB1722:
LLSDACSE1722:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8pop_backEv,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backERKS1_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE9push_backERKS1_:
LFB1723:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L102
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L104
L102:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	subl	$8, %esp
L104:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1723:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implD1Ev:
LFB1727:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaI4EdgeED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1727:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EEC2Ev
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EEC2Ev:
LFB1728:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1728:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev:
LFB1731:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1731
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j
	subl	$8, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implD1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1731:
	.section	.gcc_except_table,"w"
LLSDA1731:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1731-LLSDACSB1731
LLSDACSB1731:
LLSDACSE1731:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1733:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1733:
	.section	.text$_ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E
	.def	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E:
LFB1734:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4EdgeEvT_S2_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1734:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev:
LFB1738:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIiED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1738:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEEC2Ev
	.def	__ZNSt12_Vector_baseIiSaIiEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEEC2Ev:
LFB1739:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1739:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEED2Ev
	.def	__ZNSt12_Vector_baseIiSaIiEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEED2Ev:
LFB1742:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1742
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij
	subl	$8, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1742:
	.section	.gcc_except_table,"w"
LLSDA1742:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1742-LLSDACSB1742
LLSDACSB1742:
LLSDACSE1742:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv:
LFB1744:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1744:
	.section	.text$_ZSt8_DestroyIPiiEvT_S1_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E
	.def	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E:
LFB1745:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPiEvT_S1_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1745:
	.section	.text$_ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	.def	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE:
LFB1746:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1746:
	.section	.text$_ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_:
LFB1747:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeE9constructIS1_JS1_EEEvPT_DpOT0_
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1747:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE3endEv
	.def	__ZNSt6vectorI4EdgeSaIS0_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE3endEv:
LFB1748:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1748:
	.section .rdata,"dr"
LC3:
	.ascii "vector::_M_realloc_insert\0"
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_:
LFB1749:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1749
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB2:
	call	__ZNKSt6vectorI4EdgeSaIS0_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE5beginEv
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIP4EdgeSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE11_M_allocateEj
LEHE2:
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ecx
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaI4EdgeEE9constructIS0_JS0_EEEvRS1_PT_DpOT0_
	movl	$0, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB3:
	call	__ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_
	movl	%eax, -12(%ebp)
	addl	$12, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_
LEHE3:
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB4:
	call	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E
	movl	-44(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	8(%edx), %edx
	subl	-20(%ebp), %edx
	sarl	$2, %edx
	imull	$-1431655765, %edx, %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j
LEHE4:
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L129
L127:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L124
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB5:
	call	__ZNSt16allocator_traitsISaI4EdgeEE7destroyIS0_EEvRS1_PT_
	jmp	L125
L124:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4EdgeS0_EvT_S2_RSaIT0_E
L125:
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE5:
L128:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB6:
	call	__Unwind_Resume
LEHE6:
L129:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1749:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1749:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1749-LLSDATTD1749
LLSDATTD1749:
	.byte	0x1
	.uleb128 LLSDACSE1749-LLSDACSB1749
LLSDACSB1749:
	.uleb128 LEHB2-LFB1749
	.uleb128 LEHE2-LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB3-LFB1749
	.uleb128 LEHE3-LEHB3
	.uleb128 L127-LFB1749
	.uleb128 0x1
	.uleb128 LEHB4-LFB1749
	.uleb128 LEHE4-LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB5-LFB1749
	.uleb128 LEHE5-LEHB5
	.uleb128 L128-LFB1749
	.uleb128 0
	.uleb128 LEHB6-LFB1749
	.uleb128 LEHE6-LEHB6
	.uleb128 0
	.uleb128 0
LLSDACSE1749:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1749:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_,"x"
	.linkonce discard
	.section	.text$_ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	.def	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE:
LFB1750:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1750:
	.section	.text$_ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_:
LFB1751:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiE9constructIiJiEEEvPT_DpOT0_
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1751:
	.section	.text$_ZNSt6vectorIiSaIiEE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE3endEv
	.def	__ZNSt6vectorIiSaIiEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE3endEv:
LFB1752:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1752:
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
LFB1753:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1753
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB7:
	call	__ZNKSt6vectorIiSaIiEE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIiSaIiEE5beginEv
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE11_M_allocateEj
LEHE7:
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIiEE9constructIiJiEEEvRS0_PT_DpOT0_
	movl	$0, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB8:
	call	__ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_
	movl	%eax, -12(%ebp)
	addl	$4, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_
LEHE8:
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB9:
	call	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E
	movl	-44(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	8(%edx), %edx
	subl	-20(%ebp), %edx
	sarl	$2, %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij
LEHE9:
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L142
L140:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L137
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB10:
	call	__ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_
	jmp	L138
L137:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPiiEvT_S1_RSaIT0_E
L138:
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij
	subl	$8, %esp
	call	___cxa_rethrow
LEHE10:
L141:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
LEHE11:
L142:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1753:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1753:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1753-LLSDATTD1753
LLSDATTD1753:
	.byte	0x1
	.uleb128 LLSDACSE1753-LLSDACSB1753
LLSDACSB1753:
	.uleb128 LEHB7-LFB1753
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB8-LFB1753
	.uleb128 LEHE8-LEHB8
	.uleb128 L140-LFB1753
	.uleb128 0x1
	.uleb128 LEHB9-LFB1753
	.uleb128 LEHE9-LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB10-LFB1753
	.uleb128 LEHE10-LEHB10
	.uleb128 L141-LFB1753
	.uleb128 0
	.uleb128 LEHB11-LFB1753
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE1753:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1753:
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EEC2Ev
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EEC2Ev:
LFB1755:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implC1Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1755:
	.section	.text$_ZNSaIN8Dijkstra8HeapNodeEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIN8Dijkstra8HeapNodeEED2Ev
	.def	__ZNSaIN8Dijkstra8HeapNodeEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIN8Dijkstra8HeapNodeEED2Ev:
LFB1758:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1758:
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j:
LFB1760:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L147
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE10deallocateERS2_PS1_j
L147:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1760:
	.section	.text$_ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_
	.def	__ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_:
LFB1761:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIPN8Dijkstra8HeapNodeEEEvT_S5_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1761:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12emplace_backIJS1_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12emplace_backIJS1_EEEvDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12emplace_backIJS1_EEEvDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12emplace_backIJS1_EEEvDpOT_:
LFB1762:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L150
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L152
L150:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	subl	$8, %esp
L152:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1762:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_:
LFB1765:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1765:
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1ES5_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1ES5_
	.def	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1ES5_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1ES5_:
LFB1768:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1768:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmiEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmiEi
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmiEi;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmiEi:
LFB1769:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	negl	%edx
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1769:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv:
LFB1770:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1770:
	.section	.text$_ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	.def	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_:
LFB1771:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	sarl	$3, %eax
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1771:
	.section	.text$_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_,"x"
	.linkonce discard
	.globl	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	.def	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_;	.scl	2;	.type	32;	.endef
__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_:
LFB1772:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
L165:
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jle	L162
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, %ecx
	movl	28(%ebp), %eax
	leal	20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%ecx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEES4_EEbT_RT0_
	subl	$8, %esp
	testb	%al, %al
	je	L162
	movl	$1, %eax
	jmp	L163
L162:
	movl	$0, %eax
L163:
	testb	%al, %al
	je	L164
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%ebp)
	movl	12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
	jmp	L165
L164:
	leal	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1772:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv:
LFB1773:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1773:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE3endEv:
LFB1774:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1774:
	.section	.text$_ZN9__gnu_cxxeqIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxeqIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_
	.def	__ZN9__gnu_cxxeqIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxeqIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_:
LFB1775:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	sete	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1775:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv:
LFB1776:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1776:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmmEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmmEv
	.def	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmmEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEmmEv:
LFB1777:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	-8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1777:
	.section	.text$_ZSt10__pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_SE_SE_RT0_,"x"
	.linkonce discard
	.globl	__ZSt10__pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_SE_SE_RT0_
	.def	__ZSt10__pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_SE_SE_RT0_;	.scl	2;	.type	32;	.endef
__ZSt10__pop_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_SE_SE_RT0_:
LFB1778:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	leal	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	leal	16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	movl	%eax, %ecx
	movl	20(%ebp), %eax
	movzbl	(%eax), %eax
	movb	%al, 20(%esp)
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	%ecx, 8(%esp)
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_
	nop
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1778:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_:
LFB1779:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE7destroyIS2_EEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1779:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_:
LFB1780:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JRKS2_EEEvPT_DpOT0_
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1780:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB1781:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1781
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB12:
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj
LEHE12:
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JRKS1_EEEvRS2_PT_DpOT0_
	movl	$0, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB13:
	call	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_
	movl	%eax, -12(%ebp)
	addl	$8, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_
LEHE13:
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB14:
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
	movl	-44(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	8(%edx), %edx
	subl	-20(%ebp), %edx
	sarl	$3, %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
LEHE14:
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L186
L184:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L181
	movl	-28(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_
	jmp	L182
L181:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
LEHB15:
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
L182:
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE15:
L185:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB16:
	call	__Unwind_Resume
LEHE16:
L186:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1781:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1781:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1781-LLSDATTD1781
LLSDATTD1781:
	.byte	0x1
	.uleb128 LLSDACSE1781-LLSDACSB1781
LLSDACSB1781:
	.uleb128 LEHB12-LFB1781
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB13-LFB1781
	.uleb128 LEHE13-LEHB13
	.uleb128 L184-LFB1781
	.uleb128 0x1
	.uleb128 LEHB14-LFB1781
	.uleb128 LEHE14-LEHB14
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB15-LFB1781
	.uleb128 LEHE15-LEHB15
	.uleb128 L185-LFB1781
	.uleb128 0
	.uleb128 LEHB16-LFB1781
	.uleb128 LEHE16-LEHB16
	.uleb128 0
	.uleb128 0
LLSDACSE1781:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1781:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implC1Ev
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EE12_Vector_implC1Ev:
LFB1784:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaI4EdgeEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1784:
	.section	.text$_ZNSaI4EdgeED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaI4EdgeED2Ev
	.def	__ZNSaI4EdgeED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaI4EdgeED2Ev:
LFB1786:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1786:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EE13_M_deallocateEPS0_j:
LFB1788:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L191
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaI4EdgeEE10deallocateERS1_PS0_j
L191:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1788:
	.section	.text$_ZSt8_DestroyIP4EdgeEvT_S2_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP4EdgeEvT_S2_
	.def	__ZSt8_DestroyIP4EdgeEvT_S2_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP4EdgeEvT_S2_:
LFB1789:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIP4EdgeEEvT_S4_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1789:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev
	.def	__ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev:
LFB1792:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIiEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1792:
	.section	.text$_ZNSaIiED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIiED2Ev
	.def	__ZNSaIiED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIiED2Ev:
LFB1794:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiED2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1794:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij
	.def	__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPij:
LFB1796:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L197
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pij
L197:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1796:
	.section	.text$_ZSt8_DestroyIPiEvT_S1_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPiEvT_S1_
	.def	__ZSt8_DestroyIPiEvT_S1_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPiEvT_S1_:
LFB1797:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1797:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeE9constructIS1_JS1_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeE9constructIS1_JS1_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeE9constructIS1_JS1_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeE9constructIS1_JS1_EEEvPT_DpOT0_:
LFB1798:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjPv
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	4(%ebx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebx), %edx
	movl	%edx, 8(%eax)
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1798:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_
	.def	__ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_:
LFB1801:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1801:
	.section	.text$_ZNKSt6vectorI4EdgeSaIS0_EE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4EdgeSaIS0_EE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorI4EdgeSaIS0_EE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4EdgeSaIS0_EE12_M_check_lenEjPKc:
LFB1802:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L202
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L202:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE4sizeEv
	cmpl	%eax, -12(%ebp)
	jb	L203
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv
	cmpl	%eax, -12(%ebp)
	jbe	L204
L203:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv
	jmp	L205
L204:
	movl	-12(%ebp), %eax
L205:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1802:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE5beginEv
	.def	__ZNSt6vectorI4EdgeSaIS0_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE5beginEv:
LFB1803:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1803:
	.section	.text$_ZN9__gnu_cxxmiIP4EdgeSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIP4EdgeSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	.def	__ZN9__gnu_cxxmiIP4EdgeSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIP4EdgeSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_:
LFB1804:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1804:
	.section	.text$_ZNSt12_Vector_baseI4EdgeSaIS0_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4EdgeSaIS0_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseI4EdgeSaIS0_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4EdgeSaIS0_EE11_M_allocateEj:
LFB1805:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L212
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaI4EdgeEE8allocateERS1_j
	jmp	L214
L212:
	movl	$0, %eax
L214:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1805:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP4EdgeSt6vectorIS1_SaIS1_EEE4baseEv:
LFB1806:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1806:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIP4EdgeS1_SaIS0_EET0_T_S4_S3_RT1_:
LFB1807:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_
	movl	%eax, %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt22__uninitialized_copy_aISt13move_iteratorIP4EdgeES2_S1_ET0_T_S5_S4_RSaIT1_E
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1807:
	.section	.text$_ZNSt16allocator_traitsISaI4EdgeEE7destroyIS0_EEvRS1_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaI4EdgeEE7destroyIS0_EEvRS1_PT_
	.def	__ZNSt16allocator_traitsISaI4EdgeEE7destroyIS0_EEvRS1_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaI4EdgeEE7destroyIS0_EEvRS1_PT_:
LFB1808:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeE7destroyIS1_EEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1808:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiE9constructIiJiEEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiE9constructIiJiEEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorIiE9constructIiJiEEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiE9constructIiJiEEEvPT_DpOT0_:
LFB1809:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIiEOT_RNSt16remove_referenceIS0_E4typeE
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjPv
	movl	%ebx, (%eax)
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1809:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_:
LFB1812:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1812:
	.section	.text$_ZNKSt6vectorIiSaIiEE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIiSaIiEE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorIiSaIiEE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIiSaIiEE12_M_check_lenEjPKc:
LFB1813:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L223
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L223:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE4sizeEv
	cmpl	%eax, -12(%ebp)
	jb	L224
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE8max_sizeEv
	cmpl	%eax, -12(%ebp)
	jbe	L225
L224:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIiSaIiEE8max_sizeEv
	jmp	L226
L225:
	movl	-12(%ebp), %eax
L226:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1813:
	.section	.text$_ZNSt6vectorIiSaIiEE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE5beginEv
	.def	__ZNSt6vectorIiSaIiEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE5beginEv:
LFB1814:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1814:
	.section	.text$_ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_
	.def	__ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_:
LFB1815:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	sarl	$2, %eax
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1815:
	.section	.text$_ZNSt12_Vector_baseIiSaIiEE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIiSaIiEE11_M_allocateEj
	.def	__ZNSt12_Vector_baseIiSaIiEE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIiSaIiEE11_M_allocateEj:
LFB1816:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L233
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIiEE8allocateERS0_j
	jmp	L235
L233:
	movl	$0, %eax
L235:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1816:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv:
LFB1817:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1817:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_:
LFB1818:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_
	movl	%eax, %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1818:
	.section	.text$_ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_
	.def	__ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_:
LFB1819:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_
	subl	$4, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1819:
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implC1Ev
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE12_Vector_implC1Ev:
LFB1822:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIN8Dijkstra8HeapNodeEEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1822:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEED2Ev:
LFB1824:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1824:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE10deallocateERS2_PS1_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE10deallocateERS2_PS1_j
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE10deallocateERS2_PS1_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE10deallocateERS2_PS1_j:
LFB1826:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE10deallocateEPS2_j
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1826:
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIPN8Dijkstra8HeapNodeEEEvT_S5_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIPN8Dijkstra8HeapNodeEEEvT_S5_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIPN8Dijkstra8HeapNodeEEEvT_S5_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIPN8Dijkstra8HeapNodeEEEvT_S5_:
LFB1827:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1827:
	.section	.text$_ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	.def	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE:
LFB1828:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1828:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_:
LFB1829:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JS2_EEEvPT_DpOT0_
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1829:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB1830:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1830
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	-44(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB17:
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE5beginEv
	movl	%eax, -36(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKSA_SD_
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj
LEHE17:
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE9constructIS1_JS1_EEEvRS2_PT_DpOT0_
	movl	$0, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB18:
	call	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_
	movl	%eax, -12(%ebp)
	addl	$8, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_
LEHE18:
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
LEHB19:
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
	movl	-44(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	8(%edx), %edx
	subl	-20(%ebp), %edx
	sarl	$3, %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
LEHE19:
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L255
L253:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L250
	movl	-28(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	-32(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE7destroyIS1_EEvRS2_PT_
	jmp	L251
L250:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
LEHB20:
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeES1_EvT_S3_RSaIT0_E
L251:
	movl	-44(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE20:
L254:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB21:
	call	__Unwind_Resume
LEHE21:
L255:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1830:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1830:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1830-LLSDATTD1830
LLSDATTD1830:
	.byte	0x1
	.uleb128 LLSDACSE1830-LLSDACSB1830
LLSDACSB1830:
	.uleb128 LEHB17-LFB1830
	.uleb128 LEHE17-LEHB17
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB18-LFB1830
	.uleb128 LEHE18-LEHB18
	.uleb128 L253-LFB1830
	.uleb128 0x1
	.uleb128 LEHB19-LFB1830
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB20-LFB1830
	.uleb128 LEHE20-LEHB20
	.uleb128 L254-LFB1830
	.uleb128 0
	.uleb128 LEHB21-LFB1830
	.uleb128 LEHE21-LEHB21
	.uleb128 0
	.uleb128 0
LLSDACSE1830:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1830:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv:
LFB1831:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1831:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi:
LFB1832:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1832:
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEES4_EEbT_RT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEES4_EEbT_RT0_
	.def	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEES4_EEbT_RT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEES4_EEbT_RT0_:
LFB1833:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	%ebx, %ecx
	call	__ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_
	subl	$8, %esp
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1833:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEC1ERKS4_:
LFB1836:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1836:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPKN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEE4baseEv:
LFB1837:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1837:
	.section	.text$_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_,"x"
	.linkonce discard
	.globl	__ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_
	.def	__ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_;	.scl	2;	.type	32;	.endef
__ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops15_Iter_comp_iterISt4lessIS3_EEEEvT_T0_SF_T1_T2_:
LFB1838:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
L268:
	movl	16(%ebp), %eax
	subl	$1, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -12(%ebp)
	jge	L266
	movl	-12(%ebp), %eax
	addl	$1, %eax
	addl	%eax, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, %edx
	leal	28(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEESD_EEbT_T0_
	subl	$8, %esp
	testb	%al, %al
	je	L267
	subl	$1, -12(%ebp)
L267:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -32(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -28(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	movl	-12(%ebp), %eax
	movl	%eax, 12(%ebp)
	jmp	L268
L266:
	movl	16(%ebp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	L269
	movl	16(%ebp), %eax
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, -12(%ebp)
	jne	L269
	movl	-12(%ebp), %eax
	addl	$1, %eax
	addl	%eax, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEplEi
	subl	$4, %esp
	movl	%eax, -20(%ebp)
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 12(%ebp)
L269:
	leal	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEEEONSt16remove_referenceIT_E4typeEOSA_
	movl	%eax, %edx
	leal	-33(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1EONS0_15_Iter_comp_iterIS5_EE
	subl	$4, %esp
	leal	20(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRN8Dijkstra8HeapNodeEEONSt16remove_referenceIT_E4typeEOS4_
	movl	%eax, %edx
	leal	-33(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	(%edx), %eax
	movl	4(%edx), %edx
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1838:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE7destroyIS2_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE7destroyIS2_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE7destroyIS2_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE7destroyIS2_EEvPT_:
LFB1839:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1839:
	.section	.text$_ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE,"x"
	.linkonce discard
	.globl	__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE
	.def	__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE;	.scl	2;	.type	32;	.endef
__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE:
LFB1840:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1840:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JRKS2_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JRKS2_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JRKS2_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JRKS2_EEEvPT_DpOT0_:
LFB1841:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIRKN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS4_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjPv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1841:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE12_M_check_lenEjPKc:
LFB1842:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L275
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L275:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv
	cmpl	%eax, -12(%ebp)
	jb	L276
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv
	cmpl	%eax, -12(%ebp)
	jbe	L277
L276:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv
	jmp	L278
L277:
	movl	-12(%ebp), %eax
L278:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1842:
	.section	.text$_ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE11_M_allocateEj:
LFB1843:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L281
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8allocateERS2_j
	jmp	L283
L281:
	movl	$0, %eax
L283:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1843:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIPN8Dijkstra8HeapNodeES2_SaIS1_EET0_T_S5_S4_RT1_:
LFB1844:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_
	movl	%eax, %edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt22__uninitialized_copy_aISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_S2_ET0_T_S6_S5_RSaIT1_E
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1844:
	.section	.text$_ZNSaI4EdgeEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaI4EdgeEC2Ev
	.def	__ZNSaI4EdgeEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaI4EdgeEC2Ev:
LFB1846:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1846:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeED2Ev:
LFB1849:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1849:
	.section	.text$_ZNSt16allocator_traitsISaI4EdgeEE10deallocateERS1_PS0_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaI4EdgeEE10deallocateERS1_PS0_j
	.def	__ZNSt16allocator_traitsISaI4EdgeEE10deallocateERS1_PS0_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaI4EdgeEE10deallocateERS1_PS0_j:
LFB1851:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeE10deallocateEPS1_j
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1851:
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIP4EdgeEEvT_S4_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIP4EdgeEEvT_S4_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIP4EdgeEEvT_S4_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIP4EdgeEEvT_S4_:
LFB1852:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1852:
	.section	.text$_ZNSaIiEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIiEC2Ev
	.def	__ZNSaIiEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIiEC2Ev:
LFB1854:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1854:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIiED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiED2Ev:
LFB1857:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1857:
	.section	.text$_ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pij,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pij
	.def	__ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pij;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pij:
LFB1859:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiE10deallocateEPij
	subl	$8, %esp
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1859:
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_:
LFB1860:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1860:
	.section	.text$_ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv
	.def	__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4EdgeSaIS0_EE8max_sizeEv:
LFB1861:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaI4EdgeEE8max_sizeERKS1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1861:
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
LFB1862:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jnb	L297
	movl	12(%ebp), %eax
	jmp	L298
L297:
	movl	8(%ebp), %eax
L298:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1862:
	.section	.text$_ZNSt16allocator_traitsISaI4EdgeEE8allocateERS1_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaI4EdgeEE8allocateERS1_j
	.def	__ZNSt16allocator_traitsISaI4EdgeEE8allocateERS1_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaI4EdgeEE8allocateERS1_j:
LFB1863:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4EdgeE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1863:
	.section	.text$_ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_,"x"
	.linkonce discard
	.globl	__ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_
	.def	__ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_;	.scl	2;	.type	32;	.endef
__ZSt32__make_move_if_noexcept_iteratorI4EdgeSt13move_iteratorIPS0_EET0_PT_:
LFB1864:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt13move_iteratorIP4EdgeEC1ES1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1864:
	.section	.text$_ZSt22__uninitialized_copy_aISt13move_iteratorIP4EdgeES2_S1_ET0_T_S5_S4_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aISt13move_iteratorIP4EdgeES2_S1_ET0_T_S5_S4_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aISt13move_iteratorIP4EdgeES2_S1_ET0_T_S5_S4_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aISt13move_iteratorIP4EdgeES2_S1_ET0_T_S5_S4_RSaIT1_E:
LFB1865:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyISt13move_iteratorIP4EdgeES2_ET0_T_S5_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1865:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeE7destroyIS1_EEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeE7destroyIS1_EEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeE7destroyIS1_EEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeE7destroyIS1_EEvPT_:
LFB1866:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1866:
	.section	.text$_ZNKSt6vectorIiSaIiEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIiSaIiEE8max_sizeEv
	.def	__ZNKSt6vectorIiSaIiEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIiSaIiEE8max_sizeEv:
LFB1867:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1867:
	.section	.text$_ZNSt16allocator_traitsISaIiEE8allocateERS0_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIiEE8allocateERS0_j
	.def	__ZNSt16allocator_traitsISaIiEE8allocateERS0_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIiEE8allocateERS0_j:
LFB1868:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIiE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1868:
	.section	.text$_ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_,"x"
	.linkonce discard
	.globl	__ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_
	.def	__ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_;	.scl	2;	.type	32;	.endef
__ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_:
LFB1869:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt13move_iteratorIPiEC1ES0_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1869:
	.section	.text$_ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E:
LFB1870:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1870:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_
	.def	__ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_:
LFB1871:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1871:
	.section	.text$_ZNSaIN8Dijkstra8HeapNodeEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIN8Dijkstra8HeapNodeEEC2Ev
	.def	__ZNSaIN8Dijkstra8HeapNodeEEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaIN8Dijkstra8HeapNodeEEC2Ev:
LFB1873:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEEC2Ev
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1873:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE10deallocateEPS2_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE10deallocateEPS2_j
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE10deallocateEPS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE10deallocateEPS2_j:
LFB1875:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1875:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JS2_EEEvPT_DpOT0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JS2_EEEvPT_DpOT0_
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JS2_EEEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE9constructIS2_JS2_EEEvPT_DpOT0_:
LFB1876:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjPv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1876:
	.section	.text$_ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_
	.def	__ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_;	.scl	2;	.type	32;	.endef
__ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_:
LFB1877:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNK8Dijkstra8HeapNodeltERKS0_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1877:
	.section	.text$_ZN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEESD_EEbT_T0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEESD_EEbT_T0_
	.def	__ZN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEESD_EEbT_T0_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEclINS_17__normal_iteratorIPS4_St6vectorIS4_SaIS4_EEEESD_EEbT_T0_:
LFB1878:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %ebx
	leal	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %esi
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS2_SaIS2_EEEdeEv
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%ebx, %ecx
	call	__ZNKSt4lessIN8Dijkstra8HeapNodeEEclERKS1_S4_
	subl	$8, %esp
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1878:
	.section	.text$_ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEEEONSt16remove_referenceIT_E4typeEOSA_,"x"
	.linkonce discard
	.globl	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEEEONSt16remove_referenceIT_E4typeEOSA_
	.def	__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEEEONSt16remove_referenceIT_E4typeEOSA_;	.scl	2;	.type	32;	.endef
__ZSt4moveIRN9__gnu_cxx5__ops15_Iter_comp_iterISt4lessIN8Dijkstra8HeapNodeEEEEEONSt16remove_referenceIT_E4typeEOSA_:
LFB1879:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1879:
	.section	.text$_ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1EONS0_15_Iter_comp_iterIS5_EE,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1EONS0_15_Iter_comp_iterIS5_EE
	.def	__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1EONS0_15_Iter_comp_iterIS5_EE;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx5__ops14_Iter_comp_valISt4lessIN8Dijkstra8HeapNodeEEEC1EONS0_15_Iter_comp_iterIS5_EE:
LFB1882:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4moveIRSt4lessIN8Dijkstra8HeapNodeEEEONSt16remove_referenceIT_E4typeEOS6_
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1882:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE8max_sizeEv:
LFB1883:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8max_sizeERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1883:
	.section	.text$_ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv
	.def	__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE4sizeEv:
LFB1884:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$3, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1884:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8allocateERS2_j,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8allocateERS2_j
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8allocateERS2_j;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8allocateERS2_j:
LFB1885:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8allocateEjPKv
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1885:
	.section	.text$_ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_,"x"
	.linkonce discard
	.globl	__ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_
	.def	__ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_;	.scl	2;	.type	32;	.endef
__ZSt32__make_move_if_noexcept_iteratorIN8Dijkstra8HeapNodeESt13move_iteratorIPS1_EET0_PT_:
LFB1886:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEC1ES2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1886:
	.section	.text$_ZSt22__uninitialized_copy_aISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_S2_ET0_T_S6_S5_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_S2_ET0_T_S6_S5_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_S2_ET0_T_S6_S5_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_S2_ET0_T_S6_S5_RSaIT1_E:
LFB1887:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_ET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1887:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeEC2Ev:
LFB1889:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1889:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeE10deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeE10deallocateEPS1_j
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeE10deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeE10deallocateEPS1_j:
LFB1891:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1891:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIiEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiEC2Ev:
LFB1893:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1893:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiE10deallocateEPij,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiE10deallocateEPij
	.def	__ZN9__gnu_cxx13new_allocatorIiE10deallocateEPij;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiE10deallocateEPij:
LFB1895:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1895:
	.section	.text$_ZNSt16allocator_traitsISaI4EdgeEE8max_sizeERKS1_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaI4EdgeEE8max_sizeERKS1_
	.def	__ZNSt16allocator_traitsISaI4EdgeEE8max_sizeERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaI4EdgeEE8max_sizeERKS1_:
LFB1896:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1896:
	.section	.text$_ZNKSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseI4EdgeSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1897:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1897:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4EdgeE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4EdgeE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorI4EdgeE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4EdgeE8allocateEjPKv:
LFB1898:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv
	cmpl	%eax, 8(%ebp)
	seta	%al
	testb	%al, %al
	je	L344
	call	__ZSt17__throw_bad_allocv
L344:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1898:
	.section	.text$_ZNSt13move_iteratorIP4EdgeEC1ES1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIP4EdgeEC1ES1_
	.def	__ZNSt13move_iteratorIP4EdgeEC1ES1_;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIP4EdgeEC1ES1_:
LFB1901:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1901:
	.section	.text$_ZSt18uninitialized_copyISt13move_iteratorIP4EdgeES2_ET0_T_S5_S4_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyISt13move_iteratorIP4EdgeES2_ET0_T_S5_S4_
	.def	__ZSt18uninitialized_copyISt13move_iteratorIP4EdgeES2_ET0_T_S5_S4_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyISt13move_iteratorIP4EdgeES2_ET0_T_S5_S4_:
LFB1902:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1902:
	.section	.text$_ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_
	.def	__ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_:
LFB1903:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1903:
	.section	.text$_ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv:
LFB1904:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1904:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIiE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIiE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIiE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIiE8allocateEjPKv:
LFB1905:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv
	cmpl	%eax, 8(%ebp)
	seta	%al
	testb	%al, %al
	je	L354
	call	__ZSt17__throw_bad_allocv
L354:
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1905:
	.section	.text$_ZNSt13move_iteratorIPiEC1ES0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIPiEC1ES0_
	.def	__ZNSt13move_iteratorIPiEC1ES0_;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIPiEC1ES0_:
LFB1908:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1908:
	.section	.text$_ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_
	.def	__ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_:
LFB1909:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1909:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEEC2Ev:
LFB1911:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1911:
	.section	.text$_ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8max_sizeERKS2_,"x"
	.linkonce discard
	.globl	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8max_sizeERKS2_
	.def	__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8max_sizeERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt16allocator_traitsISaIN8Dijkstra8HeapNodeEEE8max_sizeERKS2_:
LFB1913:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1913:
	.section	.text$_ZNKSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseIN8Dijkstra8HeapNodeESaIS1_EE19_M_get_Tp_allocatorEv:
LFB1914:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1914:
	.section	.text$_ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8allocateEjPKv:
LFB1915:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv
	cmpl	%eax, 8(%ebp)
	seta	%al
	testb	%al, %al
	je	L365
	call	__ZSt17__throw_bad_allocv
L365:
	movl	8(%ebp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1915:
	.section	.text$_ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEC1ES2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEC1ES2_
	.def	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEC1ES2_;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEC1ES2_:
LFB1918:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1918:
	.section	.text$_ZSt18uninitialized_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_ET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_ET0_T_S6_S5_
	.def	__ZSt18uninitialized_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_ET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES3_ET0_T_S6_S5_:
LFB1919:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1919:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorI4EdgeE8max_sizeEv:
LFB1920:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$357913941, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1920:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_:
LFB1921:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1921
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
L374:
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB22:
	call	__ZStneIP4EdgeEbRKSt13move_iteratorIT_ES6_
LEHE22:
	testb	%al, %al
	je	L373
	leal	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIP4EdgeEdeEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofI4EdgeEPT_RS1_
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt10_ConstructI4EdgeJS0_EEvPT_DpOT0_
	leal	8(%ebp), %ecx
	call	__ZNSt13move_iteratorIP4EdgeEppEv
	addl	$12, -12(%ebp)
	jmp	L374
L373:
	movl	-12(%ebp), %eax
	jmp	L380
L378:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4EdgeEvT_S2_
LEHB23:
	call	___cxa_rethrow
LEHE23:
L379:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB24:
	call	__Unwind_Resume
LEHE24:
L380:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1921:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1921:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1921-LLSDATTD1921
LLSDATTD1921:
	.byte	0x1
	.uleb128 LLSDACSE1921-LLSDACSB1921
LLSDACSB1921:
	.uleb128 LEHB22-LFB1921
	.uleb128 LEHE22-LEHB22
	.uleb128 L378-LFB1921
	.uleb128 0x1
	.uleb128 LEHB23-LFB1921
	.uleb128 LEHE23-LEHB23
	.uleb128 L379-LFB1921
	.uleb128 0
	.uleb128 LEHB24-LFB1921
	.uleb128 LEHE24-LEHB24
	.uleb128 0
	.uleb128 0
LLSDACSE1921:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1921:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIP4EdgeES4_EET0_T_S7_S6_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv:
LFB1922:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$1073741823, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1922:
	.section	.text$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_
	.def	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_:
LFB1923:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1923:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIN8Dijkstra8HeapNodeEE8max_sizeEv:
LFB1924:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$536870911, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1924:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_:
LFB1925:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1925
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
L389:
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB25:
	call	__ZStneIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_
LEHE25:
	testb	%al, %al
	je	L388
	leal	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEEdeEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofIN8Dijkstra8HeapNodeEEPT_RS2_
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt10_ConstructIN8Dijkstra8HeapNodeEJS1_EEvPT_DpOT0_
	leal	8(%ebp), %ecx
	call	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEppEv
	addl	$8, -12(%ebp)
	jmp	L389
L388:
	movl	-12(%ebp), %eax
	jmp	L395
L393:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPN8Dijkstra8HeapNodeEEvT_S3_
LEHB26:
	call	___cxa_rethrow
LEHE26:
L394:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L395:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1925:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1925:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1925-LLSDATTD1925
LLSDATTD1925:
	.byte	0x1
	.uleb128 LLSDACSE1925-LLSDACSB1925
LLSDACSB1925:
	.uleb128 LEHB25-LFB1925
	.uleb128 LEHE25-LEHB25
	.uleb128 L393-LFB1925
	.uleb128 0x1
	.uleb128 LEHB26-LFB1925
	.uleb128 LEHE26-LEHB26
	.uleb128 L394-LFB1925
	.uleb128 0
	.uleb128 LEHB27-LFB1925
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
LLSDACSE1925:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1925:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPN8Dijkstra8HeapNodeEES5_EET0_T_S8_S7_,"x"
	.linkonce discard
	.section	.text$_ZStneIP4EdgeEbRKSt13move_iteratorIT_ES6_,"x"
	.linkonce discard
	.globl	__ZStneIP4EdgeEbRKSt13move_iteratorIT_ES6_
	.def	__ZStneIP4EdgeEbRKSt13move_iteratorIT_ES6_;	.scl	2;	.type	32;	.endef
__ZStneIP4EdgeEbRKSt13move_iteratorIT_ES6_:
LFB1926:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSteqIP4EdgeEbRKSt13move_iteratorIT_ES6_
	xorl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1926:
	.section	.text$_ZNSt13move_iteratorIP4EdgeEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIP4EdgeEppEv
	.def	__ZNSt13move_iteratorIP4EdgeEppEv;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIP4EdgeEppEv:
LFB1927:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	12(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1927:
	.section	.text$_ZSt11__addressofI4EdgeEPT_RS1_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofI4EdgeEPT_RS1_
	.def	__ZSt11__addressofI4EdgeEPT_RS1_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofI4EdgeEPT_RS1_:
LFB1928:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1928:
	.section	.text$_ZNKSt13move_iteratorIP4EdgeEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIP4EdgeEdeEv
	.def	__ZNKSt13move_iteratorIP4EdgeEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIP4EdgeEdeEv:
LFB1929:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1929:
	.section	.text$_ZSt10_ConstructI4EdgeJS0_EEvPT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZSt10_ConstructI4EdgeJS0_EEvPT_DpOT0_
	.def	__ZSt10_ConstructI4EdgeJS0_EEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructI4EdgeJS0_EEvPT_DpOT0_:
LFB1930:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardI4EdgeEOT_RNSt16remove_referenceIS1_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$12, (%esp)
	call	__ZnwjPv
	movl	(%ebx), %edx
	movl	%edx, (%eax)
	movl	4(%ebx), %edx
	movl	%edx, 4(%eax)
	movl	8(%ebx), %edx
	movl	%edx, 8(%eax)
	nop
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1930:
	.section	.text$_ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_
	.def	__ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_:
LFB1931:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1931:
	.section	.text$_ZStneIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_,"x"
	.linkonce discard
	.globl	__ZStneIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_
	.def	__ZStneIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_;	.scl	2;	.type	32;	.endef
__ZStneIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_:
LFB1932:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSteqIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_
	xorl	$1, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1932:
	.section	.text$_ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEppEv
	.def	__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEppEv;	.scl	2;	.type	32;	.endef
__ZNSt13move_iteratorIPN8Dijkstra8HeapNodeEEppEv:
LFB1933:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1933:
	.section	.text$_ZSt11__addressofIN8Dijkstra8HeapNodeEEPT_RS2_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofIN8Dijkstra8HeapNodeEEPT_RS2_
	.def	__ZSt11__addressofIN8Dijkstra8HeapNodeEEPT_RS2_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofIN8Dijkstra8HeapNodeEEPT_RS2_:
LFB1934:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1934:
	.section	.text$_ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEEdeEv
	.def	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEEdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEEdeEv:
LFB1935:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1935:
	.section	.text$_ZSt10_ConstructIN8Dijkstra8HeapNodeEJS1_EEvPT_DpOT0_,"x"
	.linkonce discard
	.globl	__ZSt10_ConstructIN8Dijkstra8HeapNodeEJS1_EEvPT_DpOT0_
	.def	__ZSt10_ConstructIN8Dijkstra8HeapNodeEJS1_EEvPT_DpOT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructIN8Dijkstra8HeapNodeEJS1_EEvPT_DpOT0_:
LFB1936:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt7forwardIN8Dijkstra8HeapNodeEEOT_RNSt16remove_referenceIS2_E4typeE
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjPv
	movl	%eax, %ecx
	movl	(%ebx), %eax
	movl	4(%ebx), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	nop
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1936:
	.section	.text$_ZSteqIP4EdgeEbRKSt13move_iteratorIT_ES6_,"x"
	.linkonce discard
	.globl	__ZSteqIP4EdgeEbRKSt13move_iteratorIT_ES6_
	.def	__ZSteqIP4EdgeEbRKSt13move_iteratorIT_ES6_;	.scl	2;	.type	32;	.endef
__ZSteqIP4EdgeEbRKSt13move_iteratorIT_ES6_:
LFB1937:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIP4EdgeE4baseEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt13move_iteratorIP4EdgeE4baseEv
	cmpl	%eax, %ebx
	sete	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1937:
	.section	.text$_ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E
	.def	__ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E:
LFB1938:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	leal	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIPiE4baseEv
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPiET_S1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1938:
	.section	.text$_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_
	.def	__ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_:
LFB1939:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPiET_S1_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPiET_S1_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPiET_S1_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1939:
	.section	.text$_ZSteqIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_,"x"
	.linkonce discard
	.globl	__ZSteqIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_
	.def	__ZSteqIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_;	.scl	2;	.type	32;	.endef
__ZSteqIPN8Dijkstra8HeapNodeEEbRKSt13move_iteratorIT_ES7_:
LFB1940:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv
	cmpl	%eax, %ebx
	sete	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1940:
	.section	.text$_ZNKSt13move_iteratorIP4EdgeE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIP4EdgeE4baseEv
	.def	__ZNKSt13move_iteratorIP4EdgeE4baseEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIP4EdgeE4baseEv:
LFB1941:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1941:
	.section	.text$_ZNKSt13move_iteratorIPiE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIPiE4baseEv
	.def	__ZNKSt13move_iteratorIPiE4baseEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIPiE4baseEv:
LFB1942:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1942:
	.section	.text$_ZSt12__miter_baseIPiET_S1_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPiET_S1_
	.def	__ZSt12__miter_baseIPiET_S1_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPiET_S1_:
LFB1943:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1943:
	.section	.text$_ZSt12__niter_baseIPiET_S1_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIPiET_S1_
	.def	__ZSt12__niter_baseIPiET_S1_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIPiET_S1_:
LFB1944:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1944:
	.section	.text$_ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_
	.def	__ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_:
LFB1945:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1945:
	.section	.text$_ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv
	.def	__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNKSt13move_iteratorIPN8Dijkstra8HeapNodeEE4baseEv:
LFB1946:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1946:
	.section	.text$_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_
	.def	__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_:
LFB1947:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L437
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_memmove
L437:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1947:
	.section	.text$_ZN8DijkstraD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN8DijkstraD1Ev
	.def	__ZN8DijkstraD1Ev;	.scl	2;	.type	32;	.endef
__ZN8DijkstraD1Ev:
LFB1951:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$20, %eax
	testl	%eax, %eax
	je	L440
	movl	-12(%ebp), %eax
	addl	$20, %eax
	leal	12240(%eax), %ebx
L441:
	movl	-12(%ebp), %eax
	addl	$20, %eax
	cmpl	%eax, %ebx
	je	L440
	subl	$12, %ebx
	movl	%ebx, %ecx
	call	__ZNSt6vectorIiSaIiEED1Ev
	jmp	L441
L440:
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EED1Ev
	nop
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1951:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1952:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$_dijkstra, %ecx
	call	__ZN8DijkstraD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1952:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1948:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L445
	cmpl	$65535, 12(%ebp)
	jne	L445
	movl	$_dijkstra, %ecx
	call	__ZN8DijkstraC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L445:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1948:
	.def	__GLOBAL__sub_I_dijkstra;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_dijkstra:
LFB1953:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1953:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_dijkstra
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
