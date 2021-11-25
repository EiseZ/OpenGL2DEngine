#pragma once

#include <glad/glad.h>
#include <iostream>

namespace Engine
{
  class Shader
  {
  public:
    Shader();

    void bind() const;

  private:
    unsigned int m_RendererID;
  };
}