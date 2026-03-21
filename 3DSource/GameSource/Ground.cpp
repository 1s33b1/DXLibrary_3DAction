//
// 地面の描画を行う。
//
#include "Ground.h"

Ground::Ground() : BaseActor(p_actorManager)
{
	m_Position = { 0.0f, 0.0f, 20.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Ground"; // タグを設定
	m_Status = UPDATE;
	m_GroundPhoto = LoadGraph("Contents\\Ground\\ground.png");
}
Ground::Ground(ActorManager* manager)
{
}

Ground::~Ground()
{
	DeleteGraph(m_GroundPhoto);
}
void Ground::Update()
{

}
void Ground::Draw()
{
	DrawBillboard3D(VGet(0.0f, 0.0f, 300.0f), 0.5f, 0.5f, 100.0f,0.0f, m_GroundPhoto, FALSE);
}

void Ground::OnCollision(BaseActor* actor) 
{

}
