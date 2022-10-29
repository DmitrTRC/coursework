//
// Created by Dmitry Morozov on 29/10/22.
//

#ifndef COURSEWORK_DEV_MOVABLE_RECT_HPP
#define COURSEWORK_DEV_MOVABLE_RECT_HPP

#include "Drawable_Rect.hpp"

class MovableRect : public DrawableRect {
public:
    MovableRect(int, int, const std::string &);
    virtual ~MovableRect() = default;

    virtual void move() = 0;
};


#endif //COURSEWORK_DEV_MOVABLE_RECT_HPP
