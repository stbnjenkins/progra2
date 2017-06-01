#ifndef _GENERAL_H
#define _GENERAL_H

static const long double PI = 3.141592653589793;
static const long double ENV_LIGHT = 0.17834;
static const long double EPSILON = 0.0005;
list shapeList;
MAGNITUD_PTR inter;
SHAPE_PTR ptr = NULL;
RAY ray;
long double tmin;
PointNodePtr Light_list = NULL;

// Global parameters (overwritten by read values from file)
long double Ia;
POINT eye;
int resx;
int resy;
int Enable_intensity;
int Enable_Shadow;
int Enable_Especular;
short int max_mirror = 3;



#endif /* _GENERAL_H */