#include <stdio.h>
#include <stdlib.h>

#include "point.h"
#include "plot.c"
#include "list.c"
#include "pointNode.c"
#include "general.h"
#include "vectors.c"
#include "ray.c"
#include "shapes.c"
#include "getColor.c"
#include "ray_tracer.c"
#include "frame_manager.c"
#include "keyboard_input.c"

//Run the window
void window_runner(int resx, int resy) {

    // Making calculations
    create_list_of_lights();

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

    initialize_frame(resx, resy);

    // Define keyboard input
    glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

    glutMainLoop();
}

int main(int argc, char **argv){

    // get parameters
    if (argc != 1) {
        printf("Usage <program>\n");
        return -1;
    }  

    //Ini resolution
    resx = 1110;
    resy = 660;

    window_runner(resx, resy);
}