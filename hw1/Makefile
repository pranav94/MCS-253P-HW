CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant -Weffc++
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings -Weffc++

main: MusicLibrary.cpp
	echo -------Compiling MusicLibrary.cpp to create executable MusicLibrary---------
	g++ -ggdb $(CXXFLAGS) MusicLibrary.cpp -o MusicLibrary

clean:
	echo -------Removing executable program MusicLibrary----------
	/bin/rm MusicLibrary
