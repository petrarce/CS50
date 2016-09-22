#include <stdio.h>
#include "CLI_submenues.h"

typedef unsigned short CHOISE_t;

static int END=0;
short success=0;

short* parse_mainmenu(char choise)
{
	switch(choise)
	{
		case '1':
			printf("option1 was chosen");
			success = 1;
			break;
		case '2':
			printf("option2 was chosen");
			success = 1;
			break;
		case '3':
			printf("option3 was chosen");
			success = 1;
			break;
		default:
			printf("incorrect option was chosen");
			success = 0;
			break;
	}
	return (short *)&success;
}

CLI_submenu_s mainmenu = {"MainMenu",
	"mainmenu",
	(char *[]){"1.option1",
		 	 "2.option2",
		 	 "3.option3"},
	NULL};


void main(int argc,char* argv)
{

	while(!END)
	{
			menu_heandler(&mainmenu,parse_mainmenu);
	}
}
