#include "shader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "GL/glew.h"
namespace JAGE {
  static unsigned int LoadShader(ShaderName shadername);

  Shader::Shader(const std::vector<ShaderName>& shadernames)
  {
    m_ID = glCreateProgram();

    std::vector<unsigned int> shaders;

    // Build all the shaders
    for(ShaderName shadername : shadernames)
    {
      shaders.push_back(LoadShader(shadername));
      glAttachShader(m_ID, shaders.back());
    }

    // Link the program
    glLinkProgram(m_ID);

    // Check the program
    int Result, InfoLogLength;
    glGetProgramiv(m_ID, GL_LINK_STATUS, &Result);
    glGetProgramiv(m_ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
      std::vector<char> ProgramErrorMessage(InfoLogLength+1);
      glGetProgramInfoLog(m_ID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
      printf("%s\n", &ProgramErrorMessage[0]);
    }
    
    // Delete the shaders (Now they are in the program)
    for(unsigned int shader : shaders)
    {
      glDetachShader(m_ID, shader);
      glDeleteShader(shader);
    }
  }

  Shader::~Shader()
  {
    glDeleteProgram(m_ID);
    m_ID = 0;
  }

  void Shader::Bind() const
  {
    glUseProgram(m_ID);
  }

  void Shader::UnBind() const
  {
    glUseProgram(0);
  }

  void Shader::SetUniform1f(const std::string& name, float f0)
  {
    Bind();
    glUniform1f(GetUniformLocation(name), f0);
  }

  void Shader::SetUniform1i(const std::string& name, int i0)
  {
    Bind();
    glUniform1i(GetUniformLocation(name), i0);
  }

  void Shader::SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3)
  {
    Bind();
    glUniform4f(GetUniformLocation(name), f0, f1, f2, f3);
  }

  void Shader::SetUniformMatrix4(const std::string& name, const glm::mat4* matrices, int count /* = 1 */)
  {
    Bind();
    glUniformMatrix4fv(GetUniformLocation(name), count, GL_FALSE, &(*matrices)[0][0]);
  }

  int Shader::GetUniformLocation(std::string name)
  {
    if(m_cached_uniforms.count(name) == 0)
      m_cached_uniforms[name] = glGetUniformLocation(m_ID, name.c_str());

    return m_cached_uniforms.at(name);
  }


  static unsigned int LoadShader(ShaderName shadername)
  {
    // Create the shader
    unsigned int shaderID = glCreateShader(shadername.type);

    std::string shadercode;
    std::ifstream shaderfile(shadername.filename, std::ios::in);

    // Check if file is open correctly
    if(!shaderfile.is_open())
    {
      std::cerr << "Impossible to open " << shadername.filename << "\n";
      return 0;
    }

    // Save the content of the file in shadercode
    std::stringstream sstr;
    sstr << shaderfile.rdbuf();
    shadercode = sstr.str();
    shaderfile.close();
    
    // Compile Shader
    char const * shadercodepointer = shadercode.c_str();
    glShaderSource(shaderID, 1, &shadercodepointer , NULL);
    glCompileShader(shaderID);

    // Check Shader for errors
    int Result = GL_FALSE;
    int InfoLogLength;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
      std::vector<char> shaderErrorMessage(InfoLogLength+1);
      glGetShaderInfoLog(shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
      printf("%s\n", &shaderErrorMessage[0]);
    }

    return shaderID;
  }
}
