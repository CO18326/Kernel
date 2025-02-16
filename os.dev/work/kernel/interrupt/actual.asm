

bits 32
global lidta
global isr0
extern interrupt
extern print_at
;hlt


lidta:

mov ebp,esp

mov eax, dword[ebp+4]

lidt [eax]

mov esp,ebp

ret




;isr0:

;cli
;push byte +0x0f
;push lj
;push 0
;call print_at
;push 0
;add esp,5
;sti
;iret
;
;jmp common_part




global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31
global isr32
global isr33
global isr34
global isr35
global isr36
global isr37
global isr38
global isr39
global isr40
global isr41
global isr42
global isr43
global isr44
global isr45
global isr46
global isr47

extern sep
; 0: Divide By Zero Exception
isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_common_stub

; 1: Debug Exception
isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_common_stub

; 2: Non Maskable Interrupt Exception
isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_common_stub

; 3: Int 3 Exception
isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_common_stub

; 4: INTO Exception
isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_common_stub

; 5: Out of Bounds Exception
isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_common_stub

; 6: Invalid Opcode Exception
isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_common_stub

; 7: Coprocessor Not Available Exception
isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_common_stub

; 8: Double Fault Exception (With Error Code!)
isr8:
    cli
    push byte 8
    jmp isr_common_stub

; 9: Coprocessor Segment Overrun Exception
isr9:
    cli
    push byte 0
    push byte 9
    jmp isr_common_stub

; 10: Bad TSS Exception (With Error Code!)
isr10:
    cli
    push byte 10
    jmp isr_common_stub

; 11: Segment Not Present Exception (With Error Code!)
isr11:
    cli
    push byte 11
    jmp isr_common_stub

; 12: Stack Fault Exception (With Error Code!)
isr12:
    cli
    push byte 12
    jmp isr_common_stub

; 13: General Protection Fault Exception (With Error Code!)
isr13:
    cli
    push byte 13
    jmp isr_common_stub

; 14: Page Fault Exception (With Error Code!)
isr14:
    cli
    push byte 14
    jmp isr_common_stub

; 15: Reserved Exception
isr15:
    cli
    push byte 0
    push byte 15
    jmp isr_common_stub

; 16: Floating Point Exception
isr16:
    cli
    push byte 0
    push byte 16
    jmp isr_common_stub

; 17: Alignment Check Exception
isr17:
    cli
    push byte 0
    push byte 17
    jmp isr_common_stub

; 18: Machine Check Exception
isr18:
    cli
    push byte 0
    push byte 18
    jmp isr_common_stub

; 19: Reserved
isr19:
    cli
    push byte 0
    push byte 19
    jmp isr_common_stub

; 20: Reserved
isr20:
    cli
    push byte 0
    push byte 20
    jmp isr_common_stub

; 21: Reserved
isr21:
    cli
    push byte 0
    push byte 21
    jmp isr_common_stub

; 22: Reserved
isr22:
    cli
    push byte 0
    push byte 22
    jmp isr_common_stub

; 23: Reserved
isr23:
    cli
    push byte 0
    push byte 23
    jmp isr_common_stub

; 24: Reserved
isr24:
    cli
    push byte 0
    push byte 24
    jmp isr_common_stub

; 25: Reserved
isr25:
    cli
    push byte 0
    push byte 25
    jmp isr_common_stub

; 26: Reserved
isr26:
    cli
    push byte 0
    push byte 26
    jmp isr_common_stub

; 27: Reserved
isr27:
    cli
    push byte 0
    push byte 27
    jmp isr_common_stub

; 28: Reserved
isr28:
    cli
    push byte 0
    push byte 28
    jmp isr_common_stub

; 29: Reserved
isr29:
    cli
    push byte 0
    push byte 29
    jmp isr_common_stub

; 30: Reserved
isr30:
    cli
    push byte 0
    push byte 30
    jmp isr_common_stub

; 31: Reserved
isr31:
    cli
    push byte 0
    push byte 31
    jmp isr_common_stub



isr32:
cli
push byte 0
push byte 32
jmp iqr_common_stub
isr33:
cli
push byte 0
push byte 33
jmp iqr_common_stub
isr34:
cli
push byte 0
push byte 34
jmp iqr_common_stub
isr35:
cli
push byte 0
push byte 35
jmp iqr_common_stub
isr36:
cli
push byte 0
push byte 36
jmp iqr_common_stub
isr37:
cli
push byte 0
push byte 37
jmp iqr_common_stub
isr38:
cli
push byte 0
push byte 38
jmp iqr_common_stub
isr39:
cli
push byte 0
push byte 39
jmp iqr_common_stub
isr40:
cli
push byte 0
push byte 40
jmp iqr_common_stub
isr41:
cli
push byte 0
push byte 41
jmp iqr_common_stub
isr42:
cli
push byte 0
push byte 42
jmp iqr_common_stub
isr43:
cli
push byte 0
push byte 43
jmp iqr_common_stub
isr44:
cli
push byte 0
push byte 44
jmp iqr_common_stub
isr45:
cli
push byte 0
push byte 45
jmp iqr_common_stub
isr46:
cli
push byte 0
push byte 46
jmp iqr_common_stub
isr47:
cli
push byte 0
push byte 47
jmp iqr_common_stub



















isr_common_stub:



mov ax,ds

push eax

mov ax,10h

mov ds,ax
mov es,ax
mov fs,ax
mov gs,ax
;mov ss,ax


call sep
;call sep
pop ebx

mov ds,bx
mov es,bx
mov fs,bx
mov gs,bx
;mov ss,ax

add esp,8
sti
iret

iqr_common_stub:

mov ax,ds

push eax

mov ax,10h

mov ds,ax
mov es,ax
mov fs,ax
mov gs,ax
;mov ss,ax


call interrupt
;call sep
pop ebx

mov ds,bx
mov es,bx
mov fs,bx
mov gs,bx
;mov ss,ax

add esp,8
sti
iret




nb db 0x0f
lj db "sai",0