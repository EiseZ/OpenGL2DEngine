#include "shader.hpp"

const char *vertexShaderSource =
#include "../src/shaders/vs.vs"
    ;
const char *fragmentShaderSource =
#include "../src/shaders/fs.fs"
    ;

namespace Engine
{

  Shader::Shader()
  {
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSource, 0);
    glCompileShader(vs);

    int infoLength, res;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &res);
    glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &infoLength);
    if (infoLength > 0)
    {
      char error[1000];
      glGetShaderInfoLog(vs, infoLength, 0, &error[0]);
      std::cout << "Error: Vertex shader failed to compile, message: " << &error[0] << "!" << std::endl;
    }

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSource, 0);
    glCompileShader(fs);

    glGetShaderiv(fs, GL_COMPILE_STATUS, &res);
    glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &infoLength);
    if (infoLength > 0)
    {
      char error[1000];
      glGetShaderInfoLog(fs, infoLength, 0, &error[0]);
      std::cout << "Error: Fragment shader failed to compile, message: " << &error[0] << "!" << std::endl;
    }

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, fs);
    glAttachShader(m_RendererID, vs);

    glLinkProgram(m_RendererID);
    bind();
  }

  void Shader::bind() const
  {
    glUseProgram(m_RendererID);
  }
}