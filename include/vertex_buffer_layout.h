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
      void Push(unsigned int count)
      {
        std::runtime_error("Not Managed type for VertexBufferLayout");
      }

      template<>
      void Push<float>(unsigned int count)
      {
        m_elements.push_back({GL_FLOAT, count, GL_FALSE});
        m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
      }

      template<>
      void Push<unsigned int>(unsigned int count)
      {
        m_elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
        m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
      }

      template<>
      void Push<unsigned char>(unsigned int count)
      {
        m_elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
        m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
      }

      inline const std::vector<VertexBufferElement>& GetElements() const {return m_elements;}
      inline unsigned int GetStride() const {return m_stride;}

    private:
      std::vector<VertexBufferElement> m_elements;
      unsigned int m_stride;
  };
}
