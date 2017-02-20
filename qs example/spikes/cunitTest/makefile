make:		./src/adder.c ./src/lib.c 
			gcc ./src/adder.c ./src/lib.c -o ./builds/adder.out
run:		make ./builds/adder.out
			./builds/adder.out
makeTest:	./tests/t_lib.c ./src/lib.c
			gcc -lcunit ./tests/t_lib.c ./src/lib.c -o ./tests/t_lib.out
runTest:	makeTest ./tests/t_lib.out
			./tests/t_lib.out
docs:		Doxyfile
			doxygen Doxyfile
viewDocs:	docs ./docs/html/index.html
			firefox ./docs/html/index.html	
clean:  
			rm -rf ./docs ./builds/adder.out ./tests/t_lib.out	