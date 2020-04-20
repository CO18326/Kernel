
void port_byte_out(unsigned short port,unsigned char input){


asm volatile("out %%al, %%dx" :: "a"(input) , "d"(port));

}






unsigned char port_byte_in(unsigned short port){

unsigned char result;
asm volatile("in %%dx, %%al": "=a"(result) : "d"(port));

return result;
}


#define CMD_READ 0x20
#define BSY_FLAG 0x80
 

void write_sector_lba(unsigned char drive_num, unsigned int start_lba, unsigned char sector_count, unsigned char* dest)
{
    unsigned int index, max, base;
    unsigned char* buffer = (unsigned char*)dest;
    unsigned char  drive = 0x40;
 
    switch(drive_num){
        case 0: case 1: base = 0x1F0; break;
        case 2: case 3: base = 0x170; break;
        case 4: case 5: base = 0x1E8; break;
        case 6: case 7: base = 0x168; break;
        default:
            // error
            return;
    }
    if(drive_num % 2){
        drive |= 0x10;
    }
 
    port_byte_out(base + 2, sector_count);
    port_byte_out(base + 3, (unsigned char)((start_lba & 0x000000FF)      ));
    port_byte_out(base + 4, (unsigned char)((start_lba & 0x0000FF00) >>  8));
    port_byte_out(base + 5, (unsigned char)((start_lba & 0x00FF0000) >> 16));
    port_byte_out(base + 6, (unsigned char)((start_lba & 0x0F000000) >> 24) | drive);
    port_byte_out(base + 7, CMD_READ);
 
    while(port_byte_in(base + 7) & BSY_FLAG);
 
    max = (sector_count * (512));
    for(index = 0; index < max; index++){
        port_byte_out(base+0,*(buffer++));
    }
}
void read_sector_lba(unsigned char drive_num, unsigned int start_lba, unsigned char sector_count, unsigned char* dest)
{
    unsigned int index, max, base;
    unsigned char* buffer = (unsigned char*)dest;
    unsigned char  drive = 0x40;
 
    switch(drive_num){
        case 0: case 1: base = 0x1F0; break;
        case 2: case 3: base = 0x170; break;
        case 4: case 5: base = 0x1E8; break;
        case 6: case 7: base = 0x168; break;
        default:
            // error
            return;
    }
    if(drive_num % 2){
        drive |= 0x10;
    }
 
    port_byte_out(base + 2, sector_count);
    port_byte_out(base + 3, (unsigned char)((start_lba & 0x000000FF)      ));
    port_byte_out(base + 4, (unsigned char)((start_lba & 0x0000FF00) >>  8));
    port_byte_out(base + 5, (unsigned char)((start_lba & 0x00FF0000) >> 16));
    port_byte_out(base + 6, (unsigned char)((start_lba & 0x0F000000) >> 24) | drive);
    port_byte_out(base + 7, CMD_READ);
 
    while(port_byte_in(base + 7) & BSY_FLAG);
 
    max = (sector_count * (512));
    for(index = 0; index < max; index++){
        *(buffer++)=port_byte_in(base+0);
    }
*(buffer)=0;
}