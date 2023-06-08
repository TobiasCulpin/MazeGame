#pragma once
#include "MazeEntity.h"
#include <cmath>


namespace MazeGame
{
	class Room;

	class Treasure : MazeEntity
	{
	public:
		int m_value;
		Treasure();
		Treasure(std::pair<int, int> pos, int value, Room* room);
		void Draw() override;
		void Claim();
	};
}
