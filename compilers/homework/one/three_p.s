	.file	"three.cpp"
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1961:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	$_dijkstra+12000248, %ebx
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
LFE1961:
	.p2align 4,,15
	.def	__ZN8Dijkstra8dijkstraEi._omp_fn.0;	.scl	3;	.type	32;	.endef
__ZN8Dijkstra8dijkstraEi._omp_fn.0:
LFB1963:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1963
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
	subl	$76, %esp
	.cfi_def_cfa_offset 96
	movl	96(%esp), %eax
	movl	96(%esp), %ebx
	movl	$0, 28(%esp)
	movl	8(%eax), %eax
	movl	(%ebx), %ebp
	leal	(%eax,%eax,2), %edx
	addl	$3250068, %eax
	leal	20(%ebp,%edx,4), %esi
	movl	%eax, 44(%esp)
	movl	(%esi), %edx
	movl	%esi, 56(%esp)
	movl	4(%esi), %esi
	movl	%edx, 32(%esp)
	movl	%esi, 40(%esp)
	cmpl	%edx, %esi
	jne	L15
	jmp	L14
	.p2align 4,,10
L28:
	addl	$1, 28(%esp)
	movl	40(%esp), %eax
	movl	28(%esp), %edi
	subl	32(%esp), %eax
	sarl	$2, %eax
	cmpl	%edi, %eax
	jbe	L14
