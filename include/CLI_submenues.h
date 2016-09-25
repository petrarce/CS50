#ifndef CLI_SUBMENUES_H
#define CLI_SUBMENUES_H

#define print_tiltle(msg) fprintf(stdout,"          =====%s=====\n", msg)
#define print_submenu(subm_numb, msg)  fprintf(stdout, "%i:%s\n", msg, subm_numb)
#define print_option(opt_numb, msg) fprintf(stdout, "%i:%s\n", msg, opt_numb)
#define print_str(msg) fprintf(stdout,"%s\n", msg)

typedef struct CLI_submenu {
    char* title;
    char* listTitle;
    char** option;
    struct CLI_submenu** subMenues;
} CLI_submenu_s;

void print_menu(CLI_submenu_s* menu_itemn);
void menu_heandler(CLI_submenu_s* const , short* parse(char*));



#endif //CLI_SUBMENUES_H
