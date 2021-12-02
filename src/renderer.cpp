#include "renderer.hpp"

namespace Engine
{
  Renderer::Renderer() : m_VBO(sizeof(Vertex) * MAX_VERTICES_PER_CALL, nullptr, GL_DYNAMIC_DRAW), m_IBO(sizeof(unsigned int) * 6, nullptr, GL_STATIC_DRAW)
  {
    m_VAO.addAttrib(m_VBO, 3, GL_FLOAT, sizeof(Engine::Vertex), (void *)offsetof(Engine::Vertex, pos));
    m_VAO.addAttrib(m_VBO, 4, GL_FLOAT, sizeof(Engine::Vertex), (void *)offsetof(Engine::Vertex, color));
  }

  const unsigned int indices[] = {
      0, 1, 3,
      1, 2, 3};
  void Renderer::drawQuadArray(Shader shader, Quad quads[], int size)
  {
    for (int i = 0; i < size; i++)
    {
      drawQuad(shader, quads[i]);
    }
  }

  void Renderer::drawQuad(Shader shader, Quad quad)
  {
    m_VBO.bind();
    Vertex vertices[4];
    for (int i = 0; i < 4; i++)
    {
      vertices[i] = quad.getVertex(i);
    }
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    m_IBO.bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(indices), indices);
    draw(shader, 6, 0);
  }

  void Renderer::clear(float r, float g, float b, float a)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r, g, b, a);
  }

  void Renderer::draw(Shader shader, int count, const void *offset)
  {
    shader.bind();
    m_VAO.bind();
    m_IBO.bind();
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, offset);
  }
}