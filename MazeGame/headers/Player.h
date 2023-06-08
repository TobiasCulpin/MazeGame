#pragma once
#include "MazeEntity.h"
#include <utility>

namespace MazeGame
{
    class Player : public MazeEntity
    {
    public:
        int m_totalTreasure;
        int m_totalThreats;

        Player();
        Player(std::pair<int, int> pos, Room* room);
        void Draw(HDC* hdc) override;
        void Move(int direction);
    };
}
