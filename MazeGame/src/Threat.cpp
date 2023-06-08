#include "Threat.h"
#include "Room.h"
#include "Globals.h"
namespace MazeGame
{
	Threat::Threat() : MazeEntity()
	{
		this->m_type = 0;
		this->m_counter = 0;
	}
	Threat::Threat(std::pair<int, int> pos, int type, int counter, Room* room) : MazeEntity(pos, room)
	{
		this->m_type = type;
		this->m_counter = counter;
	}
	
	void Threat::Draw(HDC* hdc)
	{
		if (this->m_pos.second > 0 && this->m_isHidden == false)
		{
			Graphics graphics(*hdc);

			LPCWSTR path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Threat.png";
			Image image(path);
			Point point = Point(MG_ROOM_X + 12 + (64 * this->m_pos.first),
				MG_ROOM_Y + 12 + (64 * this->m_pos.second));
			graphics.DrawImage(&image, point);
		}
	}
	bool Threat::Defeat(int action)
	{
		this->m_isHidden = action == this->m_counter;
		this->m_room->m_remainingThreats -= 1;
		this->m_room->m_player.m_totalThreats += 1;
		return this->m_isHidden;
	}
}