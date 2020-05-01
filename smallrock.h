//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_SMALLROCK_H
#define GF_GRAPHICS_FINAL_SMALLROCK_H

#include "fallingstuff.h"
#include "graphics.h"

class SmallRock : public FallingStuff {
private:
    int speed;
    int height;
    int width;
    vector<point> corners;
    point center_point;
public:
    explicit SmallRock(double start_x);

    void reset_corners() override ;

    void fall() override;

    void draw() const override;

    double get_y() const override;

    int get_area() const override;

    point get_corner() const override;

    int get_width() const override;

    int get_height() const override;
};

#endif //GF_GRAPHICS_FINAL_SMALLROCK_H
