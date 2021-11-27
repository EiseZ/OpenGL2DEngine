#pragma once

#include <array>

namespace Engine
{
  struct Vertex
  {
    std::array<float, 3> pos;
    std::array<float, 4> color;
    // std::array<float, 2> texCoords;
    // float texID;
  };

  class Quad
  {
  public:
    Quad(Vertex vertices[4]);

    Vertex getVertex(int i) { return m_Vertices[i]; };

  private:
    Vertex m_Vertices[4];
  };
}