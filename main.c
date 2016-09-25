#include <stdio.h>
#include "CLI_functions.h"

static int END=0;



void main(int argc,char* argv)
{
	menu_heandler(&mainmenu,parse_mainmenu);
}
