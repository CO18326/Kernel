gdt_start:



	null_ds:

	dd 0h
	dd 0h


	code_ds:

	dw 0ffffh       ;limit (0-15)


	dw 0h          ;base address (0-15)

	db 0h          ;base address (16-23)

	db 10011010b   ;(present,previllage,code or data/trap    code or data , confirmity, readable/execute only , accessed)

	db 11001111b   ;(granuality,32 bit default,64-bit mode,AVL  limit (16-19))

	db 0b          ;(limit (24-31))



	data_ds:


	dw 0ffffh

	dw 0h

	db 0h

	db 10010010b

	db 11001111b

	db 0h


gdt_end:




gdt_describe:

dw gdt_end - gdt_start - 1
dd gdt_start



code_seg equ code_ds - gdt_start
data_seg equ data_ds - gdt_start

