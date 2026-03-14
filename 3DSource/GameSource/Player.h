///
/// BaseActorを継承し、プレイヤークラスを作成する
///
#pragma once
#include "BaseActor.h"
#include <string>
#include "DxLib.h"

class ActorManager;

class Player : public BaseActor
{
public:
	Player();
	Player(ActorManager* manager);
	~Player();
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
	void KeyInput();
	void UpdateMovement();
	VECTOR GetPos() { return m_Position; }
private:
	int m_Model; // プレイヤーのモデル
};