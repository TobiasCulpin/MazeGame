#pragma once
#include <vector>
#include "Room.h"
#include "Player.h"
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
		int m_activeRoom;
		std::vector<Room> m_rooms;
		Player m_player;

		Maze(GameData* gameData);
		void Draw(HDC* hdc);
		void SetActiveRoom(int roomIndex);
	};
}
