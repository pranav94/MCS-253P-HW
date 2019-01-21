CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: test_string.cpp
	echo -------Compiling test_string.cpp to create executable test_string---------
	g++ -ggdb $(CXXFLAGS) test_string.cpp -o test_string

clean:
	echo -------Removing executable program test_string----------
	/bin/rm test_string
