//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_BIGROCK_H
#define GF_GRAPHICS_FINAL_BIGROCK_H

#include "fallingstuff.h"
#include "graphics.h"

class BigRock : public FallingStuff {
private:
    int speed;
    int height;
    int width;
    vector<point> corners;
    point center_point;
public:
    // Constructor containing the x position where it will start falling from
    explicit BigRock(double start_x);

    // reset the corners and outline a big rock
    void reset_corners() override ;

    // fall at the specified speed
    void fall() override;

    // draw the big rock
    void draw() const override;

    // returns the Y value of the craft
    double get_y() const override;

    // returns the area of the craft
    int get_area() const override;

    // returns the corners vector
    point get_corner() const override;

    // get width
    int get_width() const override;

    // get height
    int get_height() const override;
};

#endif //GF_GRAPHICS_FINAL_BIGROCK_H
