#ifndef POINT_H
#define POINT_H

typedef struct point{
    long double x,y,z;
} POINT, *POINT_PTR;

typedef struct point2D{
    long double x,y;
} POINT2D, *POINT2D_PTR;

typedef struct magnitud{
    long double t;
} MAGNITUD, *MAGNITUD_PTR;

#endif /* POINT_H */