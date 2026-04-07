//
// シングルトンパターンで作成
//

#include "Game.h"
#include "DxLib.h"
#include "GameParameter.h"
#include "ActorManager.h"
#include "Camera.h"
#include "Player.h"
#include "Ground.h"

Game::Game()
{
}
Game::~Game()
{
}

// 更新処理
void Game::Update()
{
	if (p_actorManager) {
		p_actorManager->AllUpdate();
	}
	if (p_camera) {
		VECTOR playerPos = p_actorManager->GetPlayerPosition();
		p_camera->Update(playerPos);
	}
}

// 描画処理
void Game::Draw()
{
	if (p_actorManager) {
		p_actorManager->AllDraw();
	}
}

// メインループ
int Game::RunGame() 
{
	if (!Initialize()) return -1;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに
		{
			DrawLine3D(VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), GetColor(255, 0, 0)); // X軸を赤で描画
			DrawLine3D(VGet(0.0f, 0.0f, -1000.0f), VGet(0.0f, 0.0f, 1000.0f), GetColor(255, 0, 0));
		}
		Update();
		Draw();
		ScreenFlip();    // 画面を更新して、少し休む
	}

	//-------------------------------------
	// 終了処理
	Finalize();
	return 0;
}

// 初期化処理
bool Game::Initialize()
{
	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, ScreenSettings::screenColorBit); // 画面のサイズを決定
	SetWaitVSyncFlag(TRUE); // 垂直同期を有効にする。本来であればあんまりおすすめされないらしい。	
	// DXライブラリ初期化処理
	if (DxLib_Init() == -1) return false;
	p_actorManager = std::make_unique<ActorManager>(); // マネージャーの生成
	p_camera = std::make_unique<Camera>();
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(FALSE); // マウスカーソルを非表示
	SetUseZBuffer3D(TRUE); // Zバッファを有効
	SetWriteZBuffer3D(TRUE); // Zバッファに書き込む
	CreateInitialActors(); // アクターの作成

	return true;
}

// 終了処理
void Game::Finalize()
{
	DxLib_End();				// ＤＸライブラリ使用の終了処理
}

// 最初のアクターを配置する際に使用
void Game::CreateInitialActors()
{
	// ループで最大個数分、配列に追加する
	//for (int i = 0; i < GroundSettings::groundMax; i++) {
	//	p_actorManager->AddActor(std::make_unique<Ground>(p_actorManager.get()));
	//}
	p_actorManager->AddActor(std::make_unique<Player>());
	//p_actorManager->AddActor(std::make_unique<Ground>());
	for (int i = 0; i < GroundSettings::groundMax; ++i){
		p_actorManager->AddActor(std::make_unique<Ground>(p_actorManager.get()));
	}

	p_actorManager->AllInitialize(); // アクターの初期化

	OutputDebugString("aiueo\n");
}


