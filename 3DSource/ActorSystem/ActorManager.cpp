#include "pch.h"
#include "ActorManager.h"
#include "BaseActor.h"
#include "GameParameter.h"

// コンストラクタ
ActorManager::ActorManager()
{

}

// デストラクタ
ActorManager::~ActorManager()
{
}

// 初期化処理
void ActorManager::AllInitialize()
{
	m_firstGroundPosx = GroundSettings::groundMaxX * GroundSettings::size / -2; // 地面の生成を中心から行うため、地面の最大数と地面のサイズから最初の地面を生成する位置を計算している。
	// すべてのアクターの初期化処理を行う
	for(int i = 0; i < m_Children.size(); ++i){
		m_Children[i]->Initialize();
	}

	// 床の初期化
	for(int x = 0; x < m_Children.size(); ++x){
		// アクターの配列から地面のタグがついたものを探し配置する
		if (m_Children[x]->GetTag() == "Ground") {
			//m_Children[x]->SetPos(VGet(GroundSettings::firstGroundPosx + (GroundSettings::groundMaxX * GroundSettings::size * groundCountX / -2), 
			//						   GroundSettings::firstGroundPosy, 
			//						   GroundSettings::firstGroundPosz + (GroundSettings::size * groundCountZ))
			//);
			m_Children[x]->SetPos(VGet(m_firstGroundPosx + (GroundSettings::size * groundCountX),
									   GroundSettings::firstGroundPosy,
									   GroundSettings::firstGroundPosz + (GroundSettings::size * groundCountZ))
			);

			groundCountX++;
			// 地面の生成を縦横で行うが、X座標のカウンタが最大値に達したらX座標のカウンタをリセットしたのちにZ座標のカウンタを増やす。
			if (groundCountX >= GroundSettings::groundMaxX) {
				groundCountX = 0;
				groundCountZ++;
			}
		}
	}
}

// すべてのアクターの更新処理。ループを抜けた後にアクターの削除処理を行う
void ActorManager::AllUpdate()
{
	for(auto& actor : m_Children){
		actor->Update();
	}
	//ClearActor();
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
	for (int i = 0; i < m_Children.size(); ++i) {
		m_Children.erase(std::remove_if(m_Children.begin(), m_Children.end(),
			[](const std::unique_ptr<BaseActor>& actor) {
				return actor->GetStatus() == BaseActor::DEAD; // 死亡しているアクターを削除する条件
			}), m_Children.end());
	}

	// ここに書く処理はゲーム終了時にすべてのアクターを削除するための処理を記述する。
	for(int i= 0; i < m_Children.size(); ++i){
		m_Children.erase(m_Children.begin() + i);
	}
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
