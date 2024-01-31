#include "camera.h"
#include "index_buffer.h"
#include "shader.h"
#include "vertex_array.h"

class Renderer
{
  public:
    void Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader) const;
    void Draw(const VertexArray& va, const IndexBuffer& ibo, Shader& shader, const Camera& camera, const glm::mat4& ModelMatrix) const;
    void Clear() const;
}; 
