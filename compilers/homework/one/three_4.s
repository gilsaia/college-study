	.file	"three.cpp"
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1965:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$_dijkstra+12248, %ebx
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
L2:
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L3
	movl	%eax, (%esp)
	subl	$12, %ebx
	call	__ZdlPv
	cmpl	$_dijkstra+8, %ebx
	jne	L2
L4:
	movl	_dijkstra+8, %eax
	testl	%eax, %eax
	je	L1
	movl	%eax, (%esp)
	call	__ZdlPv
L1:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
L3:
	.cfi_restore_state
	subl	$12, %ebx
	cmpl	$_dijkstra+8, %ebx
	jne	L2
	jmp	L4
	.cfi_endproc
LFE1965:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_:
LFB1763:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	(%ecx), %edi
	movl	4(%ecx), %eax
	movl	64(%esp), %ebx
	movl	68(%esp), %edx
	movl	%ecx, 24(%esp)
	movl	%eax, 20(%esp)
	subl	%edi, %eax
	sarl	$2, %eax
	movl	%ebx, %ebp
	imull	$-1431655765, %eax, %eax
	subl	%edi, %ebp
	testl	%eax, %eax
	je	L22
	leal	(%eax,%eax), %esi
	movl	$-4, %ecx
	cmpl	%esi, %eax
	jbe	L31
L16:
	movl	%ecx, (%esp)
	movl	%edx, 68(%esp)
	movl	%ecx, 28(%esp)
	call	__Znwj
	movl	28(%esp), %ecx
	movl	68(%esp), %edx
	movl	%eax, %esi
	leal	(%eax,%ecx), %eax
	leal	12(%esi), %ecx
	movl	%eax, 28(%esp)
L17:
	movl	(%edx), %eax
	movl	%eax, (%esi,%ebp)
	movl	4(%edx), %eax
	movl	%eax, 4(%esi,%ebp)
	movl	8(%edx), %eax
	movl	%eax, 8(%esi,%ebp)
	cmpl	%edi, %ebx
	je	L18
	movl	%edi, %eax
	movl	%esi, %edx
	.p2align 4,,10
L19:
	movl	(%eax), %ecx
	addl	$12, %eax
	addl	$12, %edx
	movl	%ecx, -12(%edx)
	movl	-8(%eax), %ecx
	movl	%ecx, -8(%edx)
	movl	-4(%eax), %ecx
	movl	%ecx, -4(%edx)
	cmpl	%eax, %ebx
	jne	L19
	leal	-12(%ebx), %eax
	subl	%edi, %eax
	shrl	$2, %eax
	imull	$715827883, %eax, %eax
	leal	(%eax,%eax,2), %eax
	leal	24(%esi,%eax,4), %ecx
L18:
	movl	20(%esp), %eax
	cmpl	%eax, %ebx
	je	L20
	subl	%ebx, %eax
	movl	%ecx, (%esp)
	subl	$12, %eax
	movl	%ebx, 4(%esp)
	shrl	$2, %eax
	movl	%ecx, 20(%esp)
	imull	$715827883, %eax, %eax
	leal	(%eax,%eax,2), %eax
	leal	12(,%eax,4), %ebp
	movl	%ebp, 8(%esp)
	call	_memcpy
	movl	20(%esp), %ecx
	addl	%ebp, %ecx
L20:
	testl	%edi, %edi
	je	L21
	movl	%edi, (%esp)
	movl	%ecx, 20(%esp)
	call	__ZdlPv
	movl	20(%esp), %ecx
L21:
	movl	24(%esp), %eax
	movl	28(%esp), %edi
	movl	%esi, (%eax)
	movl	%ecx, 4(%eax)
	movl	%edi, 8(%eax)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	$8
	.p2align 4,,10
L31:
	.cfi_restore_state
	cmpl	$357913941, %esi
	ja	L16
	testl	%esi, %esi
	jne	L15
	movl	$12, %ecx
	movl	$0, 28(%esp)
	xorl	%esi, %esi
	jmp	L17
	.p2align 4,,10
