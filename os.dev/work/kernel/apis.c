

extern void write_sector_lba(unsigned char,unsigned int,unsigned char,unsigned char*);
extern void read_sector_lba(unsigned char,unsigned int,unsigned char,unsigned char*);

void clear_s(){
char *video_memory=(char*)0xb8000;
int row=25;
int col=80;

for (int i=0;i<(row*col);i++){
video_memory[2*i]=' ';
video_memory[2*i+1]=0x0f;

}

set_offset(0);


}



void print_at(char* msg,unsigned char property){

int current_offset;
char *video_memory = (char*)0xb8000;

current_offset = get_offset();

int i=0;

while(msg[i]!=0){

if (msg[i]=='\n'){
	int a=(current_offset%160/2)-14;
	*(input+a)='\0';
	int m=current_offset;
	do{
		m-=2;
		*(input+a-1)=video_memory[m];
		a--;} while(m%160!=28);




	current_offset+=(160-current_offset%160);i++;

}
else{
video_memory[current_offset]=msg[i];
video_memory[current_offset+1]=property;
i++;
current_offset+=2;
}
if (current_offset > 2*(25*80)-2){
	for (int i;i<=(current_offset-2*80);i+=2*80){
		mem_cpy(video_memory+i,video_memory+i-160,160);
	}
current_offset-=160;
for(int i=0;i<160;i+=2){
video_memory[current_offset+i]=' ';
video_memory[current_offset+i+1]=0x0f;
}
}

}
set_offset(current_offset);

}



int get_offset(){
int offset;
port_byte_out(0x3d4,14);
offset=port_byte_in(0x3d5);
offset<<=8;
port_byte_out(0x3d4,15);
offset+=port_byte_in(0x3d5);

return 2*offset;



}

void set_offset(int offset){

offset/=2;
port_byte_out(0x3d4,14);
port_byte_out(0x3d5,(unsigned char)( offset >> 8));
port_byte_out(0x3d4,15);
offset=offset&0xff;
port_byte_out(0x3d5,(unsigned char) offset);



}

void mem_cpy(char* source,char* destination,int size){

for(int i=0;i<size;i++){
*(destination+i)=*(source+i);	
}
}

void print_backspace(){
	char* video_memory=(char*)0xb8000;
	int current_offset=get_offset();
	
	video_memory[current_offset-2]=' ';
	video_memory[current_offset-1]=0x0f;
	current_offset-=2;
	set_offset(current_offset);
}

int str_cmp(char* first,char* second){
	int i;
	for(i=0;first[i]==second[i];i++){
		if (first[i]==0) break;
	}
return first[i]-second[i];
}
void mem_write(char* arr){
	static int i=0;
	unsigned char *addr=(unsigned char*)0x10000;
	
	*(addr+i)=arr[0];
	if (arr[0]=='?'){
		write_sector_lba(0,25,1,addr);
		i=0;
		return;
	}	

	i=i+1;
}
void cprint(){
	unsigned char* addr=(unsigned char*)0x10000;
	read_sector_lba(0,1,1,addr);
	print_at(addr,0x0f);
}