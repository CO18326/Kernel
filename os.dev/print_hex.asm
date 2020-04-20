use16



mov ax,07c0h
mov ds,ax
mov ax,07e0h

mov ss,ax

mov sp,2000h


call screen

call pointer

mov dx,123fh

push msg

call printing

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
	mov cx,0h
	mov dh,18h
	mov dl,4fh

	int 10h

	popa
	mov sp,bp
	pop bp

	ret


pointer:
	push bp
	mov bp,sp
	pusha

	mov ah,02h
	mov bh,00h
	mov dx,0h

	int 10h
	
	popa
	mov sp,bp
	pop bp

	ret



printing:
	push bp
	mov bp,sp
	pusha
	mov si,word[bp+4]
	add si,5
	mov bh,03
    	
	labels:
		mov bl,bh
		mov cl,04h
		cmp bh,03h
		jne ler
		mov cl,00h
		ler:
		shr dx,cl
		mov ax,dx
		
		and ax,000fh
		cmp ax,9h
		ja here

        add ax,30h
        jmp exit

		here:
			add ax,55
		exit:
			
			
			
			mov byte[si],al
			
			dec si
			dec bh
			cmp bh,0h
			jge labels

	
	mov ah,0eh
	mov bh,00h
	mov bl,00h
   dec si
	printd:
		mov al,byte[si]
		inc si
		or al,00h
		je done
		int 10h
		jmp printd
		done: 



	popa
	mov sp,bp
	pop bp
    ret



msg db "ox0000",0

db 508-156 dup (0)
dw 0aa55h




