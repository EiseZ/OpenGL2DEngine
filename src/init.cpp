#include "init.hpp"

std::tuple<bool, GLFWwindow *> init(bool enableWireframe)
{
  // Init GLFW
  if (!glfwInit())
  {
    std::cout << "Error: Failed to init GLFW!" << std::endl;
    return {false, 0};
  }
  glfwSetErrorCallback(errorCallback);

  // Set version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  // Create window
  GLFWwindow *window = glfwCreateWindow(800, 600, "Minecraft", 0, 0);
  if (!window)
  {
    std::cout << "Error: Failed to create window!" << std::endl;
    glfwTerminate();
    return {false, 0};
  }
  glfwMakeContextCurrent(window);

  // Callback on keypress
  glfwSetKeyCallback(window, keyCallback);

  // Init glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Error: Failed to init glad!" << std::endl;
    glfwTerminate();
    return {false, 0};
  }

  // Set viewport to window dimensions
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  // Enable vsync
  glfwSwapInterval(1);

  // Texture settings
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  if (enableWireframe)
  {
    // Set wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  return {true, window};
}