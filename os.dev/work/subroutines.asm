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



printing:                      ;requires dx hex value and argument of memory
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
		je dones
		int 10h
		jmp printd
		dones: 



	popa
	mov sp,bp
	pop bp
    ret




disk_read:
	
	push bp
	mov bp,sp
	pusha
	mov ah,02h
	mov cl,02h
	mov al,0fh
	mov dh,00h
	mov ch,00h
	mov bx,0000h
	mov es,bx
	mov bx,1000h
	mov dl,byte[boot_load]
	mov byte[boot_load],al
	
	int 13h
	jc disk_error

   cmp al,byte[boot_load]
      jne disk_error

    jmp  done


	disk_error:
			mov si,word[bp+4]
			mov ah,0eh
			
			printg:
				
				mov al,byte[si]
				inc si
				or al,00h
				je done
				int 10h
				jmp printg
   done:
   popa
   mov sp,bp
   pop bp

   ret







use32
print_32:
	push ebp
	mov ebp,esp
	pusha

	mov ah,0fh
	mov ebx,dword[ebp+8]

	printingx:
		mov al,byte[ebx]
		inc ebx
		or al,0h
		je donez
		mov byte[edx],al
		mov byte[edx+1],ah
		add edx,2h
		jmp printingx
		donez:
popa
mov esp,ebp
pop ebp
ret







use16
switch_to_pm:
	cli
	
	lgdt [gdt_describe]

	mov eax,cr0
	or eax,1h
	mov cr0,eax

	jmp code_seg:pm_init



	use32
	pm_init:
	mov ax,data_seg
	mov ds,ax
	mov ss,ax
	mov es,ax
	mov fs,ax
	mov gs,ax

	
	mov ebp , 90000h 
	mov esp , ebp
	call actual_start




