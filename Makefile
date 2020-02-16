.PHONY: all install clean

all :
	- mkdir bin
	- g++ @projectfiles.args @conanbuildinfo.args -Iinclude -std=c++14 -o bin/main

install:
	- conan install . --build missing

clean :
	- rm -rf bin
