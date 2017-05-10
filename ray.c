#include <math.h>
#include <stdio.h>

#include "point.h"

typedef struct ray{
    POINT point;
    VECTOR vector;
} RAY, *RAY_PTR;


// print a Ray
void rayPrint(RAY_PTR r){
    printf("[vector] x = %Lf\ty = %Lf\tz = %Lf\n", (r->vector).x,(r->vector).y,(r->vector).z);
    printf("[point] x = %Lf\ty = %Lf\tz = %Lf\n", (r->point).x,(r->point).y,(r->point).z);
}

//Find RAY
RAY find_ray (POINT_PTR eye, int x, int y){
    long double Xw,Yw,Zw;

    VECTOR vector;
    RAY ray;

    Xw = (long double) x + 0.5;
    Yw = (long double) y + 0.5;
    Zw = 0;

    vector.x = Xw - eye->x;
    vector.y = Yw - eye->y;
    vector.z = Zw - eye->z;

    normalizeVector (&vector);

    ray.point = *eye;
    ray.vector = vector;

//    rayPrint(&ray);
    return ray;
}

//Get point from ray
POINT get_point_from_ray (RAY_PTR ray, long double t){
    POINT point;

    point.x = (ray->point).x + (t* (ray->vector).x);
    point.y = (ray->point).y + (t* (ray->vector).y);
    point.z = (ray->point).z + (t* (ray->vector).z);

    return point;
}