#include "Player.h"
#include "Globals.h"
#include "Room.h"
#include "Treasure.h"
#include "MazeEntity.h"
#include "Maze.h"
namespace MazeGame
{
	Player::Player() : MazeEntity()
	{
		this->m_totalTreasure = 0;
		this->debug = "no args";
	}
	Player::Player(std::pair<int, int> pos, Room* room) : MazeEntity(pos, room)
	{
		this->debug = "normal";
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
		int dY = (direction - 1) % 2;
		int newPos;
		try
		{
			newPos = m_room->m_tiles[this->m_pos.second + dY][this->m_pos.first + dX];
			if (this->m_pos.first + dX < 0 || this->m_pos.first + dX > 8 || this->m_pos.second + dY < 0 || this->m_pos.second + dY > 8) { newPos = 0; }
		}
		catch (...)
		{
			newPos = 0;
		}
		switch (newPos)
		{
		case 0://Wall
		{
			//Passages
			int pass = 0;
			if (this->m_pos.first == 4 && this->m_pos.second == 0 && dY == -1 && this->m_room->m_passages[0] != -1)//North Passage
			{
				this->m_pos = std::pair<int, int>(4, 8);
				this->m_room->m_maze->SetActiveRoom(this->m_room->m_passages[0]);
			}
			else if (this->m_pos.first == 8 && this->m_pos.second == 4 && dX == 1 && this->m_room->m_passages[1] != -1)//East Passage
			{
				this->m_pos = std::pair<int, int>(0, 4);
				this->m_room->m_maze->SetActiveRoom(this->m_room->m_passages[1]);
			}
			else if (this->m_pos.first == 4 && this->m_pos.second == 8 && dY == 1 && this->m_room->m_passages[2] != -1)//South Passage
			{
				this->m_pos = std::pair<int, int>(4, 0);
				this->m_room->m_maze->SetActiveRoom(this->m_room->m_passages[2]);
			}
			else if (this->m_pos.first == 0 && this->m_pos.second == 4 && dX == -1 && this->m_room->m_passages[3] != -1)//West Passage
			{
				this->m_pos = std::pair<int, int>(8, 4);
				this->m_room->m_maze->SetActiveRoom(this->m_room->m_passages[3]);
			}
		}
		break;
		case 1://Path
		{
			this->m_pos = std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY);
		}
		break;
		case 2://Treasure
		{
			for (int i = 0; i < 3; i++)
			{
				if (this->m_room->m_treasures[i].m_pos == std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY))
				{
					m_room->m_treasures[i].Claim();

					m_room->m_tiles[this->m_pos.second + dY][this->m_pos.first + dX] = 1;
					this->m_pos = std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY);
					this->m_totalTreasure += this->m_room->m_treasures[i].m_value;
					this->m_room->m_remainingTreasures -= 1;
				}
			}
		}
		break;
		case 3://Threat
		{
			for (int i = 0; i < 3; i++)
			{
				if (this->m_room->m_threats[i].m_pos == std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY))
				{
					if (this->m_room->m_threats[i].m_type == 3 or this->m_room->m_threats[i].m_isHidden != false)
					{
						m_room->m_tiles[this->m_pos.second + dY][this->m_pos.first + dX] = 1;
						this->m_pos = std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY);
						this->m_totalThreats += 1;
						this->m_room->m_remainingThreats -= 1;
						this->m_room->m_threats[i].m_isHidden = true;
					}
				}
			}
		}
		break;
		case 4://Coin
		{
			this->m_pos = std::pair<int, int>(this->m_pos.first + dX, this->m_pos.second + dY);//Treat as path
		}
		}
	}
	void Player::Deposit()
	{
		if (this->m_totalTreasure > 0 && m_room->m_tiles[this->m_pos.second][this->m_pos.first] != 4)
		{
			m_room->m_tiles[this->m_pos.second][this->m_pos.first] = 4;//Coin
			this->m_totalTreasure -= 1;
		}
	}
	void Player::DetectThreat(int counter)
	{
		int x, y, tx, ty;
		for (int i = 0; i < 3; i++)
		{
			x = this->m_pos.first;
			y = this->m_pos.second;
			tx = this->m_room->m_threats[i].m_pos.first;
			ty = this->m_room->m_threats[i].m_pos.second;
			if ((x == tx && y + 1 == ty) || (x == tx && y - 1 == ty) || (x + 1 == tx && y == ty) || (x - 1 == tx && y == ty))//adjacent
			{
				this->m_room->m_threats[i].Defeat(counter);
			}
		}
	}
}