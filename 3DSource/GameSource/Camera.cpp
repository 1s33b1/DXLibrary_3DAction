#include "DxLib.h"
#include "Camera.h"
#include "BaseActor.h"

Camera::Camera()
	:m_cameraPos(VGet(0.0f, 0.0f, 0.0f)),
	m_cameraRota(VGet(0.0f, 0.0f, 0.0f)),
	m_near(100.0f),m_far(1000.0f),
	m_fov(100.0f)
{

}
Camera::~Camera()
{
}
void Camera::Initialize()
{
}
void Camera::Update()
{
	SetCameraPos();
}

void Camera::SetCameraPos()
{
	SetCameraNearFar(m_near, m_far);
	SetupCamera_Perspective(m_fov);
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, m_player.GetPos());
}
void Camera::SetCameraRotate()
{

}
