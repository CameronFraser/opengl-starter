# OpenGL Starter Code

## Dependencies

* glfw - opengl library for creating windows and receiving inputs and events
* glew - opengl extensions
* glm - opengl math library
* stb - image library
* Assimp - model library

## Install Conan & add repositories

Using Conan because most approaches are too platform specific.

Install Conan:  
`pip install conan`  

Add bincrafters repository:  
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`  

Add repository for Assimp:  
`conan remote add jacmoe https://api.bintray.com/conan/jacmoe/Conan`  

## Install dependencies

`make install`

This will generate the following files along with installing dependencies:  

- `conanbuildinfo.args` - compiler arguments for use with gcc, clang, and cl
- `conanbuildinfo.mak` - makefile variables for use with a makefile
- `conanbuildinfo.props` - property sheet for visual studio

## Building Project

### Linux & Mac 

To build the project run `make`  
To run the built project run `./bin/main`
