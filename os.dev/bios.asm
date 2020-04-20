use16

mov ax,07c0h
mov ds,ax

mov ax,07e0h
mov ss,ax


mov sp,2000h



call screen

call cursor


push msg

call print

add sp,2


cli

hlt





screen:
	push bp
	mov bp,sp
	pusha
	mov ah,07h
	mov al,00h
	mov bh,4eh
	mov cx,00h
	mov dh,18h
	mov dl,4fh
	int 10h

	popa
	mov sp,bp
	pop bp
	ret



cursor:
	push bp
	mov bp,sp
	pusha
	mov ah,02h
	mov bh,00h
	mov dx,00h

	popa
	mov sp,bp
	pop bp
	ret


print:
	push bp
	mov bp,sp
	pusha


	mov ah,0eh
	mov bh,00h
	mov bl,00h
	mov si,word[bp+4]

	.repeats:
		mov al,byte[si]
		add si,1
		or al,0h
		je done
		int 10h
		jmp .repeats

		done:

			popa
			mov sp,bp
			pop bp
			ret


msg   db "I am first bootloader created by Ishan Gambhir !",0





db 361 dup(0)

dw 0aa55h
