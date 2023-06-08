#include "Room.h"
//#include "Player.h" - do not include for some reason
#include "MazeData.h"
#include "Treasure.h"
//#include "Threat"
#include <Random>
namespace MazeGame
{
	Room::Room()
	{

	}
	Room::Room(MazeData* data)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->m_tiles[i][j] = data->m_tiles[i][j];
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			int y = std::floor(data->m_treasure[i][0] / 9);
			int x = data->m_treasure[i][0] - (9 * y);
			this->m_treasures.push_back(Treasure({ x,y }, data->m_treasure[i][1], this));
		}
		

		// TODO this->m_threats = threats;
		//this->m_player = Player();
	}
}