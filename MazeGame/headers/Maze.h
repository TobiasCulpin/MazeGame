#pragma once
#include <vector>
#include "Room.h"

namespace MazeGame
{
	class Room;
	class GameData;
	class Maze
	{
	public:
		std::vector<Room> m_rooms;
		Maze(GameData* gameData);
		void Draw();
	};
}
