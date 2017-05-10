#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "color.h"

COLOR **buffer;

//Plot put the points in the buffer
void plot(int res, int x,int y,long double R,long double G,long double B){
    if (x<res && y <res){
        buffer[x][y].r = R;
        buffer[x][y].g = G;
        buffer[x][y].b = B;
    }
}

//Take info from buffer and put it on display
void plot_framebuffer(int res) {
  int i, j;
  COLOR color;

  for (i = 0; i < res; i++) 
      {
       for (j = 0; j < res; j++) 
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }
  glutSwapBuffers();
}

//Initialize buffer (everything white)
void ini_buffer(int res) {
    int i, j;

    //reserve the memory space for the buffer
    buffer = (COLOR **)malloc(res * sizeof(COLOR*));
    for (i = 0; i < res; i++){
        buffer[i] = (COLOR *)malloc(res * sizeof(COLOR));
    }

    //initialize the values R G B for every pixel 
    for (i = 0; i < res; i++) {
        for (j = 0; j < res; j++) {
            buffer[i][j].r = 0.57255;
            buffer[i][j].g = 0.9098;
            buffer[i][j].b = 1;
        }
    }
}

