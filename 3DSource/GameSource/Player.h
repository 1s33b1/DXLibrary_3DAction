///
/// BaseActorを継承し、プレイヤークラスを作成する
///
#pragma once
#include "BaseActor.h"

class Player : public BaseActor
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
private:
	VECTOR m_Position; // プレイヤーの位置
};