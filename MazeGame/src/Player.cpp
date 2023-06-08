#include "Player.h"
namespace MazeGame
{
	Player::Player() : MazeEntity()
	{
		this->m_totalTreasure = 0;
	}
	Player::Player(std::pair<int, int> pos, int totalTreasure, Room* room) : MazeEntity(pos, room)
	{
		this->m_totalTreasure = totalTreasure;
	}

	void Player::Draw()
	{
		//TODO
	}
}