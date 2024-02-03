#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace JAGE {

  glm::vec3 Camera::GetPosition() const
  {
    return m_Position;
  }

  void Camera::SetPosition(glm::vec3 position)
  {
    m_Position = position;
  }

  void Camera::Move(glm::vec3 position)
  {
    m_Position += position;
  }

  void Camera::LookAt(glm::vec3 position)
  {
    SetDirection(position - m_Position);
  }


  glm::vec3 Camera::GetDirection() const
  {
    glm::vec3 dir;
    dir.x = cos(m_Angle.x) * cos(m_Angle.y);
    dir.y = sin(m_Angle.y);
    dir.z = sin(m_Angle.x) * cos(m_Angle.y);
    return glm::normalize(dir);
  }

  void Camera::SetDirection(glm::vec3 direction)
  {
    m_Angle.x = (direction.y >= 0 ? 1 : -1) * std::acos(direction.x / std::sqrt(direction.x*direction.x + direction.y*direction.y));
    m_Angle.y = std::acos(direction.z / direction.length());
  }


  glm::vec3 Camera::GetWorldUp() const
  {
    return m_WorldUp;
  }

  void Camera::SetWorldUp(glm::vec3 world_up)
  {
    m_WorldUp = world_up;
  }


  glm::vec3 Camera::GetRightVector() const
  {
    return -glm::normalize(glm::cross(GetWorldUp(), GetDirection()));
  }

  glm::vec3 Camera::GetUpVector() const
  {
    return glm::normalize(glm::cross(GetRightVector(), GetDirection()));
  }


  glm::vec2 Camera::GetAngle() const
  {
    return m_Angle;
  }

  void Camera::SetAngle(glm::vec2 Angle)
  {
    m_Angle = Angle;
  }


  void Camera::Rotate(glm::vec2 Angle, bool ClampYAngle /*= true*/)
  {
    m_Angle += Angle;
    m_Angle.x = std::fmod(m_Angle.x, glm::radians<float>(360));
    if(ClampYAngle)
      m_Angle.y = glm::clamp(m_Angle.y, glm::radians<float>(-89.5), glm::radians<float>(89.5));
  }


  glm::mat4 Camera::GetViewMatrix() const
  {
    return glm::lookAt(
        m_Position,
        m_Position + GetDirection(),
        GetUpVector() );
  }

  glm::mat4 Camera::GetProjectionMatrix() const
  {
    return glm::perspective(glm::radians(m_FoV), m_camRatio, 0.1f, 100.0f);
  }

}
