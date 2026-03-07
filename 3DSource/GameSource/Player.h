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
	VECTOR m_Rotation; // プレイヤーの回転
	VECTOR m_Scale; // プレイヤーのスケール
	int m_Model; // プレイヤーのモデル
	int color; // プレイヤーの色(メインシステムとなる数字キーで色の変更を行う)
};