#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "init.hpp"
#include "shader.hpp"
#include "quad.hpp"
#include "vertexArray.hpp"
#include "vertexBuffer.hpp"
#include "indexBuffer.hpp"
#include "renderer.hpp"

int main()
{
  auto [initSucces, window] = init(false);
  if (!initSucces)
  {
    std::cout << "Error: Failed to init program!" << std::endl;
    return -1;
  };

  Engine::Vertex v1;
  v1.pos = {0.5f, 0.5f, 0.0f};
  v1.color = {0.5f, 0.0f, 0.8f, 0.0f};
  Engine::Vertex v2;
  v2.pos = {0.5f, -0.5f, 0.0f};
  v2.color = {0.5f, 0.0f, 0.8f, 0.0f};
  Engine::Vertex v3;
  v3.pos = {-0.5f, -0.5f, 0.0f};
  v3.color = {0.5f, 0.0f, 0.8f, 0.0f};
  Engine::Vertex v4;
  v4.pos = {-0.5f, 0.5f, 0.0f};
  v4.color = {0.5f, 0.0f, 0.8f, 0.0f};
  Engine::Vertex vertices[] = {v1, v2, v3, v4};
  Engine::Quad quad(vertices);

  Engine::Shader shader;
  Engine::Renderer renderer;

  while (!glfwWindowShouldClose(window))
  {
    renderer.clear();

    renderer.drawQuad(shader, quad);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  std::cout << glGetError() << std::endl;

  glfwTerminate();
  return 0;
}