//
// GameParameter.h：ゲームで使用するパラメーターをまとめるファイル
//
#pragma once
namespace ScreenSettings {
	const int screenWidth = 800;
	const int screenHeight = 600;
	const int screenColorBit = 16;
}

namespace PlayerSettings {
	const float StartPos = 0; 
	const int playerSpeed = 5;
}

// この色の数値たちは何かしら違う形でいい感じにまとめたい。structとかクラスとかでまとめたいと考えてる
namespace ColorSettings {
	const int Red_r = 255;
	const int Red_g = 0;
	const int Red_b = 0;

	const int Blue_r = 0;
	const int Blue_g = 255;
	const int Blue_b = 0;

	const int Green_r = 0;
	const int Green_g = 0;
	const int Green_b = 255;
}

namespace GroundSettings{
	const int groundMax = 5; // 描画する地面の最大個数
	const int groundMaxX = 5;
	const int groundMaxZ = 10;
	const float  groundSpeed = 1.0f; // 地面のスピード

	const float firstGroundPosx = 0.0f;
	const float firstGroundPosy = 0.0f;
	const float firstGroundPosz = 0.0f;
	
	const float cx = 0.5f; // 0.0～1.0の間で変更する
	const float cy = 0.5f; // 0.0～1.0の間で変更する
	const float size = 300.0f;
	const float angle = 0.0f;
}

// 障害物のパラメーター関連
namespace ObstacleSettings {
	const float obstacleRadius = 20.0f; // 障害物の半径
	const float obstacleSpeed = 1.0f; // 障害物のスピード
	const int obstacleMax = 10; // 描画する障害物の最大個数
	const int obstacleVertex = 36; // 障害物の頂点数
}