#include "window.h"

#include <iostream>
#include <GLFW/glfw3.h>

namespace JAGE {
  Window::Window(std::string name, int width, int height)
  {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a windowed mode window and its OpenGL context
    m_window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (!m_window)
    {
      glfwTerminate();
      std::cerr << "Error in creating window " << name << std::endl;
    }

    // Make the window's context current
    glfwMakeContextCurrent(m_window);

    // Enable vSync
    glfwSwapInterval(1);
  }

  Window::~Window()
  {
    glfwDestroyWindow(m_window);
  }

  void Window::Bind() const
  {
    // Make the window's context current
    glfwMakeContextCurrent(m_window);
  }

  int Window::getWidth() const
  {
    int width;
    glfwGetWindowSize(m_window, &width, NULL);
    return width;
  }

  int Window::getHeight() const
  {
    int height;
    glfwGetWindowSize(m_window, NULL, &height);
    return height;
  }

  GLFWwindow* Window::getWindow()
  {
    return m_window;
  }

  glm::vec2 Window::getMousePos() const
  {
    double x, y;
    glfwGetCursorPos(m_window, &x, &y);
    return glm::vec2(x, y);
  }

  void Window::setMousePos(glm::vec2 pos)
  {
    glfwSetCursorPos(m_window, pos.x, pos.y);
  }


  void Window::disableCursor()
  {
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }

  void Window::enableCursor()
  {
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
  }

  bool Window::shouldClose() const
  {
    return glfwWindowShouldClose(m_window);
  }
}
