//
// Created by Dmitry Morozov on 23/10/22.
//

#include "Drawable_Rect.hpp"

#include <fstream>


DrawableRect::DrawableRect(int y, int x, const std::string &_texture_file) : Drawable(y, x) {

    _loadTexture(_texture_file);

}

void DrawableRect::_loadTexture(const std::string &file_name) {

    std::ifstream texture_file(file_name);
    if (!texture_file.is_open()) {
        throw std::runtime_error("Can't open texture file " + file_name);
    }
    //Fill texture vector
    std::string line;
    while (std::getline(texture_file, line)) {
        _rect_icon.push_back(line);
    }

    _height = static_cast<int>(_rect_icon.size());

    //set max width
    for (auto &item: _rect_icon) {
        if (item.size() > _width) {
            _width = static_cast<int>(item.size());
        }
    }

}


void DrawableRect::mvAdd(WINDOW *window) {

    auto y = _y;
    auto x = _x;

    for (const auto &line: _rect_icon) {
        mvwaddstr(window, y, x, line.c_str());
        y++;
    }

}

void DrawableRect::clear(WINDOW *window) {

    auto y = _y;
    auto x = _x;


    for (const auto &line: _rect_icon) {
        mvwaddstr(window, y, x, std::string(_width + 1, ' ').c_str());
        y++;
    }

}

int DrawableRect::getHeight() const {

    return _height;

}

int DrawableRect::getWidth() const {

    return _width;

}


