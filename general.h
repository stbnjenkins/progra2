#ifndef _GENERAL_H
#define _GENERAL_H

static const long double PI = 3.141592653589793;
static const long double ENV_LIGHT = 0.17834;
list shapeList;
long double Ia = 0.5;
PointNodePtr Light_list = NULL;
POINT eye = {x: 550.0, y: 400.0, z:-2000};

#endif /* _GENERAL_H */