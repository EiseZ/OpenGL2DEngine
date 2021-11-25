#include <callback.hpp>

void errorCallback(int errorCode, const char *description)
{
  std::cout << "Error: " << description << ", code: " << errorCode << "." << std::endl;
}

void keyCallback(GLFWwindow *window, int key, int _scancode, int action, int _mods)
{
  if (action == GLFW_PRESS)
  {
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
      glfwSetWindowShouldClose(window, true);
      break;
    }
  }
}