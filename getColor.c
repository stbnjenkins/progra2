#include <math.h>

//// PARTIAL CALCULUS /////////////////////////////////////////////////////////
//Get Partial Especular
long double get_partial_especular(long double product, long double Distance, long double Ks, long double Ip, long double c1, long double c2, long double c3){
    long double partial_E, Fatt;

    Fatt = 1 / (c1 + (Distance*c2) + (powl(Distance,2)*c3));
    
    if (Fatt > 1) {Fatt = 1;}
    if(product < 0) product = 0;
    partial_E = (product) * Ks * Ip * Fatt ;

    return partial_E;
}

//Get Partial Intensity
long double get_partial_intensity(long double product, long double Distance, long double Kd, long double Ip, long double c1, long double c2, long double c3){
    long double partial_I, Fatt ;

    Fatt = 1 / (c1 + (Distance*c2) + (powl(Distance,2)*c3));
    
    if (Fatt > 1) {Fatt = 1;}
    partial_I = (product) * Kd * Ip * Fatt ;

    return partial_I;
}

//// SHAPE COLOR /////////////////////////////////////////////////////////
//Get Color for any shape
COLOR get_shape_color (VECTOR N, COLOR color, POINT intersection, PointNodePtr Light_list, long double Kd, long double Ks, long double c1,long double c2, long double c3, long double Ka, long double Kn) {
    PointNodePtr my_ptr;
    VECTOR L,V,R;
    COLOR final_color;
    long double Distance, productLN, productVR, I, E, Ip, Final_I, Final_E;

    Final_I = 0;
    Final_E = 0;

    if (Light_list== NULL || !Enable_intensity ){
        final_color = color;

    } else{
        for (my_ptr = Light_list;my_ptr != NULL;my_ptr = my_ptr->next){ 

            ptr = NULL;

            if (Enable_Shadow) {
                ray = find_ray_from_2_points(&intersection, &(my_ptr->point));
                ptr = first_intersection(&shapeList);
            }    
            if (ptr == NULL) {
                Ip = my_ptr->Ip;
                L = getNormVectorFromPoints(intersection,my_ptr->point);
                productLN = vectorDotProduct(&L, &N);
                if(productLN < 0) productLN = 0;
                Distance = getDistance(intersection, my_ptr->point);
                I = get_partial_intensity(productLN, Distance, Kd, Ip, c1, c2, c3);
                Final_I = Final_I + I;

                if (Enable_Especular) {
                    V = getNormVectorFromPoints(intersection,eye);
                    R = vectorScale (&N, (productLN * 2));
                    R = vectorDiff (&R,&L);
                    productVR = vectorDotProduct(&V,&R);
                    if(productVR < 0) productVR = 0;
                    productVR = (powl(productVR,Kn));
                    E = get_partial_especular(productVR, Distance, Ks, Ip, c1, c2, c3);
                    Final_E = Final_E + E; 
                }
            }
        }
    }

    Final_I = Final_I + (Ia * Ka);
    if (Final_I > 1 || !Enable_intensity ) {Final_I = 1;}
    if (Final_E > 1) {Final_E = 1;}

    final_color.r = Final_I * color.r;
    final_color.g = Final_I * color.g;
    final_color.b = Final_I * color.b;

    if (Enable_Especular){
        final_color.r = final_color.r + (Final_E * (1.0 - final_color.r));
        final_color.g = final_color.g + (Final_E * (1.0 - final_color.g));
        final_color.b = final_color.b + (Final_E * (1.0 - final_color.b));
    }

    return final_color;

}


//// GET COLOR ////////////////////////////////////////////////////////////
//Get Color
COLOR get_color(SHAPE_PTR shape, POINT intersection, PointNodePtr Light_list){
    int id = shape->id;
    long double Kd, Ks, Ka, Kn, Ip, c1, c2, c3, dotprod;
    VECTOR N,D;
    COLOR final_color, base_color;
    
    base_color = shape->color;
    Kd = shape->Kd;
    Ks = shape->Ks;
    Ka = shape->Ka;
    Kn = shape->Kn;
    c1 = shape->c1;
    c2 = shape->c2;
    c3 = shape->c3;

//Color for spheres
    if (id == 0){
        SPHERE s = (shape->shape).sphere;
        N = get_normal_sphere(&s, intersection);
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    } 
    else if (id == 2){
        PLANE p = (shape->shape).plane;
        N = get_normal_plane(&p);
        D = getNormVectorFromPoints (eye,intersection);
        dotprod = vectorDotProduct (&N,&D);
        if (dotprod > 0 ) {N=vectorScale(&N,-1);}
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    }
    else if (id == 3){
        PLANE p = ((shape->shape).polygon).plane;
        N = get_normal_plane(&p);
        D = getNormVectorFromPoints (eye,intersection);
        dotprod = vectorDotProduct (&N,&D);
        if (dotprod > 0 ) {N=vectorScale(&N,-1);}
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    }
    else if (id == 4){
        CYLINDER c = (shape->shape).cylinder;
        N = get_normal_cylinder(&c,intersection);
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    }
    else if (id == 5){
        PLANE p = ((shape->shape).disc).plane;
        N = get_normal_plane(&p);
        D = getNormVectorFromPoints (eye,intersection);
        dotprod = vectorDotProduct (&N,&D);
        if (dotprod > 0 ) {N=vectorScale(&N,-1);}
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    }
    else if (id == 5){
        CYLINDER c = ((shape->shape).fcylinder).cylinder;
        N = get_normal_cylinder(&c,intersection);
        final_color = get_shape_color (N, base_color,intersection, Light_list, Kd, Ks, c1, c2, c3, Ka, Kn);
    }
    return final_color;

}