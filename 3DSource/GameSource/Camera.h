//
// Fogを使用
//
#pragma once
#include "pch.h"
#include "Player.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update(VECTOR targetPos);
	void Initialize();
	void SetCameraPos(VECTOR targetPos);
	void SetCameraRotate();
	void CameraRotate(VECTOR targetPos);
	bool CheckDebugMode() { return isDebugMode; } // デバッグモードの状態を返す関数。
	VECTOR GetCameraPos() const { return m_cameraPos; }
private:
	VECTOR m_cameraPos;
	VECTOR m_cameraRota;
	float m_near; // カメラの見える範囲(手前)
	float m_far; // カメラの見える範囲(奥)
	float m_fov; // 視野角

	// デバッグ用のカメラ回転変数
	bool isDebugMode;// デバッグのフラグ
};
