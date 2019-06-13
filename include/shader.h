#include <string>
#include <GL/glew.h>

class Shader
{
public:
  Shader(std::string type);
  std::string loadShader(const char *filePath);
};

GLuint createShaderProgram();