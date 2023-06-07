#pragma once
#include <list>
#include <string>

namespace MazeGame
{
	class MazeData
	{
	public:
		int m_tiles[9][9];
		int m_treasure[3][2];
		int m_threats[3][3];
		int m_passages[4];
		int m_exit;

		MazeData();
	};
}