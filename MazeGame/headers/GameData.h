#pragma once
#include "MazeData.h"
#include "Vector"

namespace MazeGame
{
	class GameData
	{
	public:
		std::vector<MazeData> m_mazes;
		GameData();
	};
}