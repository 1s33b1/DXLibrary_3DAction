#pragma once
#include <vector>
#include <memory>
//class BaseActor;

class ActorManager
{
public:
	ActorManager();
	~ActorManager();
	void AllUpdate(); // すべてのアクターの更新処理
	void AllDraw(); // すべてのアクターの描画処理
	void AllCollision(); // すべてのアクターの衝突処理
	void AddActor(BaseActor* actor); // アクターを追加する関数
	void ClearActor(); // アクターを削除する関数
	void AllDestroy(BaseActor* actor); // すべてのアクターを削除する関数
private:
	std::vector<std::unique_ptr<BaseActor*>> m_Children; // アクターのベクター配列
};
