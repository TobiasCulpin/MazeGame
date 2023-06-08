#pragma once
#include "MazeEntity.h"
namespace MazeGame
{
	class Threat : MazeEntity
	{
	public:
		int m_type;
		int m_counter;// as in counter-measure
		Threat();
		Threat(std::pair<int, int> pos, int type, int counter, Room* room);
		void Draw() override;
		bool Defeat(int action);
	};
}