//
// Created by George on 4/27/20.
//

#include "graphics.h"
#include "spaceship.h"
#include "bigrock.h"
#include "smallrock.h"
#include "mediumrock.h"
#include <iostream>
using namespace std;

GLdouble width, height;
int wd;
Spaceship ship;
vector<unique_ptr<FallingStuff>> falling_vec;

void make_rock(int rock_size){
    int start_x = rand() % (int(width) - 100) + 100;
    if (rock_size == 0){
        int random = rand() % 3 + 1;
        if (random == 1){
            falling_vec.push_back(make_unique<BigRock>(start_x));
        }else if (random == 2){
            falling_vec.push_back(make_unique<MediumRock>(start_x));
        } else {
            falling_vec.push_back(make_unique<SmallRock>(start_x));
        }
    } else if (rock_size == 1){
        falling_vec.push_back(make_unique<BigRock>(start_x));
    } else if (rock_size == 2){
        falling_vec.push_back(make_unique<MediumRock>(start_x));
    } else if(rock_size == 3){
        falling_vec.push_back(make_unique<SmallRock>(start_x));
    }
    glutPostRedisplay();
}

void init() {
    width = 1000;
    height = 750;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}


/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    // doodle time
    ship.draw();
    if(!falling_vec.empty()) {
        for (int i = 0; i < falling_vec.size(); ++i){
            falling_vec[i]->draw();
        }
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            ship.move(-10.0, 0.0);
            break;
        case GLUT_KEY_RIGHT:
            ship.move(10.0, 0.0);
            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

int max_rocks = 1;
int counter = 0;
point top_left;
int rock_height;
int rock_width;
int rock_area;
void timer(int dummy) {
    // handling number of rocks
    if(falling_vec.size() < max_rocks) {
        for (int q = 0; q < max_rocks; ++q) {
            make_rock(0); // make a random rock
        }
    }
    // periodically increase the amount of rocks
    if (counter % 300 == 0){
        ++max_rocks;
    }
    ++counter;

    // major Loop to handle many small events
    if(!falling_vec.empty()) {
        for (int i = 0; i < falling_vec.size(); ++i){


            // FALL
            falling_vec[i]->fall();

            // HIT DETECTION
            top_left = falling_vec[i]->get_corner();
            rock_height = falling_vec[i]->get_height();
            rock_width = falling_vec[i]->get_width();
            rock_area = falling_vec[i]->get_area();
            for(int p = 0; p < rock_width; ++p){
                if(ship.detect_hit(top_left.x + p, top_left.y)){
                    ship.destroy();
                }
                if(ship.detect_hit(top_left.x + p, top_left.y + height)){
                    ship.destroy();
                }
            }
            for(int p = 0; p < rock_height; ++p){
                if(ship.detect_hit(top_left.x, top_left.y + p)){
                    ship.destroy();
                }
                if(ship.detect_hit(top_left.x + width, top_left.y + p)){
                    ship.destroy();
                }
            }



            // IF LEAVE THE SCREEN, DELETE
            if(falling_vec[i]->get_y() > height) {
                falling_vec.erase(falling_vec.begin() + i);
            }
        }
    }


    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("GF Final Project" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
