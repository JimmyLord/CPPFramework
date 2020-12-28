#include "FrameworkPCH.h"

#include "Objects/Camera.h"

namespace fw {

Camera::Camera(GameCore* pGameCore, vec2 pos, vec2 projScale)
    : GameObject( pGameCore, "Camera", pos, nullptr, nullptr, nullptr, vec4::White() )
    , m_ProjectionScale( projScale )
{
}

Camera::~Camera()
{
}

void Camera::Update(float deltaTime)
{
    m_Position = m_pObjectWeAreFollowing->GetPosition();
}

} // namespace fw
