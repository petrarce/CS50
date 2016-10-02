#ifndef CERNEL_H
#define CERNEL_H

//=================DEFINES=======================
#define CLEAN_BUFFER "                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n\
                                                  \n"

//=========================TYPES=================
typedef unsigned short COORDINATE_t;
typedef unsigned short MATRIX_t;

struct Coordinates{
    COORDINATE_t x;
    COORDINATE_t y;
};
typedef struct Coordinates COORDINATES_s;
typedef COORDINATES_s MATRIX_SIZE_s;

struct Request_storage{
    char* name;
    COORDINATES_s coord;
};
typedef struct Request_storage REQUEST_STORAGE_s;

//===================VARIABLES================
static struct Matrix{
    char* matrix_buf;
    MATRIX_SIZE_s matrix_size;
    unsigned int string_size;
}   matrix,
    console_buffer;

static char* string_buf;

//================FUNCTIONS================
void init_console_buffer();
void Read_image_from_file(char* filename);
void Str_to_matrix();
MATRIX_SIZE_s Calculate_matrix_size();
void Add_image_to_console_buffer();
void Print_console_buffer();

#endif //CERNEL_H
