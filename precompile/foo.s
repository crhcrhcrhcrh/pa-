foo:
	movl	%edi, n
	movl	$0, sum
	movl	$1, i
	jmp	.L2
.L3:
	movl	i, tmp
	addl	tmp, sum
	addl	$1, i
.L2:
	movl	i, tmp
	cmpl	n, tmp
	jle	.L3
	movl	sum, tmp
	popq	%rbp
	ret
