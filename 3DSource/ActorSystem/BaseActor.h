#pragma once
#include <memory>
#include <vector>
#include <string>
#include "DxLib.h"

class BaseActor
{
public:
	BaseActor();
	~BaseActor();
	virtual void Update();
	virtual void Draw() = 0; // 純粋仮想関数(このクラスを継承したクラスで必ず実装する必要がある)
	virtual void OnCollision(BaseActor* other);
	virtual void AddActor(std::unique_ptr<BaseActor>);
	virtual void RemoveActor(BaseActor* actor);
protected:
	enum ActorStatus
	{
		UPDATE, // 更新中
		DEAD, // 死亡
		REST, // 休止(Update、Drawを行わない)
	};
	ActorStatus m_Status; // アクターの状態
	std::string m_Tag; // アクターのタグ
	bool isDead() const { return m_Status == DEAD; } // 死亡しているかどうかを確認する関数
	int m_Color; // アクターの色の変数
	VECTOR m_Position; // アクターの位置の変数
	VECTOR m_Rotation; // プレイヤーの回転
};
