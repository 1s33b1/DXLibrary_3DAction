#pragma once
#include "BaseActor.h"
#include "Camera.h"

class Player;
class Ground : public BaseActor
{
public:
	Ground();
	Ground(ActorManager* manager);
	~Ground();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
	void Relocation(float zPos);
	//void GetCameraMatrix()
private:
	int m_GroundPhoto; // 地面の画像。
	MATRIX m_GroundMatrix; // 地面のマトリックス
	Camera m_camera;
	float m_angle;
};