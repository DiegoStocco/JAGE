#pragma once
#include <GL/glew.h>

namespace JAGE {
  class VertexBuffer
  {
    public:
      VertexBuffer(const void* data, unsigned int size, GLenum usage = GL_STATIC_DRAW);
      ~VertexBuffer();

      void Bind() const;
      void UnBind() const;

      unsigned int GetSize() const;

      void SetData(const void* data, unsigned int size, GLenum usage = GL_STATIC_DRAW);

    private:
      unsigned int m_ID;
      unsigned int m_size;
  };
}
