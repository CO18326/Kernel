


;mov ax,07c0h
mov ds,ax
mov ax,07e0h
mov ss,ax
mov sp,2000h


;org 07c00h
;mov bp,9000h
;mov sp,bp
call screen

call pointer

push left

mov dx,1234h
call printing

add sp,2
call switch_to_pm

hlt

include 'gdt.asm'
include 'subroutines.asm'


use32


actual_start:
	mov ebx, msg
	mov edx,0b8000h
	call print_32

	
	hlt




boot_load db 0
left  db  "ox0000",0
msg   db "Now in 32 bit protected mode",0



db 506-371 dup(0)

dw 0aa55h