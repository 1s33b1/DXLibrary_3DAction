#include "Player.h"
#include "DxLib.h"

// コンストラクタ
Player::Player()
{
	m_Position = { 0.0f, 0.0f, 0.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Player"; // タグを設定
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
	MV1DrawModel(m_Model);
}

// 衝突処理
void Player::OnCollision(BaseActor* other)
{

}
