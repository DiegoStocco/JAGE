#pragma once

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
namespace JAGE {
  class VertexArray
  {
    public:
      VertexArray();
      ~VertexArray();

      void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

      void Bind() const;
      void UnBind() const;

    private:
      unsigned int m_ID;
  };
}
