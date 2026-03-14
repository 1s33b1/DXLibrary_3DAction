#pragma once
#include "DxLib.h"
#include "Player.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update();
	//void Update(VECTOR targetPos);
	void Initialize();
	void SetCameraPos();
	void SetCameraRotate();
private:
	VECTOR m_cameraPos;
	VECTOR m_cameraRota;
	float m_near; // ƒJƒƒ‰‚ÌŒ©‚¦‚é”ÍˆÍ(è‘O)
	float m_far; // ƒJƒƒ‰‚ÌŒ©‚¦‚é”ÍˆÍ(‰œ)
	float m_fov; // ‹–ìŠp
	Player m_player;
};
