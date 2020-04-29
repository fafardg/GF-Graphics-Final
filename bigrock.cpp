//
// Created by George on 4/29/20.
//

#include "bigrock.h"
#include "graphics.h"

BigRock::BigRock(double start_x){
    speed = 5;
    height = 75;
    width = 75;
    center_point = {start_x,0};
    reset_corners();
};

void BigRock::reset_corners() {
    corners.clear();
    corners.resize(4);
    // size corners here
    corners[0] = {center_point.x + width/2.0, center_point.y - height/2.0};
    corners[1] = {center_point.x - width/2.0, center_point.y - height/2.0};
    corners[2] = {center_point.x - width/2.0, center_point.y + height/2.0};
    corners[3] = {center_point.x + width/2.0, center_point.y + height/2.0};
}

void BigRock::draw() const {
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.30, 0.05);
    for(int i = 0; i < corners.size(); ++i) {
        draw_point(corners[i]);
    }
    glEnd();
}

void BigRock::fall() {
    center_point = {center_point.x, center_point.y + speed};
    for(int i = 0; i < corners.size(); ++i) {
        corners[i] = {corners[i].x, corners[i].y + speed};
    }
}
