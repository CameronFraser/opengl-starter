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

const char *Shader::loadShader()
{
    std::cout << (std::string)this->filePath + " loading." << std::endl;
    std::string content;
    std::string line = "";
    std::ifstream fileStream(this->filePath, std::ios::in);

    if (fileStream)
    {
        while (std::getline(fileStream, line))
        {
            content.append(line + "\n");
        }
        fileStream.close();
        std::cout << (std::string)this->filePath + " loaded." << std::endl;
    }
    else
    {
        throw std::runtime_error((std::string)this->filePath + " failed to load.");
    }

    return content.c_str();
}

GLuint createShaderProgram()
{
    GLint vertCompiled;
    GLint fragCompiled;
    GLint linked;

    Shader VertexShader = Shader("src/shaders/vShader.glsl");
    Shader FragmentShader = Shader("src/shaders/fShader.glsl");

    const char *vshaderSource = VertexShader.loadShader();
    const char *fshaderSource = FragmentShader.loadShader();

    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glShaderSource(fShader, 1, &fshaderSource, NULL);

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