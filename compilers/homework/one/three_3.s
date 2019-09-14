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
L3:
	movl	(%ebx), %eax
	testl	%eax, %eax
	je	L2
	movl	%eax, (%esp)
	call	__ZdlPv
L2:
	subl	$12, %ebx
	cmpl	$_dijkstra+8, %ebx
	jne	L3
	movl	_dijkstra+8, %eax
	testl	%eax, %eax
	je	L1
	movl	%eax, (%esp)
	call	__ZdlPv
L1:
	addl	$24, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
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
	movl	%ecx, %eax
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
	movl	(%eax), %ebp
	movl	4(%eax), %eax
	movl	64(%esp), %ebx
	movl	%ecx, 20(%esp)
	movl	%eax, 16(%esp)
	subl	%ebp, %eax
	movl	68(%esp), %ecx
	sarl	$2, %eax
	movl	%ebx, %edi
	imull	$-1431655765, %eax, %eax
	subl	%ebp, %edi
	testl	%eax, %eax
	je	L23
	leal	(%eax,%eax), %edx
	movl	$-4, %esi
	cmpl	%edx, %eax
	jbe	L33
L16:
	movl	%esi, (%esp)
	movl	%ecx, 68(%esp)
	call	__Znwj
	movl	68(%esp), %ecx
	leal	(%eax,%esi), %esi
	leal	12(%eax), %edx
	movl	%esi, 24(%esp)
L17:
	movl	(%ecx), %esi
	movl	%esi, (%eax,%edi)
	movl	4(%ecx), %esi
	movl	8(%ecx), %ecx
	movl	%esi, 4(%eax,%edi)
	movl	%ecx, 8(%eax,%edi)
	cmpl	%ebp, %ebx
	je	L18
	movl	16(%esp), %esi
	movl	%ebp, %edx
	movl	%eax, %ecx
	.p2align 4,,10
L19:
	movl	(%edx), %edi
	addl	$12, %edx
	addl	$12, %ecx
	movl	%edi, -12(%ecx)
	movl	-8(%edx), %edi
	movl	%edi, -8(%ecx)
	movl	-4(%edx), %edi
	movl	%edi, -4(%ecx)
	cmpl	%edx, %ebx
	jne	L19
	leal	-12(%ebx), %edx
	movl	%esi, 16(%esp)
	subl	%ebp, %edx
	shrl	$2, %edx
	imull	$715827883, %edx, %edx
	leal	(%edx,%edx,2), %edx
	leal	24(%eax,%edx,4), %edx
L18:
	movl	16(%esp), %esi
	cmpl	%esi, %ebx
	je	L20
	movl	%eax, 16(%esp)
	movl	%ebx, %ecx
	movl	%edx, %edi
	.p2align 4,,10
L21:
	movl	(%ecx), %eax
	addl	$12, %ecx
	addl	$12, %edi
	movl	%eax, -12(%edi)
	movl	-8(%ecx), %eax
	movl	%eax, -8(%edi)
	movl	-4(%ecx), %eax
	movl	%eax, -4(%edi)
	cmpl	%ecx, %esi
	jne	L21
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-12(%esi), %ecx
	shrl	$2, %ecx
	imull	$715827883, %ecx, %ecx
	leal	(%ecx,%ecx,2), %ecx
	leal	12(%edx,%ecx,4), %edx
L20:
	testl	%ebp, %ebp
	je	L22
	movl	%ebp, (%esp)
	movl	%edx, 28(%esp)
	movl	%eax, 16(%esp)
	call	__ZdlPv
	movl	28(%esp), %edx
	movl	16(%esp), %eax
L22:
	movl	20(%esp), %esi
	movl	24(%esp), %ebx
	movl	%eax, (%esi)
	movl	%edx, 4(%esi)
	movl	%ebx, 8(%esi)
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
L33:
	.cfi_restore_state
	cmpl	$357913941, %edx
	ja	L16
	testl	%edx, %edx
	jne	L15
	movl	$12, %edx
	movl	$0, 24(%esp)
	xorl	%eax, %eax
	jmp	L17
	.p2align 4,,10
L23:
	movl	$1, %edx
L15:
	leal	(%edx,%edx,2), %edx
	leal	0(,%edx,4), %eax
	movl	%eax, %esi
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
	je	L43
	leal	(%edi,%edi), %eax
	movl	$-4, %ecx
	cmpl	%eax, %edi
	jbe	L49
