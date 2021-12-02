#pragma once

#include <glad/glad.h>

#include "shader.hpp"
#include "quad.hpp"
#include "vertexArray.hpp"
#include "indexBuffer.hpp"

#define MAX_VERTICES_PER_CALL 1000

namespace Engine
{
  class Renderer
  {
  public:
    Renderer();

    void drawQuadArray(Shader shader, Quad quads[], int size);
    void drawQuad(Shader shader, Quad quad);
    void clear(float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 1.0f);
    void draw(Shader shader, int count, const void *offset = 0);

  private:
    Engine::VertexArray m_VAO;
    Engine::VertexBuffer m_VBO;
    Engine::IndexBuffer m_IBO;
  };
}