L22:
	movl	$1, %esi
L15:
	leal	(%esi,%esi,2), %ecx
	sall	$2, %ecx
	jmp	L16
	.cfi_endproc
LFE1763:
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
LFB1766:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	movl	%ecx, %ebx
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	4(%ecx), %ebp
	movl	(%ecx), %esi
	movl	64(%esp), %edx
	movl	%ebp, %edi
	subl	%esi, %edi
	subl	%esi, %edx
	sarl	$2, %edi
	je	L41
	leal	(%edi,%edi), %eax
	movl	$-4, %ecx
	cmpl	%eax, %edi
	jbe	L47
L34:
	movl	%ecx, (%esp)
	movl	%edx, 24(%esp)
	movl	%ecx, 16(%esp)
	call	__Znwj
	movl	16(%esp), %ecx
	movl	24(%esp), %edx
	movl	%eax, %edi
	leal	(%eax,%ecx), %eax
	movl	%eax, 20(%esp)
L35:
	movl	68(%esp), %eax
	leal	4(%edi,%edx), %ecx
	movl	(%eax), %eax
	movl	%eax, (%edi,%edx)
	movl	%ebp, %eax
	subl	64(%esp), %eax
	movl	%eax, 24(%esp)
	addl	%ecx, %eax
	movl	%eax, 16(%esp)
	cmpl	%esi, 64(%esp)
	je	L36
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	%ecx, 28(%esp)
	call	_memmove
	cmpl	%ebp, 64(%esp)
	movl	28(%esp), %ecx
	je	L40
