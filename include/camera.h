#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Camera
{
  public:
    Camera() {};

    Camera(glm::vec3 position, glm::vec3 world_up, glm::vec2 Angle, float FoV, float ratio)
      : m_Position(position),
        m_WorldUp(world_up),
        m_Angle(Angle),
        m_FoV(FoV),
        m_camRatio(ratio) {}

    glm::vec3 GetPosition() const;
    void SetPosition(glm::vec3 position);
    void Move(glm::vec3 position);

    void LookAt(glm::vec3 position);

    glm::vec3 GetDirection() const;
    void SetDirection(glm::vec3 direction);

    glm::vec3 GetWorldUp() const;
    void SetWorldUp(glm::vec3 world_up);

    glm::vec3 GetRightVector() const;
    glm::vec3 GetUpVector() const;

    glm::vec2 GetAngle() const;
    void SetAngle(glm::vec2 Angle);

    void Rotate(glm::vec2 Angle, bool ClampYAngle = true);

    glm::mat4 GetViewMatrix() const;
    glm::mat4 GetProjectionMatrix() const;

  private:
    glm::vec3 m_Position;
    glm::vec3 m_WorldUp;
    glm::vec2 m_Angle;

    float m_FoV;
    float m_camRatio;
};
