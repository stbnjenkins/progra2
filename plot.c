#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

COLOR **buffer;

//Plot put the points in the buffer
void plot(int resx,int resy, int x,int y,long double R,long double G,long double B){
    if (x<resx && y <resy){
        buffer[x][y].r = R;
        buffer[x][y].g = G;
        buffer[x][y].b = B;
    }
}

//Take info from buffer and put it on display
void plot_framebuffer(int resx, int resy) {
  int i, j;
  COLOR color;

  for (i = 0; i < resx; i++) 
      {
       for (j = 0; j < resy; j++) 
           {
            glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
            glBegin (GL_POINTS);
            glVertex2i (i,j);
            glEnd();
           }
      }
  glFlush();
}

//Initialize buffer (everything white)
void ini_buffer(int resx, int resy) {
    int i, j;

    //reserve the memory space for the buffer
    buffer = (COLOR **)malloc(resx * sizeof(COLOR*));
    for (i = 0; i < resx; i++){
        buffer[i] = (COLOR *)malloc(resy * sizeof(COLOR));
    }

    //initialize the values R G B for every pixel 
    for (i = 0; i < resx; i++) {
        for (j = 0; j < resy; j++) {
            buffer[i][j].r = bg_color.r;
            buffer[i][j].g = bg_color.g;
            buffer[i][j].b = bg_color.b;
        }
    }
}

