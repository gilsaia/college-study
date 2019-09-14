	.file	"three.cpp"
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1965:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	$_dijkstra+12260, %ebx
	jmp	L3
L8:
	movl	%eax, (%esp)
	call	__ZdlPv
L2:
	cmpl	$_dijkstra+20, %ebx
	je	L7
L3:
	subl	$12, %ebx
	movl	(%ebx), %eax
	testl	%eax, %eax
	jne	L8
	jmp	L2
L7:
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
	movl	%ecx, 24(%esp)
	movl	64(%esp), %esi
	movl	4(%ecx), %ebx
	movl	(%ecx), %ebp
	movl	%ebx, %eax
	subl	%ebp, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	testl	%eax, %eax
	je	L10
	leal	(%eax,%eax), %edi
	movl	%edi, 20(%esp)
	cmpl	%edi, %eax
	ja	L11
	cmpl	$357913941, %edi
	ja	L11
	movl	64(%esp), %eax
	subl	%ebp, %eax
	movl	%eax, 28(%esp)
	movl	$0, %edi
	cmpl	$0, 20(%esp)
	je	L19
	jmp	L18
L20:
	movl	%edi, %esi
	jmp	L13
L11:
	movl	64(%esp), %eax
	subl	%ebp, %eax
	movl	%eax, 28(%esp)
	movl	$357913941, 20(%esp)
	jmp	L18
L10:
	movl	64(%esp), %eax
	subl	%ebp, %eax
	movl	%eax, 28(%esp)
	movl	$1, 20(%esp)
L18:
	movl	20(%esp), %eax
	leal	(%eax,%eax,2), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	movl	%eax, %edi
L19:
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	28(%esp), %edx
	movl	%eax, (%edi,%edx)
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%edi,%edx)
	movl	68(%esp), %eax
	movl	8(%eax), %eax
	movl	%eax, 8(%edi,%edx)
	cmpl	%ebp, 64(%esp)
	je	L20
	movl	%ebp, %eax
	movl	%edi, %edx
L14:
	movl	(%eax), %ecx
	movl	%ecx, (%edx)
	movl	4(%eax), %ecx
	movl	%ecx, 4(%edx)
	movl	8(%eax), %ecx
	movl	%ecx, 8(%edx)
	addl	$12, %edx
	addl	$12, %eax
	cmpl	%eax, %esi
	jne	L14
	movl	64(%esp), %eax
	subl	$12, %eax
	subl	%ebp, %eax
	shrl	$2, %eax
	imull	$715827883, %eax, %eax
	leal	(%eax,%eax,2), %eax
	leal	12(%edi,%eax,4), %esi
L13:
	addl	$12, %esi
	cmpl	%ebx, 64(%esp)
	je	L15
	movl	64(%esp), %eax
	movl	%esi, %edx
L16:
	movl	(%eax), %ecx
	movl	%ecx, (%edx)
	movl	4(%eax), %ecx
	movl	%ecx, 4(%edx)
	movl	8(%eax), %ecx
	movl	%ecx, 8(%edx)
	addl	$12, %edx
	addl	$12, %eax
	cmpl	%eax, %ebx
	jne	L16
	subl	64(%esp), %ebx
	leal	-12(%ebx), %eax
	shrl	$2, %eax
	imull	$715827883, %eax, %eax
	leal	(%eax,%eax,2), %eax
	leal	12(%esi,%eax,4), %esi
L15:
	testl	%ebp, %ebp
	je	L17
	movl	%ebp, (%esp)
	call	__ZdlPv
L17:
	movl	24(%esp), %ebx
	movl	%edi, (%ebx)
	movl	%esi, 4(%ebx)
	movl	20(%esp), %eax
	leal	(%eax,%eax,2), %eax
	leal	(%edi,%eax,4), %eax
	movl	%eax, 8(%ebx)
	addl	$44, %esp
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
	.cfi_endproc
LFE1763:
	.section	.text$_ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_
	.def	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_:
LFB1711:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$24, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %edx
	movl	4(%ecx), %eax
	cmpl	8(%ecx), %eax
	je	L27
	movl	(%edx), %ebx
	movl	%ebx, (%eax)
	movl	4(%edx), %ebx
	movl	%ebx, 4(%eax)
	movl	8(%edx), %edx
	movl	%edx, 8(%eax)
	addl	$12, 4(%ecx)
L26:
	addl	$24, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret	$4
