#include <vertex_buffer_layout.h>

namespace JAGE {
  template<typename T>
  void VertexBufferLayout::Push(unsigned int count)
  {
    std::runtime_error("Not Managed type for VertexBufferLayout");
  }

  template<>
  void VertexBufferLayout::Push<float>(unsigned int count)
  {
    m_elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
  }

  template<>
  void VertexBufferLayout::Push<unsigned int>(unsigned int count)
  {
    m_elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
  }

  template<>
  void VertexBufferLayout::Push<unsigned char>(unsigned int count)
  {
    m_elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
  }

  const std::vector<VertexBufferElement>& VertexBufferLayout::GetElements() const {
    return m_elements;
  }

  unsigned int VertexBufferLayout::GetStride() const {
      return m_stride;
  }
}
