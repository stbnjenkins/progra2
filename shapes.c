#include "point.h"
#include <math.h>
#include <stdio.h>

enum shape_id {SPHERE_ID, PLANE_ID, SQUARE_ID};

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
        //sphere begin eye
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

// END SPHERE ///////////////////////////////////////////////

typedef union shape_u{
        SPHERE sphere;
        // other shapes
} SHAPE_U;

typedef struct shape{
    int id;
    COLOR color;
    long double Kd, c1, c2, c3;
    SHAPE_U shape;
}SHAPE, *SHAPE_PTR;


