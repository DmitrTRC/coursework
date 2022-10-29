//
// Created by Dmitry Morozov on 29/10/22.
//

#ifndef COURSEWORK_DEV_TRX_HPP
#define COURSEWORK_DEV_TRX_HPP

#include "Movable_Rect.hpp"

class TRX : public MovableRect {
public:
    TRX(int, int, const std::string &);

    void jump();

    void move() override;

    [[nodiscard]] bool isJump() const;


private:
    int _floor_level;
    int _speed;
    bool _isJumping;
};


#endif //COURSEWORK_DEV_TRX_HPP
