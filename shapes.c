#include "point.h"
#include <math.h>
#include <stdio.h>

enum shape_id {SPHERE_ID, CONE_ID, SQUARE_ID};

// SPHERE //////////////////////////////////////////////////
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

//get intersection
MAGNITUD_PTR get_sphere_intersection (RAY_PTR ray, SPHERE_PTR sphere) {
    
    MAGNITUD_PTR t = NULL;
    MAGNITUD my_t;

    long double t1, t2, t3, A, B, C, D;
    long double Xd, Yd, Zd, Xe, Ye, Ze, Xc, Yc, Zc;


    Xd = (ray->vector).x; Yd = (ray->vector).y; Zd = (ray->vector).z;
    Xe = (ray->point).x; Ye = (ray->point).y; Ze = (ray->point).z;
    Xc = (sphere->center).x; Yc = (sphere->center).y; Zc = (sphere->center).z;

    //calculate A, B, C, and discriminant
    A = 1;
    B = 2*((Xd*(Xe-Xc))+(Yd*(Ye-Yc))+(Zd*(Ze-Zc)));
    C = (powl(Xe-Xc,2))+(powl(Ye-Yc,2))+(powl(Ze-Zc,2))-(powl(sphere->radius,2));
    D = powl(B,2) - (4 * C);

//Intersection cases
    //One Intersection
    if (D == 0){
        my_t.t = -B/(2);
        t=&my_t; 
    } 
    //2 intersection
    else if (D > 0) {
        t1 = (-B - (sqrtl(D))) / (2);
        t2 = (-B + (sqrtl(D))) / (2);

        //Order ts = t1 < t2
        if (t2 < t1) {t3 = t2; t2 = t1; t1 = t3;}

        //sphere front eye
        if (t1 > 0){
            my_t.t = t1;
            t=&my_t;
        }
        //sphere behind eye
        else if (t2 < 0) {
            return t;
            //no nothing
        }
        //eye inside sphere
        else if (t1 < 0 && t2 > 0) {
            my_t.t=t2;  
            t = &my_t;

        }
    } 
//    else {printf("hola");}

    return t;

}

//Get Normal on sphere
VECTOR get_normal_sphere(SPHERE_PTR sphere, POINT surface) {
    POINT center = sphere->center;
    VECTOR vector = getNormVectorFromPoints(center,surface);
    return vector;
}

// END SPHERE ///////////////////////////////////////////////

// CONE /////////////////////////////////////////////////////
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

// END CONE ////////////////////////////////////////////////

// SHAPE STRUCT ///////////////////////////////////////////

typedef union shape_u{
        SPHERE sphere;
        CONE cone;
        // other shapes
} SHAPE_U;

typedef struct shape{
    int id;
    COLOR color;
    long double Kd, Ka, c1, c2, c3;
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

bool quadratic(void *data){
    ((SHAPE_PTR)data)->c1 = 0.0;
    ((SHAPE_PTR)data)->c2 = 0.0;
    ((SHAPE_PTR)data)->c3 = 0.00001;
    return TRUE;
}

bool constant(void *data){
    ((SHAPE_PTR)data)->c1 = 0.5;
    ((SHAPE_PTR)data)->c2 = 0.0;
    ((SHAPE_PTR)data)->c3 = 0.0;
    return TRUE;
}

bool linear(void *data){
    ((SHAPE_PTR)data)->c1 = 0.0;
    ((SHAPE_PTR)data)->c2 = 0.005;
    ((SHAPE_PTR)data)->c3 = 0.0;
    return TRUE;
}

///
