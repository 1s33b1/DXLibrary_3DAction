///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
///
#include"BaseActor.h"

// コンストラクタ
BaseActor::BaseActor()
{

}

// デストラクタ
BaseActor::~BaseActor()
{

}

// 更新関数
void BaseActor::Update()
{
	for (auto it = m_ChildActors.begin(); it != m_ChildActors.end();) {
		(*it)->Update();
	}
}

// 描画関数
void BaseActor::Draw()
{

}

// 衝突時処理
void BaseActor::OnCollision(BaseActor* other)
{

}

// アクターを追加する関数
void BaseActor::AddActor(std::unique_ptr<BaseActor>)
{

}

// アクターを削除する関数
void BaseActor::RemoveActor(BaseActor* actor)
{

}