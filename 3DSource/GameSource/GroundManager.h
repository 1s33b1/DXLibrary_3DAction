#pragma once
#include <memory>
#include <vector>
class Ground;
class GroundManager
{
public:
	GroundManager();
	~GroundManager();
	void AllUpdate();
	void AllDraw();
	void AddGround(std::unique_ptr<Ground> ground);
private:
	std::vector<std::unique_ptr<Ground>> m_groundChildren;
	const int m_groundMax = 
};
