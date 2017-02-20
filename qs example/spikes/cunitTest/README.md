@mainpage CUnit Test Project

##CUnit Test Project README

@date 3/20/14
@author Owen Watson


##Introduction
This is a simple test example showing basic unit testing in C. 

This project also uses basic Doxygen formating to generate comments, man files, and etc.

##CUnit Compilation Notes

When builing the test unit, there was an issue linking the CUnit header files to t_lib.c file.
The switch \b -lcunit was used, however the location of the switch was wrong.
The \b -lcunit switch MUST preceed the src files in the compile command.

Example:

	gcc -lcunit t_lib.c lib.c -o test.out

##Makefile Notes

A make file is used to build, execute, run test, and generate Doxygen files.

Make commands:

	make:		Builds the executable adder.out
	run:		Runs adder.out
	makeTest:	Builds the executable t_lib.out
	runTest:	Runs t_lib.out
	docs:		Generates Doxygen documentation
	viewDocs:	View the generated documentation in Firefox
	clean:		Removes contents of builds and deletes the docs file


##Doxygen Notes

Doxyfile Settings Changed:

	PROJECT_NAME = "NameChangeHere"
	PROJECT_NUMBER = #.#
	OUTPUT_DIRECTORY  = ./docs
	PTIMIZE_OUTPUT_FOR_C = YES
	EXTRACT_ALL = YES
	EXTRACT_PRIVATE = YES
	EXTRACT_STATIC = YES
	INPUT = ./ ./src
	SOURCE_BROWSER = YES
	GENERATE_MAN = YES


##References

Most of the code samples and doxygen setup were shamelessly ripped from the following:

	[1]: http://nuno-sousa-corner.blogspot.com/2009/10/back-to-c-cmake-and-cunit.html 						"CUnit Basic Setup Example"
	[2]: http://www.openlogic.com/wazi/bid/188121/Doxygen-Magically-Turns-Source-Code-into-Documentation 	"Doxygen Basic Setup Info"
	[3]: https://www.rosettacommons.org/manuals/rosetta3.2_user_guide/doxygen_tips.html 					"Doxygen Basic Styling Info"
	[4]: https://www.cs.cmu.edu/~410/doc/doxygen.htmlDoxygen 												"Styling Example"
	[5]: http://nestacms.com/docs/creating-content/markdown-cheat-sheet 									"Markdown (Fake) Cheetsheet"
