///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
///
#include "pch.h"
#include "BaseActor.h"
#include "ActorManager.h"

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

// 使用していないメソッド
void BaseActor::Add(std::unique_ptr<BaseActor> newActor) 
{
	// 例：新しいアクター（ここでは仮に何かの派生クラス）を生成
	if (p_actorManager && newActor){
		p_actorManager->AddActor(std::move(newActor));
	}
}