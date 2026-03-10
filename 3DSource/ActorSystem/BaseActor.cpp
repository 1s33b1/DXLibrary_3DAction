///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
/// Update():毎フレーム呼び出す更新関数。アクターの状態を更新する際に使用。
/// Draw():毎フレーム呼び出す描画関数。アクターの描画を行う際に使用。
/// OnCollision():アクター同士が衝突した際に呼び出す関数。衝突処理を行う際に使用。
#include"BaseActor.h"

// コンストラクタ
BaseActor::BaseActor()
	:m_Tag("NoName")
{

}

// デストラクタ
BaseActor::~BaseActor()
{

}

// 更新関数
void BaseActor::Update()
{
}

// 衝突時処理
void BaseActor::OnCollision(BaseActor* other)
{

}
