#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <glm/mat4x4.hpp>

struct ShaderName
{
  const char* filename;
  unsigned int type;
};

class Shader
{
  public:
    Shader(const std::vector<ShaderName>& shadernames);
    ~Shader();

    void Bind() const;
    void UnBind() const;

    void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
    void SetUniform1i(const std::string& name, float i0);
    void SetUniformMatrix4(const std::string& name, const glm::mat4* matrices, int count = 1);

  private:
    int GetUniformLocation(std::string name);

  private:
    unsigned int m_ID;
    std::unordered_map<std::string, int> m_cached_uniforms;
};
