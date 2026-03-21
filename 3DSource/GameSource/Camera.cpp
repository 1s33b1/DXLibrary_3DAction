#include "DxLib.h"
#include "Camera.h"
#include "BaseActor.h"

Camera::Camera()
	:m_cameraPos(VGet(0.0f, 0.0f, 0.0f)),
	m_cameraRota(VGet(0.0f, 0.0f, 0.0f)),
	m_near(100.0f),m_far(1000.0f),
	m_fov(DX_PI_F / 4.0f)
{

}
Camera::~Camera()
{
}
void Camera::Initialize()
{
}
void Camera::Update(VECTOR targetPos)
{
	SetCameraPos(targetPos);
}

void Camera::SetCameraPos(VECTOR targetPos)
{
	SetCameraNearFar(m_near, m_far);
	SetupCamera_Perspective(m_fov);

	m_cameraPos = VAdd(targetPos, VGet(0.0f, 200.0f, -100.0f));
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, targetPos);
}
void Camera::SetCameraRotate()
{

}
