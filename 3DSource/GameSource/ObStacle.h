#pragma once
#include "pch.h"
#include "BaseActor.h"

class Obstacle : public BaseActor
{
public:
	Obstacle();
	Obstacle(ActorManager* manager);
	virtual ~Obstacle();
	virtual void Initialize() override; // 初期化処理
	virtual void Update() override; // 更新処理
	virtual void Draw() override; // 描画処理
	virtual void Relocation(VECTOR newPosition) override; // 再配置処理
	virtual void MovePosition(VECTOR move) override; // 移動処理
	virtual void CheckBehindPlayer() override; // プレイヤーの後ろに行ったかの確認。
	void DrawCube(VECTOR CENTER, float SIZE); // 正方形を作る関数
private:
	VERTEX3D m_Vertexs[36]; // 障害物の頂点配列
	//VERTEX3D m_Vertexs[6]; // とりあえず一面だけ作るから頂点を6個に
	int m_ObstaclePhotoHandle; // 障害物のテクスチャハンドル
	//unsigned int m_drawColor; // アクターの描画色を表す変数
	COLOR_U8 m_drawColor;
};