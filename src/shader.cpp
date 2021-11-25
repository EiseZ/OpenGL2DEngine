#include "shader.hpp"

const char *vertexShaderSource =
#include "../src/shaders/vs.vert"
    ;
const char *fragmentShaderSource =
#include "../src/shaders/fs.frag"
    ;

namespace Engine
{

  Shader::Shader()
  {
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSource, 0);
    glCompileShader(vs);

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSource, 0);
    glCompileShader(fs);

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