L37:
	movl	24(%esp), %eax
	movl	%ecx, (%esp)
	movl	%eax, 8(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	call	_memcpy
L39:
	testl	%esi, %esi
	jne	L40
L38:
	movl	16(%esp), %eax
	movl	%edi, (%ebx)
	movl	%eax, 4(%ebx)
	movl	20(%esp), %eax
	movl	%eax, 8(%ebx)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	$8
	.p2align 4,,10
L40:
	.cfi_restore_state
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L38
	.p2align 4,,10
L47:
	cmpl	$1073741823, %eax
	ja	L34
	movl	$0, 20(%esp)
	xorl	%edi, %edi
	testl	%eax, %eax
	je	L35
	jmp	L33
	.p2align 4,,10
L36:
	cmpl	%ebp, 64(%esp)
	jne	L37
	jmp	L39
	.p2align 4,,10
L41:
	movl	$1, %eax
L33:
	leal	0(,%eax,4), %ecx
	jmp	L34
	.cfi_endproc
LFE1766:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB1796:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	4(%ecx), %esi
	movl	(%ecx), %edi
	movl	64(%esp), %ebx
	movl	68(%esp), %edx
	movl	%ecx, 24(%esp)
	movl	%esi, %eax
	subl	%edi, %eax
	movl	%ebx, %ecx
	subl	%edi, %ecx
	sarl	$3, %eax
	movl	%ecx, 20(%esp)
	je	L57
	leal	(%eax,%eax), %ebp
	movl	$-8, %ecx
	cmpl	%ebp, %eax
	jbe	L67
L50:
	movl	%ecx, (%esp)
	movl	%edx, 68(%esp)
	movl	%ecx, 16(%esp)
	call	__Znwj
	movl	16(%esp), %ecx
	movl	68(%esp), %edx
	movl	%eax, %ebp
	leal	(%eax,%ecx), %eax
	movl	%eax, 28(%esp)
	leal	8(%ebp), %eax
	movl	%eax, 16(%esp)
L51:
	movl	20(%esp), %ecx
	movl	4(%edx), %eax
	movl	(%edx), %edx
	addl	%ebp, %ecx
	movl	%eax, 4(%ecx)
	movl	%edx, (%ecx)
	cmpl	%edi, %ebx
	je	L52
	movl	%esi, 16(%esp)
	movl	%edi, %edx
	movl	%ebp, %eax
	.p2align 4,,10
L53:
	movl	4(%edx), %ecx
	movl	(%edx), %esi
	addl	$8, %edx
	addl	$8, %eax
	movl	%esi, -8(%eax)
	movl	%ecx, -4(%eax)
	cmpl	%edx, %ebx
	jne	L53
	leal	-8(%ebx), %eax
	movl	16(%esp), %esi
	subl	%edi, %eax
	shrl	$3, %eax
	leal	16(%ebp,%eax,8), %eax
	movl	%eax, 16(%esp)
L52:
	cmpl	%esi, %ebx
	je	L54
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	.p2align 4,,10
L55:
	movl	(%edx), %eax
	addl	$8, %edx
	addl	$8, %ecx
	movl	%eax, -8(%ecx)
	movl	-4(%edx), %eax
	movl	%eax, -4(%ecx)
	cmpl	%edx, %esi
	jne	L55
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-8(%esi), %edx
	shrl	$3, %edx
	leal	8(%eax,%edx,8), %eax
	movl	%eax, 16(%esp)
L54:
	testl	%edi, %edi
	je	L56
	movl	%edi, (%esp)
	call	__ZdlPv
L56:
	movl	24(%esp), %edi
	movl	28(%esp), %ebx
	movl	16(%esp), %eax
	movl	%ebp, (%edi)
	movl	%eax, 4(%edi)
	movl	%ebx, 8(%edi)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	$8
	.p2align 4,,10
L67:
	.cfi_restore_state
	cmpl	$536870911, %ebp
	ja	L50
	testl	%ebp, %ebp
	jne	L49
	movl	$8, 16(%esp)
	xorl	%ebp, %ebp
	movl	$0, 28(%esp)
	jmp	L51
	.p2align 4,,10
L57:
	movl	$1, %ebp
L49:
	leal	0(,%ebp,8), %ecx
	jmp	L50
	.cfi_endproc
LFE1796:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB1844:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	4(%ecx), %esi
	movl	(%ecx), %edi
	movl	64(%esp), %ebx
	movl	68(%esp), %edx
	movl	%ecx, 24(%esp)
	movl	%esi, %eax
	subl	%edi, %eax
	movl	%ebx, %ecx
	subl	%edi, %ecx
	sarl	$3, %eax
	movl	%ecx, 20(%esp)
	je	L77
	leal	(%eax,%eax), %ebp
	movl	$-8, %ecx
	cmpl	%ebp, %eax
	jbe	L87
L70:
	movl	%ecx, (%esp)
	movl	%edx, 68(%esp)
	movl	%ecx, 16(%esp)
	call	__Znwj
	movl	16(%esp), %ecx
	movl	68(%esp), %edx
	movl	%eax, %ebp
	leal	(%eax,%ecx), %eax
	movl	%eax, 28(%esp)
	leal	8(%ebp), %eax
	movl	%eax, 16(%esp)
L71:
	movl	20(%esp), %ecx
	movl	4(%edx), %eax
	movl	(%edx), %edx
	addl	%ebp, %ecx
	movl	%eax, 4(%ecx)
	movl	%edx, (%ecx)
	cmpl	%edi, %ebx
	je	L72
	movl	%esi, 16(%esp)
	movl	%edi, %edx
	movl	%ebp, %eax
	.p2align 4,,10
L73:
	movl	4(%edx), %ecx
	movl	(%edx), %esi
	addl	$8, %edx
	addl	$8, %eax
	movl	%esi, -8(%eax)
	movl	%ecx, -4(%eax)
	cmpl	%edx, %ebx
	jne	L73
	leal	-8(%ebx), %eax
	movl	16(%esp), %esi
	subl	%edi, %eax
	shrl	$3, %eax
	leal	16(%ebp,%eax,8), %eax
	movl	%eax, 16(%esp)
L72:
	cmpl	%esi, %ebx
	je	L74
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	.p2align 4,,10
L75:
	movl	(%edx), %eax
	addl	$8, %edx
	addl	$8, %ecx
	movl	%eax, -8(%ecx)
	movl	-4(%edx), %eax
	movl	%eax, -4(%ecx)
	cmpl	%edx, %esi
	jne	L75
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-8(%esi), %edx
	shrl	$3, %edx
	leal	8(%eax,%edx,8), %eax
	movl	%eax, 16(%esp)
L74:
	testl	%edi, %edi
	je	L76
	movl	%edi, (%esp)
	call	__ZdlPv
L76:
	movl	24(%esp), %edi
	movl	28(%esp), %ebx
	movl	16(%esp), %eax
	movl	%ebp, (%edi)
	movl	%eax, 4(%edi)
	movl	%ebx, 8(%edi)
	addl	$44, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret	$8
	.p2align 4,,10
L87:
	.cfi_restore_state
	cmpl	$536870911, %ebp
	ja	L70
	testl	%ebp, %ebp
	jne	L69
	movl	$8, 16(%esp)
	xorl	%ebp, %ebp
	movl	$0, 28(%esp)
	jmp	L71
	.p2align 4,,10
L77:
	movl	$1, %ebp
L69:
	leal	0(,%ebp,8), %ecx
	jmp	L70
	.cfi_endproc
LFE1844:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8Dijkstra8dijkstraEi
	.def	__ZN8Dijkstra8dijkstraEi;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra8dijkstraEi:
LFB1665:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1665
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	(%ecx), %eax
	movl	8(%ebp), %ebx
	movl	%ecx, -64(%ebp)
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	testl	%eax, %eax
	jle	L91
	sall	$2, %eax
	movl	$63, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-64(%ebp), %eax
	addl	$13280, %eax
	movl	%eax, (%esp)
	call	_memset
L91:
	movl	-64(%ebp), %eax
	leal	12264(%eax), %edi
	leal	12260(%eax), %ecx
	movl	$0, 13280(%eax,%ebx,4)
	movl	$0, 12260(%eax)
	andl	$-4, %edi
	movl	$0, 13276(%eax)
	subl	%edi, %ecx
	xorl	%eax, %eax
	addl	$1020, %ecx
	shrl	$2, %ecx
	rep stosl
	leal	-48(%ebp), %eax
	movl	$0, (%esp)
	leal	-40(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	$0, -48(%ebp)
	movl	%ebx, -44(%ebp)
LEHB0:
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	movl	-36(%ebp), %eax
	movl	-40(%ebp), %edx
	subl	$8, %esp
	movl	-4(%eax), %edi
	movl	-8(%eax), %esi
	movl	%eax, -80(%ebp)
	subl	%edx, %eax
	sarl	$3, %eax
	movl	%edx, -68(%ebp)
	leal	-1(%eax), %ebx
	subl	$2, %eax
	movl	%edi, -60(%ebp)
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%eax, %edx
	sarl	%edx
	testl	%ebx, %ebx
	jle	L150
	movl	-68(%ebp), %eax
	leal	(%eax,%edx,8), %ecx
	cmpl	(%ecx), %esi
	jge	L151
	movl	%ebx, %eax
	movl	-68(%ebp), %edi
	jmp	L93
	.p2align 4,,10
L94:
	leal	(%edi,%ebx,8), %ecx
	movl	%edx, %eax
	cmpl	(%ecx), %esi
	jge	L144
	movl	%ebx, %edx
L93:
	movl	4(%ecx), %ebx
	movl	(%ecx), %ecx
	movl	%ebx, 4(%edi,%eax,8)
	movl	%ecx, (%edi,%eax,8)
	leal	-1(%edx), %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%eax, %ebx
	sarl	%ebx
	testl	%edx, %edx
	jg	L94
L144:
	movl	%edi, -68(%ebp)
	movl	%edi, %eax
L92:
	movl	-60(%ebp), %edi
	leal	(%eax,%edx,8), %eax
	movl	%esi, (%eax)
	movl	%edi, 4(%eax)
L111:
	movl	-80(%ebp), %eax
	movl	-68(%ebp), %edx
	cmpl	%eax, %edx
	je	L95
	movl	-64(%ebp), %edi
	movl	%eax, -64(%ebp)
	movl	%edi, -68(%ebp)
	movl	%edx, %edi
L109:
	movl	-64(%ebp), %esi
	movl	4(%edi), %eax
	movl	%eax, -72(%ebp)
	movl	%esi, %eax
	subl	$8, %esi
	subl	%edi, %eax
	movl	%esi, -64(%ebp)
	cmpl	$8, %eax
	jg	L152
L96:
	movl	-68(%ebp), %esi
	movl	-72(%ebp), %edx
	movl	-64(%ebp), %eax
	cmpb	$0, 12260(%esi,%edx)
	movl	%eax, -36(%ebp)
	je	L108
	cmpl	%eax, %edi
	jne	L109
	movl	%eax, -80(%ebp)
L95:
	movl	-80(%ebp), %eax
	testl	%eax, %eax
	je	L88
	movl	%eax, (%esp)
	call	__ZdlPv
L88:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.p2align 4,,10
L108:
	.cfi_restore_state
	movl	%eax, -80(%ebp)
	leal	(%edx,%edx,2), %eax
	leal	20(%esi,%eax,4), %eax
	movl	%edi, -68(%ebp)
	movl	%eax, -96(%ebp)
	movl	(%eax), %edi
	movl	4(%eax), %eax
	movb	$1, 12260(%esi,%edx)
	addl	$3320, %edx
	movl	%esi, -64(%ebp)
	xorl	%esi, %esi
	movl	%edi, -60(%ebp)
	movl	%eax, -84(%ebp)
	movl	%edx, -88(%ebp)
	cmpl	%edi, %eax
	jne	L110
	jmp	L111
	.p2align 4,,10
L112:
	movl	-84(%ebp), %eax
	subl	-60(%ebp), %eax
	addl	$1, %esi
	sarl	$2, %eax
	cmpl	%esi, %eax
	jbe	L111
L110:
	movl	-60(%ebp), %eax
	movl	-64(%ebp), %ebx
	movl	-88(%ebp), %edi
	leal	(%eax,%esi,4), %edx
	movl	(%edx), %eax
	leal	(%eax,%eax,2), %ecx
	movl	8(%ebx), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	4(%ecx), %eax
	movl	8(%ecx), %ecx
	addl	(%ebx,%edi,4), %ecx
	movl	%eax, -72(%ebp)
	leal	(%ebx,%eax,4), %eax
	cmpl	%ecx, 13280(%eax)
	jle	L112
	movl	%ecx, 13280(%eax)
	movl	-72(%ebp), %edi
	movl	(%edx), %edx
	movl	%ecx, -48(%ebp)
	movl	%edi, -44(%ebp)
	movl	%edx, 17360(%eax)
	movl	-80(%ebp), %eax
	cmpl	%eax, -32(%ebp)
	je	L113
	movl	%ecx, (%eax)
	addl	$8, %eax
	movl	%edi, -4(%eax)
	movl	%eax, -80(%ebp)
	movl	%eax, -36(%ebp)
L114:
	movl	-68(%ebp), %ebx
	subl	%ebx, %eax
	sarl	$3, %eax
	leal	-1(%eax), %edi
	subl	$2, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%eax, %edx
	sarl	%edx
	testl	%edi, %edi
	jle	L128
	leal	(%ebx,%edx,8), %ebx
	cmpl	%ecx, (%ebx)
	jle	L153
	movl	%esi, -92(%ebp)
	movl	%edi, %esi
	movl	-68(%ebp), %edi
	movl	%ecx, -76(%ebp)
	jmp	L116
	.p2align 4,,10
L117:
	leal	(%edi,%eax,8), %ebx
	movl	%edx, %esi
	movl	-76(%ebp), %ecx
	cmpl	%ecx, (%ebx)
	jle	L148
	movl	%eax, %edx
L116:
	movl	(%ebx), %ecx
	movl	4(%ebx), %ebx
	movl	%ebx, 4(%edi,%esi,8)
	leal	-1(%edx), %ebx
	movl	%ebx, %eax
	movl	%ecx, (%edi,%esi,8)
	shrl	$31, %eax
	addl	%ebx, %eax
	sarl	%eax
	testl	%edx, %edx
	jg	L117
	movl	-76(%ebp), %ecx
	movl	-92(%ebp), %esi
	movl	%edi, -68(%ebp)
	movl	%edi, %eax
L115:
	movl	-72(%ebp), %edi
	leal	(%eax,%edx,8), %eax
	movl	%ecx, (%eax)
	movl	%edi, 4(%eax)
	jmp	L112
	.p2align 4,,10
L148:
	movl	-92(%ebp), %esi
	movl	%edi, -68(%ebp)
	movl	%edi, %eax
	jmp	L115
	.p2align 4,,10
L152:
	movl	(%esi), %eax
	movl	4(%edi), %edx
	movl	%eax, -76(%ebp)
	movl	4(%esi), %eax
	movl	%eax, -80(%ebp)
	movl	(%edi), %eax
	movl	%edx, 4(%esi)
	movl	%eax, (%esi)
	movl	%esi, %eax
	subl	%edi, %eax
	movl	%eax, %ebx
	sarl	$3, %ebx
	leal	-1(%ebx), %edx
	movl	%ebx, -92(%ebp)
	andl	$1, %ebx
	movl	%edx, %ecx
	movl	%ebx, -84(%ebp)
	shrl	$31, %ecx
	addl	%edx, %ecx
	sarl	%ecx
	movl	%ecx, -60(%ebp)
	cmpl	$16, %eax
	jle	L97
	movl	%ecx, %eax
	movl	%esi, -88(%ebp)
	xorl	%ecx, %ecx
	movl	%eax, -64(%ebp)
	.p2align 4,,10
L98:
	leal	1(%ecx), %eax
	leal	(%eax,%eax), %edx
	sall	$4, %eax
	leal	-1(%edx), %esi
	addl	%edi, %eax
	movl	%esi, -60(%ebp)
	leal	(%edi,%esi,8), %esi
	movl	(%eax), %ebx
	cmpl	%ebx, (%esi)
	jl	L99
	movl	(%eax), %ebx
	movl	4(%eax), %esi
	movl	%ebx, (%edi,%ecx,8)
	movl	%esi, 4(%edi,%ecx,8)
	cmpl	%edx, -64(%ebp)
	jle	L154
L101:
	movl	%edx, %ecx
	jmp	L98
	.p2align 4,,10
L154:
	movl	-88(%ebp), %esi
	movl	-84(%ebp), %ecx
	movl	%esi, -64(%ebp)
	testl	%ecx, %ecx
	jne	L104
L155:
	movl	-92(%ebp), %ecx
	subl	$2, %ecx
	movl	%ecx, %ebx
	shrl	$31, %ebx
	addl	%ebx, %ecx
	leal	-1(%edx), %ebx
	sarl	%ecx
	sarl	%ebx
	cmpl	%edx, %ecx
	je	L103
L122:
	leal	(%edi,%ebx,8), %esi
	movl	-76(%ebp), %ecx
	cmpl	%ecx, (%esi)
	jle	L102
	movl	-64(%ebp), %eax
	movl	%ebx, -60(%ebp)
	movl	%eax, -84(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, -64(%ebp)
	jmp	L106
	.p2align 4,,10
L107:
	movl	%esi, %edx
	leal	(%edi,%ecx,8), %esi
	movl	%ecx, -60(%ebp)
	movl	-64(%ebp), %ecx
	cmpl	(%esi), %ecx
	jge	L146
L106:
	movl	(%esi), %ebx
	movl	4(%esi), %esi
	movl	%esi, 4(%edi,%edx,8)
	movl	-60(%ebp), %esi
	movl	%ebx, (%edi,%edx,8)
	leal	-1(%esi), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%eax, %ecx
	leal	(%edi,%esi,8), %eax
	sarl	%ecx
	testl	%esi, %esi
	jne	L107
L146:
	movl	-84(%ebp), %esi
	movl	%esi, -64(%ebp)
L102:
	movl	-76(%ebp), %esi
	movl	%esi, (%eax)
	movl	-80(%ebp), %esi
	movl	%esi, 4(%eax)
	jmp	L96
	.p2align 4,,10
L99:
	movl	4(%esi), %edx
	movl	(%esi), %eax
	movl	%edx, 4(%edi,%ecx,8)
	movl	-60(%ebp), %edx
	movl	%eax, (%edi,%ecx,8)
	cmpl	%edx, -64(%ebp)
	jg	L101
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %ecx
	movl	%eax, -64(%ebp)
	movl	%esi, %eax
	testl	%ecx, %ecx
	je	L155
L104:
	leal	-1(%edx), %ebx
	sarl	%ebx
	jmp	L122
	.p2align 4,,10
L113:
	leal	-48(%ebp), %eax
	leal	-40(%ebp), %ecx
	movl	%eax, 4(%esp)
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
LEHE0:
	movl	-36(%ebp), %eax
	subl	$8, %esp
	movl	%eax, -80(%ebp)
	movl	-8(%eax), %ecx
	movl	-4(%eax), %eax
	movl	%eax, -72(%ebp)
	movl	-96(%ebp), %eax
	movl	(%eax), %edi
	movl	4(%eax), %eax
	movl	%eax, -84(%ebp)
	movl	-40(%ebp), %eax
	movl	%edi, -60(%ebp)
	movl	%eax, -68(%ebp)
	movl	-80(%ebp), %eax
	jmp	L114
	.p2align 4,,10
L128:
	movl	%edi, %edx
	movl	%ebx, %eax
	jmp	L115
	.p2align 4,,10
L153:
	movl	%edi, %edx
	movl	-68(%ebp), %eax
	jmp	L115
L97:
	movl	-84(%ebp), %ebx
	movl	%edi, %eax
	testl	%ebx, %ebx
	jne	L102
	cmpl	$2, %edx
	ja	L102
	xorl	%edx, %edx
	.p2align 4,,10
L103:
	leal	1(%edx,%edx), %edx
	leal	(%edi,%edx,8), %ecx
	movl	(%ecx), %ebx
	movl	4(%ecx), %esi
	movl	%ebx, (%eax)
	leal	-1(%edx), %ebx
	movl	%esi, 4(%eax)
	sarl	%ebx
	movl	%ecx, %eax
	jmp	L122
L150:
	movl	%ebx, %edx
	movl	-68(%ebp), %eax
	jmp	L92
L151:
	movl	%ebx, %edx
	jmp	L92
L129:
	movl	%eax, %ebx
L120:
	movl	-40(%ebp), %edx
	testl	%edx, %edx
	je	L121
	movl	%edx, (%esp)
	call	__ZdlPv
L121:
	movl	%ebx, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
	.cfi_endproc
LFE1665:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1665:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1665-LLSDACSB1665
LLSDACSB1665:
	.uleb128 LEHB0-LFB1665
	.uleb128 LEHE0-LEHB0
	.uleb128 L129-LFB1665
	.uleb128 0
	.uleb128 LEHB1-LFB1665
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE1665:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d%d\0"
LC1:
	.ascii "%d\12\0"
LC2:
	.ascii "%d%d%d\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1672:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$56, %esp
	call	___main
	leal	-56(%ebp), %eax
	movl	$LC0, (%esp)
	movl	%eax, 8(%esp)
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_scanf
	movl	-56(%ebp), %ebx
	movl	%ebx, _dijkstra
	testl	%ebx, %ebx
	jle	L161
	leal	(%ebx,%ebx,2), %ecx
	xorl	%eax, %eax
	sall	$2, %ecx
	.p2align 4,,10
L162:
	movl	_dijkstra+20(%eax), %edx
	cmpl	_dijkstra+24(%eax), %edx
	je	L160
	movl	%edx, _dijkstra+24(%eax)
L160:
	addl	$12, %eax
	cmpl	%ecx, %eax
	jne	L162
L161:
	movl	_dijkstra+8, %eax
	cmpl	_dijkstra+12, %eax
	je	L159
	movl	%eax, _dijkstra+12
L159:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	jle	L171
	xorl	%ebx, %ebx
	.p2align 4,,10
L163:
	leal	-40(%ebp), %eax
	movl	$LC2, (%esp)
	movl	%eax, 12(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_scanf
	movl	-48(%ebp), %eax
	leal	-1(%eax), %esi
	movl	-44(%ebp), %eax
	movl	%esi, -48(%ebp)
	subl	$1, %eax
	movl	%esi, -36(%ebp)
	movl	%eax, -44(%ebp)
	movl	%eax, -32(%ebp)
	movl	-40(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	_dijkstra+12, %eax
	cmpl	_dijkstra+16, %eax
	je	L164
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L165:
	movl	%eax, %edx
	subl	_dijkstra+8, %edx
	leal	(%esi,%esi,2), %ecx
	sarl	$2, %edx
	sall	$2, %ecx
	imull	$-1431655765, %edx, %edx
	movl	_dijkstra+24(%ecx), %esi
	movl	%edx, _dijkstra+4
	subl	$1, %edx
	movl	%edx, -36(%ebp)
	cmpl	_dijkstra+28(%ecx), %esi
	je	L166
	movl	%edx, (%esi)
	addl	$4, %esi
	movl	%esi, _dijkstra+24(%ecx)
L167:
	movl	-48(%ebp), %edx
	movl	-44(%ebp), %esi
	movl	%edx, -32(%ebp)
	movl	-40(%ebp), %edx
	movl	%esi, -36(%ebp)
	movl	%edx, -28(%ebp)
	cmpl	%eax, _dijkstra+16
	je	L168
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L169:
	subl	_dijkstra+8, %eax
	leal	(%esi,%esi,2), %ecx
	sarl	$2, %eax
	sall	$2, %ecx
	imull	$-1431655765, %eax, %eax
	movl	_dijkstra+24(%ecx), %edx
	movl	%eax, _dijkstra+4
	subl	$1, %eax
	movl	%eax, -36(%ebp)
	cmpl	_dijkstra+28(%ecx), %edx
	je	L170
	movl	%eax, (%edx)
	addl	$4, %edx
	addl	$1, %ebx
	movl	%edx, _dijkstra+24(%ecx)
	cmpl	%ebx, -52(%ebp)
	jg	L163
L178:
	movl	-56(%ebp), %ebx
L171:
	subl	$1, %ebx
	movl	$_dijkstra, %ecx
	movl	%ebx, (%esp)
	call	__ZN8Dijkstra8dijkstraEi
	movl	_dijkstra+13280, %eax
	subl	$4, %esp
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	-16(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.p2align 4,,10
L170:
	.cfi_restore_state
	leal	-36(%ebp), %eax
	movl	%edx, (%esp)
	addl	$_dijkstra+20, %ecx
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	subl	$8, %esp
	cmpl	-52(%ebp), %ebx
	jl	L163
	jmp	L178
	.p2align 4,,10
L168:
	leal	-36(%ebp), %edi
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	movl	%edi, 4(%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L169
	.p2align 4,,10
L164:
	leal	-36(%ebp), %edi
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	movl	%edi, 4(%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L165
	.p2align 4,,10
L166:
	leal	-36(%ebp), %eax
	movl	%esi, (%esp)
	addl	$_dijkstra+20, %ecx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L167
	.cfi_endproc
LFE1672:
	.p2align 4,,15
	.def	__GLOBAL__sub_I_dijkstra;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_dijkstra:
LFB1966:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$_dijkstra+20, %eax
	movl	$0, _dijkstra+8
	movl	$0, _dijkstra+12
	movl	$0, _dijkstra+16
	.p2align 4,,10
L180:
	movl	$0, (%eax)
	addl	$12, %eax
	movl	$0, -8(%eax)
	movl	$0, -4(%eax)
	cmpl	$_dijkstra+12260, %eax
	jne	L180
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1966:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_dijkstra
	.globl	_dijkstra
	.bss
	.align 32
_dijkstra:
	.space 21440
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
