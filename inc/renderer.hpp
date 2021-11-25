#pragma once

#include <glad/glad.h>

#include "shader.hpp"
#include "vertexArray.hpp"
#include "indexBuffer.hpp"

namespace Engine
{
  class Renderer
  {
  public:
    static void clear(float r = 0.5f, float g = 0.5f, float b = 0.5f, float a = 1.0f);
    static void Renderer::draw(Shader shader, VertexArray vao, IndexBuffer ibo, int count, const void *offset = 0);
  };
}