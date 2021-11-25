#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

void errorCallback(int errorCode, const char *description);
void keyCallback(GLFWwindow *window, int key, int _scancode, int action, int _mods);