#include "vertexArray.hpp"

namespace Engine
{
  VertexArray::VertexArray()
  {
    glGenVertexArrays(1, &m_RendererID);
    bind();
  }

  void VertexArray::addAttrib(VertexBuffer vbo, int size, unsigned int type, int stride, const void *offset)
  {
    bind();
    vbo.bind();
    glVertexAttribPointer(m_AttribAmount, size, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(m_AttribAmount);
    m_AttribAmount++;
  }

  void VertexArray::bind() const
  {
    glBindVertexArray(m_RendererID);
  }
}