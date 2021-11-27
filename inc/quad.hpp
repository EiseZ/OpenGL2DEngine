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
    Quad(float x, float y, float size = 1.0f, float r = 0.5f, float g = 0.0f, float b = 0.8f, float a = 1.0f);

    Vertex getVertex(int i) { return m_Vertices[i]; };

  private:
    Vertex m_Vertices[4];
  };
}