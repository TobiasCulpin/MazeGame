#include "MazeEntity.h"

namespace MazeGame
{
	MazeEntity::MazeEntity()
	{
		this->m_pos = { 0,0 };
		this->m_isHidden = false;
		this->m_room = nullptr;
	}
	MazeEntity::MazeEntity(std::pair<int, int> pos, Room* room)
	{
		this->m_pos = pos;
		this->m_isHidden = false;
		this->m_room = room;
	}
	void MazeEntity::Draw(HDC* hdc)
	{
		//Cannot draw base class
	}
}