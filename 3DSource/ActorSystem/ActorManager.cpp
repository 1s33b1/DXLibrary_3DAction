#include "ActorManager.h"

// コンストラクタ
ActorManager::ActorManager()
{

}

// デストラクタ
ActorManager::~ActorManager()
{

}

// すべてのアクターの更新処理
void ActorManager::AllUpdate()
{
	for(auto it = m_Children.begin(); it != m_Children.end(); ++it)
	{
	}
}

// すべてのアクターの描画処理
void ActorManager::AllDraw()
{
	for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
	{
	}
}

// すべてのアクターの衝突処理
void ActorManager::AllCollision()
{

}

// アクターを追加する関数
void ActorManager::AddActor(BaseActor* actor)
{
	m_Children.push_back(std::make_unique<BaseActor*>(actor));
}

// すべてのアクターを削除する処理
void ActorManager::AllClear()
{

}
