#include "renderer.h"
#include "GL/glew.h"
namespace JAGE {
  void Renderer::Draw(const VertexArray& va, const IndexBuffer& ibo, const Shader& shader) const
  {
    va.Bind();
    ibo.Bind();
    shader.Bind();

    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
  }

  void Renderer::Draw(const VertexArray& va, const IndexBuffer& ibo, Shader& shader, const Camera& cam, const glm::mat4& ModelMatrix) const
  {
    va.Bind();
    ibo.Bind();
    shader.Bind();

    glm::mat4 MPV = cam.GetProjectionMatrix() * cam.GetViewMatrix() * ModelMatrix;
    shader.SetUniformMatrix4("MPV", &MPV);

    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);
  }

  void Renderer::Clear() const
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
}
