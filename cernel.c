#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "cernel.h"
#include "CLI_functions.h"

static REQUEST_STORAGE_s request;

void init_matrix(struct Matrix* locMatrix, unsigned int size, unsigned int x, unsigned int y, char symb){
    int i = 0;
    locMatrix->string_size = size;
    locMatrix->matrix_size.x = x;
    locMatrix->matrix_size.y = y;
    if(locMatrix->matrix_buf)
        free(locMatrix->matrix_buf);
    locMatrix->matrix_buf = malloc(size);

    for(size_t i; i < locMatrix->string_size; i++)
        locMatrix->matrix_buf[i] = symb;
}

void init_console_buffer(){
    init_matrix(&console_buffer, 2602, 51, 51, ' ');
    for(size_t i = 0; i < console_buffer.matrix_size.y; i++) {
        console_buffer.matrix_buf[i*console_buffer.matrix_size.x + 50] = '\n';
    }
}

void Read_image_from_file(char* filename){
    FILE *file = fopen(filename, "r");
    unsigned int i=0;
    struct stat file_stat;
    if(!file){
        print_str("Warning: file doesnot exists");
        return;
    }

    stat(filename, &file_stat);
    if(matrix.matrix_buf)
        free(matrix.matrix_buf);
    matrix.matrix_buf = malloc(matrix.string_size = file_stat.st_size);

    while(matrix.string_size - i)
        matrix.matrix_buf[i++] = getc(file);

    fclose(file);

    matrix.matrix_size = Calculate_matrix_size((char *) matrix.matrix_buf);
    return;
}

//matrix size is equal to rows*maxcolumns value
MATRIX_SIZE_s Calculate_matrix_size(char* string){

    MATRIX_SIZE_s local_matr_size = {0,0};
    unsigned int i = 0;
    unsigned int max_width=0;
    unsigned int current_width=0;

    while(string[i]){
        current_width++;
        if(string[i++] == '\n'){
            local_matr_size.y++;
            max_width = (max_width>=current_width)? max_width: current_width;
            current_width = 0;
            continue;
        }
    }
    //if last character wasnt EOL increase amount of rows
    if(string[i-1] != '\n')
        local_matr_size.y++;
    local_matr_size.x = max_width;

    return local_matr_size;
}

void Add_image_to_console_buffer(){
    unsigned int matr_cont = 0, i = 0, j = 0; //counters
    while(matrix.matrix_buf[matr_cont]){
        if(matrix.matrix_buf[matr_cont] == '\n'){
            matr_cont++; i++; j = 0;
            continue;
        }
        console_buffer.matrix_buf[i*console_buffer.matrix_size.x+j++] =
            matrix.matrix_buf[matr_cont++];
    }
}

void Print_console_buffer(){
    int i = 0;
    while(console_buffer.matrix_buf[i]){
        fprintf(stderr, "%c", console_buffer.matrix_buf[i++]);
    }
}
