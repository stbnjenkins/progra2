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
        POINT p1 = {x: 4.0, y: 4.0, z: 4.0};
        POINT p2 = {x: 6.0, y: 4.0, z: 4.0};
        POINT p3 = {x: 6.0, y: 6.0, z: 6.0};
        POINT p4 = {x: 10.0, y: 2.0, z: 4.0};
        POINT p5 = {x: 10.0, y: 10.0, z: 10.0};
        POINT p6 = {x: 12.0, y: 5.0, z: 4.0};
        POLYGON poly = create_polygon(6, p1,p2,p3,p4,p5,p6);
        printPolygon(&poly);

        POLYGON poly2 = create_empty_polygon();
        addVertex(&poly2, p1);
        addVertex(&poly2, p2);
        addVertex(&poly2, p3);
        addVertex(&poly2, p4);
        addVertex(&poly2, p5);
        addVertex(&poly2, p6);
        put_plane_on_polygon(&poly2);
        printPolygon(&poly2);
    // get parameters
    if (argc != 1) {
        printf("Usage <program>\n");
        return -1;
    }  

    //Ini resolution
    resx = 1110;
    resy = 750;

    window_runner(resx, resy);
}