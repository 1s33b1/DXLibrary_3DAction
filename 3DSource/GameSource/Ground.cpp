//
// 地面の描画を行う。
//
#include "pch.h"
#include "Ground.h"
#include "Player.h"
#include "GameParameter.h"
#include "ActorManager.h"
#include "Camera.h"

// コンストラクタ
Ground::Ground() : BaseActor(nullptr)
{
}

// 引数付きコンストラクタ
Ground::Ground(ActorManager* manager) : BaseActor(manager)
{
	m_Position = { 0.0f, 0.0f, 200.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Ground"; // タグを設定
	m_Status = UPDATE;
	m_GroundPhoto = LoadGraph("Contents\\Ground\\ground.png");
	char buf[128];
	sprintf_s(buf, sizeof(buf), "basyo: x=%f, y=%f, z=%f", m_Position.x, m_Position.y, m_Position.z);
	OutputDebugString(buf);
}

// デストラクタ
Ground::~Ground()
{
	DeleteGraph(m_GroundPhoto);
}

// 初期化処理
void Ground::Initialize()
{
}

// 更新処理
void Ground::Update()
{
	GroundForward();
	GroundChecker();
}

// 描画処理
void Ground::Draw()
{
	// 描画する四角形の半分のサイズ
	float halfW = GroundSettings::size / 2.0f;
	float halfH = GroundSettings::size / 2.0f;

	// 頂点配列
	VERTEX3D vertex[6];

	for (int i = 0; i < 6; ++i) {
		vertex[i].dif = GetColorU8(255, 255, 255, 255); // ディフューズカラー(光の反射色)を白色
		vertex[i].norm = VGet(0.0f, 1.0f, 0.0f); // 法線ベクトル。地面だからY軸を向かせる
	}

	// 一つ目の三角形	
	vertex[0].pos = VGet(m_Position.x - halfW, m_Position.y, m_Position.z - halfH);
	vertex[0].u = 0.0f; vertex[0].v = 0.0f; // テクスチャ座標
	
	vertex[1].pos = VGet(m_Position.x - halfW, m_Position.y, m_Position.z + halfH);
	vertex[1].u = 0.0f; vertex[1].v = 1.0f;

	vertex[2].pos = VGet(m_Position.x + halfW, m_Position.y, m_Position.z + halfH);
	vertex[2].u = 1.0f; vertex[2].v = 1.0f;

	// 二つ目の三角形
	vertex[3].pos = VGet(m_Position.x - halfW, m_Position.y, m_Position.z - halfH);
	vertex[3].u = 0.0f; vertex[3].v = 1.0f;

	vertex[4].pos = VGet(m_Position.x + halfW, m_Position.y, m_Position.z + halfH);
	vertex[4].u = 1.0f; vertex[4].v = 0.0f;

	vertex[5].pos = VGet(m_Position.x + halfW, m_Position.y, m_Position.z - halfH);
	vertex[5].u = 1.0f; vertex[5].v = 1.0f;

	DrawPolygon3D(vertex, 2, m_GroundPhoto, FALSE);
}

// 衝突処理
void Ground::OnCollision(BaseActor* actor) 
{
}
	
// 地面がプレイヤーの座標より少し後ろに行ったかの確認
void Ground::GroundChecker()
{
	if (!p_actorManager) return;
	VECTOR playerPos = p_actorManager->GetPlayerPosition(); // プレイヤーの場所を取得

	float backEdge = m_Position.z + (GroundSettings::size / 2.0f); // 地面の後ろの端

	// 地面の場所がプレイヤーの地面の端を超えたとき、再配置
	if (playerPos.z > backEdge + GroundSettings::size) {
		float totalLength = GroundSettings::size * GroundSettings::groundMaxZ; // 全長は地面一つ分のサイズと地面の数を掛けたもの

		Relocation(m_Position.z + totalLength);
	}
}

// 再配置処理
void Ground::Relocation(float zPos)
{
	m_Position.z = zPos;
}

// 地面の前身処理
void Ground::GroundForward()
{
	m_Position.z -= GroundSettings::groundSpeed; // 地面を前に動かす
}