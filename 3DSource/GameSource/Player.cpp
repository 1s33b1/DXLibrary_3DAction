#include "Player.h"
#include "DxLib.h"

// コンストラクタ
Player::Player()
{
	m_Model = MV1LoadModel("Contents/PlayerModel/Player.mv1");
}

// デストラクタ
Player::~Player()
{
	MV1DeleteModel(m_Model);
}

// 更新処理
void Player::Update()
{
	m_Position.z += 10.0f; // プレイヤーを前進させる
	MV1SetPosition(m_Model, m_Position);
}

// 描画処理
void Player::Draw()
{

}

// 衝突処理
void Player::OnCollision(BaseActor* other)
{

}
