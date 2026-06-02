// Obstacleクラス(正方形を作る)
// m_positionのyの値をGameParameterとかで宣言した半径を代入する
// VERTEX3D変数配列にGameParameterの半径とかを使って頂点座標を代入していく。
// (とりあえずはこのようなものを考えてるから一面ずつ実装してく)
// もしかしたらsin, cosとかのメソッドでなんか行けるかも
//
#include "pch.h"
#include "ObStacle.h"
#include "BaseActor.h"
#include "GameParameter.h"
#include "ActorManager.h"

// コンストラクタ
Obstacle::Obstacle() : BaseActor(nullptr)
{
}

// 引数付きコンストラクタ
Obstacle::Obstacle(ActorManager* manager) : BaseActor(manager)
{
	m_Position = { 0.0f,ObstacleSettings::obstacleRadius, 0.0f }; // 初期位置を設定
	m_Rotation = { 0.0f, 0.0f, 0.0f }; // 初期回転を設定
	m_Tag = "Obstacle"; // タグを設定
	m_Status = UPDATE;	
	m_ObstaclePhotoHandle = LoadGraph("Contents\\Obstacle\\Obstacle.jpg");
	m_ColorType = ColorType::None;
	//m_ObstaclePhotoHandle = LoadGraph("Contents\\Ground\\ground.png");
	//m_Color = GetColor(ColorSettings::Red_r, ColorSettings::Red_g, ColorSettings::Red_b);
}

// デストラクタ
Obstacle::~Obstacle()
{
	DeleteGraph(m_ObstaclePhotoHandle);
}

// 初期化処理
void Obstacle::Initialize()
{
	m_ColorType = ColorType::Red; // 障害物の色を赤色に設定
}

// 更新処理
void Obstacle::Update()
{
	MovePosition(VGet(0.0f, 0.0f, ObstacleSettings::obstacleSpeed)); // 地面と同じ速度で前に動かす
	CheckBehindPlayer(); // プレイヤーの後ろに行ったか確認して、行ってたら再配置
}

// 描画処理
void Obstacle::Draw()
{
	//const float r = ObstacleSettings::obstacleRadius; // 障害物の半径を変数に代入しておく

	//// --- 1つ目の三角形 (左上、右上、左下) ---
	//m_Vertexs[0].pos = VAdd(m_Position, VGet(-r, r, 0.0f)); // 左上
	//m_Vertexs[0].u = 0.0f; m_Vertexs[0].v = 0.0f;
	//m_Vertexs[1].pos = VAdd(m_Position, VGet(r, r, 0.0f)); // 右上
	//m_Vertexs[1].u = 1.0f; m_Vertexs[1].v = 0.0f;
	//m_Vertexs[2].pos = VAdd(m_Position, VGet(-r, -r, 0.0f)); // 左下
	//m_Vertexs[2].u = 0.0f; m_Vertexs[2].v = 1.0f;

	//// --- 2つ目の三角形 (右上、右下、左下) ---
	//m_Vertexs[3].pos = VAdd(m_Position, VGet(r, r, 0.0f)); // 右上
	//m_Vertexs[3].u = 1.0f; m_Vertexs[3].v = 0.0f;
	//m_Vertexs[4].pos = VAdd(m_Position, VGet(r, -r, 0.0f)); // 右下
	//m_Vertexs[4].u = 1.0f; m_Vertexs[4].v = 1.0f;
	//m_Vertexs[5].pos = VAdd(m_Position, VGet(-r, -r, 0.0f)); // 左下
	//m_Vertexs[5].u = 0.0f; m_Vertexs[5].v = 1.0f;

	//for (int i = 0; i < 6; i++) {
	//	m_Vertexs[i].dif = GetColorU8(255, 255, 255, 255); // ディフューズカラー(光の反射色)を白色
	//	m_Vertexs[i].norm = VGet(0.0f, 0.0f, -1.0f); // 法線ベクトル。正面を向かせる
	//}

	//DrawPolygon3D(m_Vertexs, 2, m_ObstaclePhotoHandle, FALSE);
	DrawCube(m_Position, ObstacleSettings::obstacleRadius);
}

