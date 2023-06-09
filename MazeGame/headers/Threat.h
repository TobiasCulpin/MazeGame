#pragma once
#include "MazeEntity.h"

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
namespace MazeGame
{
	class Threat : public MazeEntity
	{
	public:
		int m_type;
		int m_counter;// as in counter-measure
		Threat();
		Threat(std::pair<int, int> pos, int type, int counter, Room* room);
		void Draw(HDC* hdc) override;
		bool Defeat(int action);
	};
}