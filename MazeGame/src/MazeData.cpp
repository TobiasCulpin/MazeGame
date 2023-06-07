#include "MazeData.h"
namespace MazeGame
{
	MazeData::MazeData()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->m_tiles[i][j] = 0;
			}
		}
		this->m_tiles[0][4] = 1;//passage tiles
		this->m_tiles[4][0] = 1;
		this->m_tiles[4][8] = 1;
		this->m_tiles[8][4] = 1;

		this->m_treasure[0][0] = -1;
		this->m_treasure[0][1] = 0;
		this->m_treasure[1][0] = -1;
		this->m_treasure[1][1] = 0;
		this->m_treasure[2][0] = -1;
		this->m_treasure[2][1] = 0;

		this->m_threats[0][0] = -1;
		this->m_threats[0][1] = 0;
		this->m_threats[0][2] = 0;
		this->m_threats[1][0] = -1;
		this->m_threats[1][1] = 0;
		this->m_threats[1][2] = 0;
		this->m_threats[2][0] = -1;
		this->m_threats[2][1] = 0;
		this->m_threats[2][2] = 0;

		this->m_passages[0] = -1;
		this->m_passages[0] = -1;
		this->m_passages[0] = -1;
		this->m_passages[0] = -1;

		this->m_exit = -1;
	}
}