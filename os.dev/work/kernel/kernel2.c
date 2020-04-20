

#include "../driver/vote.h"
#include "apis.h"
void extern mainc();
extern ayappa;
extern int str_cmp(char*,char*);
extern void cprint();
int command_mode=0;
char* input;

void test(){

/*char str[24+80];
for(int i=0;i<24;i++){
	str[i]='\n';
}
for(int i=24;i<80;i++){
	str[i]='I';
}*/
//mainc();
clear_s();
print_at("CCEtian@2020>>",0x02);
//print_at(,0x0f);
int result=0;
//asm volatile("div %%eax"::"a"(result));
//asm volatile ("int $0x0");
asm volatile ("sti");
while ( ayappa != 0x3){   if(ayappa==0x1C)
	{
		if(str_cmp(input,"CFILE")==0) {command_mode=1;}
 else if(str_cmp(input,"CPRINT")==0) {cprint();} 
else{ print_at("CCEtian@2020>>",0x02); ayappa=0;   }
}
}


print_at(input,0x0f);



}



#include "../driver/vote.c"
#include "apis.c"