#pragma once
#include <memory>
class Camera;

class ActorManager;
class Game
{
private:
	Game();
	~Game();

	// コピーガード：コピーコンストラクタと代入演算子を禁止
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
public:
	static Game& GetInstance()
	{
		static Game Instance; // static変数として一度だけ生成される
		return Instance;
	}

	int RunGame(); // メインループ
	bool Initialize(); // 初期化処理
	void Finalize(); // 終了処理
private:
	void Update(); // 更新処理
	void Draw(); // 描画処理
	void CreateInitialActors();
	std::unique_ptr<ActorManager> p_actorManager;
	std::unique_ptr<Camera> p_camera;
};
