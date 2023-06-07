#include "GameData.h"
namespace MazeGame
{
	GameData::GameData()
	{
		this->m_mazes.push_back(MazeData());
		this->m_mazes.push_back(MazeData());
		this->m_mazes.push_back(MazeData());
	}
}