L27:
	.cfi_restore_state
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6vectorI4EdgeSaIS0_EE17_M_realloc_insertIJS0_EEEvN9__gnu_cxx17__normal_iteratorIPS0_S2_EEDpOT_
	.cfi_def_cfa_offset 24
	subl	$8, %esp
	.cfi_def_cfa_offset 32
	jmp	L26
	.cfi_endproc
LFE1711:
	.section	.text$_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
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
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	%ecx, %esi
	movl	4(%ecx), %eax
	movl	%eax, 24(%esp)
	movl	(%ecx), %ebx
	subl	%ebx, %eax
	sarl	$2, %eax
	je	L31
	leal	(%eax,%eax), %ecx
	movl	%ecx, 20(%esp)
	cmpl	%ecx, %eax
	ja	L32
	cmpl	$1073741823, %ecx
	ja	L32
	movl	64(%esp), %edi
	subl	%ebx, %edi
	movl	$0, %ebp
	cmpl	$0, 20(%esp)
	je	L38
	jmp	L37
L32:
	movl	64(%esp), %edi
	subl	%ebx, %edi
	movl	$1073741823, 20(%esp)
	jmp	L37
L31:
	movl	64(%esp), %edi
	subl	%ebx, %edi
	movl	$1, 20(%esp)
