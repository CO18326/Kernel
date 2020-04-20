
void interrupt();
void sep();
extern void print_at(char*,unsigned char);
extern void port_byte_out(unsigned short,unsigned char);
extern unsigned port_byte_in(unsigned short);
extern void print_backspace();
extern void mem_write(char*);
extern int command_mode;
int ayappa=0;

//char impo[]={'?','?','1','2','3','4','5','6','7','8','9','0','-','+','?','?','q','w','e','r','t','y','u','i','o','p','[',']','\n','?'};


void interrupt(unsigned int arg1,unsigned int arg2){

	if (arg2>=40){
		port_byte_out(0x00a0,0x20);
	}
port_byte_out(0x0020,0x20);
//print_at("2",0x1f);
if (arg2==33){
int result;
result=port_byte_in(0x60);

 switch (result) {
        case 0x0:
            if(command_mode){mem_write("ERROR");}
            print_at("ERROR",0x0f);
            break;
        case 0x1:
            if(command_mode){mem_write("?");command_mode=0;print_at("Bye Bye",0x0f);result=0x1c;}
            print_at("ESC",0x0f);
            break;
        case 0x2:
            if(command_mode){mem_write("1");}
            print_at("1",0x0f);
            break;
        case 0x3:
           if(command_mode){mem_write("2");}
           print_at("2",0x0f);
            break;
        case 0x4:
           print_at("3",0x0f);
            break;
        case 0x5:
           print_at("4",0x0f);
            break;
        case 0x6:
           print_at("5",0x0f);
            break;
        case 0x7:
           print_at("6",0x0f);
            break;
        case 0x8:
           print_at("7",0x0f);
            break;
        case 0x9:
           print_at("8",0x0f);
            break;
        case 0x0A:
           print_at("9",0x0f);
            break;
        case 0x0B:
           print_at("0",0x0f);
            break;
        case 0x0C:
           print_at("-",0x0f);
            break;
        case 0x0D:
           print_at("+",0x0f);
            break;
        case 0x0E:
           print_backspace();
            break;
        case 0x0F:
           print_at("Tab",0x0f);
            break;
        case 0x10:
           print_at("Q",0x0f);
            break;
        case 0x11:
           print_at("W",0x0f);
            break;
        case 0x12:
           print_at("E",0x0f);
            break;
        case 0x13:
           print_at("R",0x0f);
            break;
        case 0x14:
           print_at("T",0x0f);
            break;
        case 0x15:
           print_at("Y",0x0f);
            break;
        case 0x16:
           print_at("U",0x0f);
            break;
        case 0x17:
           print_at("I",0x0f);
            break;
        case 0x18:
           print_at("O",0x0f);
            break;
        case 0x19:
           print_at("P",0x0f);
            break;
		case 0x1A:
			print_at("[",0x0f);
			break;
		case 0x1B:
			print_at("]",0x0f);
			break;
		case 0x1C:
			print_at("\n",0x0f);
			break;
		case 0x1D:
			print_at("LCtrl",0x0f);
			break;
		case 0x1E:
			print_at("A",0x0f);
			break;
		case 0x1F:
			print_at("S",0x0f);
			break;
        case 0x20:
           print_at("D",0x0f);
            break;
        case 0x21:
           print_at("F",0x0f);
            break;
        case 0x22:
           print_at("G",0x0f);
            break;
        case 0x23:
           print_at("H",0x0f);
            break;
        case 0x24:
           print_at("J",0x0f);
            break;
        case 0x25:
           print_at("K",0x0f);
            break;
        case 0x26:
           print_at("L",0x0f);
            break;
        case 0x27:
           print_at(";",0x0f);
            break;
        case 0x28:
           print_at("'",0x0f);
            break;
        case 0x29:
           print_at("`",0x0f);
            break;
		case 0x2A:
			print_at("LShift",0x0f);
			break;
		case 0x2B:
			print_at("\\",0x0f);
			break;
		case 0x2C:
			print_at("Z",0x0f);
			break;
		case 0x2D:
			print_at("X",0x0f);
			break;
		case 0x2E:
			print_at("C",0x0f);
			break;
		case 0x2F:
			print_at("V",0x0f);
			break;
        case 0x30:
           print_at("B",0x0f);
            break;
        case 0x31:
           print_at("N",0x0f);
            break;
        case 0x32:
           print_at("M",0x0f);
            break;
        case 0x33:
           print_at(",",0x0f);
            break;
        case 0x34:
           print_at(".",0x0f);
            break;
        case 0x35:
           print_at("/",0x0f);
            break;
        case 0x36:
           print_at("Rshift",0x0f);
            break;
        case 0x37:
           print_at("Keypad *",0x0f);
            break;
        case 0x38:
           print_at("LAlt",0x0f);
            break;
        case 0x39:
           print_at(" ",0x0f);
            break;
        default:
            /* 'keuyp' event corresponds to the 'keydown' + 0x80 
             * it may still be a scancode we haven't implemented yet, or
             * maybe a control/escape sequence */
            /*if (result <= 0x7f) {
                print_at("Unknown key down",0x0f);
            } else if (result <= 0x39 + 0x80) {
                print_at("key up ",0x0f);
                //print_let(scancode - 0x80);
            } else print_at("Unknown key up",0x0f);*/
            break;
    }
//print_at(str,0x1f);
ayappa=result;
//asm volatile ("mov (%0),%%eax": :"r"(result));


}



}
void sep(unsigned int arg1,unsigned int arg2){

	
	
	
	print_at("sc",0x1f);
}

