///
/// BaseActorを継承し、プレイヤークラスを作成する
///
#pragma once
#include "BaseActor.h"
#include <string>

class Player : public BaseActor
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
	void KeyInput();
	void UpdateMovement();
private:
	int m_Model; // プレイヤーのモデル
};