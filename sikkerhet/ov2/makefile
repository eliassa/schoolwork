CC=gcc
CFLAGS=-O3
DEPS=fargeskrift.h

.PHONY: all clean install

.SUFFIXES:


all: fargedemo fargetest minefarger


%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

%: %.o fargeskrift.o
	$(CC) -o $@ $< fargeskrift.o  

#	fargedemo: fargedemo.o fargeskrift.o
#		$(CC) -o fargedemo fargedemo.o fargeskrift.o
#
#	fargetest: fargetest.o fargeskrift.o
#		$(CC) -o fargetest fargetest.o fargeskrift.o
#
#	minefarger: minefarger.o fargeskrift.o
#		$(CC) -o minefarger minefarger.o fargeskrift.o
#
clean:
	rm -f *.o fargedemo fargetest minefarger

install: fargedemo fargetest minefarger
	cp fargedemo fargetest minefarger  /usr/local/bin/
