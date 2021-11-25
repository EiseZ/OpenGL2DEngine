#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <tuple>
#include <iostream>

#include "callback.hpp"

std::tuple<bool, GLFWwindow *> init(bool enableWireframe);