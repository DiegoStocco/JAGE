#pragma once

namespace JAGE {

  class IndexBuffer
  {
    public:
      IndexBuffer(const unsigned int* data, unsigned int count);
      ~IndexBuffer();

      void Bind() const;
      void UnBind() const;
      
      unsigned int GetCount() const;

    private:
      unsigned int m_ID;
      unsigned int m_count;
  };

}
