#pragma once
#include <utility>
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
		virtual void Draw();
	};
}
