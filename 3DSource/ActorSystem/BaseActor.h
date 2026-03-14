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
	~BaseActor();
	//virtual void Init(); // 純粋仮想関数。セット関数を使用するときとかに呼び出すもの
	virtual void Update();
	virtual void Draw() = 0; // 純粋仮想関数(このクラスを継承したクラスで必ず実装する必要がある)
	virtual void OnCollision(BaseActor* other);
	int GetStatus() const { return m_Status; } // アクターのステータスを取得する関数
	enum ActorStatus
	{
		UPDATE, // 更新中
		DEAD, // 死亡
		REST, // 休止(Update、Drawを行わない)
	};
	void SetStatus(ActorStatus status) { m_Status = status; } // アクターのステータスを設定する関数

	std::string GetTag() const { return m_Tag; } // アクターのタグ
	void Add(std::unique_ptr<BaseActor> newActor);
	VECTOR GetPos() { return m_Position; } // アクターの場所を返す関数

protected:
	ActorStatus m_Status; // アクターの状態
	std::string m_Tag; // アクターのタグ
	int m_Color; // アクターの色の変数
	VECTOR m_Position; // アクターの位置の変数
	VECTOR m_Rotation; // プレイヤーの回転
	ActorManager* p_actorManager;
private:
};
