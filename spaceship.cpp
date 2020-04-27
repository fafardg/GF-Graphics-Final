//
// Created by George on 4/27/20.
//

#include <cmath>
#include "spaceship.h"
#include "graphics.h"

/* Private helper methods*/
void Spaceship::reset_corners() {
    corners.clear();
    corners.resize(6);
    // size the corners here
    corners[0] = {center_point.x, center_point.y - (height/2.0)};
    corners[1] = {center_point.x - (width/2.0), center_point.y + (height/2.0)};
    corners[2] = {center_point.x, center_point.y};
    corners[3] = {center_point.x + (width/2.0), center_point.y + (height/2.0)};
    corners[4] = {center_point.x, center_point.y - (height/2.0)};
    corners[5] = {center_point.x, center_point.y};
}

void Spaceship::draw_point(const point &p) const {
    glVertex2f(p.x, p.y);
}

/* Public methods */
Spaceship::Spaceship() {
    center_point = {500, 500};
    width = 50;
    height = 50;
    reset_corners();
}

Spaceship::Spaceship(point center_point, unsigned int width, unsigned int height) {
    this->center_point = center_point;
    this->width = width;
    this->height = height;
    reset_corners();
}

void Spaceship::draw() const {
    glBegin(GL_TRIANGLES);

    // Left side
    glColor3f(1, 1, 0);
    draw_point(corners[0]);
    draw_point(corners[1]);
    draw_point(corners[2]);
    // Right side
    draw_point(corners[3]);
    draw_point(corners[4]);
    draw_point(corners[5]);

    glEnd();
}

void Spaceship::move(double delta_x, double delta_y) {
    center_point.x += delta_x;
    center_point.y += delta_y;
    for (point &p : corners) {
        p.x += delta_x;
        p.y += delta_y;
    }
}