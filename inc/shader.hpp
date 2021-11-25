#pragma once

#include <glad/glad.h>

class Shader
{
public:
  Shader();

  void bind() const;

private:
  unsigned int m_RendererID;
};