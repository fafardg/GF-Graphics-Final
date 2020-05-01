//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_FALLING_STUFF_H
#define GF_GRAPHICS_FINAL_FALLING_STUFF_H
#include <vector>
#include "graphics.h"
#include "spaceship.h"

using namespace std;

class FallingStuff{
private:
    int speed;
    int width;
    int height;
    vector<point> corners;

    point center_point;

    // helper functions
    virtual void reset_corners();

public:
    // constructors (shouldn't be used)
    FallingStuff();
    FallingStuff(int speed, int width, int height, point center_point);
    // fall method
    virtual void fall();
    // draw
    virtual void draw() const;
    // draw a point
    void draw_point(const point &p) const;

    // get Y value
    virtual double get_y() const;

    // return Area
    virtual int get_area() const;

    // get height
    virtual int get_height() const;
    // get width
    virtual int get_width() const;
    // returns the position of the corners
    virtual point get_corner() const;

};

#endif //GF_GRAPHICS_FINAL_FALLING_STUFF_H
