#include "Maze.h"
#include "Room.h"
#include "GameData.h"
#include "MazeData.h"
#include "Globals.h"
#include <string>


#include <Random>
namespace MazeGame
{
	Maze::Maze(GameData* gameData)
	{
		this->m_activeRoom = 0;
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms.push_back(Room(&(gameData->m_mazes[i]), this));
		}
		//This must be done after all rooms are created
		for (int i = 0; i < 3; i++)
		{
			this->m_rooms[i].AssignPassages();
		}

		//Player
		int x, y;
		int z = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 1);
		while (true)
		{
			x = std::floor(9 * dis(gen));
			y = std::floor(9 * dis(gen));
			if (this->m_rooms[this->m_activeRoom].m_tiles[y][x] != 0) { break; }
			z++;
			if (z >= 80)
			{
				break;
				//TODO Throw error - space not found
			}
		}
		this->m_player = Player({ x, y }, &this->m_rooms[this->m_activeRoom]);
	}
	void Maze::Draw(HDC* hdc)
	{
		//Background
		Graphics graphics(*hdc);
		SolidBrush solidBrush(Color(255, 30, 10, 130));
		
		graphics.FillRectangle(&solidBrush, 0, 0, MG_WINDOW_WIDTH, MG_WINDOW_HEIGHT);
		//Room
		this->m_rooms[this->m_activeRoom].Draw(hdc);
		//Player
		this->m_player.Draw(hdc);
		//Menu
		SolidBrush menuColor(Color(255, 200, 200, 200));
		graphics.FillRectangle(&menuColor, MG_INFO_X, MG_INFO_Y, MG_INFO_SIZE, MG_INFO_SIZE);
		FontFamily fontFamily(L"Arial");
		Font font(&fontFamily, 16, FontStyleRegular, UnitPixel);
		SolidBrush black(Color(2555, 0, 0, 0));

		PointF p1(MG_INFO_X + 25, MG_INFO_Y + 25);
		graphics.DrawString(L"Total Treasure: ", -1, &font, p1, &black);

		PointF p2(MG_INFO_X + 160, MG_INFO_Y + 25);
		graphics.DrawString(std::to_wstring(this->m_player.m_totalTreasure).c_str(), -1, &font, p2, &black);

		PointF p3(MG_INFO_X + 25, MG_INFO_Y + 50);
		graphics.DrawString(L"Threats Defeated: ", -1, &font, p3, &black);

		PointF p4(MG_INFO_X + 160, MG_INFO_Y + 50);
		graphics.DrawString(std::to_wstring(this->m_player.m_totalThreats).c_str(), -1, &font, p4, &black);

		//Other TODO
	}

	void Maze::SetActiveRoom(int roomIndex)
	{
		if (roomIndex == -1) { return; }//no passage
		this->m_activeRoom = roomIndex;
		this->m_player.m_room = &this->m_rooms[this->m_activeRoom];
	}
}
