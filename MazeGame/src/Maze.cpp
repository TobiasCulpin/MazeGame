#include "Maze.h"
#include "Room.h"
#include "GameData.h"
#include "MazeData.h"
#include "Globals.h"
namespace MazeGame
{
	Maze::Maze(GameData* gameData)
	{
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms.push_back(Room(&(gameData->m_mazes[i]), this));
		}
		//This must be done after all rooms are created
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms[i].AssignPassages();
		}
	}
	void Maze::Draw(HDC hdc)
	{
		//Background
		Graphics graphics(hdc);
		Pen pen(Color(255, 0, 0, 255));
		SolidBrush solidBrush(Color(255, 30, 10, 130));
		
		graphics.FillRectangle(&solidBrush, 0, 0, MG_WINDOW_WIDTH, MG_WINDOW_HEIGHT);
		//Walls
		//Passages
		//Treasure
		//Threats
		//Player
	}
}
