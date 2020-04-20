

c_source = $(wildcard  kernel/*.c kernel/interrupt/*.c kernel/interrupt/actual.asm)


obj = ${c_source:.c=.o} - $(wildcard kernel/apis.o)

all : os-image

%.o : %.c 
	gcc -fno-pie -m32 -c $< -o $@




kernel2.bin : ${obj}
	ld -o $@ -Ttext 0x1000 $^ -melf_i386 --oformat binary




os-image : switching32.bin kernel2.bin
	cat $^ > $@


