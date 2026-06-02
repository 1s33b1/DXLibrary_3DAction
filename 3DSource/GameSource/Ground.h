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
	void CheckBehindPlayer() override; // プレイヤーの後ろに行ったかの確認。
	void Relocation(VECTOR newPosition) override; // 再配置処理。
	void MovePosition(VECTOR move) override; // 前方に移動させる関数
	//void Relocation(float zPos);
	void GroundChecker();

	//void GroundForward();
private:
	int m_GroundPhoto; // 地面の画像。
	//float m_angle;
	//float m_acceleration; // 地面の加速度(現在未実装)
};