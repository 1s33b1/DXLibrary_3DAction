#pragma once
#include <vector>
#include <memory>
class BaseActor;

class ActorManager
{
public:
	ActorManager();
	~ActorManager();
	void AddActor(BaseActor* actor); // アクターを追加する関数
	void AllUpdate(); // すべてのアクターの更新処理
	void AllDraw(); // すべてのアクターの描画処理
	void AllCollision(); // すべてのアクターの衝突処理
	void AllClear(); // すべてのアクターを削除する処理
private:
	std::vector<std::unique_ptr<BaseActor*>> m_Children; // アクターのベクター配列
};
