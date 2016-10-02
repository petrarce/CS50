//this file contains declaration of handlers for every cli menu
#ifndef CLI_functions_h
#define CLI_functions_h

#include <stdio.h>
#include "CLI_submenues.h"

static CLI_submenu_s clean_db_menu = {
    "REMOVE FIELD FROM DB",
    "remove image",
    (char *[]){
        "clean all images",
        NULL
    },
    NULL
};
static CLI_submenu_s add_db_fileld_menu = {
    "ADD NEW IMAGE RO DB",
    "append db",
    (char *[]){
        "from file",
        "from console",
        NULL
    },
    NULL
};
static CLI_submenu_s db_menu = {
    "Database menu",
    "database menu",
    NULL,
    (CLI_submenu_s *[]){
        &clean_db_menu,
        &add_db_fileld_menu,
        NULL
    }
};
static CLI_submenu_s show_menu = {
    "Show image menu",
    "show image menu",
    NULL,
    NULL
};
static CLI_submenu_s mainmenu = {
    "Main menu",
    "main menu",
    NULL,
	(CLI_submenu_s *[]){
        &db_menu,
        &show_menu,
        NULL
    }
};


short* parse_mainmenu(char* choise);
short* parce_db_menu(char* choise);
short* parce_show_menu(char* choise);
short* parce_add_db_fileld_menu(char* choise);
short* parce_clean_db_menu(char* choise);

#endif // CLI_functions_h
