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
    explicit BigRock(double start_x);

    void reset_corners() override ;

    void fall() override;

    void draw() const override;
};

#endif //GF_GRAPHICS_FINAL_BIGROCK_H
