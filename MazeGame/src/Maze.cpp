#include "Maze.h"
#include "Room.h"
#include "GameData.h"
#include "MazeData.h"
#include "Globals.h"


#include <Random>
namespace MazeGame
{
	Maze::Maze(GameData* gameData)
	{
		this->m_activeRoom = 0;
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms.push_back(Room(&(gameData->m_mazes[i]), this));
		}
		//This must be done after all rooms are created
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms[i].AssignPassages();
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
			if (this->m_rooms[this->m_activeRoom].m_tiles[y][x] != 0) { break; }
			z++;
			if (z >= 80)
			{
				break;
				//TODO Throw error - space not found
			}
		}
		this->m_player = Player({ x, y }, &this->m_rooms[this->m_activeRoom]);
	}
	void Maze::Draw(HDC* hdc)
	{
		//Background
		Graphics graphics(*hdc);
		SolidBrush solidBrush(Color(255, 30, 10, 130));
		
		graphics.FillRectangle(&solidBrush, 0, 0, MG_WINDOW_WIDTH, MG_WINDOW_HEIGHT);
		//Maze
		this->m_rooms[this->m_activeRoom].Draw(hdc);
		//Player
		this->m_player.Draw(hdc);
		//Other TODO
	}
}
