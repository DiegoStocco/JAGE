#include "shader_storage_buffer.h"
#include <cstring>
#include <iostream>
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
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_ID);
  }

  void ShaderStorageBuffer::Bind(unsigned int index) const
  {
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, m_ID);
  }

  void ShaderStorageBuffer::UnBind() const
  {
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
  }

  unsigned int ShaderStorageBuffer::GetSize() const
  {
    return m_size;
  }

  void ShaderStorageBuffer::SetData(const void* data, unsigned int size, unsigned int offset /* = 0 */)
  {
    if(size + offset > m_size)
      std::cerr << "Tried to write too much data on SSBO\n";
    Bind();
    void* buffer = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_WRITE_ONLY);
    memcpy((char*)buffer + offset, data, size);
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
  }

  void* ShaderStorageBuffer::GetData()
  {
    void* res = malloc(m_size);
    Bind();
    void* buffer = glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_ONLY);
    memcpy(res, buffer, m_size);
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
    return res;
  }
}
