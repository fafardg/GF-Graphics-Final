//
// Created by George on 4/27/20.
//

#ifndef GF_GRAPHICS_FINAL_FALLINGSTUFF_H
#define GF_GRAPHICS_FINAL_FALLINGSTUFF_H
#include <vector>

using namespace std;


// struct for a point with x,y coordinates
struct point {
    double x;
    double y;
};

class FallingStuff{
private:
    int speed;
    int width;
    int height;
    vector<point> corners;

    point center_point;

    // helper functions
    void reset_corners();
    void draw_point(const point &p) const;

public:
    // constructors (shouldn't be used)
    FallingStuff();
    FallingStuff(int speed, int width, int height, point center_point);
    // fall method
    void fall(double start_x);
    // draw
    void draw() const;
};

#endif //GF_GRAPHICS_FINAL_FALLINGSTUFF_H
