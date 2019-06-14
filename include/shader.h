#include <GL/glew.h>

class Shader
{
public:
    Shader(const char *filePath);
    const char *loadShader();
private:
    const char *filePath;
};

GLuint createShaderProgram();