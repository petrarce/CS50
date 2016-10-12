#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1000
size_t imageSize = 0;
char* image;

char bufferStr[BUF_SIZE];

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

void format_local_str(char* str, size_t size, size_t offset, int spaces, int sharps){
    char space = ' ';
    char sharp = '#';
    char newLine = '\n';

    for(int i = 0; i < size; i++){
        if(spaces){
            str[i + offset] = space; spaces--;
        }
        else if(sharps){
           str[i + offset] = sharp; sharps--;
        }
        else
            str[i + offset] = newLine;
    }
}

void prepare_buffer(char* str, size_t height){
    int sharps = 2;
    int spaces = height + 2 - sharps;
    int size = height+3;
    int offset = 0;
    char* local_str;

    if(image)
        free(image);
    image = malloc(size * height);
    image[0] = '\n';

    for(int i = 0; i < height; i++){
        format_local_str(image, size, offset, spaces, sharps);
        spaces--; sharps++; offset += size;
    }
}

int main(){
    int height = 0;

    do{
        printf("height: ");
        fgets(bufferStr, BUF_SIZE, stdin);
    }while(parse_arg(bufferStr));
    sscanf(bufferStr,"%i",&height);
    prepare_buffer(image, height);
    fprintf(stdout, "%s", image);
    return 0;
}
