.PHONY: all install clean

all :
	- g++ @projectfiles.args @conanbuildinfo.args -Iinclude -std=c++14 -o bin/main

install:
	- mkdir bin
	- conan install . --build missing

clean :
	- rm -rf bin
