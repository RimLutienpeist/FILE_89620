***************************
The project consists of 6 source code files and 1 makefile
to construct the executable.

-main.cpp
	main
	Tokenize
	parseExpression
	getVariable
	printTree

-tree.hpp
	declaration of Tree class

-check.cpp
	All wheel functions to support detailed inspections in other 
	key functions

-autograd.cpp
	autoGrad
	simplifyTree

-autograd.hpp
-check.hpp
	head files of autograd.cpp and check.cpp

-Makefile
	Here are some notes if you have trouble using Makefile

	1. Warnings may generate when compiling because I 
	   turn on some compilation flags for more information from
	   the compiler. This is not a big deal since the platform and 
	   the compilers we choose may be different.
	2. We are using the `g++` compiler.
	3. We have to turn on the flag `-std=c++11` since some features
	   are supported only in c++11 standard or higher.
	4. If using MACOSX or Linux platform, we will generate an executable
	   with the name `autograd` and you can run it in the terminal.
	   If using Windows platform, we will generate an executable with
	   the name `autograd.exe`.
	5. `make clean` may encounter an error under Windows platform.
	6. If you don't have make in your environment, you may use Dev C++ or
	   other IDEs, and it may bother you to construct a project for me, 
	   sorry for wasting you some time for that.
