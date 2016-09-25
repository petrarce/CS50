CC=gcc
SOURCES+=$(wildcard *.c)
OBJECTS+=$(patsubst %.c, %.o, $(SOURCES))
TARGET=main
CFLAGS=-Iinclude -Isource -O0 -ggdb
.PHONY: all clean

all: ${OBJECTS} ${TARGET}

${OBJECTS}:
	${CC} ${CFLAGS} -c $(patsubst %.o, %.c, $@) -o $@

${TARGET}:
	${CC} ${CFLAGS} ${OBJECTS} -o ${TARGET}
	mv ${TARGET} ./bin

clean:
	find -name "*.o" | xargs -i rm -rf {}
	find -name "*.a" | xargs -i rm -rf {}
	find -name "*.so" | xargs -i rm -rf {}
	rm -rf ./${TARGET}
