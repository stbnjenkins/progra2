#include <stdio.h>
#include <stdlib.h>

#include "plot.c"
#include "keyboard_input.c"
#include "figure_struct.c"
#include "frame_manager.c"

//Run the window
void window_runner(int res) {
    //starting window
    char *myargv[1];
    int myargc=1;
    myargv [0]=strdup ("Plot");
    glutInit(&myargc, myargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(res,res);
    glutCreateWindow("Plot");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-0.5, res +0.5, -0.5, res + 0.5);
  
    ini_buffer(res);
    plot_framebuffer(res);

    // here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

    glutMainLoop();
}

int main(int argc, char **argv){
    int res;

    // get parameters
    if (argc != 1) {
        printf("Usage <program>\n");
        return -1;
    }  

    //Ini resolution
    res = 1000;

    ini_buffer(res);
    window_runner(res);
}