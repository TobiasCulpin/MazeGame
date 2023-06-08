#include "Maze.h"
#include "Room.h"
#include "GameData.h"
#include "MazeData.h"
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
	void Maze::Draw()
	{

	}
}
