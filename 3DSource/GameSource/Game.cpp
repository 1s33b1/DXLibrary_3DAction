//
// シングルトンパターンで作成
//
#include "DxLib.h"
#include "Game.h"
#include "GameParameter.h"
#include "ActorManager.h"
#include "Player.h"

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
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに
		DrawLine3D(VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), GetColor(255, 0, 0)); // X軸を赤で描画
		Update();
		Draw();
		ScreenFlip();    // 画面を更新して、少し休む	 
	}

	//-------------
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
	p_actorManager->AddActor(std::make_unique<Player>());
}


