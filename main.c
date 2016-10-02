#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "CLI_functions.h"
#include "cernel.h"

extern REQUEST_STORAGE_s request;

void main(int argc,char* argv)
{
	init_console_buffer();
	Read_image_from_file("/home/ivan/Yandex.Disk/CS50/week1/files/file");
	Add_image_to_console_buffer();
	Print_console_buffer();
	//menu_heandler(&mainmenu,parse_mainmenu);
}
