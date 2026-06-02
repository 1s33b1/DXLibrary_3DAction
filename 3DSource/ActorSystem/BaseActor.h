#pragma once
#include "pch.h"
class ActorManager;

class BaseActor
{
public:
	BaseActor();
	BaseActor(ActorManager* manager);
	virtual ~BaseActor();
	virtual void Initialize() = 0; // 初期化処理。純粋仮想関数(実装必須)
	virtual void Update(); // 更新処理
	virtual void Draw() = 0; // 純粋仮想関数(実装必須)
	virtual void OnCollision(BaseActor* other);
	virtual void MovePosition(VECTOR move); // アクターを前方に移動させる関数
	virtual void Relocation(VECTOR newPosition); // アクターを再配置させる関数。引数はベクトルを指しているが今はfloatでZ座標だけで使用している
	virtual void CheckBehindPlayer(); // プレイヤーの後ろに行ったかの確認。

	// アクターの状態を表す列挙型
	enum ActorStatus
	{
		UPDATE, // 更新中
		DEAD, // 死亡
		REST, // 休止(Update、Drawを行わない)
	};

	// 未使用関数
	// 現在、Addメソッドは使用していない。理由としてはアクターマネージャーのAddActorだけで十分だから。
	void Add(std::unique_ptr<BaseActor> newActor);

protected:
	ActorManager* p_actorManager; // アクターマネジャーのポインタ
	ActorStatus m_Status; // アクターの状態
	VECTOR m_Position; // アクターの位置の変数
	VECTOR m_Rotation; // プレイヤーの回転
	std::string m_Tag; // アクターのタグ

	// アクターの色を表す列挙型
	enum ColorType
	{
		Red, // 赤色
		Green, // 緑色
		Blue, // 青色
		None, // 色なし。BaseActorを継承していて、色を使用しないアクターに使用する
	};
	ColorType m_ColorType; // アクターの色の種類を表す変数
	
public:
	// ゲッター関数
	int GetStatus() const { return m_Status; } // アクターのステータスを取得する関数
	VECTOR GetPos() const { return m_Position; } // アクターの場所を返す関数
	std::string GetTag() const { return m_Tag; } // アクターのタグ
	ColorType GetColorType() const { return m_ColorType; } // アクターの色の種類を取得する関数

	// セッター関数
	void SetPos(VECTOR setPosition) { m_Position = setPosition; }
	void SetStatus(ActorStatus status) { m_Status = status; } // アクターのステータスを設定する関数
};
