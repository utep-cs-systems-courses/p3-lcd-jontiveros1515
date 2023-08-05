	.arch msp430g2553
	.p2align 1,0
	.text
	.align 2
	.extern forloop
	.global advanceState2
	
jt:
	.word c0
	.word c1
	.word c2
	.word c3
	.data
	.align 2
b:
	.word 0
	.text
	
advanceState2:
	mov &b, r12
	mov jt(r12), r0

c0:
	mov #0, r12
	mov #-1, r13
	call #forloop
	add #1, &b
	pop r0
c1:
	mov #-1, r12
	mov #-1, r13
	call #forloop
	add #1, &b
	pop r0
c2:
	mov #0, r12
	mov #-1, r13
	call #forloop
	add #1, &b
	pop r0
c3:
	mov #1, r12
	mov #-1, r13
	call #forloop
	mov #0, &b
	pop r0
