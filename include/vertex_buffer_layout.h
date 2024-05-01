#pragma once

#include <stdexcept>
#include <vector>
#define GLFW_INCLUDE_NONE
#include <GL/glew.h>

namespace JAGE {
  struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
      switch(type)
      {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
      }
      return 0;
    }
  };

  class VertexBufferLayout
  {
    public:
      VertexBufferLayout()
        : m_stride(0) {}

      template<typename T>
      void Push(unsigned int count);

      const std::vector<VertexBufferElement>& GetElements() const;
      unsigned int GetStride() const;

    private:
      std::vector<VertexBufferElement> m_elements;
      unsigned int m_stride;
  };
}
