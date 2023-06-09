#include "Threat.h"
#include "Room.h"
#include "Globals.h"
#include "Maze.h"
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

			LPCWSTR path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Threat.png";;
			switch (this->m_type)
			{
			case 0:
				path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Bomb.png";
				break;
			case 1:
				path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Monster.png";
				break;
			case 2:
				path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Spikes.png";
				break;
			case 3:
				path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Defeated.png";
				break;
			}
			Image image(path);
			Point point = Point(MG_ROOM_X + 12 + (64 * this->m_pos.first),
				MG_ROOM_Y + 12 + (64 * this->m_pos.second));
			graphics.DrawImage(&image, point);
		}
	}
	void Threat::Defeat(int action)
	{
		if (action == this->m_type)
		{
			this->m_type = 3;//defeated
		}
	}
}