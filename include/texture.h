#pragma once

#include <string>
namespace JAGE {
  class Texture
  {
    public:
      Texture(std::string fileName);
      ~Texture();

      void Bind(unsigned int slot = 0) const;
      void UnBind() const;

      inline unsigned int GetWidth() const { return m_Width; }
      inline unsigned int GetHeight() const { return m_Height; }
    private:
      unsigned int m_ID;
      std::string m_fileName;
      unsigned char* m_LocalBuffer;
      int m_Width, m_Height, m_BPP;
  };
}
