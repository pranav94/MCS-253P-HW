CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: main.cpp
	echo -------Compiling main.cpp to create executable main---------
	g++ -ggdb $(CXXFLAGS) main.cpp -o main

clean:
	echo -------Removing executable program main----------
	/bin/rm main
