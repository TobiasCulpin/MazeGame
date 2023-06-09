#include "Room.h"
//#include "Player.h" - do not include for some reason
#include "MazeData.h"
//#include "Treasure.h" - do not include for some reason
//#include "Threat.h" - do not include for some reason
#include "GameData.h"
#include "Maze.h"
#include "Globals.h"


namespace MazeGame
{
	Room::Room(MazeData* mazeData, Maze* maze)
	{
		this->m_mazeData = mazeData;
		this->m_maze = maze;

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
		
		//Exit
		this->m_exit = mazeData->m_exit;

		
	}

	void Room::AssignPassages()
	{
		for (int i = 0; i < 4; i++)//Passages  0=North, 1=East, 2=South, 3=West
		{
			int room = this->m_mazeData->m_passages[i];
			if (room >= 0)
			{
				this->m_passages.push_back(& (m_maze->m_rooms[room]));
			}
		}
	}
	void Room::Draw(HDC* hdc)
	{
		//Background
		Graphics graphics(*hdc);
		SolidBrush mediumGrey(Color(255, 70, 70, 70));

		graphics.FillRectangle(&mediumGrey, MG_ROOM_X, MG_ROOM_Y, MG_ROOM_SIZE, MG_ROOM_SIZE);

		//Tiles
		SolidBrush lightGrey(Color(255, 200, 200, 200));
		SolidBrush darkGrey(Color(255, 50, 50, 50));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (this->m_tiles[i][j] == 0)
				{
					graphics.FillRectangle(&darkGrey, MG_ROOM_X + 12 + (64 * j), MG_ROOM_Y + 12 + (64 * i), 64, 64);
				}
				else
				{
					graphics.FillRectangle(&lightGrey, MG_ROOM_X + 12 + (64 * j), MG_ROOM_Y + 12 + (64 * i), 64, 64);
				}
			}
		}

		//Treasures & Threats
		for (int i = 0; i < 3; i++)
		{
			this->m_treasures[i].Draw(hdc);
			this->m_threats[i].Draw(hdc);
		}
	}
}