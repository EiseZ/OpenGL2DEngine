#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "init.hpp"

int main()
{
  auto [initSucces, window] = init(false);
  if (!initSucces)
  {
    std::cout << "Error: Failed to init program!" << std::endl;
    return -1;
  }

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}