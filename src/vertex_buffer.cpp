#include "vertex_buffer.h"

namespace JAGE {
  VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum usage /* = GL_STATIC_DRAW*/ )
  {
    m_size = size;
    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    UnBind();
  }

  VertexBuffer::~VertexBuffer()
  {
    glDeleteBuffers(1, &m_ID);
  }


  void VertexBuffer::Bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
  }

  void VertexBuffer::UnBind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  unsigned int VertexBuffer::GetSize() const
  {
    return m_size;
  }

  void VertexBuffer::SetData(const void* data, unsigned int size, GLenum usage /* = GL_STATIC_DRAW*/ )
  {
    m_size = size;
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    UnBind();
  }
}
