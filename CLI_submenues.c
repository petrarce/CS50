#include <stdio.h>
//#include <curses.h>
#include "CLI_submenues.h"

void print_menu(CLI_submenu_s* const menu_itemn)
{
    int i=0;
    print_tiltle(menu_itemn->title);
    while(menu_itemn->subMenues+i != NULL)
        print_submenu(menu_itemn->subMenues[i++].listTitle);
    i=0;
    if(!menu_itemn->option)
        return;
    while(menu_itemn->option[i] != NULL)
        print_option(menu_itemn->option[i++]);

}

void menu_heandler(CLI_submenu_s* const menu_itemn, short* parse(char))
{
    int choise = 0;
    short success = 0;
    while(!success){
        print_menu(menu_itemn);
        choise = getchar();
        success = *parse(choise);
    }
    return;
}
