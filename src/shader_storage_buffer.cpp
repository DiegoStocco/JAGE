#include "shader_storage_buffer.h"
#include <GL/glew.h>

namespace JAGE {
  ShaderStorageBuffer::ShaderStorageBuffer(const void* data, unsigned int size, GLenum usage /* = GL_STATIC_DRAW*/ )
  {
    m_size = size;
    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, usage);
    UnBind();
  }

  ShaderStorageBuffer::~ShaderStorageBuffer()
  {
    glDeleteBuffers(1, &m_ID);
  }


  void ShaderStorageBuffer::Bind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
  }

  void ShaderStorageBuffer::UnBind() const
  {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  unsigned int ShaderStorageBuffer::GetSize() const
  {
    return m_size;
  }

  void ShaderStorageBuffer::SetData(const void* data, unsigned int size, GLenum usage /* = GL_STATIC_DRAW*/ )
  {
    m_size = size;
    Bind();
    glBufferData(GL_SHADER_STORAGE_BUFFER, size, data, usage);
    UnBind();
  }
}
