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
	void KeyInput(); // プレイヤーの入力管理
	void UpdateMovement(); // プレイヤーの移動管理

private:
	int m_Model; // プレイヤーのモデル
};