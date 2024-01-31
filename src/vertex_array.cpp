#include "vertex_array.h"
#include "vertex_buffer_layout.h"
#include <vector>

VertexArray::VertexArray()
{
  glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
  glDeleteVertexArrays(1, &m_ID);
}


void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
  Bind();
  vb.Bind();
  const std::vector<VertexBufferElement>& elements = layout.GetElements();

  unsigned int offset = 0;
  for(unsigned int i = 0; i < elements.size(); i++)
  {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, elements[i].count, elements[i].type,
        elements[i].normalized, layout.GetStride(), reinterpret_cast<const void*>(offset));

    offset += elements[i].count * VertexBufferElement::GetSizeOfType(elements[i].type);
  }
}

void VertexArray::Bind() const
{
  glBindVertexArray(m_ID);
}

void VertexArray::UnBind() const
{
  glBindVertexArray(0);
}
