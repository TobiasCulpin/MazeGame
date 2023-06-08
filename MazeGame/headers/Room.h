#pragma once
#include <vector>
#include "Player.h"


namespace MazeGame
{
	class Treasure;
	//class Threat;
	class MazeData;

	class Room
	{
	public:
		int m_tiles[9][9];

		std::vector<Treasure> m_treasures;
		//std::vector<Threat> m_threats;
		Player m_player;

		unsigned int m_remainingTreasures;
		unsigned int m_remainingThreats;
		unsigned int m_roomIndex;

		// passages
		// exit
		// TODO a lot more

		Room();
		Room(MazeData* data);
	};
}