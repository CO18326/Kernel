use16



mov ax,07c0h
mov ds,ax

mov ax,07e0h
mov ss,ax

mov sp,8000h




mov byte[boot_load],dl

call screen

call pointer

push msg
call disk_read
add sp,2

mov bx,00000h
mov es,bx

mov bx,9000h



mov dx,word[9000h-07c00h+512]
push stri

call printing
add sp,2


cli
hlt




include 'subroutines.asm'










boot_load db 0
msg db "Disk Error! Sorry",0
stri db "ox0000",0



db 507-258 dup(0)

dw 0aa55h

dw 256 dup(1234h)
dw 256 dup(5656h) 