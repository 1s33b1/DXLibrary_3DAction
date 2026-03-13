///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
/// Update():毎フレーム呼び出す更新関数。アクターの状態を更新する際に使用。
/// Draw():毎フレーム呼び出す描画関数。アクターの描画を行う際に使用。
/// OnCollision():アクター同士が衝突した際に呼び出す関数。衝突処理を行う際に使用。
#include"BaseActor.h"
#include "ActorManager.h"

// コンストラクタ
BaseActor::BaseActor()
{

}
BaseActor::BaseActor(ActorManager* manager)
	:m_Tag("NoName"),
	p_actorManager(manager)
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

// 衝突時処理
void BaseActor::OnCollision(BaseActor* other)
{

}

void BaseActor::Add(std::unique_ptr<BaseActor> newActor) 
{
	// 例：新しいアクター（ここでは仮に何かの派生クラス）を生成
	// auto newActor = std::make_unique<Bullet>(p_actorManager); 
	// p_actorManager->AddActor(std::move(newActor));
	//auto newActor =
	if (p_actorManager && newActor){
		p_actorManager->AddActor(std::move(newActor));
	}
}
