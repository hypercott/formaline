CC = gcc
SOURCES = source_file.c
FORMALINESOURCES = formaline_prepare.c
TARBALLFILES=Makefile $(SOURCES) $(FORMALINESOURCES) 

all: formaline_test

source_file.o: source_file.c
	$(CC) -c source_file.c


src.tar.gz: $(TARBALLFILES)
	tar -czvf src.tar.gz $^

formaline.c: src.tar.gz formaline
	./formaline < src.tar.gz

formaline: formaline_prepare.c
	$(CC) -o formaline formaline_prepare.c

formaline.o: formaline.c
	$(CC) -c formaline.c

formaline_test: source_file.o formaline.o
	$(CC) formaline.o source_file.o -o formaline_test
	rm -rf src.tar.gz

clean:
	rm -rf *.o formaline_test
	rm -rf formaline.c
	rm -rf src.tar.gz