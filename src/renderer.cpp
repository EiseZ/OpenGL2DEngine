#include "renderer.hpp"

namespace Engine
{
  void Renderer::clear(float r, float g, float b, float a)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r, g, b, a);
  }
  void Renderer::draw(Shader shader, VertexArray vao, IndexBuffer ibo, int count, const void *offset)
  {
    shader.bind();
    vao.bind();
    ibo.bind();
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, offset);
  }
}