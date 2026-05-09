///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
///
#include "pch.h"
#include "BaseActor.h"
#include "ActorManager.h"
#include "GameParameter.h"

// コンストラクタ
BaseActor::BaseActor()
{
}
BaseActor::BaseActor(ActorManager* manager)
	:m_Tag("NoName"),
	p_actorManager(manager),
	m_Color(0),
	m_Position(0.0f,0.0f,0.0f),m_Rotation(0.0f,0.0f,0.0f),
	m_Status(REST)
{
}

// デストラクタ
BaseActor::~BaseActor()
{
}

// 更新関数
void BaseActor::Update()
{
}

// 描画処理
void BaseActor::Draw()
{
}

// 衝突時処理
void BaseActor::OnCollision(BaseActor* other)
{
}

// 再配置処理
void BaseActor::Relocation(VECTOR newPosition)
{
	m_Position = newPosition;
}

// アクターを前方に移動させる関数
void BaseActor::MovePosition(VECTOR move)
{
	m_Position = VSub(m_Position, move); // VSub関数を使用して、手前側へ移動させる
}

// プレイヤーの後ろに行ったかの確認。まだ未完成
void BaseActor::CheckBehindPlayer()
{
	if (!p_actorManager) return;
	VECTOR playerPos = p_actorManager->GetPlayerPosition(); // プレイヤーの場所を取得

	float backEdge = m_Position.z + (GroundSettings::size / 2.0f); // 地面の後ろの端

	// 地面の場所がプレイヤーの地面の端を超えたとき、再配置
	if (playerPos.z > backEdge + GroundSettings::size) {
		float totalLength = GroundSettings::size * GroundSettings::groundMaxZ; // 全長は地面一つ分のサイズと地面の数を掛けたもの

		//Relocation(m_Position.z + totalLength); // 変更前のコード(地面のz座標だけを変更して再配置)
		Relocation(VGet(m_Position.x, m_Position.y, m_Position.z + totalLength));
	}

}

// 使用していないメソッド
void BaseActor::Add(std::unique_ptr<BaseActor> newActor) 
{
	// 例：新しいアクター（ここでは仮に何かの派生クラス）を生成
	if (p_actorManager && newActor){
		p_actorManager->AddActor(std::move(newActor));
	}
}