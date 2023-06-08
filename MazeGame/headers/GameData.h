#pragma once
#include <Vector>
#include "MazeData.h"


namespace MazeGame
{
	class GameData
	{
	public:
		std::vector<MazeData> m_mazes = {};
		GameData();
	};
}