L15:
	movl	32(%esp), %eax
	movl	28(%esp), %esi
	leal	(%eax,%esi,4), %edx
	movl	(%edx), %eax
	leal	(%eax,%eax,2), %ecx
	movl	8(%ebp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	4(%ecx), %eax
	movl	8(%ecx), %esi
	movl	44(%esp), %ecx
	movl	%eax, 36(%esp)
	leal	0(%ebp,%eax,4), %eax
	addl	8(%ebp,%ecx,4), %esi
	cmpl	%esi, 13000280(%eax)
	jle	L28
	movl	%esi, 13000280(%eax)
	movl	(%edx), %edx
	movl	%edx, 17000360(%eax)
	movl	96(%esp), %eax
	movl	4(%eax), %ecx
	movl	4(%ecx), %ebx
	movl	(%ecx), %edi
	movl	%ecx, 52(%esp)
	cmpl	8(%ecx), %ebx
	je	L18
	movl	36(%esp), %eax
	movl	%esi, (%ebx)
	movl	%eax, 4(%ebx)
	leal	8(%ebx), %eax
	movl	%eax, 4(%ecx)
	subl	%edi, %eax
	sarl	$3, %eax
	leal	-1(%eax), %ecx
	subl	$2, %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%eax, %ebx
	leal	(%edi,%ecx,8), %eax
	movl	%eax, 48(%esp)
	sarl	%ebx
L19:
	testl	%ecx, %ecx
	jle	L25
	leal	(%edi,%ebx,8), %edx
	cmpl	%esi, (%edx)
	jle	L25
	movl	%ebp, 52(%esp)
	jmp	L26
	.p2align 4,,10
L27:
	leal	(%edi,%eax,8), %edx
	movl	%ebx, %ecx
	movl	%eax, %ebx
	cmpl	%esi, (%edx)
	jle	L43
L26:
	movl	(%edx), %eax
	movl	4(%edx), %edx
	leal	(%edi,%ebx,8), %ebp
	movl	%edx, 4(%edi,%ecx,8)
	leal	-1(%ebx), %edx
	movl	%eax, (%edi,%ecx,8)
	movl	%edx, %eax
	shrl	$31, %eax
	addl	%edx, %eax
	sarl	%eax
	testl	%ebx, %ebx
	jg	L27
L43:
	movl	%ebp, 48(%esp)
	movl	52(%esp), %ebp
L25:
	movl	48(%esp), %eax
	movl	%esi, (%eax)
	movl	36(%esp), %esi
	movl	%esi, 4(%eax)
	jmp	L28
	.p2align 4,,10
L14:
	addl	$76, %esp
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
	ret
	.p2align 4,,10
L18:
	.cfi_restore_state
	movl	%ebx, %ecx
	subl	%edi, %ecx
	movl	%ecx, %edx
	sarl	$3, %edx
	je	L30
	leal	(%edx,%edx), %eax
	movl	$-8, 40(%esp)
	cmpl	%eax, %edx
	jbe	L45
L20:
	movl	40(%esp), %edx
	movl	%ecx, 48(%esp)
	movl	%edx, (%esp)
	call	__Znwj
	movl	40(%esp), %edx
	movl	48(%esp), %ecx
	movl	%eax, 32(%esp)
	addl	%eax, %edx
	movl	%edx, 40(%esp)
	leal	8(%eax), %edx
L21:
	movl	32(%esp), %eax
	addl	%ecx, %eax
	movl	%esi, (%eax)
	movl	36(%esp), %esi
	movl	%esi, 4(%eax)
	cmpl	%edi, %ebx
	je	L34
	movl	32(%esp), %edx
	movl	%edi, %eax
	.p2align 4,,10
L23:
	movl	(%eax), %esi
	movl	4(%eax), %ecx
	addl	$8, %eax
	addl	$8, %edx
	movl	%esi, -8(%edx)
	movl	%ecx, -4(%edx)
	cmpl	%eax, %ebx
	jne	L23
	subl	$8, %ebx
	movl	32(%esp), %ecx
	subl	%edi, %ebx
	shrl	$3, %ebx
	leal	8(%ecx,%ebx,8), %esi
	leal	8(%esi), %edx
	movl	%edx, %eax
	subl	%ecx, %eax
	sarl	$3, %eax
	leal	-1(%eax), %ecx
	subl	$2, %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%eax, %ebx
	movl	32(%esp), %eax
	sarl	%ebx
	leal	(%eax,%ecx,8), %eax
	movl	%eax, 48(%esp)
L22:
	testl	%edi, %edi
	je	L24
	movl	%edi, (%esp)
	movl	%edx, 60(%esp)
	movl	%ecx, 36(%esp)
	call	__ZdlPv
	movl	60(%esp), %edx
	movl	36(%esp), %ecx
L24:
	movl	52(%esp), %eax
	movl	32(%esp), %edi
	movl	%edx, 4(%eax)
	movl	40(%esp), %edx
	movl	%edi, (%eax)
	movl	%edx, 8(%eax)
	movl	4(%esi), %eax
	movl	(%esi), %esi
	movl	%eax, 36(%esp)
	movl	56(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%edx, 40(%esp)
	movl	%eax, 32(%esp)
	jmp	L19
	.p2align 4,,10
L45:
	cmpl	$536870911, %eax
	ja	L20
	testl	%eax, %eax
	jne	L46
	movl	$8, %edx
	movl	$0, 40(%esp)
	movl	$0, 32(%esp)
	jmp	L21
	.p2align 4,,10
L30:
	movl	$8, 40(%esp)
	jmp	L20
L34:
	movl	32(%esp), %esi
	xorl	%ebx, %ebx
	xorl	%ecx, %ecx
	movl	%esi, 48(%esp)
	jmp	L22
L46:
	sall	$4, %edx
	movl	%edx, 40(%esp)
	jmp	L20
	.cfi_endproc
LFE1963:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1963:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1963-LLSDACSB1963
LLSDACSB1963:
LLSDACSE1963:
	.text
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_:
LFB1759:
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
	je	L55
	leal	(%eax,%eax), %esi
	movl	$-4, %ecx
	cmpl	%esi, %eax
	jbe	L64
L49:
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
L50:
	movl	(%edx), %eax
	movl	%eax, (%esi,%ebp)
	movl	4(%edx), %eax
	movl	%eax, 4(%esi,%ebp)
	movl	8(%edx), %eax
	movl	%eax, 8(%esi,%ebp)
	cmpl	%edi, %ebx
	je	L51
	movl	%edi, %eax
	movl	%esi, %edx
	.p2align 4,,10
L52:
	movl	(%eax), %ecx
	addl	$12, %eax
	addl	$12, %edx
	movl	%ecx, -12(%edx)
	movl	-8(%eax), %ecx
	movl	%ecx, -8(%edx)
	movl	-4(%eax), %ecx
	movl	%ecx, -4(%edx)
	cmpl	%eax, %ebx
	jne	L52
	leal	-12(%ebx), %eax
	subl	%edi, %eax
	shrl	$2, %eax
	imull	$715827883, %eax, %eax
	leal	(%eax,%eax,2), %eax
	leal	24(%esi,%eax,4), %ecx
L51:
	movl	20(%esp), %eax
	cmpl	%eax, %ebx
	je	L53
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
L53:
	testl	%edi, %edi
	je	L54
	movl	%edi, (%esp)
	movl	%ecx, 20(%esp)
	call	__ZdlPv
	movl	20(%esp), %ecx
L54:
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
L64:
	.cfi_restore_state
	cmpl	$357913941, %esi
	ja	L49
	testl	%esi, %esi
	jne	L48
	movl	$12, %ecx
	movl	$0, 28(%esp)
	xorl	%esi, %esi
	jmp	L50
	.p2align 4,,10
L55:
	movl	$1, %esi
L48:
	leal	(%esi,%esi,2), %ecx
	sall	$2, %ecx
	jmp	L49
	.cfi_endproc
LFE1759:
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.def	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
LFB1762:
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
	je	L74
	leal	(%edi,%edi), %eax
	movl	$-4, %ecx
	cmpl	%eax, %edi
	jbe	L80
L67:
	movl	%ecx, (%esp)
	movl	%edx, 24(%esp)
	movl	%ecx, 16(%esp)
	call	__Znwj
	movl	16(%esp), %ecx
	movl	24(%esp), %edx
	movl	%eax, %edi
	leal	(%eax,%ecx), %eax
	movl	%eax, 20(%esp)
L68:
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
	je	L69
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	%ecx, 28(%esp)
	call	_memmove
	cmpl	%ebp, 64(%esp)
	movl	28(%esp), %ecx
	je	L73
L70:
	movl	24(%esp), %eax
	movl	%ecx, (%esp)
	movl	%eax, 8(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	call	_memcpy
L72:
	testl	%esi, %esi
	jne	L73
L71:
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
L73:
	.cfi_restore_state
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L71
	.p2align 4,,10
L80:
	cmpl	$1073741823, %eax
	ja	L67
	movl	$0, 20(%esp)
	xorl	%edi, %edi
	testl	%eax, %eax
	je	L68
	jmp	L66
	.p2align 4,,10
L69:
	cmpl	%ebp, 64(%esp)
	jne	L70
	jmp	L72
	.p2align 4,,10
L74:
	movl	$1, %eax
L66:
	leal	0(,%eax,4), %ecx
	jmp	L67
	.cfi_endproc
LFE1762:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.def	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
LFB1840:
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
	je	L90
	leal	(%eax,%eax), %ebp
	movl	$-8, %ecx
	cmpl	%ebp, %eax
	jbe	L100
L83:
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
L84:
	movl	20(%esp), %ecx
	movl	4(%edx), %eax
	movl	(%edx), %edx
	addl	%ebp, %ecx
	movl	%eax, 4(%ecx)
	movl	%edx, (%ecx)
	cmpl	%edi, %ebx
	je	L85
	movl	%esi, 16(%esp)
	movl	%edi, %edx
	movl	%ebp, %eax
	.p2align 4,,10
L86:
	movl	4(%edx), %ecx
	movl	(%edx), %esi
	addl	$8, %edx
	addl	$8, %eax
	movl	%esi, -8(%eax)
	movl	%ecx, -4(%eax)
	cmpl	%edx, %ebx
	jne	L86
	leal	-8(%ebx), %eax
	movl	16(%esp), %esi
	subl	%edi, %eax
	shrl	$3, %eax
	leal	16(%ebp,%eax,8), %eax
	movl	%eax, 16(%esp)
L85:
	cmpl	%esi, %ebx
	je	L87
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	.p2align 4,,10
L88:
	movl	(%edx), %eax
	addl	$8, %edx
	addl	$8, %ecx
	movl	%eax, -8(%ecx)
	movl	-4(%edx), %eax
	movl	%eax, -4(%ecx)
	cmpl	%edx, %esi
	jne	L88
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-8(%esi), %edx
	shrl	$3, %edx
	leal	8(%eax,%edx,8), %eax
	movl	%eax, 16(%esp)
L87:
	testl	%edi, %edi
	je	L89
	movl	%edi, (%esp)
	call	__ZdlPv
L89:
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
L100:
	.cfi_restore_state
	cmpl	$536870911, %ebp
	ja	L83
	testl	%ebp, %ebp
	jne	L82
	movl	$8, 16(%esp)
	xorl	%ebp, %ebp
	movl	$0, 28(%esp)
	jmp	L84
	.p2align 4,,10
L90:
	movl	$1, %ebp
L82:
	leal	0(,%ebp,8), %ecx
	jmp	L83
	.cfi_endproc
LFE1840:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZN8Dijkstra8dijkstraEi
	.def	__ZN8Dijkstra8dijkstraEi;	.scl	2;	.type	32;	.endef
__ZN8Dijkstra8dijkstraEi:
LFB1661:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1661
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
	movl	%ecx, -76(%ebp)
	movl	$0, -40(%ebp)
	movl	$0, -36(%ebp)
	movl	$0, -32(%ebp)
	testl	%eax, %eax
	jle	L104
	sall	$2, %eax
	movl	$63, 4(%esp)
	movl	%eax, 8(%esp)
	movl	-76(%ebp), %eax
	addl	$13000280, %eax
	movl	%eax, (%esp)
	call	_memset
L104:
	movl	-76(%ebp), %eax
	movl	$0, 13000280(%eax,%ebx,4)
	addl	$12000260, %eax
	movl	$1000020, 8(%esp)
	movl	$0, 4(%esp)
	movl	%eax, (%esp)
	call	_memset
	leal	-52(%ebp), %eax
	leal	-40(%ebp), %ecx
	movl	%ebx, -48(%ebp)
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	movl	$0, -52(%ebp)
LEHB0:
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
LEHE0:
	movl	-36(%ebp), %eax
	movl	-40(%ebp), %edi
	subl	$8, %esp
	movl	-4(%eax), %edx
	movl	-8(%eax), %esi
	movl	%eax, -60(%ebp)
	subl	%edi, %eax
	sarl	$3, %eax
	leal	-1(%eax), %ebx
	subl	$2, %eax
	movl	%edx, -64(%ebp)
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%eax, %edx
	sarl	%edx
	testl	%ebx, %ebx
	jle	L128
	leal	(%edi,%edx,8), %ecx
	movl	%ebx, %eax
	cmpl	%esi, (%ecx)
	jg	L106
	jmp	L128
	.p2align 4,,10
L107:
	leal	(%edi,%ebx,8), %ecx
	movl	%edx, %eax
	cmpl	%esi, (%ecx)
	jle	L105
	movl	%ebx, %edx
L106:
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
	jg	L107
L105:
	leal	(%edi,%edx,8), %eax
	movl	-64(%ebp), %edx
	movl	%esi, (%eax)
	movl	%edx, 4(%eax)
	movl	-60(%ebp), %eax
	jmp	L123
	.p2align 4,,10
L109:
	movl	-76(%ebp), %edx
	movl	-64(%ebp), %esi
	movl	-60(%ebp), %eax
	cmpb	$0, 12000260(%edx,%esi)
	movl	%eax, -36(%ebp)
	jne	L149
	movl	%edx, %eax
	movl	-64(%ebp), %edx
	movl	%eax, -52(%ebp)
	movb	$1, 12000260(%eax,%edx)
	leal	-40(%ebp), %eax
	movl	%eax, -48(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$__ZN8Dijkstra8dijkstraEi._omp_fn.0, (%esp)
	movl	%edx, -44(%ebp)
	call	_GOMP_parallel
	movl	-40(%ebp), %edi
	movl	-36(%ebp), %eax
L123:
	movl	%eax, -60(%ebp)
L149:
	cmpl	%eax, %edi
	je	L108
	movl	-60(%ebp), %esi
	movl	4(%edi), %eax
	movl	%eax, -64(%ebp)
	movl	%esi, %eax
	subl	$8, %esi
	subl	%edi, %eax
	movl	%esi, -60(%ebp)
	cmpl	$8, %eax
	jle	L109
	movl	(%esi), %eax
	movl	4(%edi), %edx
	movl	%esi, %ebx
	movl	%eax, -72(%ebp)
	movl	4(%esi), %eax
	movl	%eax, -80(%ebp)
	movl	(%edi), %eax
	movl	%edx, 4(%esi)
	movl	%eax, (%esi)
	movl	%esi, %eax
	subl	%edi, %eax
	movl	%eax, %ecx
	sarl	$3, %ecx
	leal	-1(%ecx), %edx
	movl	%ecx, -92(%ebp)
	andl	$1, %ecx
	movl	%edx, %esi
	movl	%ecx, -84(%ebp)
	shrl	$31, %esi
	addl	%edx, %esi
	sarl	%esi
	cmpl	$16, %eax
	jle	L110
	movl	%ebx, -88(%ebp)
	xorl	%ecx, %ecx
	movl	%esi, -60(%ebp)
	.p2align 4,,10
L111:
	leal	1(%ecx), %eax
	leal	(%eax,%eax), %edx
	sall	$4, %eax
	leal	-1(%edx), %esi
	addl	%edi, %eax
	movl	%esi, -68(%ebp)
	leal	(%edi,%esi,8), %esi
	movl	(%eax), %ebx
	cmpl	%ebx, (%esi)
	jl	L112
	movl	(%eax), %ebx
	movl	4(%eax), %esi
	movl	%ebx, (%edi,%ecx,8)
	movl	%esi, 4(%edi,%ecx,8)
	cmpl	-60(%ebp), %edx
	jge	L150
L114:
	movl	%edx, %ecx
	jmp	L111
	.p2align 4,,10
L150:
	movl	-88(%ebp), %esi
	movl	-84(%ebp), %ecx
	movl	%esi, -60(%ebp)
	testl	%ecx, %ecx
	jne	L117
L151:
	movl	-92(%ebp), %ecx
	subl	$2, %ecx
	movl	%ecx, %ebx
	shrl	$31, %ebx
	addl	%ebx, %ecx
	leal	-1(%edx), %ebx
	sarl	%ecx
	sarl	%ebx
	cmpl	%edx, %ecx
	je	L116
L127:
	leal	(%edi,%ebx,8), %esi
	movl	-72(%ebp), %ecx
	cmpl	(%esi), %ecx
	jge	L115
	movl	%edx, %ecx
	movl	%esi, %edx
	movl	%ecx, %esi
	jmp	L119
	.p2align 4,,10
L120:
	leal	(%edi,%ecx,8), %edx
	movl	%ebx, %esi
	movl	%ecx, %ebx
	movl	-72(%ebp), %ecx
	cmpl	(%edx), %ecx
	jge	L115
L119:
	movl	(%edx), %eax
	movl	4(%edx), %edx
	movl	%eax, (%edi,%esi,8)
	leal	-1(%ebx), %eax
	movl	%eax, %ecx
	movl	%edx, 4(%edi,%esi,8)
	shrl	$31, %ecx
	addl	%eax, %ecx
	leal	(%edi,%ebx,8), %eax
	sarl	%ecx
	testl	%ebx, %ebx
	jne	L120
L115:
	movl	-72(%ebp), %edx
	movl	%edx, (%eax)
	movl	-80(%ebp), %edx
	movl	%edx, 4(%eax)
	jmp	L109
	.p2align 4,,10
L112:
	movl	(%esi), %eax
	movl	4(%esi), %edx
	movl	%eax, (%edi,%ecx,8)
	movl	-60(%ebp), %eax
	movl	%edx, 4(%edi,%ecx,8)
	movl	-68(%ebp), %edx
	cmpl	%eax, %edx
	jl	L114
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %ecx
	movl	%eax, -60(%ebp)
	movl	%esi, %eax
	testl	%ecx, %ecx
	je	L151
L117:
	leal	-1(%edx), %ebx
	sarl	%ebx
	jmp	L127
	.p2align 4,,10
L108:
	testl	%eax, %eax
	je	L101
	movl	%eax, (%esp)
	call	__ZdlPv
L101:
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
L110:
	.cfi_restore_state
	movl	-84(%ebp), %ebx
	movl	%edi, %eax
	testl	%ebx, %ebx
	jne	L115
	cmpl	$2, %edx
	ja	L115
	xorl	%edx, %edx
	.p2align 4,,10
L116:
	leal	1(%edx,%edx), %edx
	leal	(%edi,%edx,8), %ecx
	movl	(%ecx), %ebx
	movl	4(%ecx), %esi
	movl	%ebx, (%eax)
	leal	-1(%edx), %ebx
	movl	%esi, 4(%eax)
	sarl	%ebx
	movl	%ecx, %eax
	jmp	L127
	.p2align 4,,10
L128:
	movl	%ebx, %edx
	jmp	L105
L132:
	movl	%eax, %ebx
L125:
	movl	-40(%ebp), %edx
	testl	%edx, %edx
	je	L126
	movl	%edx, (%esp)
	call	__ZdlPv
L126:
	movl	%ebx, (%esp)
LEHB1:
	call	__Unwind_Resume
LEHE1:
	.cfi_endproc
LFE1661:
	.section	.gcc_except_table,"w"
LLSDA1661:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1661-LLSDACSB1661
LLSDACSB1661:
	.uleb128 LEHB0-LFB1661
	.uleb128 LEHE0-LEHB0
	.uleb128 L132-LFB1661
	.uleb128 0
	.uleb128 LEHB1-LFB1661
	.uleb128 LEHE1-LEHB1
	.uleb128 0
	.uleb128 0
LLSDACSE1661:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "r\0"
LC1:
	.ascii "in.txt\0"
LC2:
	.ascii "w\0"
LC3:
	.ascii "out.txt\0"
LC4:
	.ascii "%d%d\0"
LC5:
	.ascii "%d\12\0"
LC6:
	.ascii "%d%d%d\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1668:
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
	movl	__imp___iob, %ebx
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	movl	%ebx, 8(%esp)
	addl	$32, %ebx
	call	_freopen
	movl	%ebx, 8(%esp)
	movl	$LC2, 4(%esp)
	movl	$LC3, (%esp)
	call	_freopen
	leal	-56(%ebp), %eax
	movl	$LC4, (%esp)
	movl	%eax, 8(%esp)
	leal	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	call	_scanf
	movl	-56(%ebp), %ebx
	movl	%ebx, _dijkstra
	testl	%ebx, %ebx
	jle	L157
	leal	(%ebx,%ebx,2), %ecx
	xorl	%eax, %eax
	sall	$2, %ecx
	.p2align 4,,10
L158:
	movl	_dijkstra+20(%eax), %edx
	cmpl	_dijkstra+24(%eax), %edx
	je	L156
	movl	%edx, _dijkstra+24(%eax)
L156:
	addl	$12, %eax
	cmpl	%ecx, %eax
	jne	L158
L157:
	movl	_dijkstra+8, %eax
	cmpl	_dijkstra+12, %eax
	je	L155
	movl	%eax, _dijkstra+12
L155:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	jle	L167
	xorl	%ebx, %ebx
	.p2align 4,,10
L159:
	leal	-40(%ebp), %eax
	movl	$LC6, (%esp)
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
	je	L160
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L161:
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
	je	L162
	movl	%edx, (%esi)
	addl	$4, %esi
	movl	%esi, _dijkstra+24(%ecx)
L163:
	movl	-48(%ebp), %edx
	movl	-44(%ebp), %esi
	movl	%edx, -32(%ebp)
	movl	-40(%ebp), %edx
	movl	%esi, -36(%ebp)
	movl	%edx, -28(%ebp)
	cmpl	%eax, _dijkstra+16
	je	L164
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L165:
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
	je	L166
	movl	%eax, (%edx)
	addl	$4, %edx
	addl	$1, %ebx
	movl	%edx, _dijkstra+24(%ecx)
	cmpl	%ebx, -52(%ebp)
	jg	L159
L174:
	movl	-56(%ebp), %ebx
L167:
	subl	$1, %ebx
	movl	$_dijkstra, %ecx
	movl	%ebx, (%esp)
	call	__ZN8Dijkstra8dijkstraEi
	movl	_dijkstra+13000280, %eax
	subl	$4, %esp
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
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
L166:
	.cfi_restore_state
	leal	-36(%ebp), %eax
	movl	%edx, (%esp)
	addl	$_dijkstra+20, %ecx
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	subl	$8, %esp
	cmpl	-52(%ebp), %ebx
	jl	L159
	jmp	L174
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
L160:
	leal	-36(%ebp), %edi
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	movl	%edi, 4(%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L161
	.p2align 4,,10
L162:
	leal	-36(%ebp), %eax
	movl	%esi, (%esp)
	addl	$_dijkstra+20, %ecx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L163
	.cfi_endproc
LFE1668:
	.p2align 4,,15
	.def	__GLOBAL__sub_I_dijkstra;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_dijkstra:
LFB1962:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$_dijkstra+20, %eax
	movl	$0, _dijkstra+8
	movl	$0, _dijkstra+12
	movl	$0, _dijkstra+16
	.p2align 4,,10
L176:
	movl	$0, (%eax)
	addl	$12, %eax
	movl	$0, -8(%eax)
	movl	$0, -4(%eax)
	cmpl	$_dijkstra+12000260, %eax
	jne	L176
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1962:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_dijkstra
	.globl	_dijkstra
	.bss
	.align 32
_dijkstra:
	.space 21000440
	.ident	"GCC: (MinGW.org GCC-8.2.0-3) 8.2.0"
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	_GOMP_parallel;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_freopen;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
