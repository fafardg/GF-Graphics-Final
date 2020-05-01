//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_SPACESHIP_H
#define GF_GRAPHICS_FINAL_SPACESHIP_H

#include <vector>
using namespace std;

// struct for a point with x,y coordinates
struct point {
    double x;
    double y;
};

class Spaceship {
private:
    point center_point;
    vector<point> corners;
    unsigned int width;
    unsigned int height;

    bool destroyed = false;

    // helper functions
    void reset_corners();
    void draw_point(const point &p) const;
    void death_corners();

public:
    // Public constructors
    Spaceship();

    Spaceship(point center_point, unsigned int width, unsigned int height);

    // draw the ship
    void draw() const;

    // move the ship laterally or vertically
    void move(double delta_x, double delta_y);

    // returns the edge point given a x,y
    bool detect_hit(double x, double y);

    // make the spaceship go boom
    void destroy();

    // get destroyed status
    bool get_destroyed() const;
};

#endif //GF_GRAPHICS_FINAL_SPACESHIP_H
