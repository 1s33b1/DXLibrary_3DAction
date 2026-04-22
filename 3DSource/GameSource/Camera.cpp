#include "pch.h"
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
	SetFogEnable(TRUE); // フォグを有効にする
	SetFogColor(0,0,0); // フォグの色を黒にする
	SetFogStartEnd(200.0f, 1000.0f); // フォグが始まる距離と終了する距離を設定する
}

void Camera::Update(VECTOR targetPos)
{
	SetCameraPos(targetPos);
}

void Camera::SetCameraPos(VECTOR targetPos)
{
	SetCameraNearFar(m_near, m_far); // カメラの見える範囲を設定
	SetupCamera_Perspective(m_fov); // カメラの視野角を設定

	m_cameraPos = VAdd(targetPos, VGet(0.0f, 150.0f, -200.0f));
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, targetPos); // カメラを設置する
}
void Camera::SetCameraRotate()
{

}
