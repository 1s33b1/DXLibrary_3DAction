#pragma once
#include "BaseActor.h"

class Player;
class Ground : public BaseActor
{
public:
	Ground();
	Ground(ActorManager* manager);
	~Ground();
	void Update() override;
	void Draw() override;
	void OnCollision(BaseActor* other) override;
	void Relocation(float zPos);
private:
	int m_GroundPhoto; // ’n–Ê‚Ì‰æ‘œB
};