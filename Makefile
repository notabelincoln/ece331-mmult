TARGET=mmult
OBJS=main.o mmult.o
CFLAGS=-g -Wall -O2

.PHONY: clean

all: ${TARGET}

${TARGET}: ${OBJS}

clean:
	rm -f ${TARGET} ${OBJS} core*

mmult.o: mmult.h
