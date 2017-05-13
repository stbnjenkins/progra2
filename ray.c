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
    VECTOR vector;
    RAY ray;

    POINT frame;
    frame.x=(long double) x + 0.5;
    frame.y=(long double) y + 0.5;
    frame.z= 0;

    vector = getNormVectorFromPoints(*eye,frame);

    ray.point = *eye;
    ray.vector = vector;

//    rayPrint(&ray);
    return ray;
}

//Find Ray 2 points
RAY find_ray_from_2_points (POINT_PTR ini, POINT_PTR fin){
    VECTOR vector;
    RAY ray;
    
    vector = getNormVectorFromPoints(*ini,*fin);

    ray.point = *ini;
    ray.vector = vector;

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