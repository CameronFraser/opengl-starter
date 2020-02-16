#include "shader.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>

Shader::Shader(const char *filePath)
{
    this->filePath = filePath;
}

std::string Shader::loadShader()
{
    std::cout << (std::string)this->filePath + " loading." << std::endl;
    std::string content;
    std::ifstream fileStream(this->filePath, std::ios::in);
    std::string line = "";

    if (fileStream)
    {
        while (!fileStream.eof()) {
            getline(fileStream, line);
            content.append(line + "\n");
        }
        std::cout << (std::string)this->filePath + " loaded." << std::endl;
    }
    else
    {
        throw std::runtime_error((std::string)this->filePath + " failed to load.");
    }
    fileStream.close();
    return content;
}

GLuint createShaderProgram()
{
    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;

    Shader VertexShader = Shader("src/shaders/vShader.glsl");
    Shader FragmentShader = Shader("src/shaders/fShader.glsl");

    std::string vertShaderStr = VertexShader.loadShader();
    std::string fragShaderStr = FragmentShader.loadShader();

    const char *vertShaderSource = vertShaderStr.c_str();
    const char *fragShaderSource = fragShaderStr.c_str();

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vertShaderSource, NULL);
    glShaderSource(fShader, 1, &fragShaderSource, NULL);

    glCompileShader(vShader);
    checkOpenGLError();
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
    if (vertCompiled != 1) {
        std::cout << "Vertex compilation failed." << std::endl;
        printShaderLog(vShader);
    }

    glCompileShader(fShader);
    checkOpenGLError();
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
        if (fragCompiled != 1) {
        std::cout << "Fragment compilation failed." << std::endl;
        printShaderLog(fShader);
    }

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    checkOpenGLError();
    glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
        if (linked != 1) {
        std::cout << "Linking failed." << std::endl;
        printProgramLog(vfProgram);
    }

    return vfProgram;
}