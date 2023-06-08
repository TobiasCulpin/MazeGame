#pragma once
#include <vector>
#include "Room.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace MazeGame
{
	class Room;
	class GameData;
	class Maze
	{
	public:
		std::vector<Room> m_rooms;
		Maze(GameData* gameData);
		void Draw(HDC hdc);
	};
}
