//
// 地面の描画を行う。
//
#include "Ground.h"
#include "Player.h"
#include "GameParameter.h"
#include "ActorManager.h"

Ground::Ground() : BaseActor(p_actorManager)
{
	m_Position = { 0.0f, 0.0f, 100.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Ground"; // タグを設定
	m_Status = UPDATE;
	m_GroundPhoto = LoadGraph("Contents\\Ground\\ground.png");
}
Ground::Ground(ActorManager* manager) : BaseActor(manager)
{
}

Ground::~Ground()
{
	DeleteGraph(m_GroundPhoto);
}
void Ground::Update()
{
	if (!p_actorManager) return;
	VECTOR playerPos = p_actorManager->GetPlayerPosition(); // プレイヤーの場所を取得

	float groundEndLine = (m_Position.z - 150.0f) + (GroundSettings::cx / 2.0f);

	// 地面の場所がプレイヤーの地面の端を超えたとき、再配置
	if (playerPos.z > groundEndLine) {
		float allGrounds = GroundSettings::cx * GroundSettings::groundMax;
		Relocation(m_Position.z + allGrounds);
	}
}
void Ground::Draw()
{
	DrawBillboard3D(m_Position, GroundSettings::cx, GroundSettings::cy, GroundSettings::size, GroundSettings::angle, m_GroundPhoto, FALSE);
}

void Ground::OnCollision(BaseActor* actor) 
{

}

// 再配置するメソッド
void Ground::Relocation(float zPos)
{
	m_Position.z = zPos;
}
