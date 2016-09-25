#include <stdio.h>
//#include <curses.h>
#include "CLI_submenues.h"

void print_menu(CLI_submenu_s* const menu_itemn)
{
    int i=0;
    print_tiltle(menu_itemn->title);
    if(menu_itemn->subMenues){
        while(menu_itemn->subMenues[i] != NULL)
            print_submenu( menu_itemn->subMenues[i++]->listTitle, i);
    }
    i=0;
    if(menu_itemn->option)
    {
        while(menu_itemn->option[i] != NULL)
            print_option( menu_itemn->option[i++], i);
    }
    print_str("press \"q\" to escape the menu");
}

void menu_heandler(CLI_submenu_s* const menu_itemn, short* parse(char*))
{
    char* choise = malloc(5 * sizeof(char));
    short quit = 0;
    short scanf_result = 0;

    while(*choise != 'q'){
        system("clear");
        print_menu(menu_itemn);
        scanf_result = scanf("%s", choise);
        *parse(choise);
    }
    
    free(choise);
    return;
}
