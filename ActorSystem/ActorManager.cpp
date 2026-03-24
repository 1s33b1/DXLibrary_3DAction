#include "ActorManager.h"
#include "BaseActor.h"

// コンストラクタ
ActorManager::ActorManager()
{

}

// デストラクタ
ActorManager::~ActorManager()
{
}

void ActorManager::Initialize()
{

}

// すべてのアクターの更新処理
void ActorManager::AllUpdate()
{
	for(auto& actor : m_Children){
		actor->Update();
	}
	ClearActor();
}

// すべてのアクターの描画処理
void ActorManager::AllDraw()
{
	for (auto& actor : m_Children){
		actor->Draw();
	}
}

// すべてのアクターの衝突処理
void ActorManager::AllCollision()
{
}

// アクターを追加する関数
void ActorManager::AddActor(std::unique_ptr<BaseActor> actor)
{
	m_Children.push_back(std::move(actor));
}

// アクターを削除する処理
void ActorManager::ClearActor()
{
	for (auto it = m_Children.begin(); it != m_Children.end();) {
		if (it->get()->GetStatus() == BaseActor::DEAD) {
			it = m_Children.erase(it); // 死亡しているアクターを削除し、メモリを解放する
		}
		else {
			++it; // 削除していないアクターならば次に進む
		}
	}
}

// すべてのアクターを削除する関数
void ActorManager::AllDestroy(BaseActor* actor)
{
}

// プレイヤーの位置を返す関数
VECTOR ActorManager::GetPlayerPosition()
{
	for (const auto& actor : m_Children) {
		if (actor->GetTag() == "Player") {
			return actor->GetPos();
		}
	}
	// プレイヤーが見つからなかった場合、原点を返す
	return VGet(0.0f, 0.0f, 0.0f);
}
