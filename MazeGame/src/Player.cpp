#include "Player.h"
#include "Globals.h"
#include "Room.h"
namespace MazeGame
{
	Player::Player() : MazeEntity()
	{
		this->m_totalTreasure = 0;
	}
	Player::Player(std::pair<int, int> pos, Room* room) : MazeEntity(pos, room)
	{
		this->m_totalTreasure = 0;
	}

	void Player::Draw(HDC* hdc)
	{
		Graphics graphics(*hdc);

		LPCWSTR path = L"C:\\Users\\tculpin\\source\\repos\\MazeGame\\MazeGame\\res\\Player.png";
		Image image(path);
		Point point = Point(MG_ROOM_X + 12 + (64 * this->m_pos.first),
			MG_ROOM_Y + 12 + (64 * this->m_pos.second));
		graphics.DrawImage(&image, point);
	}

	void Player::Move(int direction)
	{
		int dX = (direction % 2) * (2 - direction);
		int dY = (-(direction - 1) % 2);
		int newPos;
		try
		{
			newPos = this->m_room->m_tiles[this->m_pos.first + dX][this->m_pos.second + dY];
		}
		catch (...)
		{
			newPos = 0;
		}
		switch (newPos)
		{
		case 0://Wall
		{

		}
		break;
		case 1://Path
		{
			this->m_pos = std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY);
		}
		break;
		case 2://TODO
		{

		}
		break;
		case 3://TODO
		{

		}
		break;
		}
	}
}