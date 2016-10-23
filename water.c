#include <stdio.h>

char buffer_str[1000];

void clean_n(char* str){
    int i=0;
    
    while(str[i]){
        if(str[i] == '\n')
            str[i] = 0;
        i++;
    }
}

int parse_arg(char* str){
    int i = 0;
    clean_n(str);
    if(!str[0])
        return 1;
    while(str[i]){
        if(str[i] < 48 || str[i] > 58)
            return 1;
        i++;
    }
    return 0;
}
int main(){
    int minutes = 0;
    do{
        printf("minutes: ");
        fgets(buffer_str, 1000, stdin);
    }while(parse_arg(buffer_str));
    sscanf(buffer_str,"%i",&minutes);
    printf("bottles: %i", minutes * 12);
    return 0;
}

