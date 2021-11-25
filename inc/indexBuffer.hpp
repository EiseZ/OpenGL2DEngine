#pragma once

#include <glad/glad.h>

namespace Engine
{
  class IndexBuffer
  {
  public:
    IndexBuffer(long long int size, const void *data, unsigned int usage);

    void bind() const;

  private:
    unsigned int m_RendererID;
  };
}