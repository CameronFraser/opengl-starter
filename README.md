# OpenGL Starter Code

Using Conan because most approaches are too platform specific and a pain in the ass.

Install Conan:  
`pip install conan`  

Add bincrafters repository:  
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan`  

Add repository for Assimp:  
`conan remote add jacmoe https://api.bintray.com/conan/jacmoe/Conan`  

Install dependencies:  
`conan install .`

This will generate the following files along with installing dependencies:  

- `conanbuildinfo.args` - compiler arguments for use with CLI compiler
- `conanbuildinfo.mak` - makefile variables for use with a makefile
- `conanbuildinfo.props` - property sheet for visual studio
