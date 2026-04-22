#pragma once

#include "pch.h"
class BaseActor;

class ActorManager
{
public:
	ActorManager();
	~ActorManager();
	void AllInitialize(); // 全アクターの初期化処理
	void AllUpdate(); // 全アクターの更新処理
	void AllDraw(); // 全アクターの描画処理
	void AllCollision(); // 全アクターの衝突処理
	void AddActor(std::unique_ptr<BaseActor> actor); // アクターをベクター配列に追加する関数
	void ClearActor(); // アクターを削除する関数。ゲームの終了時に使用する
	VECTOR GetPlayerPosition(); // プレイヤーの位置を取得する関数。
private:
	std::vector<std::unique_ptr<BaseActor>> m_Children; // アクターのベクター配列
	int groundCount = 0; // 地面を生成するときに使用するカウンタ。現在は使用していない。代わりに下記のカウンタを使用している
	int groundCountX = 0; // 地面を生成するときに使用するカウンタ(X)
	int groundCountZ = 0; // 地面を生成するときに使用するカウンタ(Z)
	float m_firstGroundPosx = 0.0f; // zの位置は変更しないけど、Xの位置は横に生成する数に応じて変わるから定数から変数に変更
};
