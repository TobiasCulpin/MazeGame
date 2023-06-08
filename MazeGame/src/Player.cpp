#include "Player.h"
namespace MazeGame
{
	Player::Player() : MazeEntity()
	{
		this->m_totalTreasure = 0;
	}
	Player::Player(std::pair<int, int> pos, Room* room) : MazeEntity(pos, room)
	{
		this->m_totalTreasure = 0;
	}

	void Player::Draw()
	{
		//TODO
	}
}