// 正方形を作る関数
void Obstacle::DrawCube(VECTOR CENTER, float RADIUS)
{
	const float radius = RADIUS;
	int index = 0; // VECTOR変数の配列のインデックスを管理する変数
	
	// 拡張店の法線ベクトルの方向
	VECTOR normal[6] = {
		VGet(0.0f, 0.0f, -1.0f), // 前面
		VGet(0.0f, 0.0f, 1.0f), // 背面
		VGet(-1.0f, 0.0f, 0.0f), // 左面
		VGet(1.0f, 0.0f, 0.0f), // 右面
		VGet(0.0f, 1.0f, 0.0f), // 上面
		VGet(0.0f, -1.0f, 0.0f) // 底面
	};

	// 正方形の立方体を構成する8つの頂点の座標を代入しておく
	VECTOR vertexPos1 = { -radius, radius , -radius}; // カメラ側の左上の頂点
	VECTOR vertexPos2 = { radius, radius, -radius}; // カメラ側の右上の頂点
	VECTOR vertexPos3 = {-radius, -radius, -radius}; // カメラ側の左下の頂点
	VECTOR vertexPos4 = {radius, -radius, -radius}; // カメラ側の右下の頂点
	VECTOR vertexPos5 = { -radius, radius, radius}; // カメラ側から見た奥側の左上の頂点
	VECTOR vertexPos6 = { radius, radius, radius}; // カメラ側から見た奥側の右上の頂点
	VECTOR vertexPos7 = { -radius, -radius, radius}; // カメラ側から見た奥側の左下の頂点
	VECTOR vertexPos8 = { radius, -radius, radius}; // カメラ側から見た奥側の右下の頂点

	// 前面(Z軸をすべてマイナス)
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos1); // 前面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos2); // 前面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos3); // 前面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos2); // 前面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos4); // 前面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos3); // 前面の左下の頂点

	// 背面(Z軸をすべてプラス)
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos6); // 背面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos5); // 背面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos8); // 背面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos5); // 背面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos8); // 背面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos7); // 背面の左下の頂点

	// 左面(X軸をすべてマイナス)
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos5); // 左面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos1); // 左面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos7); // 左面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos1); // 左面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos3); // 左面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos7); // 左面の左下の頂点

	// 右面(X軸をすべてプラス)
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos2); // 右面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos6); // 右面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos4); // 右面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos6); // 右面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos8); // 右面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos4); // 右面の左下の頂点

	// 上面(Y軸をすべてプラス)
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos5); // 上面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos6); // 上面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos1); // 上面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos6); // 上面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos2); // 上面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos1); // 上面の左下の頂点

	// 底面(Y軸をすべてマイナス)。見えないから描画しなくてもいいかも
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos7); // 底面の左上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos8); // 底面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos3); // 底面の左下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos8); // 底面の右上の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos4); // 底面の右下の頂点
	m_Vertexs[index++].pos = VAdd(CENTER, vertexPos7); // 底面の左下の頂点

	switch (m_ColorType)
	{
	case ColorType::Red: // 障害物の色を赤色に設定
		m_drawColor = GetColorU8(ColorSettings::Red_r, ColorSettings::Red_g, ColorSettings::Red_b, 255);
		break;
	case ColorType::Green: // 障害物の色を緑色に設定
		m_drawColor = GetColorU8(ColorSettings::Green_r, ColorSettings::Green_g, ColorSettings::Green_b, 255);
		break;
	case ColorType::Blue: // 障害物の色を青色に設定
		m_drawColor = GetColorU8(ColorSettings::Blue_r, ColorSettings::Blue_g, ColorSettings::Blue_b, 255);
		break;
	default:
		m_drawColor = GetColorU8(255, 255, 255, 255); // デフォルトは白色
		break;
	}

	// 全頂点の色と法線の設定
	for (int i = 0; i < std::size(m_Vertexs); i++) {
		m_Vertexs[i].dif = m_drawColor; // ディフューズカラー(光の反射色)を白色
		m_Vertexs[i].norm = normal[i / 6]; // 法線ベクトル

		// 各面ごとに法線ベクトルの方向を設定
		if (i % 6 == 0) { m_Vertexs[i].u = 0.0f; m_Vertexs[i].v = 0.0f; }
		else if (i % 6 == 1) { m_Vertexs[i].u = 1.0f; m_Vertexs[i].v = 0.0f; }
		else if (i % 6 == 2) { m_Vertexs[i].u = 0.0f; m_Vertexs[i].v = 1.0f; }
		else if (i % 6 == 3) { m_Vertexs[i].u = 1.0f; m_Vertexs[i].v = 0.0f; }
		else if (i % 6 == 4) { m_Vertexs[i].u = 1.0f; m_Vertexs[i].v = 1.0f; }
		else if (i % 6 == 5) { m_Vertexs[i].u = 0.0f; m_Vertexs[i].v = 1.0f; }
	}

	DrawPolygon3D(m_Vertexs, 12, m_ObstaclePhotoHandle, FALSE); // 12は三角形の数(6面 * 2三角形)
}

// 再配置処理
void Obstacle::Relocation(VECTOR newPosition)
{
	m_Position = newPosition;

	int randColor = GetRand(3); // 0～2の乱数を生成して、障害物の色をランダムに変更する
	switch (randColor)
	{
	case 0: m_ColorType = ColorType::Red; break;
	case 1:  m_ColorType = ColorType::Green; break;
	case 2:  m_ColorType = ColorType::Blue; break;
	default:
		break;
	}
}

// 移動処理
void Obstacle::MovePosition(VECTOR move)
{
	BaseActor::MovePosition(move); // ベースクラスの移動処理を呼び出す
}

// プレイヤーの後ろに行ったかの確認
void Obstacle::CheckBehindPlayer()
{
	//BaseActor::CheckBehindPlayer(); // ベースクラスの確認処理を呼び出す
	if (!p_actorManager) return;
	VECTOR playerPos = p_actorManager->GetPlayerPosition(); // プレイヤーの場所を取得

	float backEdge = m_Position.z + (ObstacleSettings::obstacleRadius / 2.0f); // 障害物の後ろの端

	// 障害物の場所がプレイヤーの地面の端を超えたとき、再配置
	if (playerPos.z > backEdge + GroundSettings::size) {
		float totalLength = GroundSettings::size * GroundSettings::groundMaxZ; // 全長は地面一つ分のサイズと地面の数を掛けたもの

		//Relocation(m_Position.z + totalLength); // 変更前のコード(地面のz座標だけを変更して再配置)
		Relocation(VGet(m_Position.x, m_Position.y, m_Position.z + totalLength));
	}
}
