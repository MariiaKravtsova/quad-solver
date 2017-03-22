CC = gcc
Flags = -o


comp:
	gcc -o runthis main/main.c io/io.c parse/parse.c qsolve/qsolve.c mysqrt/mysqrt.c

log:
	gcc -o runthis main/main.c io/io.c parse/parse.c qsolve/qsolve.c mysqrt/mysqrt.c -DLOG

debug:
	gcc -o runthis main/main.c io/io.c parse/parse.c qsolve/qsolve.c mysqrt/mysqrt.c -DDEBUG

mach:
	gcc -o runthis main/main.c io/io.c parse/parse.c qsolve/qsolve.c mysqrt/mach_mysqrt.c

run:
	./runthis

utest:
	gcc -o unit_tests/utest_parse unit_tests/utest_parse.c parse/parse.c
	./unit_tests/utest_parse
	gcc -o unit_tests/utest_mysqrt unit_tests/utest_mysqrt.c mysqrt/mysqrt.c
	./unit_tests/utest_mysqrt
	gcc -o unit_tests/utest_qsolve unit_tests/utest_qsolve.c qsolve/qsolve.c mysqrt/mach_mysqrt.c
	./unit_tests/utest_qsolve

clean:
	rm -f *.o *.out