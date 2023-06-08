#include "GameData.h"
#include "MazeData.h"
namespace MazeGame
{
	GameData::GameData()
	{
		this->m_mazes.push_back(MazeData(this));
		this->m_mazes.push_back(MazeData(this));
		this->m_mazes.push_back(MazeData(this));
	}
}