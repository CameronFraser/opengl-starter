.PHONY: all setup clean

all :
	- g++ main.cpp @conanbuildinfo.args -std=c++14 -o bin/main

setup:
	- mkdir bin

clean :
	- rm -rf bin
