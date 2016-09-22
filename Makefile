CC=gcc
SOURCES+=main.c CLI_submenues.c
OBJECTS+=main.o CLI_submenues.o
TARGET=main
CFLAGS=-Iinclude -Isource -O0 -ggdb
.PHONY: all clean

all: ${OBJECTS} ${TARGET}

${OBJECTS}:
	${CC} ${CFLAGS} -c $(patsubst %.o, %.c, $@) -o $@

${TARGET}:
	${CC} ${CFLAGS} ${OBJECTS} -o ${TARGET}

clean:
	find -name "*.o" | xargs -i rm -rf {}
	find -name "*.a" | xargs -i rm -rf {}
	find -name "*.so" | xargs -i rm -rf {}
	rm -rf ./${TARGET}
