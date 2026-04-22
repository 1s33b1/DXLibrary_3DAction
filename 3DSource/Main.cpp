/// <summary>
/// シューティング
/// 作成日：2026/3/5
/// メイン関数
/// RGB Runner作成中
/// アクターシステムとシングルトンパターンを採用したシューティングゲーム
/// 
/// </summary>

#include "pch.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	return Game::GetInstance().RunGame();
}
