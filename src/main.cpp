#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "init.hpp"
#include "shader.hpp"
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
  }

  const float vertices[] = {
      0.0f, 0.5f, 0.5f,
      0.5f, 0.0f, 0.5f,
      -0.5f, 0.0f, 0.5f};

  const unsigned int indices[] = {
      1, 2, 3};

  Engine::Shader shader;
  Engine::VertexArray vao;
  Engine::VertexBuffer vbo(sizeof(vertices), vertices, GL_STATIC_DRAW);
  Engine::IndexBuffer ibo(sizeof(indices), indices, GL_STATIC_DRAW);
  vao.addAttrib(vbo, 3, GL_FLOAT, 3, 0);

  while (!glfwWindowShouldClose(window))
  {
    Engine::Renderer::clear();

    Engine::Renderer::draw(shader, vao, ibo, 3);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}