#include <stdio.h>
#include <string.h>

size_t imageSize = 0;
char image[1000];

char bufferStr[1000];

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

void format_local_str(char* str, size_t size, int spaces, int sharps){
    char space = ' ';
    char sharp = '#';
    char newLine = '\n';
    for(int i = 0; i < size; i++){
        if(spaces){
            strcat(str, &space); spaces--;
        }
        else if(sharps){
           strcat(str, &sharp); sharps--;
        }
        else
            strcat(str, &newLine);
    }
}

void prepare_buffer(char* str, size_t height){
    int sharps = 2;
    int spaces = height + 1 - sharps;
    char local_str[height+2];
    for(int i = 0; i < height; i++){
        format_local_str(local_str, height+2, spaces, sharps);
        strcat(image, local_str);
        spaces--; sharps++;
    }
}

int main(){
    int height = 0;
    do{
        printf("height: ");
        fgets(bufferStr, 1000, stdin);
    }while(parse_arg(bufferStr));
    sscanf(bufferStr,"%i",&height);
    prepare_buffer(image, height);
    return 0;
}
