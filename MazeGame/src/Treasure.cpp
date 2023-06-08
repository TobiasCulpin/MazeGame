#include "Treasure.h"
namespace MazeGame
{
	Treasure::Treasure() : MazeEntity()
	{
		this->m_value = 0;
	}
	Treasure::Treasure(std::pair<int, int> pos, int value, Room* room) : MazeEntity(pos, room)
	{
		this->m_value = value;
	}
	void Treasure::Draw()
	{
		//TODO
	}
	void Treasure::Claim()
	{
		//TODO
	}
}