	.global start
	.global main

start:
	call	main
	movl	%eax,%edi
	movl	$0x3c,%eax
	syscall

main:
	push	%rbp
	movq	%rsp,%rbp
	addq	$0xfffffffffffffff0,%rsp
	movl	$0xe,%edx
	movq	$0x57202c6f6c6c6548,%rax
	movq	%rax,0xfffffffffffffff0(%rbp)
	movl	$0x646c726f,0xfffffffffffffff8(%rbp)
	movw	$0xa21,0xfffffffffffffffc(%rbp)
	movb	$0,0xfffffffffffffffe(%rbp)
	leaq	0xfffffffffffffff0(%rbp),%rsi
	movl	$1,%edi
	movl	$1,%eax
	syscall
	xorl	%eax,%eax
	addq	$0x10,%rsp
	pop	%rbp
	ret
