//---------------------------------------
// Player.cpp
// BaseActorを継承。
// 1,2,3キーを押すと、赤、緑、青の色に変化する。
// キー入力での移動は現時点では行わない。デバッグ用にWASDで移動できるようにしている。
//---------------------------------------

#include "pch.h"
#include "Player.h"
#include "GameParameter.h"

// コンストラクタ
Player::Player() : BaseActor(p_actorManager)
{
	m_Position = { 0.0f, 0.0f, 0.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Model = MV1LoadModel("Contents/Player/Player.mv1");
	m_Tag = "Player"; // タグを設定
	m_Status = UPDATE;
}
Player::Player(ActorManager* manager) : BaseActor(manager)
{
}

// デストラクタ
Player::~Player()
{
	MV1DeleteModel(m_Model);
}

void Player::Initialize()
{

}

// 更新処理
void Player::Update()
{
	KeyInput();
	UpdateMovement();
	UpdateColor();
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
		m_Position.x -= PlayerSettings::playerSpeed; // 左方向
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		m_Position.x += PlayerSettings::playerSpeed; // 右方向
	}

	// 色の変更
	if (CheckHitKey(KEY_INPUT_1)) {
		m_ColorType = Red; // 赤色に変更
	}
	if (CheckHitKey(KEY_INPUT_2)) {
		m_ColorType = Green; // 緑色に変更
	}
	if (CheckHitKey(KEY_INPUT_3)) {
		m_ColorType = Blue; // 青色に変更
	}
}

// プレイヤーの移動管理
void Player::UpdateMovement()
{
	MV1SetPosition(m_Model, m_Position);
}

// プレイヤーの色管理
void Player::UpdateColor()
{
	COLOR_F color = { 0.0f, 0.0f, 0.0f, 1.0f }; // 初期色は白

	switch (m_ColorType)
	{
	case BaseActor::Red:
		color.r = 1.0f; // 赤色に設定
		break;
	case BaseActor::Green:
		color.g = 1.0f; // 緑色に設定
		break;
	case BaseActor::Blue:
		color.b = 1.0f; // 青色に設定
		break;
	case BaseActor::None:
		break;
	default:
		color.r = color.g = color.b = 1.0f; // デフォルトは白色
		break;	
	}

	int materialCount = MV1GetMaterialNum(m_Model); // モデルのマテリアルの数を取得

	for (int i = 0; i < materialCount; i++)
	{
		MV1SetMaterialDifColor(m_Model, i, color); // マテリアルのディフューズカラーを設定
	}
}
