#pragma once
class BaseActor
{
public:
	BaseActor();
	~BaseActor();
	virtual void Update();
	virtual void Draw();
	virtual void OnCollision(BaseActor* other);
private:

};
