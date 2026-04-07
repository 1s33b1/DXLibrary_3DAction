#pragma once
#include <memory>
#include <vector>
#include <string>
#include "DxLib.h"
class ActorManager;

class BaseActor
{
public:
	BaseActor();
	BaseActor(ActorManager* manager);
	virtual ~BaseActor();
	virtual void Initialize() = 0; // 初期化処理。純粋仮想関数(実装必須)
	virtual void Update();
	virtual void Draw() = 0; // 純粋仮想関数(実装必須)
	virtual void OnCollision(BaseActor* other);

	enum ActorStatus
	{
		UPDATE, // 更新中
		DEAD, // 死亡
		REST, // 休止(Update、Drawを行わない)
	};

	// ゲッター
	int GetStatus() const { return m_Status; } // アクターのステータスを取得する関数
	VECTOR GetPos() const { return m_Position; } // アクターの場所を返す関数
	std::string GetTag() const { return m_Tag; } // アクターのタグ

	// セッター
	void SetPos(VECTOR setPosition);
	void SetStatus(ActorStatus status) { m_Status = status; } // アクターのステータスを設定する関数

	// 現在はAddメソッドは使用していない
	void Add(std::unique_ptr<BaseActor> newActor);
protected:
	ActorStatus m_Status; // アクターの状態
	ActorManager* p_actorManager; // アクターマネジャーのポインタ
	VECTOR m_Position; // アクターの位置の変数
	VECTOR m_Rotation; // プレイヤーの回転
	std::string m_Tag; // アクターのタグ
	int m_Color; // アクターの色の変数
};
