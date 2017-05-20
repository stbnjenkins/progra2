#include <math.h>
#include <stdio.h>
#include "point.h"

typedef struct vector{
    long double x,y,z;
} VECTOR, *VECTOR_PTR;

// Add vector to another one and return resulting vector
VECTOR vectorAdd(VECTOR_PTR v1, VECTOR_PTR v2){
    VECTOR rv;
    rv.x = v1->x + v2->x;
    rv.y = v1->y + v2->y;
    rv.z = v1->z + v2->z;
    return rv;
}

// Substract vector to another one and return resulting vector (v1-v2)
VECTOR vectorDiff(VECTOR_PTR v1, VECTOR_PTR v2){
    VECTOR rv;
    rv.x = v1->x - v2->x;
    rv.y = v1->y - v2->y;
    rv.z = v1->z - v2->z;
    return rv;
}

// Obtain the dot product of two vectos
long double vectorDotProduct(VECTOR_PTR v1, VECTOR_PTR v2){
    long double P;
    P = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
    return P;
}

// Return new scaled vector by parameter s
VECTOR vectorScale(VECTOR_PTR v, long double s){
    VECTOR rv;
    rv.x = s * v->x;
    rv.y = s * v->y;
    rv.z = s * v->z;
    return rv;
}

// Return cross product of two vectors
VECTOR vectorCrossProduct(VECTOR_PTR v1, VECTOR_PTR v2){
    VECTOR rv;
    rv.x = (v1->y * v2->z)-(v1->z * v2->y);
    rv.y = (v1->x * v2->z)-(v1->z * v2->x);
    rv.z = (v1->x * v2->y)-(v1->y * v2->x);
    return rv;
}

/* Normalize a vector*/
void normalizeVector(VECTOR_PTR v){
    long double norm = sqrtl(powl(v->x,2) + powl(v->y,2) + powl(v->z,2));
    v->x /= norm;
    v->y /= norm;
    v->z /= norm;
};

// print a vector
void vectorPrint(VECTOR_PTR v){
    printf("[vector] x = %Lf\ty = %Lf\tz = %Lf\n", v->x,v->y, v->z);
}

// get norm vector from points
VECTOR getNormVectorFromPoints(POINT ini, POINT fin) {
    VECTOR vn;
    vn.x = fin.x - ini.x;
    vn.y = fin.y - ini.y;
    vn.z = fin.z - ini.z;
    normalizeVector(&vn);
    return vn;
}

//get distance from points
long double getDistance(POINT ini, POINT fin){
    long double norm = sqrtl(powl(fin.x-ini.x,2) + powl(fin.y-ini.y,2) + powl(fin.z-ini.z,2));
    return norm;
}

//get max direction from vector
int max_direction(VECTOR_PTR v){
    int D=0;
    long double X,Y,Z;
    X = abs(v->x); 
    Y = abs(v->y); 
    Z = abs(v->z); 

    if ( (X >= Y) && (X >= Z)) {
        D=0;
    } else if ( (Y >= X) && (Y >= Z)) {
        D=1;
    } else if ( (Z >= X) && (Z >= Y)) {
        D=2;
    }
    return D;
}

// int main(){
//     // Variable definition
//     VECTOR v1 = {x: 3.0, y: 1.0, z: 2.0};
//     VECTOR v2 = {x: 5.0, y: 4.0, z: 13.0};
//     VECTOR resta;
//     VECTOR suma;

//     // Testing functions
//     vectorPrint(&v1);
//     vectorPrint(&v2);
//     suma = vectorAdd(&v1, &v2);
//     vectorPrint(&suma);
//     resta = vectorDiff(&v1, &v2);
//     vectorPrint(&resta);
// }