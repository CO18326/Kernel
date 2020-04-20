
extern void lidta(unsigned int);
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();
extern void isr32();
extern void isr33();
extern void isr34();
extern void isr35();
extern void isr36();
extern void isr37();
extern void isr38();
extern void isr39();
extern void isr40();
extern void isr41();
extern void isr42();
extern void isr43();
extern void isr44();
extern void isr45();
extern void isr46();
extern void isr47();




extern void test();
static void time_pass(int,unsigned int,unsigned short,unsigned char);
void os();
void sab();
void mainc();
void init();
extern void port_byte_out(unsigned short,unsigned char);
struct segment{


unsigned short lower;
unsigned short sel;
char always0;
char flag;
unsigned short upper;

}__attribute__((packed));


//typedef struct segment i_seg;


struct discriptor{

unsigned short limit;

unsigned int start;

}__attribute__((packed));

typedef struct discriptor i_dis;
i_dis disc;
struct segment modi[256];


void mainc(){
port_byte_out(0x0020,0x11);
port_byte_out(0x00a0,0x11);
port_byte_out(0x0021,0x20);
port_byte_out(0x00a1,0x28);
port_byte_out(0x0021,0x04);
port_byte_out(0x00a1,0x02);
port_byte_out(0x0021,0x01);
port_byte_out(0x00a1,0x01);
port_byte_out(0x0021,0x0);
port_byte_out(0x00a1,0x0);
init();
//time_pass();
os();
sab();

}


void init(){



 time_pass(0,(unsigned int)isr0,0x08,0x8e);
time_pass(1,(unsigned int)isr1,0x08,0x8e);
time_pass(2,(unsigned int)isr2,0x08,0x8e);
time_pass(3,(unsigned int)isr3,0x08,0x8e);
time_pass(4,(unsigned int)isr4,0x08,0x8e);
time_pass(5,(unsigned int)isr5,0x08,0x8e);
time_pass(6,(unsigned int)isr6,0x08,0x8e);
time_pass(7,(unsigned int)isr7,0x08,0x8e);
time_pass(8,(unsigned int)isr8,0x08,0x8e);
time_pass(9,(unsigned int)isr9,0x08,0x8e);
time_pass(10,(unsigned int)isr10,0x08,0x8e);
time_pass(11,(unsigned int)isr11,0x08,0x8e);
time_pass(12,(unsigned int)isr12,0x08,0x8e);
time_pass(13,(unsigned int)isr13,0x08,0x8e);
time_pass(14,(unsigned int)isr14,0x08,0x8e);
time_pass(15,(unsigned int)isr15,0x08,0x8e);
time_pass(16,(unsigned int)isr16,0x08,0x8e);
time_pass(17,(unsigned int)isr17,0x08,0x8e);
time_pass(18,(unsigned int)isr18,0x08,0x8e);
time_pass(19,(unsigned int)isr19,0x08,0x8e);
time_pass(20,(unsigned int)isr20,0x08,0x8e);
time_pass(21,(unsigned int)isr21,0x08,0x8e);
time_pass(22,(unsigned int)isr22,0x08,0x8e);
time_pass(23,(unsigned int)isr23,0x08,0x8e);
time_pass(24,(unsigned int)isr24,0x08,0x8e);
time_pass(25,(unsigned int)isr25,0x08,0x8e);
time_pass(26,(unsigned int)isr26,0x08,0x8e);
time_pass(27,(unsigned int)isr27,0x08,0x8e);
time_pass(28,(unsigned int)isr28,0x08,0x8e);
time_pass(29,(unsigned int)isr29,0x08,0x8e);
time_pass(30,(unsigned int)isr30,0x08,0x8e);
time_pass(31,(unsigned int)isr31,0x08,0x8e);
time_pass(32,(unsigned int)isr32,0x08,0x8e);
time_pass(33,(unsigned int)isr33,0x08,0x8e);
time_pass(34,(unsigned int)isr34,0x08,0x8e);
time_pass(35,(unsigned int)isr35,0x08,0x8e);
time_pass(36,(unsigned int)isr36,0x08,0x8e);
time_pass(37,(unsigned int)isr37,0x08,0x8e);
time_pass(38,(unsigned int)isr38,0x08,0x8e);
time_pass(39,(unsigned int)isr39,0x08,0x8e);
time_pass(40,(unsigned int)isr40,0x08,0x8e);
time_pass(41,(unsigned int)isr41,0x08,0x8e);
time_pass(42,(unsigned int)isr42,0x08,0x8e);
time_pass(43,(unsigned int)isr43,0x08,0x8e);
time_pass(44,(unsigned int)isr44,0x08,0x8e);
time_pass(45,(unsigned int)isr45,0x08,0x8e);
time_pass(46,(unsigned int)isr46,0x08,0x8e);
time_pass(47,(unsigned int)isr47,0x08,0x8e);












}






void time_pass(int i,unsigned int lower,unsigned short sel,unsigned char flag)
{ 
 modi[i].lower= (unsigned int)lower & 0xffff;
 modi[i].sel=sel;
 modi[i].always0=0;
 modi[i].flag=flag;
 modi[i].upper=  ((unsigned int)lower >> 16) & 0xffff;
}




void os(){
disc.limit=sizeof(struct segment)*256-1;
disc.start= (unsigned int)modi;
}

void sab(){
//asm volatile ("sti");
asm volatile ("lidtl (%0)"::"r"((unsigned int)&disc));
//lidta((unsigned int)&disc);
test();
}
