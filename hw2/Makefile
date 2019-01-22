CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: test_string.cpp parseC.cpp
	echo -------Compiling test_string.cpp to create executable test_string---------
	g++ -ggdb $(CXXFLAGS) test_string.cpp -o test_string
	echo -------Compiling parseC.cpp to create executable parseC---------
	g++ -ggdb $(CXXFLAGS) parseC.cpp -o parseC

clean:
	echo -------Removing executable program test_string----------
	/bin/rm test_string
	/bin/rm parseC
