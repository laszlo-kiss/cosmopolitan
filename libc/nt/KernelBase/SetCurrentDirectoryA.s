.include "o/libc/nt/codegen.inc"
.imp	KernelBase,__imp_SetCurrentDirectoryA,SetCurrentDirectoryA,1493

	.text.windows
SetCurrentDirectoryA:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	%rdi,%rcx
	sub	$32,%rsp
	call	*__imp_SetCurrentDirectoryA(%rip)
	leave
	ret
	.endfn	SetCurrentDirectoryA,globl
	.previous
