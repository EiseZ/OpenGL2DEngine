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

  Engine::Quad quad(0.5f, 0.5f);

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