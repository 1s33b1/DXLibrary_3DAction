#include "GroundManager.h"
#include "Ground.h"

GroundManager::GroundManager()
{
}

GroundManager::~GroundManager()
{

}

void GroundManager::AllUpdate()
{
	for (auto& ground : m_groundChildren) {
		ground->Update();
	}
}

void GroundManager::AllDraw()
{
	for (auto& ground : m_groundChildren) {
		ground->Draw();
	}
}

// ’n–Ê‚Ì’Ç‰Á
void GroundManager::AddGround(std::unique_ptr<Ground> ground)
{
	m_groundChildren.push_back(std::move(ground));
}

