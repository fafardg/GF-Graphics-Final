//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_FALLINGSTUFF_H
#define GF_GRAPHICS_FINAL_FALLINGSTUFF_H
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

    void draw_point(const point &p) const;

};

#endif //GF_GRAPHICS_FINAL_FALLINGSTUFF_H
