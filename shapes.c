#include "point.h"

enum shape_id {SPHERE_ID, PLANE_ID, SQUARE_ID};

// SPHERE
typedef struct sphere{
    long double radius;
    POINT center;
} SPHERE, *SPHERE_PTR;

// Create new sphere
SPHERE create_sphere(POINT c, long double r){
    SPHERE new_sphere = {radius: r, center: c};
    return new_sphere;
}



// print a sphere
void spherePrint(SPHERE_PTR s){
    printf("[sphere] center = (%Lf, %Lf, %Lf)\tradius = %Lf\t\n", (s->center).x, (s->center).y,(s->center).z, s->radius);
}






typedef union shape_u{
        SPHERE sphere;
        CUBE q;
        // other shapes
} SHAPE_U;

typedef struct shape{
    int id;
    COLOR color;
    long double Kd, c1, c2, c3;
    SHAPE_U shape;
}SHAPE, *SHAPE_PTR;


