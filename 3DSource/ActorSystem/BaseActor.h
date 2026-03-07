#pragma once
#include <memory>
#include <vector>
class BaseActor
{
public:
	BaseActor();
	~BaseActor();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollision(BaseActor* other);
	virtual void AddActor(std::unique_ptr<BaseActor>);
	virtual void RemoveActor(BaseActor* actor);
private:
	std::vector<BaseActor* > m_ChildActors; // アクターの子供を入れるベクター配列
protected:
	enum ActorStatus
	{
		UPDATE, // 更新中
		DEAD, // 死亡
		REST, // 休止(Update、Drawを行わない)
	};
	ActorStatus m_Status; // アクターの状態
	char m_Tag[256]; // アクターのタグ
};
