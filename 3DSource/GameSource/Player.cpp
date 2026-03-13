//---------------------------------------
// プレイヤークラス
// BaseActorを継承。
// 初期値：
// 赤色、
//---------------------------------------

#include "Player.h"
#include "DxLib.h"
#include "GameParameter.h"

// コンストラクタ
Player::Player(ActorManager* manager)
{
	m_Position = { 0.0f, 0.0f, 0.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Player"; // タグを設定
	m_Model = MV1LoadModel("Contents/PlayerModel/Player.mv1");
	m_Status = UPDATE;
	m_Color = GetColor(ColorSettings::Red_r, ColorSettings::Red_g, ColorSettings::Red_b);
}

// デストラクタ
Player::~Player()
{
	MV1DeleteModel(m_Model);
}

// 更新処理
void Player::Update()
{
	KeyInput();
	UpdateMovement();
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

// プレイヤーの入力管理
void Player::KeyInput()
{
	if (CheckHitKey(KEY_INPUT_W)) {
		m_Position.z += PlayerSettings::playerSpeed; // 前進
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		m_Position.z -= PlayerSettings::playerSpeed; // 後退
	}	
	if (CheckHitKey(KEY_INPUT_A)) {
		m_Position.x -= PlayerSettings::playerSpeed; // 後退
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		m_Position.x += PlayerSettings::playerSpeed; // 後退
	}
}

// プレイヤーの移動管理
void Player::UpdateMovement()
{
	MV1SetPosition(m_Model, m_Position);
}
