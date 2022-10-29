//
// Created by Dmitry Morozov on 29/10/22.
//

#include "Cactus_1.hpp"
#include "Movable_Rect.hpp"

Cactus1::Cactus1(int y, int x) : MovableRect(y, x, "../textures/cactus_big.trx") {}

void Cactus1::move() {

    _x -= 1;
}
