//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_MEDIUM_ROCK_H
#define GF_GRAPHICS_FINAL_MEDIUM_ROCK_H

#include "falling_stuff.h"
#include "graphics.h"

class MediumRock : public FallingStuff {
private:
    int speed;
    int height;
    int width;
    vector<point> corners;
    point center_point;
public:
    // see BigRock -- all rocks follow same template
    explicit MediumRock(double start_x);

    void reset_corners() override ;

    void fall() override;

    void draw() const override;

    double get_y() const override;

    int get_area() const override;

    point get_corner() const override;

    int get_width() const override;

    int get_height() const override;
};


#endif //GF_GRAPHICS_FINAL_MEDIUM_ROCK_H
