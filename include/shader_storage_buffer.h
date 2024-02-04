#pragma once
#include <GL/glew.h>

namespace JAGE
{
  class ShaderStorageBuffer {
    public:
      ShaderStorageBuffer(const void* data, unsigned int size, GLenum usage = GL_STATIC_DRAW);
      ~ShaderStorageBuffer();

      void Bind() const;
      void UnBind() const;

      unsigned int GetSize() const;

      void SetData(const void* data, unsigned int size, unsigned int offset = 0);
      void* GetData();

    private:
      unsigned int m_ID;
      unsigned int m_size;
  };
}
