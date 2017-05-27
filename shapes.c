#define MAX_VERTEX 20

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "point.h"

enum shape_id {SPHERE_ID, CONE_ID,  PLANE_ID, POLYGON_ID, CYLINDER_ID, DISC_ID, FCYLINDER_ID};

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
    printf("[plane] A = %Lf,\tB = %Lf\tC = %LfD = %Lf\n", 
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
    
    if (N.y > 0 ) {N=vectorScale(&N,-1);}

    normalizeVector(&N);

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
//get 2D point with intersection in 0,0
POINT2D get_2d_point_with_intersection(POINT_PTR p, POINT_PTR intersection, int D){
    POINT2D inter,p2;

    inter = get_2d_point_from_3d_point(intersection,D);
    p2 = get_2d_point_from_3d_point(p,D);

    p2.x = p2.x - inter.x;
    p2.y = p2.y - inter.y;

    return p2;
}

//get cross wall
int cross_wall (POINT_PTR ini, POINT_PTR fin, POINT_PTR intersection, int D){
    int cross = 0;
    long double inter = 0.0;

    POINT2D p1 = get_2d_point_with_intersection(ini, intersection, D);
    POINT2D p2 = get_2d_point_with_intersection(fin, intersection, D);

    //rechazos triviales
    if ((p1.x<0 && p2.x<0) || (p1.y<0 && p2.y<0) || (p1.y>0 && p2.y>0)) {
        cross = 0;
    }
    //Aceptacion trivial
    else if ((p1.x>0 && p2.x>0) && ((p1.y<0 && p2.y>0) || (p1.y>0 && p2.y<0))){
        cross = 1;
    }
    //caso complejo
    else if (((p1.x>0 && p2.x<0) || (p1.x<0 && p2.x>0)) && ((p1.y<0 && p2.y>0) || (p1.y>0 && p2.y<0))){
        inter = -( ((p1.y) * (p2.x - p1.x)) / (p2.y - p1.y) ) + (p1.x) ;
        if (inter > 0) {
            cross = 1;
        }
    }

    return cross;
}

//get intersection
MAGNITUD_PTR get_polygon_intersection (RAY_PTR ray, POLYGON_PTR polygon) {
    MAGNITUD_PTR t = get_plane_intersection(ray,&(polygon->plane));
    POINT p1,p2;

    if (t != NULL) {
        POINT intersection = get_point_from_ray(ray,t->t);
        VECTOR N = get_normal_plane(&(polygon->plane));
        int max_dir = max_direction(&N);

        int cross_count = 0;

        for(int kk = 0; kk < polygon->num_vertex; kk++){
            p1 = (polygon->vertex)[kk];
            if (polygon->num_vertex == (kk+1)) {
                p2 = (polygon->vertex)[0];      
            } else {
                p2 = (polygon->vertex)[kk+1];
            }
          
            cross_count = cross_count + (cross_wall (&p1, &p2, &intersection, max_dir));

        }

        if ((cross_count % 2) == 0) {
            t = NULL;
        } else {
            t = get_plane_intersection(ray,&(polygon->plane));
        } 
    }
    return t;
}

// END POLYGON /////////////////////////////////////////////


// START DISC //////////////////////////////////////////////
typedef struct disc{
    long double radius;
    POINT center;
    VECTOR vector;
    PLANE plane;
} DISC, *DISC_PTR;

// get a plane from vector
PLANE get_plane_from_vector(VECTOR N, POINT c){
    PLANE plane;
    normalizeVector(&N);
    if (N.y > 0 ) {N=vectorScale(&N,-1);}

    plane.A = N.x;
    plane.B = N.y;
    plane.C = N.z;  
    plane.D = -((c.x * N.x) + (c.y * N.y) + (c.z * N.z));  

    return plane;
};

// Create new disc
DISC create_disc(POINT c, long double r, VECTOR v){
    PLANE p = get_plane_from_vector(v, c); 
    DISC new_disc = {radius: r, center: c, vector: v, plane: p};
    return new_disc;
}

// print a disc
void printDisc(DISC_PTR d){
    printf("[disc] center = (%Lf, %Lf, %Lf)\tradius = %Lf\t\n", (d->center).x, (d->center).y,(d->center).z, d->radius);
    printf("[plane] A = %Lf,\tB = %Lf\tC = %Lf\tD = %Lf\n", 
        (d->plane).A, (d->plane).B, (d->plane).C, (d->plane).D);   

}

//get intersection
MAGNITUD_PTR get_disc_intersection (RAY_PTR ray, DISC_PTR disc) {
    MAGNITUD_PTR t = get_plane_intersection(ray,&(disc->plane));
    long double distance;

    if (t != NULL) {
        POINT intersection = get_point_from_ray(ray,t->t);
        distance = getDistance(intersection,(disc->center));

        if (distance > disc->radius) {
            t = NULL;
        } else {
            t = get_plane_intersection(ray,&(disc->plane));
        } 
    }
    return t;
}

// END DISC //////////////////////////////////////////////

// CYLINDER //////////////////////////////////////////////////
typedef struct cylinder{
    long double radius;
    POINT eje;
    VECTOR Q;
} CYLINDER, *CYLINDER_PTR;

// Create new cylinder
CYLINDER create_cylinder(POINT e, long double r, VECTOR v){
    normalizeVector(&v);
    CYLINDER new_cylinder = {radius: r, eje: e, Q: v};
    return new_cylinder;
}

// print a cylinder
void cylinderPrint(CYLINDER_PTR s){
    printf("[cylinder] eje = (%Lf, %Lf, %Lf)\tQ = (%Lf, %Lf, %Lf)\tradius = %Lf\t\n", (s->eje).x, (s->eje).y,(s->eje).z,(s->Q).x, (s->Q).y,(s->Q).z, s->radius);
}

//get intersection
MAGNITUD_PTR get_cylinder_intersection (RAY_PTR ray, CYLINDER_PTR cylinder) {
    
    MAGNITUD_PTR t = NULL;
    MAGNITUD my_t;

    long double F, G, H, M, N, O, A, B, C, D, R;
    long double Xd, Yd, Zd, Xe, Ye, Ze, Xq, Yq, Zq, Xo, Yo, Zo;
    long double t1,t2,t3;


    Xd = (ray->vector).x; Yd = (ray->vector).y; Zd = (ray->vector).z;
    Xe = (ray->point).x; Ye = (ray->point).y; Ze = (ray->point).z;
    Xq = (cylinder->Q).x; Yq = (cylinder->Q).y; Zq = (cylinder->Q).z;
    Xo = (cylinder->eje).x; Yo = (cylinder->eje).y; Zo = (cylinder->eje).z;
    R = cylinder->radius;

    //calculate F, G, H, N, M, O

    F = Xd - (Xd*Xq*Xq) - (Yd*Yq*Xq) - (Zd*Zq*Xq);
    G = Yd - (Xd*Xq*Yq) - (Yd*Yq*Yq) - (Zd*Zq*Yq);
    H = Zd - (Xd*Xq*Zq) - (Yd*Yq*Zq) - (Zd*Zq*Zq);

    M = Xe - Xo - (Xe*Xq*Xq) + (Xo*Xq*Xq) - (Ye*Yq*Xq) + (Yo*Yq*Xq) - (Ze*Zq*Xq) + (Zo*Zq*Xq);
    N = Ye - Yo - (Xe*Xq*Yq) + (Xo*Xq*Yq) - (Ye*Yq*Yq) + (Yo*Yq*Yq) - (Ze*Zq*Yq) + (Zo*Zq*Yq);
    O = Ze - Zo - (Xe*Xq*Zq) + (Xo*Xq*Zq) - (Ye*Yq*Zq) + (Yo*Yq*Zq) - (Ze*Zq*Zq) + (Zo*Zq*Zq);

    //calculate A , B, C, D
    A = (F*F)+(G*G)+(H*H);
    B = 2*((F*M)+(G*N)+(H*O));
    C = (M*M)+(N*N)+(O*O)-(R*R);

    D = (B*B) - (4*A*C);

//Intersection cases
    //One Intersection
    if (D == 0){
        my_t.t = -B/(2*A);
        t=&my_t; 
    } 
    //2 intersection
    else if (D > 0) {
        t1 = (-B - (sqrtl(D))) / (2*A);
        t2 = (-B + (sqrtl(D))) / (2*A);

        //Order ts = t1 < t2
        if (t2 < t1) {t3 = t2; t2 = t1; t1 = t3;}

        //cylinder front eye
        if (t1 > 0){
            my_t.t = t1;
            t=&my_t;
        }
        //cylinder behind eye
        else if (t2 < 0) {
            return t;
            //no nothing
        }
        //eye inside cylinder
        else if (t1 < 0 && t2 > 0) {
            my_t.t=t2;  
            t = &my_t;

        }
    } 

    return t;

}

//Get Normal on cylinder
VECTOR get_normal_cylinder(CYLINDER_PTR cylinder, POINT surface) {
    long double Xq, Yq, Zq, Xo, Yo, Zo, Ldistance, d;
    Xo = (cylinder->eje).x; Yo = (cylinder->eje).y; Zo = (cylinder->eje).z;
    Xq = (cylinder->Q).x; Yq = (cylinder->Q).y; Zq = (cylinder->Q).z;

    VECTOR L = getNormVectorFromPoints(cylinder->eje,surface);
    Ldistance = getDistance(cylinder->eje,surface);

    d = (vectorDotProduct(&(cylinder->Q),&L)*Ldistance);

    POINT m;
    m.x = Xo + (d*Xq);
    m.y = Yo + (d*Yq);
    m.z = Zo + (d*Zq);

    VECTOR vector = getNormVectorFromPoints(m,surface);
    return vector;
}

// END CYLINDER ///////////////////////////////////////////////


// FINITE CYLINDER //////////////////////////////////////////////////
typedef struct fcylinder{
    CYLINDER cylinder;
    long double l;
} FCYLINDER, *FCYLINDER_PTR;

// Create new cylinder
FCYLINDER create_fcylinder(POINT e, long double r, VECTOR v, long double l){
    normalizeVector(&v);
    CYLINDER new_cylinder = {radius: r, eje: e, Q: v};
    FCYLINDER new_fcylinder = {cylinder: new_cylinder, l: l};
    return new_fcylinder;
}

//get intersection
MAGNITUD_PTR get_fcylinder_intersection (RAY_PTR ray, FCYLINDER_PTR fcylinder) {
    
    MAGNITUD_PTR t = NULL;
    MAGNITUD my_t;
}
// SHAPE STRUCT ///////////////////////////////////////////

typedef union shape_u{
        SPHERE sphere;
        CONE cone;
        PLANE plane;
        POLYGON polygon;
        CYLINDER cylinder;
        DISC disc;
        FCYLINDER fcylinder;
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
        case POLYGON_ID:
            printPolygon(&(s->shape).polygon);
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
