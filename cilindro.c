

// CYLINDER //////////////////////////////////////////////////
typedef struct cylinder{
    long double radius;
    POINT eje;
    VECTOR Q;
} CYLINDER, *CYLINDER_PTR;

// Create new sphere
CYLINDER create_cylinder(POINT e, long double r, VECTOR v){
    CYLINDER new_cylinder = {radius: r, eje: e, Q: v};
    return new_cylinder;
}

// print a sphere
void cylinderPrint(CYLINDER_PTR s){
    printf("[cylinder] eje = (%Lf, %Lf, %Lf)\tQ = (%Lf, %Lf, %Lf)\tradius = %Lf\t\n", (s->eje).x, (s->eje).y,(s->eje).z,(s->Q).x, (s->Q).y,(s->Q).z, s->radius);
}

//get intersection
// MAGNITUD_PTR get_cylinder_intersection (RAY_PTR ray, CYLINDER_PTR cylinder) {
    
//     MAGNITUD_PTR t = NULL;
//     MAGNITUD my_t;

// }

// END CYLINDER ///////////////////////////////////////////////