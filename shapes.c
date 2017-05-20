#define MAX_VERTEX 20

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "point.h"

enum shape_id {SPHERE_ID, CONE_ID,  PLANE_ID, POLYGON_ID,};

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

// PLANE /////////////////////////////////////////////////////
typedef struct plane{
    long double A,B,C,D;
} PLANE, *PLANE_PTR;

// create a plane
PLANE create_plane(long double A, long double B, long double C, long double D){
    PLANE new_plane = {A: A, B: B, C: C, D:D};
    return new_plane;
}
// print a plane
void planePrint(PLANE_PTR c){
    printf("[plane] A = %Lf,\tB = %Lf\tC = %Lf\nD = %Lf\n", 
        c->A, c->B, c->C, c->D);
}

//get intersection
MAGNITUD_PTR get_plane_intersection (RAY_PTR ray, PLANE_PTR plane) {
    MAGNITUD_PTR t = NULL;
    MAGNITUD my_t;
    long double D, productPwD, Xe, Ye, Ze, temp;

    //Normalizing the plane
    POINT ini,fin;
    VECTOR N;
    ini.x=0;ini.y=0;ini.z=0;
    fin.x=plane->A;
    fin.y=plane->B; 
    fin.z=plane->C;

    D = (plane->D)/(getDistance(ini,fin));
    N.x=plane->A;
    N.y=plane->B; 
    N.z=plane->C;
    normalizeVector(&N);

    //calculating t
    productPwD = vectorDotProduct(&N,&(ray->vector));
    if (productPwD != 0) {
        Xe = (ray->point).x; Ye = (ray->point).y; Ze = (ray->point).z;

        temp = ((plane->A)*Xe) + ((plane->B)*Ye) + ((plane->C)*Ze) + D;

        my_t.t=-(temp)/productPwD;
        t=&my_t;
    }
   
    return t;
}

//Get Normal on Plane
VECTOR get_normal_plane(PLANE_PTR plane) {
    VECTOR vector;    
    vector.x=plane->A;
    vector.y=plane->B; 
    vector.z=plane->C;
    normalizeVector(&vector);
    return vector;
}


// END PLANE ////////////////////////////////////////////////


// START POLYGON ///////////////////////////////////////////
typedef struct polygon{
    int num_vertex;
    POINT vertex[MAX_VERTEX];
    PLANE plane;
} POLYGON, *POLYGON_PTR;

//create polygon
POLYGON create_empty_polygon(){
    POLYGON p;
    p.num_vertex = 0;
    return p;
};

void addVertex(POLYGON_PTR p, POINT v){
    (p->vertex)[p->num_vertex] = v;
    p->num_vertex++;
    return;
};

// get a plane from points
PLANE get_plane_from_points(POINT p1, POINT p2, POINT p3){
    PLANE plane;
    long double A, B, C, D;
    VECTOR N,v1,v2;
    v1 = getNormVectorFromPoints(p1,p2);
    v2 = getNormVectorFromPoints(p1,p3);
    N = vectorCrossProduct(&v1,&v2);
    if (N.y < 0) {N = vectorScale(&N,-1.0);};

    plane.A = N.x;
    plane.B = N.y;
    plane.C = N.z;  
    plane.D = -((p1.x * N.x) + (p1.y * N.y) + (p1.z * N.z));  

    return plane;
};

//add the plane into polygon
void put_plane_on_polygon(POLYGON_PTR p){
    if (p->num_vertex >= 3) {
        POINT p1,p2,p3;
        p1 = p->vertex[0];
        p2 = p->vertex[1];
        p3 = p->vertex[2];
        PLANE plane = get_plane_from_points(p1, p2, p3);
        p->plane = plane;
    }
};

// create a poligon
POLYGON create_polygon(int n_vertex, ...){
    POLYGON p;
    p.num_vertex = n_vertex;
    va_list ap;
    va_start(ap, n_vertex);
    // va_arg(ap, POINT);
    int ii;
    for (ii = 0; ii < n_vertex; ii++){
        (p.vertex)[ii] = va_arg(ap, POINT);
    }
    va_end(ap);
    put_plane_on_polygon(&p);
    return p;
}

// print a polygon
void printPolygon(POLYGON_PTR p){
    printf("[polygon] number_vertex = %d\n", p->num_vertex);
    for(int kk = 0; kk < p->num_vertex; kk++){
        printf("\t[vertex] (%Lf, %Lf, %Lf)\n", ((p->vertex)[kk]).x, ((p->vertex)[kk]).y, ((p->vertex)[kk]).z);
    }
    printf("[plane] A = %Lf,\tB = %Lf\tC = %Lf\tD = %Lf\n", 
        (p->plane).A, (p->plane).B, (p->plane).C, (p->plane).D);   

}
//get 2D point
POINT2D get_2d_point_from_3d_point(POINT_PTR p, int D){
    POINT2D p2;
    if (D==0){p2.x=p->y;}
    else {p2.x=p->x;}
    
    if (D<=1){p2.y=p->z;} 
    else {p2.y=p->y;}

    return p2;
}
//

//get intersection
MAGNITUD_PTR get_polygon_intersection (RAY_PTR ray, POLYGON_PTR polygon) {
    MAGNITUD_PTR t = get_plane_intersection(ray,&(polygon->plane));
    
    if (t != NULL) {
        POINT intersection = get_point_from_ray(ray,t->t);
        VECTOR N = get_normal_plane(&(polygon->plane));
        int max_dir = max_direction(&N);

    }

    return t;
}

// END POLYGON /////////////////////////////////////////////

// SHAPE STRUCT ///////////////////////////////////////////

typedef union shape_u{
        SPHERE sphere;
        CONE cone;
        PLANE plane;
        POLYGON polygon;
        // other shapes
} SHAPE_U;

typedef struct shape{
    int id;
    COLOR color;
    long double Kd, Ks, Ka, Kn, c1, c2, c3;
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
        case PLANE_ID:
            planePrint(&(s->shape).plane);
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
