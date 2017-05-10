#include "point.h"
#include "../color.h"

enum shape_id {SPHERE_ID, CONE_ID, SQUARE_ID};

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


// CONE
typedef struct cone{
    long double radius;
    long double height;
    POINT center;
} CONE, *CONE_PTR;

// create a cone
CONE create_cone(POINT c, long double r, long double h){
    CONE new_cone = {radius: r, height: h, center: c};
    return new_cone;
}
// print a cone
void conePrint(CONE_PTR c){
    printf("[cone] center = (%Lf, %Lf, %Lf)\tradius = %Lf\theight = %Lf\n", 
        (c->center).x, (c->center).y,(c->center).z, c->radius, c->height);
}









typedef union shape_u{
        SPHERE sphere;
        CONE cone;
        // other shapes
} SHAPE_U;

typedef struct shape{
    int id;
    COLOR color;
    long double Kd, c1, c2, c3;
    SHAPE_U shape;
}SHAPE, *SHAPE_PTR;

void printShape(SHAPE_PTR s){
    switch(s->id){
        case SPHERE_ID:
            printf("[shape] RGB: %Lf, %Lf, %Lf\tKd: %Lf\tc1: %Lf\tc2: %Lf\tc3: %Lf\n",
                (s->color.r), (s->color.g), (s->color.b), s->Kd, s->c1, s->c2, s->c3);
            printf("\t[sphere] center = (%Lf, %Lf, %Lf)\tradius = %Lf\t\n", (s->shape).sphere.center.x, 
                (s->shape).sphere.center.y,(s->shape).sphere.center.z, (s->shape).sphere.radius);
            break;
        case CONE_ID:
            printf("[shape] RGB: %Lf, %Lf, %Lf\tKd: %Lf\tc1: %Lf\tc2: %Lf\tc3: %Lf\n",
                (s->color.r), (s->color.g), (s->color.b), s->Kd, s->c1, s->c2, s->c3);
            printf("\t[cone] center = (%Lf, %Lf, %Lf)\tradius = %Lf\theight = %Lf\n", (s->shape).cone.center.x, 
                (s->shape).cone.center.y,(s->shape).cone.center.z, (s->shape).cone.radius, (s->shape).cone.height);
            break;
        default:
            printf("Not a valid figure");
    }
}

