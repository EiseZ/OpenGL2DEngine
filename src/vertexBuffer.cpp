#include "vertexBuffer.hpp"

namespace Engine
{
  VertexBuffer::VertexBuffer(long long int size, const void *data, unsigned int usage)
  {
    glGenBuffers(1, &m_RendererID);
    bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
  }

  void VertexBuffer::bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
  }
}