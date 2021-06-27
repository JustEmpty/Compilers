segment	.text
align	4
show:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	call	printd
	add	esp, 8
	call	println
        ;; after body 
_L1:
	leave
	ret
segment	.text
align	4
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
        ;; before body 
	lea	eax, [ebp+12]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	eax
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L3:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+12]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 2
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	eax
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L4
	lea	eax, [ebp+8]
	push	eax
	pop	eax
	push	dword [eax]
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	call	show
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L3
_L4:
        ;; after body 
_L2:
	leave
	ret
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	push	dword 0
	pop	eax
	mov	[ebp-4], eax
        ;; before body 
	push	dword 3
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	sub	esp, eax
	push	esp
	pop	eax
	mov	[ebp-8], eax
segment	.rodata
align	4
_L1_cdk_emitter_internal:
	dq	1.10000
segment	.text
	push	dword $_L1_cdk_emitter_internal
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 0
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
segment	.rodata
align	4
_L2_cdk_emitter_internal:
	dq	2.20000
segment	.text
	push	dword $_L2_cdk_emitter_internal
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 1
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
segment	.rodata
align	4
_L3_cdk_emitter_internal:
	dq	3.30000
segment	.text
	push	dword $_L3_cdk_emitter_internal
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	push	esp
	pop	eax
	push	dword [eax+4]
	push	dword [eax]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 2
	push	dword 3
	pop	ecx
	sal	dword [esp], cl
	pop	eax
	add	dword [esp], eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	pop	eax
	mov	[ecx+4], eax
	add	esp, 8
	push	dword 5
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	call	f
	add	esp, 8
        ;; after body 
_L5:
	push	dword [ebp-4]
	pop	eax
	leave
	ret
extern	printd
extern	println
extern	readi
extern	readd
extern	printi
extern	prints
extern	printd
extern	println
