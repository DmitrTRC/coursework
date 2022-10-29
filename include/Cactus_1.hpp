//
// Created by Dmitry Morozov on 29/10/22.
//

#ifndef COURSEWORK_DEV_CACTUS_1_HPP
#define COURSEWORK_DEV_CACTUS_1_HPP

#include "Movable_Rect.hpp"

class Cactus1 : public MovableRect {
public:
    Cactus1(int, int);

    ~Cactus1() override = default;

    void move() override;
};


#endif //COURSEWORK_DEV_CACTUS_1_HPP
