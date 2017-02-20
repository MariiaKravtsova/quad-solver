make:	src/qsolver.c src/input.c
		gcc src/qsolver.c src/input.c -lm /usr/include/math.h
test:	tests/tests.c tests/cunit.c 
		gcc tests/tests.c tests/cunit.c -lm /usr/include/math.h
doc:	Doxyfile
		mkdir doc
		doxygen Doxyfile
run: 	src/qsolver.c src.input.c
		./a.out