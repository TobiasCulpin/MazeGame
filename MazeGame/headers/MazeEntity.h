#pragma once
#include <utility>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
namespace MazeGame
{
	class Room;

	class MazeEntity
	{
	public:
		std::pair<int, int> m_pos;
		bool m_isHidden;
		Room* m_room;

		MazeEntity();
		MazeEntity(std::pair<int, int> pos, Room* room);
		virtual void Draw(HDC* hdc);
	};
}
