#include <stdio.h>

#define print_menu_header(msg) printf("=======" msg "======\n")
#define print_menu_itemn(msg, option) printf(msg  "%s\n",option)

typedef unsigned short CHOISE_t;

static int END=0;

void print_main_menu();
void print_db_manipulate_submenu();
void print_push_db_submenu();
void print_clear_db_submenu();
void print_output_operation_submenu();

void main(int argc,char* argv)
{
	while(!END)
	{
		print_main_menu();
		
	}
}

void print_main_menu(){	
	CHOISE_t choise=NULL;

	system("clear");	
	print_menu_header("WELCOME OT PIRAMIDE BUILDER");
	print_menu_itemn("1. Deploy database ", "1");
        print_menu_itemn("2. Print image ", "2");
	
	choise=getchar();
	
	switch(choise){
		case 1:
			print_db_manipulate_submenu();
			break;
		case 2:
			print_output_operation_submenu();
			break;
		default:
			fprintf(stderr,"Unavailable option were choosen");
			getchar();
			break;
	}

}
void print_db_manipulate_submenu(){}
void print_push_db_submenu(){}
void print_clear_db_submenu(){}
void print_output_operation_submenu(){}
