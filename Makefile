.PHONY: all install clean

all :
	- g++ src/main.cpp src/utils.cpp @conanbuildinfo.args -std=c++14 -o bin/main

install:
	- mkdir bin
	- conan install . --build missing

clean :
	- rm -rf bin
