#pragma once

#include <glad/glad.h>

#include "vertexBuffer.hpp"

namespace Engine
{
  class VertexArray
  {
  public:
    VertexArray();

    void addAttrib(VertexBuffer vbo, int size, unsigned int type, int stride, const void *offset);

    void bind() const;

  private:
    unsigned int m_RendererID;
    unsigned int m_AttribAmount;
  };
}