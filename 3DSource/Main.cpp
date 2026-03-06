/// <summary>
/// シューティング
/// 作成日：2026/3/5
/// メイン関数
/// RGB Runner作成中
/// アクターシステムを採用したシューティングゲーム
/// </summary>

#include "DxLib.h"
#include "math.h"
#include "GameParameter.h"
#include <memory>

// 初期化処理
static void Initialize()
{
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, ScreenSettings::screenColorBit); // 画面のサイズを決定
	SetWaitVSyncFlag(TRUE); // 垂直同期を有効にする。本来であればあんまりおすすめされないらしい。	
	// DXライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(FALSE); // マウスカーソルを非表示
	SetUseZBuffer3D(TRUE); // Zバッファを有効にする
	SetWriteZBuffer3D(TRUE); // Zバッファに書き込む

	//auto m_Player =  std::make_unique<Player>(); // プレイヤーの描画
	//auto m_GameCamera = std::make_unique<GameCamera>(); // カメラの描画
	//auto m_Bullet = std::make_unique<Bullet>(0, 0, 0); // 弾丸の描画

	// メインのループ処理
	//----------------------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに

		//m_Player->Update(); // プレイヤーの更新
		//m_Player->Draw(); // プレイヤーの描画
		//m_GameCamera->Update(); // カメラの更新
		//m_Bullet->Update(); // 弾丸の更新
		//m_Bullet->Draw(); // 弾丸の描画

		DrawLine3D(VGet(-1000.0f, 0.0f, 0.0f), VGet(1000.0f, 0.0f, 0.0f), GetColor(255, 0, 0)); // X軸を赤で描画
		ScreenFlip();    // 画面を更新して、少し休む	
	}


	///----------------------------------------------------------------
	/// 終了処理
	
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
