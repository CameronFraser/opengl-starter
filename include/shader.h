#include <string>
#include <GL/glew.h>

class Shader
{
public:
    Shader(const char *filePath);
    std::string loadShader();
private:
    const char *filePath;
};

GLuint createShaderProgram();