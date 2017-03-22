CC = gcc
Flags = -o

qsolve: main/qsolve.c io/io.c parse/parse.c

comp:
	gcc -o qsolve main/qsolve.c io/io.c parse/parse.c mysqrt/mysqrt.c

mach:
	gcc -o qsolve main/qsolve.c io/io.c parse/parse.c mysqrt/mach_mysqrt.c

run:
	./qsolve

clean:
	rm -f *.o *.out