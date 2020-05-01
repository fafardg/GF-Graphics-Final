//
// Created by George on 4/27/20.
//
#include "falling_stuff.h"
#include "graphics.h"
#include <iostream>

/* Helper functions */

void FallingStuff::draw_point(const point &p) const {
    glVertex2f(p.x, p.y);
}

// empty
void FallingStuff::reset_corners() {
    // reset corners
    corners.clear();
    corners.resize(0);
}

FallingStuff::FallingStuff() {
    speed = 0;
    width = 0;
    height = 0;
    center_point = {0,0};
}
FallingStuff::FallingStuff(int speed, int width, int height, point center_point) {
    this->speed = speed;
    this->width = width;
    this->height = height;
    this->center_point = center_point;
}

void FallingStuff::draw() const {
    draw_point(center_point);
}


void FallingStuff::fall() {
    cout << "why" << endl;
}

double FallingStuff::get_y() const {
    return center_point.y;
}

int FallingStuff::get_area() const {
    return height * width;
}

int FallingStuff::get_height() const {
    return height;
}

int FallingStuff::get_width() const {
    return width;
}

point FallingStuff::get_corner() const {
    point corner = corners[0];
    return corner;
}