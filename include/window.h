#pragma once

#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <string>

namespace JAGE {
  class Window
  {
    public:
      Window(std::string name, int width, int height);
      ~Window();

      void Bind() const;

      int getWidth() const;
      int getHeight() const;

      GLFWwindow* getWindow();

      glm::vec2 getMousePos() const;
      void setMousePos(glm::vec2 pos);
      
      void disableCursor();
      void enableCursor();

      bool shouldClose() const;

    private:
      GLFWwindow* m_window;
  };
}
