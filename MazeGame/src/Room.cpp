#include "Room.h"
//#include "Player.h" - do not include for some reason
#include "MazeData.h"
//#include "Treasure.h" - do not include for some reason
//#include "Threat.h" - do not include for some reason
#include "GameData.h"
#include "Maze.h"

#include <Random>

namespace MazeGame
{
	Room::Room(MazeData* mazeData, Maze* maze)
	{
		for (int i = 0; i < 9; i++)//Tiles
		{
			for (int j = 0; j < 9; j++)
			{
				this->m_tiles[i][j] = mazeData->m_tiles[i][j];
			}
		}

		for (int i = 0; i < 3; i++)//Treasure
		{
			int y = std::floor(mazeData->m_treasure[i][0] / 9);
			int x = mazeData->m_treasure[i][0] - (9 * y);
			this->m_treasures.push_back(Treasure({ x, y }, mazeData->m_treasure[i][1], this));
		}

		for (int i = 0; i < 3; i++)//Threats
		{
			int y = std::floor(mazeData->m_threats[i][0] / 9);
			int x = mazeData->m_threats[i][0] - (9 * y);
			this->m_threats.push_back(Threat({x,y}, mazeData->m_threats[i][1], mazeData->m_threats[i][2], this));
		}
		for (int i = 0; i < 4; i++)//Passages  0=North, 1=East, 2=South, 3=West
		{
			int room = mazeData->m_passages[i];
			if (room >= 0)
			{
				this->m_passages[i] = &(maze->m_rooms[room]);
			}
		}


		//Player
		int x, y;
		int z = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 1);
		while (true)
		{
			x = std::floor(9 * dis(gen));
			y = std::floor(9 * dis(gen));
			if (this->m_tiles[y][x] != 0) { break; }
			z++;
			if (z >= 80)
			{
				break;
				//TODO Throw error - space not found
			}
		}
		this->m_player = Player({ x, y }, this);
	}
}