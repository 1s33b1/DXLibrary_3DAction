///
/// BaseActorを継承し、プレイヤークラスを作成する
///
#pragma once
#include "BaseActor.h"
#include "pch.h"

class ActorManager;

class Player : public BaseActor
{
public:
	Player();
	Player(ActorManager* manager);
	~Player();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
	void KeyInput();
	void UpdateMovement();
	void UpdateColor();
	VECTOR GetPos() { return m_Position; }
private:
	int m_Model; // プレイヤーのモデル
	//int m_material_red; // 赤色のマテリアル
	//int m_material_green; // 緑色のマテリアル
	//int m_material_blue; // 青色のマテリアル
};