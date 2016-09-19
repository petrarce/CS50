CC=gcc
SOUTCES+=main.c
OBJECTS+=main.o
TARGET=main

.PHONY: all

all: ${OBJECTS} ${TARGET}

${OBJECTS}:
	${CC} -c $(patsubst %.o, %.c, $@) -o $@

${TARGET}:
	${CC} ${OBJECTS} -o ${TARGET}
