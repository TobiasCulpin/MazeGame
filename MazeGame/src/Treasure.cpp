#include "Treasure.h"
#include "Room.h"
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
		if (this->m_isHidden) { return; }
		this->m_isHidden = true;
		this->m_room->m_remainingTreasures -= 1;
		this->m_room->m_player.m_totalTreasure += this->m_value;
	}
}