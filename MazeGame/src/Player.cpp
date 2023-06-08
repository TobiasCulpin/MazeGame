#include "Player.h"
#include "Globals.h"
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
}