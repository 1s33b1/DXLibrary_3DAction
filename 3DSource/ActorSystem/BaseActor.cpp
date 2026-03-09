///
/// プレイヤー、敵、障害物すべてに継承をさせるクラス 
///
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

void BaseActor::AddActor(std::unique_ptr<BaseActor>)
{

}
void BaseActor::RemoveActor(BaseActor* actor)
{

}
