#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "plot.c"
#include "list.c"
#include "pointNode.c"
#include "vectors.c"
#include "ray.c"
#include "shapes.c"
#include "general.h"
#include "first_intersection.c"
#include "getColor.c"
#include "ray_tracer.c"
#include "parser.c"
#include "frame_manager.c"

#include "keyboard_input.c"

//Run the window
void window_runner() {

    // Making calculations
    create_list_of_lights();
    parseFile();

    //starting window
    char *myargv[1];
    int myargc=1;
    myargv [0]=strdup ("Plot");
    glutInit(&myargc, myargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(resx,resy);
    glutCreateWindow("Ray Tracer");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, resx +0.5, -0.5, resy + 0.5);

    ini_buffer(resx, resy);
    plot_framebuffer(resx,resy);

    frame_plotter (resx, resy, eye);

    // Define keyboard input
    glutKeyboardFunc(processNormalKeys);
    glutMainLoop();
}

int main(int argc, char **argv){
    // get parameters
    if (argc != 1) {
        printf("Usage <program>\n");
        return -1;
    }  

    window_runner();
}