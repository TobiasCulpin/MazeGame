#pragma once
#include "MazeEntity.h"
#include <cmath>

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

namespace MazeGame
{
	class Room;

	class Treasure : public MazeEntity
	{
	public:
		int m_value;
		Treasure();
		Treasure(std::pair<int, int> pos, int value, Room* room);
		void Draw(HDC* hdc) override;
		void Claim();
	};
}
