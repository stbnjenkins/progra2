#include <stdio.h>
#include <stdlib.h>

#include "plot.c"
#include "keyboard_input.c"
#include "figure_struct.c"
#include "vectors.c"
#include "ray.c"
#include "shapes.c"
#include "frame_manager.c"
#include "ray_tracer.c"

//Run the window
void window_runner(int resx, int resy) {
    //starting window
    char *myargv[1];
    int myargc=1;
    myargv [0]=strdup ("Plot");
    glutInit(&myargc, myargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(resx,resy);
    glutCreateWindow("Plot");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, resx +0.5, -0.5, resy + 0.5);
  
    ini_buffer(resx,resy);
    plot_framebuffer(resx,resy);


//test lines
    POINT eye; eye.x = 550.0; eye.y = 400.0; eye.z = -5.0;

    ray_tracer (&eye, resx, resy);

    plot_framebuffer(resx,resy);

//end of test

    // here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

    glutMainLoop();
}

int main(int argc, char **argv){
    int resx, resy;

    // get parameters
    if (argc != 1) {
        printf("Usage <program>\n");
        return -1;
    }  

    //Ini resolution
    resx = 1100;
    resy = 800;

    window_runner(resx, resy);
}