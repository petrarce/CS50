#ifndef CLI_SUBMENUES_H
#define CLI_SUBMENUES_H

#define print_tiltle(msg) fprintf(stdout,"          =====%s=====\n", msg)
#define print_submenu(msg)  fprintf(stdout, "%s\n", msg)
#define print_option(msg) fprintf(stdout, "%s\n", msg)

typedef struct CLI_submenu {
    char* title;
    char* listTitle;
    char** option;
    struct CLI_submenu* subMenues;
    short* parce_function;
} CLI_submenu_s;

void print_menu(CLI_submenu_s* menu_itemn);
void menu_heandler(CLI_submenu_s* const , short* parse(char));



#endif //CLI_SUBMENUES_H
