# OpenGL Starter Code

## Install Conan & add repositories

Using Conan because most approaches are too platform specific and a pain in the ass.

Install Conan:  
`pip install conan`  

Add bincrafters repository:  
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`  

Add repository for Assimp:  
`conan remote add jacmoe https://api.bintray.com/conan/jacmoe/Conan`  

## Install dependencies

`conan install .`

This will generate the following files along with installing dependencies:  

- `conanbuildinfo.args` - compiler arguments for use with gcc, clang, and cl
- `conanbuildinfo.mak` - makefile variables for use with a makefile
- `conanbuildinfo.props` - property sheet for visual studio

## Building Project

### make installed & using clang or gcc  

`make setup`  
`make`
`./bin/main`

### make not installed & using clang or gcc

If clang is your default compiler then you can compile the source code with:  
`clang++ main.cpp @conanbuildinfo.args -o bin/main`  

If g++ is your default compiler then you can compile the source code with:  
`g++ main.cpp @conanbuildinfo.args -o bin/main`

### cli visual studio compilation

If visual studio is your default compiler then you can compile the source code with (note you can only run cl from visual studio console):  
`cl main.cpp @conanbuildinfo.args -o bin/main`
