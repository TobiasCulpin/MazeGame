#pragma once
#include "MazeEntity.h"
#include <utility>

namespace MazeGame
{
    class Player : public MazeEntity
    {
    public:
        int m_totalTreasure;

        Player();
        Player(std::pair<int, int> pos, int totalTreasure, Room* room);
        void Draw() override;
    };
}
