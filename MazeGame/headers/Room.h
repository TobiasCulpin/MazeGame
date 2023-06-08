#pragma once
#include <vector>
#include "Player.h"
#include "Treasure.h"
#include "Threat.h"

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace MazeGame
{
	class Treasure;
	class Threat;
	class MazeData;
	class Maze;

	class Room
	{
	public:
		int m_tiles[9][9];

		std::vector<Treasure> m_treasures;
		std::vector<Threat> m_threats;
		Player m_player;

		unsigned int m_remainingTreasures;
		unsigned int m_remainingThreats;
		unsigned int m_roomIndex;

		std::vector<Room*> m_passages;
		int m_exit;

		MazeData* m_mazeData;
		Maze* m_maze;

		Room(MazeData* mazeData, Maze* maze);
		void AssignPassages();
		void Draw(HDC* hdc);
	};
}