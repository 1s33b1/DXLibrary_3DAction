#include "pch.h"
#include "Camera.h"
#include "BaseActor.h"

Camera::Camera()
	:m_cameraPos(VGet(0.0f, 0.0f, 0.0f)),
	m_cameraRota(VGet(0.0f, 0.0f, 0.0f)),
	m_near(100.0f),m_far(1000.0f),
	m_fov(DX_PI_F / 4.0f),
	isDebugMode(false)
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
	CameraRotate(targetPos);
	if (CheckHitKey(KEY_INPUT_1) && CheckHitKey(KEY_INPUT_0) && !isDebugMode)
	{
		isDebugMode = true; // 1キーと0キーが押されたらデバッグモードを切り替える
	}
	else if(CheckHitKey(KEY_INPUT_1) && CheckHitKey(KEY_INPUT_0) && isDebugMode)
	{
		isDebugMode = false; // 1キーと0キーが押されたらデバッグモードを切り替える
	}
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

void Camera::CameraRotate(VECTOR targetPos)
{
	// カメラの回転を更新する処理
	// デバッグモードのときに左右でカメラを回転させる
	if (isDebugMode && CheckHitKey(KEY_INPUT_LEFT)) {
		m_cameraPos = VAdd(m_cameraPos, VGet(-10.0f, 0.0f, 0.0f)); // 左に移動
	}
	else if (isDebugMode && CheckHitKey(KEY_INPUT_RIGHT)){
				m_cameraPos = VAdd(m_cameraPos, VGet(10.0f, 0.0f, 0.0f)); // 右に移動
	}
	SetCameraPositionAndTarget_UpVecY(m_cameraPos, targetPos); // カメラを設置する
}
