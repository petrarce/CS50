CC=gcc
SOURCES+=$(wildcard *.c)
OBJECTS+=$(patsubst %.c, %.o, $(SOURCES))
TARGET=water
CFLAGS=-Iinclude -Isource -O0 -ggdb -std=c99
.PHONY: all clean cleanall setup

all: setup ${OBJECTS} ${TARGET}

setup:
	mkdir bin
${OBJECTS}:
	${CC} ${CFLAGS} -c $(patsubst %.o, %.c, $@) -o $@

${TARGET}:
	${CC} ${CFLAGS} ${OBJECTS} -o ${TARGET}
	mv ${TARGET} ./bin

clean:
	find -name "*.o" | xargs -i rm -rf {}
	find -name "*.a" | xargs -i rm -rf {}
	find -name "*.so" | xargs -i rm -rf {}
cleanall: clean
	rm -rf ./bin/${TARGET}
