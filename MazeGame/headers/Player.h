#pragma once
#include "MazeEntity.h"
#include <utility>

namespace MazeGame
{
    class Player : public MazeEntity
    {
    private:
        const char* debug;
    public:
        int m_totalTreasure;
        int m_totalThreats;

        Player();
        Player(std::pair<int, int> pos, Room* room);
        void Draw(HDC* hdc) override;
        void Move(int direction);
        void Deposit();
        void DetectThreat(int counter);//as in counter-measure
    };
}
