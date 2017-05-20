#ifndef _GENERAL_H
#define _GENERAL_H

static const long double PI = 3.141592653589793;
static const long double ENV_LIGHT = 0.17834;
static const long double EPSILON = 0.0005;
list shapeList;
long double Ia = 0.5;
PointNodePtr Light_list = NULL;
POINT eye = {x: 550.0, y: 400.0, z:-2000};
int resx, resy;
int Enable_intensity = 1;
int Enable_Shadow = 1;
int Enable_Especular = 1;

MAGNITUD_PTR inter;
SHAPE_PTR ptr = NULL;
RAY ray;
long double tmin;

#endif /* _GENERAL_H */