L36:
	movl	%ecx, (%esp)
	movl	%edx, 24(%esp)
	movl	%ecx, 16(%esp)
	call	__Znwj
	movl	16(%esp), %ecx
	movl	24(%esp), %edx
	movl	%eax, %edi
	leal	(%eax,%ecx), %eax
	movl	%eax, 20(%esp)
L37:
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
	je	L38
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	%ecx, 28(%esp)
	call	_memmove
	cmpl	%ebp, 64(%esp)
	movl	28(%esp), %ecx
	je	L42
L39:
	movl	24(%esp), %eax
	movl	%ecx, (%esp)
	movl	%eax, 8(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	call	_memcpy
L41:
	testl	%esi, %esi
	jne	L42
L40:
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
L42:
	.cfi_restore_state
	movl	%esi, (%esp)
	call	__ZdlPv
	jmp	L40
	.p2align 4,,10
L49:
	cmpl	$1073741823, %eax
	ja	L36
	movl	$0, 20(%esp)
	xorl	%edi, %edi
	testl	%eax, %eax
	je	L37
	jmp	L35
	.p2align 4,,10
L38:
	cmpl	%ebp, 64(%esp)
	jne	L39
	jmp	L41
	.p2align 4,,10
L43:
	movl	$1, %eax
L35:
	leal	0(,%eax,4), %ecx
	jmp	L36
	.cfi_endproc
LFE1766:
	.section	.text$_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	.def	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_;	.scl	2;	.type	32;	.endef
__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_:
LFB1786:
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
	subl	$4, %esp
	.cfi_def_cfa_offset 24
	movl	40(%esp), %eax
	movl	28(%esp), %esi
	movl	32(%esp), %ebp
	movl	24(%esp), %ebx
	movl	%eax, (%esp)
	leal	-1(%esi), %eax
	movl	36(%esp), %edi
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%eax, %edx
	sarl	%edx
	cmpl	%ebp, %esi
	jle	L54
	leal	(%ebx,%edx,8), %ecx
	movl	%ebx, %eax
	cmpl	(%ecx), %edi
	jl	L52
	jmp	L54
	.p2align 4,,10
L53:
	leal	(%eax,%ebx,8), %ecx
	movl	%edx, %esi
	cmpl	(%ecx), %edi
	jge	L57
	movl	%ebx, %edx
L52:
	movl	4(%ecx), %ebx
	movl	(%ecx), %ecx
	movl	%ecx, (%eax,%esi,8)
	leal	-1(%edx), %ecx
	movl	%ebx, 4(%eax,%esi,8)
	movl	%ecx, %ebx
	shrl	$31, %ebx
	addl	%ecx, %ebx
	sarl	%ebx
	cmpl	%edx, %ebp
	jl	L53
L57:
	movl	%eax, %ebx
L51:
	movl	(%esp), %eax
	movl	%edi, (%ebx,%edx,8)
	movl	%eax, 4(%ebx,%edx,8)
	addl	$4, %esp
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
L54:
	.cfi_restore_state
	movl	%esi, %edx
	jmp	L51
	.cfi_endproc
LFE1786:
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
	je	L68
	leal	(%eax,%eax), %ebp
	movl	$-8, %ecx
	cmpl	%ebp, %eax
	jbe	L78
L61:
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
L62:
	movl	20(%esp), %ecx
	movl	4(%edx), %eax
	movl	(%edx), %edx
	addl	%ebp, %ecx
	movl	%eax, 4(%ecx)
	movl	%edx, (%ecx)
	cmpl	%edi, %ebx
	je	L63
	movl	%esi, 16(%esp)
	movl	%edi, %edx
	movl	%ebp, %eax
	.p2align 4,,10
L64:
	movl	4(%edx), %ecx
	movl	(%edx), %esi
	addl	$8, %edx
	addl	$8, %eax
	movl	%esi, -8(%eax)
	movl	%ecx, -4(%eax)
	cmpl	%edx, %ebx
	jne	L64
	leal	-8(%ebx), %eax
	movl	16(%esp), %esi
	subl	%edi, %eax
	shrl	$3, %eax
	leal	16(%ebp,%eax,8), %eax
	movl	%eax, 16(%esp)
L63:
	cmpl	%esi, %ebx
	je	L65
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	.p2align 4,,10
L66:
	movl	(%edx), %eax
	addl	$8, %edx
	addl	$8, %ecx
	movl	%eax, -8(%ecx)
	movl	-4(%edx), %eax
	movl	%eax, -4(%ecx)
	cmpl	%edx, %esi
	jne	L66
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-8(%esi), %edx
	shrl	$3, %edx
	leal	8(%eax,%edx,8), %eax
	movl	%eax, 16(%esp)
L65:
	testl	%edi, %edi
	je	L67
	movl	%edi, (%esp)
	call	__ZdlPv
L67:
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
L78:
	.cfi_restore_state
	cmpl	$536870911, %ebp
	ja	L61
	testl	%ebp, %ebp
	jne	L60
	movl	$8, 16(%esp)
	xorl	%ebp, %ebp
	movl	$0, 28(%esp)
	jmp	L62
	.p2align 4,,10
L68:
	movl	$1, %ebp
L60:
	leal	0(,%ebp,8), %ecx
	jmp	L61
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
	je	L88
	leal	(%eax,%eax), %ebp
	movl	$-8, %ecx
	cmpl	%ebp, %eax
	jbe	L98
L81:
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
L82:
	movl	20(%esp), %ecx
	movl	4(%edx), %eax
	movl	(%edx), %edx
	addl	%ebp, %ecx
	movl	%eax, 4(%ecx)
	movl	%edx, (%ecx)
	cmpl	%edi, %ebx
	je	L83
	movl	%esi, 16(%esp)
	movl	%edi, %edx
	movl	%ebp, %eax
	.p2align 4,,10
L84:
	movl	4(%edx), %ecx
	movl	(%edx), %esi
	addl	$8, %edx
	addl	$8, %eax
	movl	%esi, -8(%eax)
	movl	%ecx, -4(%eax)
	cmpl	%edx, %ebx
	jne	L84
	leal	-8(%ebx), %eax
	movl	16(%esp), %esi
	subl	%edi, %eax
	shrl	$3, %eax
	leal	16(%ebp,%eax,8), %eax
	movl	%eax, 16(%esp)
L83:
	cmpl	%esi, %ebx
	je	L85
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	.p2align 4,,10
L86:
	movl	(%edx), %eax
	addl	$8, %edx
	addl	$8, %ecx
	movl	%eax, -8(%ecx)
	movl	-4(%edx), %eax
	movl	%eax, -4(%ecx)
	cmpl	%edx, %esi
	jne	L86
	subl	%ebx, %esi
	movl	16(%esp), %eax
	leal	-8(%esi), %edx
	shrl	$3, %edx
	leal	8(%eax,%edx,8), %eax
	movl	%eax, 16(%esp)
L85:
	testl	%edi, %edi
	je	L87
	movl	%edi, (%esp)
	call	__ZdlPv
L87:
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
L98:
	.cfi_restore_state
	cmpl	$536870911, %ebp
	ja	L81
	testl	%ebp, %ebp
	jne	L80
	movl	$8, 16(%esp)
	xorl	%ebp, %ebp
	movl	$0, 28(%esp)
	jmp	L82
	.p2align 4,,10
L88:
	movl	$1, %ebp
L80:
	leal	0(,%ebp,8), %ecx
	jmp	L81
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
	movl	%ecx, %eax
	addl	$13280, %eax
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	(%ecx), %ebx
	movl	8(%ebp), %edx
	movl	%ecx, -68(%ebp)
	movl	$0, -40(%ebp)
	movl	-68(%ebp), %esi
	movl	$0, -36(%ebp)
	leal	(%eax,%ebx,4), %ecx
	movl	$0, -32(%ebp)
	testl	%ebx, %ebx
	jle	L102
	.p2align 4,,10
L103:
	movl	$1061109567, (%eax)
	addl	$4, %eax
	cmpl	%eax, %ecx
	jne	L103
	movl	%esi, -68(%ebp)
L102:
	movl	-68(%ebp), %eax
	leal	12264(%eax), %edi
	leal	12260(%eax), %ecx
	movl	$0, 13280(%eax,%edx,4)
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
	movl	%edx, -44(%ebp)
LEHB0:
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	movl	-36(%ebp), %ecx
	movl	-40(%ebp), %ebx
	subl	$8, %esp
	leal	-49(%ebp), %edi
	movl	-8(%ecx), %eax
	movl	-4(%ecx), %edx
	subl	%ebx, %ecx
	movl	%edi, 20(%esp)
	sarl	$3, %ecx
	movl	$0, 8(%esp)
	movl	%eax, 12(%esp)
	leal	-1(%ecx), %eax
	movl	%edx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	movl	-36(%ebp), %ecx
	.p2align 4,,10
L110:
	movl	-40(%ebp), %edx
	cmpl	%ecx, %edx
	je	L104
L137:
	movl	4(%edx), %eax
	movl	%ecx, %ebx
	subl	%edx, %ebx
	movl	%eax, -72(%ebp)
	leal	-8(%ecx), %eax
	cmpl	$8, %ebx
	jg	L136
L105:
	movl	-72(%ebp), %esi
	movl	-68(%ebp), %edi
	movl	%eax, -36(%ebp)
	movl	%eax, %ecx
	cmpb	$0, 12260(%edi,%esi)
	jne	L110
	leal	(%esi,%esi,2), %edx
	movb	$1, 12260(%edi,%esi)
	leal	3320(%esi), %ebx
	leal	20(%edi,%edx,4), %edi
	movl	$0, -60(%ebp)
	movl	(%edi), %ecx
	movl	%ebx, -80(%ebp)
	movl	%ecx, -64(%ebp)
	cmpl	4(%edi), %ecx
	jne	L111
	jmp	L116
	.p2align 4,,10
L113:
	addl	$1, -60(%ebp)
	movl	4(%edi), %edx
	movl	-60(%ebp), %ecx
	subl	-64(%ebp), %edx
	sarl	$2, %edx
	cmpl	%ecx, %edx
	jbe	L116
L111:
	movl	-60(%ebp), %ebx
	movl	-64(%ebp), %esi
	leal	(%esi,%ebx,4), %esi
	movl	(%esi), %edx
	movl	%esi, -76(%ebp)
	movl	-68(%ebp), %esi
	leal	(%edx,%edx,2), %ecx
	movl	8(%esi), %edx
	leal	(%edx,%ecx,4), %edx
	movl	4(%edx), %ebx
	movl	8(%edx), %edx
	movl	%ebx, -72(%ebp)
	leal	(%esi,%ebx,4), %ecx
	movl	-80(%ebp), %ebx
	addl	(%esi,%ebx,4), %edx
	cmpl	%edx, 13280(%ecx)
	jle	L113
	movl	-76(%ebp), %esi
	movl	-72(%ebp), %ebx
	movl	%edx, 13280(%ecx)
	movl	(%esi), %esi
	movl	%edx, -48(%ebp)
	movl	%ebx, -44(%ebp)
	movl	%esi, 17360(%ecx)
	cmpl	%eax, -32(%ebp)
	je	L114
	movl	%edx, (%eax)
	addl	$8, %eax
	movl	%ebx, -4(%eax)
	movl	%eax, -36(%ebp)
L115:
	movl	-40(%ebp), %edx
	movl	-8(%eax), %ecx
	movl	-4(%eax), %ebx
	movl	$0, 8(%esp)
	subl	%edx, %eax
	movl	%ecx, 12(%esp)
	leal	-49(%ebp), %ecx
	sarl	$3, %eax
	movl	%ecx, 20(%esp)
	subl	$1, %eax
	movl	%ebx, 16(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	movl	(%edi), %ecx
	movl	-36(%ebp), %eax
	movl	%ecx, -64(%ebp)
	jmp	L113
	.p2align 4,,10
L116:
	movl	-40(%ebp), %edx
	movl	%eax, %ecx
	cmpl	%ecx, %edx
	jne	L137
L104:
	testl	%ecx, %ecx
	je	L99
	movl	%ecx, (%esp)
	call	__ZdlPv
L99:
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
L136:
	.cfi_restore_state
	movl	-8(%ecx), %edi
	subl	%edx, %eax
	movl	(%edx), %ebx
	movl	4(%edx), %esi
	movl	%edi, -76(%ebp)
	movl	-4(%ecx), %edi
	movl	%ebx, -8(%ecx)
	movl	%edi, -80(%ebp)
	movl	%eax, %edi
	sarl	$3, %edi
	movl	%esi, -4(%ecx)
	leal	-1(%edi), %ecx
	movl	%edi, -84(%ebp)
	movl	%ecx, %edi
	shrl	$31, %edi
	addl	%edi, %ecx
	movl	%ecx, %edi
	sarl	%edi
	cmpl	$16, %eax
	jle	L120
	movl	%edi, -64(%ebp)
	xorl	%ebx, %ebx
	.p2align 4,,10
L108:
	leal	1(%ebx), %eax
	leal	(%eax,%eax), %ecx
	sall	$4, %eax
	leal	-1(%ecx), %edi
	addl	%edx, %eax
	movl	%edi, -60(%ebp)
	leal	(%edx,%edi,8), %edi
	movl	(%edi), %esi
	cmpl	%esi, (%eax)
	jle	L107
	movl	-60(%ebp), %ecx
	movl	%edi, %eax
L107:
	movl	(%eax), %esi
	movl	4(%eax), %edi
	movl	%esi, (%edx,%ebx,8)
	movl	%edi, 4(%edx,%ebx,8)
	movl	%ecx, %ebx
	cmpl	-64(%ebp), %ecx
	jl	L108
L106:
	movl	-84(%ebp), %eax
	testb	$1, %al
	jne	L109
	subl	$2, %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%ebx, %eax
	sarl	%eax
	cmpl	%eax, %ecx
	jne	L109
	leal	1(%ecx,%ecx), %eax
	movl	(%edx,%eax,8), %esi
	movl	4(%edx,%eax,8), %edi
	movl	%esi, (%edx,%ecx,8)
	movl	%edi, 4(%edx,%ecx,8)
	movl	%eax, %ecx
	.p2align 4,,10
L109:
	leal	-48(%ebp), %eax
	movl	$0, 8(%esp)
	movl	%eax, 20(%esp)
	movl	-76(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%eax, 12(%esp)
	movl	-80(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, 16(%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	movl	-36(%ebp), %eax
	subl	$8, %eax
	jmp	L105
	.p2align 4,,10
L114:
	leal	-48(%ebp), %esi
	movl	%eax, (%esp)
	leal	-40(%ebp), %ecx
	movl	%esi, 4(%esp)
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
LEHE0:
	subl	$8, %esp
	movl	-36(%ebp), %eax
	jmp	L115
L120:
	xorl	%ecx, %ecx
	jmp	L106
L123:
	movl	%eax, %ebx
L118:
	movl	-40(%ebp), %edx
	testl	%edx, %edx
	je	L119
	movl	%edx, (%esp)
	call	__ZdlPv
L119:
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
	.uleb128 L123-LFB1665
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
	jle	L143
	leal	(%ebx,%ebx,2), %ecx
	xorl	%eax, %eax
	sall	$2, %ecx
	.p2align 4,,10
L144:
	movl	_dijkstra+20(%eax), %edx
	cmpl	_dijkstra+24(%eax), %edx
	je	L142
	movl	%edx, _dijkstra+24(%eax)
L142:
	addl	$12, %eax
	cmpl	%ecx, %eax
	jne	L144
L143:
	movl	_dijkstra+8, %eax
	cmpl	_dijkstra+12, %eax
	je	L141
	movl	%eax, _dijkstra+12
L141:
	movl	-52(%ebp), %eax
	testl	%eax, %eax
	jle	L154
	xorl	%ebx, %ebx
	jmp	L145
	.p2align 4,,10
L160:
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L147:
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
	je	L148
	movl	%edx, (%esi)
	addl	$4, %esi
	movl	%esi, _dijkstra+24(%ecx)
L149:
	movl	-48(%ebp), %edx
	movl	-44(%ebp), %esi
	movl	%edx, -32(%ebp)
	movl	-40(%ebp), %edx
	movl	%esi, -36(%ebp)
	movl	%edx, -28(%ebp)
	cmpl	%eax, _dijkstra+16
	je	L150
	movl	%esi, (%eax)
	movl	-32(%ebp), %edx
	addl	$12, %eax
	movl	%edx, -8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, -4(%eax)
	movl	%eax, _dijkstra+12
L151:
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
	je	L152
	movl	%eax, (%edx)
	addl	$4, %edx
	addl	$1, %ebx
	movl	%edx, _dijkstra+24(%ecx)
	cmpl	%ebx, -52(%ebp)
	jle	L159
L145:
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
	jne	L160
	leal	-36(%ebp), %edi
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	movl	%edi, 4(%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L147
	.p2align 4,,10
L152:
	leal	-36(%ebp), %eax
	movl	%edx, (%esp)
	addl	$_dijkstra+20, %ecx
	addl	$1, %ebx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	subl	$8, %esp
	cmpl	%ebx, -52(%ebp)
	jg	L145
	.p2align 4,,10
L159:
	movl	-56(%ebp), %ebx
L154:
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
L150:
	.cfi_restore_state
	leal	-36(%ebp), %edi
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	movl	%edi, 4(%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L151
	.p2align 4,,10
L148:
	leal	-36(%ebp), %eax
	movl	%esi, (%esp)
	addl	$_dijkstra+20, %ecx
	movl	%eax, 4(%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	_dijkstra+12, %eax
	subl	$8, %esp
	jmp	L149
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
L162:
	movl	$0, (%eax)
	addl	$12, %eax
	movl	$0, -8(%eax)
	movl	$0, -4(%eax)
	cmpl	$_dijkstra+12260, %eax
	jne	L162
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
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	_memcpy;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
