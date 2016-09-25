#include "CLI_functions.h"
#include "CLI_submenues.h"
//temporary variable to use its adress as return value in parse functions
//TODO: figure out other way of returning "success" value from parce functions
static short success=0;

//input prser for cli for mainmenu
short* parse_mainmenu(char* choise)
{
    if(*choise == '1'){
        success = 1;
        menu_heandler(&db_menu,parce_db_menu);
    }
    else if(*choise == '2'){
        menu_heandler(&show_menu, parce_show_menu);
        success = 1;
    }
    else{
        print_str("Note: incorrect option was chosen. Please try again");
        success = 0;
    }
	return (short *)&success;
}
short* parce_db_menu(char* choise)
{
    if(*choise == '1'){
        success = 1;
    }
    else if(*choise == '2'){
        success = 1;
    }
    else{
        print_str("Note: incorrect option was chosen. Please try again");
        success = 0;
    }
	return (short *)&success;
}

short* parce_show_menu(char* choise)
{
    if(*choise == '1'){
        success = 1;
    }
    else if(*choise == '2'){
        success = 1;
    }
    else{
        print_str("Note: incorrect option was chosen. Please try again");
        success = 0;
    }
	return (short *)&success;
}
