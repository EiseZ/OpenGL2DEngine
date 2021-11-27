#include "quad.hpp"

namespace Engine
{
  Quad::Quad(Vertex vertices[4])
  {
    for (int i = 0; i < 4; i++)
    {
      m_Vertices[i] = vertices[i];
    }
  }
}