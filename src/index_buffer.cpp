#include "GL/glew.h"

#include "index_buffer.h"

namespace JAGE {

  IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
  {
    m_count = count;

    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    UnBind();
  }

  IndexBuffer::~IndexBuffer()
  {
    glDeleteBuffers(1, &m_ID);
  }


  void IndexBuffer::Bind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
  }

  void IndexBuffer::UnBind() const
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }

  unsigned int IndexBuffer::GetCount() const
  {
    return m_count;
  }
}
