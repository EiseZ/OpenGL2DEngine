#include "indexBuffer.hpp"

namespace Engine
{
  IndexBuffer::IndexBuffer(long long int size, const void *data, unsigned int usage)
  {
    glGenBuffers(1, &m_RendererID);
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
  }

  void IndexBuffer::bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
  }
}