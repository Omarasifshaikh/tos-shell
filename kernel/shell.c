#include <kernel.h>


void omarShellProcess(PROCESS self, PARAM param){
	char ch;
	int shell_window_height=0;
	
	Keyb_Message msg;
	//kprintf("Inside Shell process...");
	WINDOW shell_window = {0, 20,  80, 25, 0, 0, ' '};
	clear_window(kernel_window);
	while(1){
		kprintf("Inside while inside shell process");
		output_string(&shell_window,"#~ROOT");
		shell_window_height++;
		//msg.key_buffer = &ch;
		//send(keyb_port, &msg);
		//output_char(kernel_window, ch);
		
		//kprintf("%c",ch);
		//poke_w(0xb8000, ch);
		while(1){
		msg.key_buffer = &ch;
		send(keyb_port, &msg);
		//kprintf("%c",ch);
		if(ch == '\r'){
				kprintf("return");
				shell_window.cursor_x = 0;
				shell_window.cursor_y++;
				if(shell_window_height==4){
				scroll_window(&shell_window);
				shell_window_height--;
				}
				break;
				
		}else {
			 	kprintf("else");
				output_char(&shell_window,ch);
			}
		}
		}
	}

void init_shell()
{
  //kprintf("Creating process...");
	create_process(omarShellProcess,5,0,"Shell");
	//kprintf("Resigning");
	resign();
}
