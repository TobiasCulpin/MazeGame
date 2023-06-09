#include "Treasure.h"
#include "Room.h"
#include "Globals.h"
#include "Maze.h"
#include <string>

namespace MazeGame
{
	Treasure::Treasure() : MazeEntity()
	{
		this->m_value = 0;
	}
	Treasure::Treasure(std::pair<int, int> pos, int value, Room* room) : MazeEntity(pos, room)
	{
		this->m_value = value;
	}
	void Treasure::Draw(HDC* hdc)
	{
		if (this->m_pos.second > 0 && this->m_isHidden == false)
		{
			Graphics graphics(*hdc);

			LPCWSTR path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Treasure.png";
			Image image(path);
			Point point = Point(MG_ROOM_X + 12 + (64 * this->m_pos.first),
				MG_ROOM_Y + 12 + (64 * this->m_pos.second));
			graphics.DrawImage(&image, point);
		}
	}
	void Treasure::Claim()
	{
		if (this->m_isHidden) { return; }
		this->m_isHidden = true;
		//this->m_room->m_remainingTreasures -= 1;
		//this->m_room->m_maze->m_player.m_totalTreasure += this->m_value;
	}
}