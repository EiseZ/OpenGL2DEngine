#include "quad.hpp"

namespace Engine
{
  Quad::Quad(float x, float y, float size, float r, float g, float b, float a)
  {
    Engine::Vertex v1;
    v1.pos = {x, y, 0.0f};
    v1.color = {r, g, b, a};
    Engine::Vertex v2;
    v2.pos = {x - size, y, 0.0f};
    v2.color = {r, g, b, a};
    Engine::Vertex v3;
    v3.pos = {x - size, y - size, 0.0f};
    v3.color = {r, g, b, a};
    Engine::Vertex v4;
    v4.pos = {x, y - size, 0.0f};
    v4.color = {r, g, b, a};
    Engine::Vertex vertices[] = {v1, v2, v3, v4};
    for (int i = 0; i < 4; i++)
    {
      m_Vertices[i] = vertices[i];
    }
  }
}