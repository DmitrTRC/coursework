//
// Created by Dmitry Morozov on 29/10/22.
//

#include "Trx.hpp"

TRX::TRX(int y, int x, const std::string &texture) : MovableRect(y, x, texture) {

    _speed = 0;
    _isJumping = false;
    _floor_level = y;
}

void TRX::jump() {

    if (!_isJumping) {
        _isJumping = true;
        _speed = 1;
    }
}


void TRX::move() {

    _y -= _speed;
    if (_y > (_floor_level - 1)) {
        _speed = 0;
        _isJumping = false;
    }

    if (_y < 5) {
        _speed = _speed * -1;
    }

}

bool TRX::isJump() const {

    return _isJumping;
}