L37:
	movl	20(%esp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	movl	%eax, %ebp
L38:
	movl	%edi, 28(%esp)
	movl	68(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 0(%ebp,%edi)
	cmpl	%ebx, 64(%esp)
	je	L34
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%ebp, (%esp)
	call	_memmove
L34:
	movl	28(%esp), %eax
	leal	4(%ebp,%eax), %edi
	movl	24(%esp), %edx
	movl	%edx, %eax
	subl	64(%esp), %eax
	movl	%eax, 24(%esp)
	cmpl	%edx, 64(%esp)
	je	L35
	movl	%eax, 8(%esp)
	movl	64(%esp), %eax
	movl	%eax, 4(%esp)
	movl	%edi, (%esp)
	call	_memcpy
L35:
	addl	24(%esp), %edi
	testl	%ebx, %ebx
	je	L36
	movl	%ebx, (%esp)
	call	__ZdlPv
L36:
	movl	%ebp, (%esi)
	movl	%edi, 4(%esi)
	movl	20(%esp), %eax
	leal	0(%ebp,%eax,4), %eax
	movl	%eax, 8(%esi)
	addl	$44, %esp
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
	.cfi_endproc
LFE1766:
	.section	.text$_ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_
	.def	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_:
LFB1713:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	32(%esp), %edx
	movl	4(%ecx), %eax
	cmpl	8(%ecx), %eax
	je	L43
	movl	(%edx), %edx
	movl	%edx, (%eax)
	addl	$4, 4(%ecx)
L42:
	addl	$28, %esp
	.cfi_remember_state
	.cfi_def_cfa_offset 4
	ret	$4
L43:
	.cfi_restore_state
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.cfi_def_cfa_offset 24
	subl	$8, %esp
	.cfi_def_cfa_offset 32
	jmp	L42
	.cfi_endproc
LFE1713:
	.section	.text$_ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_,"x"
	.linkonce discard
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
	subl	$8, %esp
	.cfi_def_cfa_offset 28
	movl	32(%esp), %ebx
	movl	36(%esp), %edi
	movl	40(%esp), %eax
	movl	44(%esp), %esi
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	movl	%eax, %ebp
	movl	28(%esp), %esi
	leal	-1(%ebx), %edx
	movl	%edx, %ecx
	shrl	$31, %ecx
	movl	%ecx, %eax
	addl	%edx, %eax
	sarl	%eax
	cmpl	%edi, %ebx
	jle	L50
	movl	%eax, %edx
	leal	(%esi,%eax,8), %ecx
	cmpl	(%ecx), %ebp
	jge	L55
	movl	%ebx, %eax
L48:
	movl	4(%ecx), %ebx
	movl	(%ecx), %ecx
	movl	%ecx, (%esi,%eax,8)
	movl	%ebx, 4(%esi,%eax,8)
	leal	-1(%edx), %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	addl	%eax, %ebx
	sarl	%ebx
	cmpl	%edx, %edi
	jge	L47
	leal	(%esi,%ebx,8), %ecx
	movl	%edx, %eax
	cmpl	(%ecx), %ebp
	jge	L47
	movl	%ebx, %edx
	jmp	L48
L55:
	movl	%ebx, %edx
	jmp	L47
L50:
	movl	%ebx, %edx
L47:
	movl	28(%esp), %eax
	movl	(%esp), %edi
	movl	%edi, (%eax,%edx,8)
	movl	4(%esp), %edi
	movl	%edi, 4(%eax,%edx,8)
	addl	$8, %esp
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
	.cfi_endproc
LFE1786:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
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
	movl	%ecx, %ebp
	movl	64(%esp), %eax
	movl	%eax, 28(%esp)
	movl	4(%ecx), %ebx
	movl	(%ecx), %edi
	movl	%ebx, %eax
	subl	%edi, %eax
	sarl	$3, %eax
	je	L57
	leal	(%eax,%eax), %ecx
	movl	%ecx, 24(%esp)
	cmpl	%ecx, %eax
	ja	L58
	cmpl	$536870911, %ecx
	ja	L58
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	cmpl	$0, 24(%esp)
	jne	L65
	movl	$0, 20(%esp)
	jmp	L66
L67:
	movl	20(%esp), %esi
	jmp	L60
L58:
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	movl	$536870911, 24(%esp)
	jmp	L65
L57:
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	movl	$1, 24(%esp)
L65:
	movl	24(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	__Znwj
	movl	%eax, 20(%esp)
L66:
	movl	68(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	20(%esp), %ecx
	movl	%eax, (%ecx,%esi)
	movl	%edx, 4(%ecx,%esi)
	cmpl	%edi, 64(%esp)
	je	L67
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	28(%esp), %esi
	movl	%ebx, 28(%esp)
L61:
	movl	(%eax), %ecx
	movl	4(%eax), %ebx
	movl	%ecx, (%edx)
	movl	%ebx, 4(%edx)
	addl	$8, %edx
	addl	$8, %eax
	cmpl	%eax, %esi
	jne	L61
	movl	28(%esp), %ebx
	movl	64(%esp), %eax
	subl	$8, %eax
	subl	%edi, %eax
	shrl	$3, %eax
	movl	20(%esp), %ecx
	leal	8(%ecx,%eax,8), %esi
L60:
	addl	$8, %esi
	cmpl	%ebx, 64(%esp)
	je	L62
	movl	64(%esp), %eax
	movl	%esi, %edx
	movl	%esi, %ecx
	movl	%edi, 28(%esp)
L63:
	movl	(%eax), %esi
	movl	4(%eax), %edi
	movl	%esi, (%edx)
	movl	%edi, 4(%edx)
	addl	$8, %edx
	addl	$8, %eax
	cmpl	%eax, %ebx
	jne	L63
	movl	28(%esp), %edi
	subl	64(%esp), %ebx
	leal	-8(%ebx), %eax
	shrl	$3, %eax
	leal	8(%ecx,%eax,8), %esi
L62:
	testl	%edi, %edi
	je	L64
	movl	%edi, (%esp)
	call	__ZdlPv
L64:
	movl	20(%esp), %eax
	movl	%eax, 0(%ebp)
	movl	%esi, 4(%ebp)
	movl	24(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movl	%eax, 8(%ebp)
	addl	$44, %esp
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
	.cfi_endproc
LFE1796:
	.section	.text$_ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"x"
	.linkonce discard
	.align 2
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
	movl	%ecx, %ebp
	movl	64(%esp), %eax
	movl	%eax, 28(%esp)
	movl	4(%ecx), %ebx
	movl	(%ecx), %edi
	movl	%ebx, %eax
	subl	%edi, %eax
	sarl	$3, %eax
	je	L74
	leal	(%eax,%eax), %ecx
	movl	%ecx, 24(%esp)
	cmpl	%ecx, %eax
	ja	L75
	cmpl	$536870911, %ecx
	ja	L75
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	cmpl	$0, 24(%esp)
	jne	L82
	movl	$0, 20(%esp)
	jmp	L83
L84:
	movl	20(%esp), %esi
	jmp	L77
L75:
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	movl	$536870911, 24(%esp)
	jmp	L82
L74:
	movl	64(%esp), %eax
	subl	%edi, %eax
	movl	%eax, %esi
	movl	$1, 24(%esp)
L82:
	movl	24(%esp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	__Znwj
	movl	%eax, 20(%esp)
L83:
	movl	68(%esp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	20(%esp), %ecx
	movl	%eax, (%ecx,%esi)
	movl	%edx, 4(%ecx,%esi)
	cmpl	%edi, 64(%esp)
	je	L84
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	28(%esp), %esi
	movl	%ebx, 28(%esp)
L78:
	movl	(%eax), %ecx
	movl	4(%eax), %ebx
	movl	%ecx, (%edx)
	movl	%ebx, 4(%edx)
	addl	$8, %edx
	addl	$8, %eax
	cmpl	%eax, %esi
	jne	L78
	movl	28(%esp), %ebx
	movl	64(%esp), %eax
	subl	$8, %eax
	subl	%edi, %eax
	shrl	$3, %eax
	movl	20(%esp), %ecx
	leal	8(%ecx,%eax,8), %esi
L77:
	addl	$8, %esi
	cmpl	%ebx, 64(%esp)
	je	L79
	movl	64(%esp), %eax
	movl	%esi, %edx
	movl	%esi, %ecx
	movl	%edi, 28(%esp)
L80:
	movl	(%eax), %esi
	movl	4(%eax), %edi
	movl	%esi, (%edx)
	movl	%edi, 4(%edx)
	addl	$8, %edx
	addl	$8, %eax
	cmpl	%eax, %ebx
	jne	L80
	movl	28(%esp), %edi
	subl	64(%esp), %ebx
	leal	-8(%ebx), %eax
	shrl	$3, %eax
	leal	8(%ecx,%eax,8), %esi
L79:
	testl	%edi, %edi
	je	L81
	movl	%edi, (%esp)
	call	__ZdlPv
L81:
	movl	20(%esp), %eax
	movl	%eax, 0(%ebp)
	movl	%esi, 4(%ebp)
	movl	24(%esp), %edi
	leal	(%eax,%edi,8), %eax
	movl	%eax, 8(%ebp)
	addl	$44, %esp
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
	.cfi_endproc
LFE1844:
	.section	.text$_ZN8Dijkstra8dijkstraEi,"x"
	.linkonce discard
	.align 2
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
	subl	$124, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, %ebx
	movl	8(%ebp), %edx
	movl	$0, -48(%ebp)
	movl	$0, -44(%ebp)
	movl	$0, -40(%ebp)
	movl	(%ecx), %ecx
	testl	%ecx, %ecx
	jle	L91
	leal	13280(%ebx), %eax
	leal	(%eax,%ecx,4), %ecx
L92:
	movl	$1061109567, (%eax)
	addl	$4, %eax
	cmpl	%ecx, %eax
	jne	L92
L91:
	movl	$0, 13280(%ebx,%edx,4)
	leal	12260(%ebx), %ecx
	movl	$0, 12260(%ebx)
	movl	$0, 13276(%ebx)
	leal	12264(%ebx), %edi
	andl	$-4, %edi
	subl	%edi, %ecx
	addl	$1020, %ecx
	shrl	$2, %ecx
	movl	$0, %eax
	rep stosl
	movl	$0, -32(%ebp)
	movl	%edx, -28(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	leal	-48(%ebp), %ecx
LEHB0:
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	subl	$8, %esp
	movl	-44(%ebp), %ecx
	movl	-48(%ebp), %esi
	movl	-8(%ecx), %eax
	movl	-4(%ecx), %edx
	leal	-56(%ebp), %edi
	movl	%edi, 20(%esp)
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
	movl	$0, 8(%esp)
	subl	%esi, %ecx
	sarl	$3, %ecx
	leal	-1(%ecx), %eax
	movl	%eax, 4(%esp)
	movl	%esi, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
L99:
	movl	-44(%ebp), %eax
	movl	-48(%ebp), %edx
	cmpl	%eax, %edx
	je	L93
	movl	4(%edx), %edi
	movl	%edi, -80(%ebp)
	movl	%eax, %ecx
	subl	%edx, %ecx
	cmpl	$8, %ecx
	jg	L118
L94:
	subl	$8, -44(%ebp)
	movl	-80(%ebp), %esi
	cmpb	$0, 12260(%ebx,%esi)
	jne	L99
	movb	$1, 12260(%ebx,%esi)
	leal	(%esi,%esi,2), %eax
	leal	(%ebx,%eax,4), %eax
	movl	20(%eax), %edx
	movl	$0, -76(%ebp)
	leal	(%esi,%esi,2), %ecx
	movl	%ecx, -84(%ebp)
	cmpl	24(%eax), %edx
	jne	L100
	jmp	L99
L118:
	movl	-8(%eax), %ecx
	movl	%ecx, -84(%ebp)
	movl	-4(%eax), %ecx
	movl	%ecx, -76(%ebp)
	movl	(%edx), %esi
	movl	4(%edx), %edi
	movl	%esi, -8(%eax)
	movl	%edi, -4(%eax)
	subl	$8, %eax
	subl	%edx, %eax
	movl	%eax, %esi
	sarl	$3, %esi
	leal	-1(%esi), %ecx
	movl	%ecx, %edi
	shrl	$31, %edi
	addl	%ecx, %edi
	sarl	%edi
	cmpl	$16, %eax
	jle	L109
	movl	$0, %ecx
	movl	%ebx, -88(%ebp)
	movl	%esi, -92(%ebp)
	jmp	L97
L96:
	movl	(%edx,%eax,8), %ebx
	movl	4(%edx,%eax,8), %esi
	movl	%ebx, (%edx,%ecx,8)
	movl	%esi, 4(%edx,%ecx,8)
	movl	%eax, %ecx
	cmpl	%edi, %eax
	jge	L119
L97:
	leal	2(%ecx,%ecx), %eax
	leal	-1(%eax), %esi
	movl	(%edx,%esi,8), %ebx
	cmpl	%ebx, (%edx,%eax,8)
	jle	L96
	movl	%esi, %eax
	jmp	L96
L119:
	movl	-88(%ebp), %ebx
	movl	-92(%ebp), %esi
L95:
	movl	%esi, %edi
	testl	$1, %esi
	jne	L98
	subl	$2, %edi
	movl	%edi, %ecx
	shrl	$31, %ecx
	addl	%edi, %ecx
	sarl	%ecx
	cmpl	%ecx, %eax
	je	L120
L98:
	leal	-56(%ebp), %edi
	movl	%edi, 20(%esp)
	movl	-84(%ebp), %esi
	movl	%esi, 12(%esp)
	movl	-76(%ebp), %edi
	movl	%edi, 16(%esp)
	movl	$0, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
	jmp	L94
L109:
	movl	$0, %eax
	jmp	L95
L120:
	leal	1(%eax,%eax), %ecx
	movl	(%edx,%ecx,8), %esi
	movl	4(%edx,%ecx,8), %edi
	movl	%esi, (%edx,%eax,8)
	movl	%edi, 4(%edx,%eax,8)
	movl	%ecx, %eax
	jmp	L98
L103:
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%ecx, (%esp)
	leal	-48(%ebp), %ecx
	call	__ZNSt6vectorIN8Dijkstra8HeapNodeESaIS1_EE17_M_realloc_insertIJRKS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
LEHE0:
	subl	$8, %esp
L104:
	movl	-44(%ebp), %eax
	movl	-48(%ebp), %edx
	movl	-8(%eax), %esi
	movl	-4(%eax), %edi
	movl	%esi, 12(%esp)
	movl	%edi, 16(%esp)
	leal	-57(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	$0, 8(%esp)
	subl	%edx, %eax
	sarl	$3, %eax
	subl	$1, %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIPN8Dijkstra8HeapNodeESt6vectorIS3_SaIS3_EEEEiS3_NS0_5__ops14_Iter_comp_valISt4lessIS3_EEEEvT_T0_SF_T1_RT2_
L102:
	addl	$1, -76(%ebp)
	movl	-76(%ebp), %esi
	movl	-84(%ebp), %eax
	leal	(%ebx,%eax,4), %eax
	movl	20(%eax), %edx
	movl	24(%eax), %eax
	subl	%edx, %eax
	sarl	$2, %eax
	cmpl	%eax, %esi
	jnb	L99
L100:
	movl	-76(%ebp), %eax
	leal	(%edx,%eax,4), %ecx
	movl	(%ecx), %eax
	leal	(%eax,%eax,2), %edx
	movl	8(%ebx), %eax
	leal	(%eax,%edx,4), %edx
	movl	4(%edx), %eax
	leal	(%ebx,%eax,4), %edi
	movl	8(%edx), %eax
	movl	-80(%ebp), %esi
	addl	13280(%ebx,%esi,4), %eax
	cmpl	%eax, 13280(%edi)
	jle	L102
	movl	%eax, 13280(%edi)
	movl	4(%edx), %eax
	movl	(%ecx), %ecx
	movl	%ecx, 17360(%ebx,%eax,4)
	movl	4(%edx), %eax
	movl	13280(%ebx,%eax,4), %edx
	movl	%edx, -56(%ebp)
	movl	%eax, -52(%ebp)
	movl	-44(%ebp), %ecx
	cmpl	-40(%ebp), %ecx
	je	L103
	movl	-56(%ebp), %eax
	movl	-52(%ebp), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	addl	$8, -44(%ebp)
	jmp	L104
L93:
	testl	%eax, %eax
	je	L90
	movl	%eax, (%esp)
	call	__ZdlPv
L90:
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
L111:
	.cfi_restore_state
	movl	%eax, %ebx
	movl	-48(%ebp), %eax
	testl	%eax, %eax
	je	L108
	movl	%eax, (%esp)
	call	__ZdlPv
L108:
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
	.uleb128 L111-LFB1665
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
	.ascii "%d%d%d\0"
LC2:
	.ascii "%d\12\0"
	.text
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
	subl	$88, %esp
	call	___main
	leal	-60(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	movl	-60(%ebp), %eax
	movl	%eax, _dijkstra
	testl	%eax, %eax
	jle	L122
	leal	(%eax,%eax,2), %ecx
	sall	$2, %ecx
	movl	$0, %eax
	jmp	L124
L123:
	addl	$12, %eax
	cmpl	%ecx, %eax
	je	L122
L124:
	movl	_dijkstra+20(%eax), %edx
	cmpl	_dijkstra+24(%eax), %edx
	je	L123
	movl	%edx, _dijkstra+24(%eax)
	jmp	L123
L122:
	movl	_dijkstra+8, %eax
	cmpl	_dijkstra+12, %eax
	je	L125
	movl	%eax, _dijkstra+12
L125:
	cmpl	$0, -64(%ebp)
	jle	L126
	movl	$0, %esi
	leal	-68(%ebp), %edi
L127:
	movl	%edi, 12(%esp)
	leal	-72(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	-76(%ebp), %eax
	leal	-1(%eax), %ebx
	movl	%ebx, -76(%ebp)
	movl	-72(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -72(%ebp)
	movl	%ebx, -36(%ebp)
	movl	%eax, -32(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -28(%ebp)
	leal	-36(%ebp), %eax
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_
	subl	$4, %esp
	movl	_dijkstra+12, %eax
	subl	_dijkstra+8, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	movl	%eax, _dijkstra+4
	subl	$1, %eax
	movl	%eax, -40(%ebp)
	leal	(%ebx,%ebx,2), %eax
	leal	_dijkstra+20(,%eax,4), %ecx
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_
	subl	$4, %esp
	movl	-72(%ebp), %ebx
	movl	%ebx, -52(%ebp)
	movl	-76(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	-68(%ebp), %eax
	movl	%eax, -44(%ebp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	movl	$_dijkstra+8, %ecx
	call	__ZNSt6vectorI4EdgeSaIS0_EE12emplace_backIJS0_EEEvDpOT_
	subl	$4, %esp
	movl	_dijkstra+12, %eax
	subl	_dijkstra+8, %eax
	sarl	$2, %eax
	imull	$-1431655765, %eax, %eax
	movl	%eax, _dijkstra+4
	subl	$1, %eax
	movl	%eax, -56(%ebp)
	leal	(%ebx,%ebx,2), %eax
	leal	_dijkstra+20(,%eax,4), %ecx
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorIiSaIiEE12emplace_backIJiEEEvDpOT_
	subl	$4, %esp
	addl	$1, %esi
	cmpl	%esi, -64(%ebp)
	jg	L127
L126:
	movl	-60(%ebp), %eax
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
	leal	-16(%ebp), %esp
	popl	%ecx
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
	.cfi_endproc
LFE1672:
	.def	__GLOBAL__sub_I_dijkstra;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_dijkstra:
LFB1966:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$0, _dijkstra+8
	movl	$0, _dijkstra+12
	movl	$0, _dijkstra+16
	movl	$_dijkstra+20, %eax
	movl	$_dijkstra+12260, %edx
L132:
	movl	$0, (%eax)
	movl	$0, 4(%eax)
	movl	$0, 8(%eax)
	addl	$12, %eax
	cmpl	%edx, %eax
	jne	L132
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
