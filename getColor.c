#include <math.h>

//Get Partial Intensity
long double get_partial_intensity(VECTOR N, VECTOR L,long double Distance, long double Kd, long double Ip, long double c1, long double c2, long double c3){
    long double partial_I, Fatt;

    Fatt = 1 / (c1 + (Distance*c2) + (powl(Distance,2)*c3));
    
    if (Fatt > 1) {Fatt = 1;}

    partial_I = (vectorDotProduct(&L, &N)) * Kd * Ip * Fatt ;

    if (partial_I < 0) {partial_I = 0;}

    return partial_I;
}

//Get Color for spheres
COLOR get_sphere_color (SPHERE_PTR sphere, COLOR color, POINT intersection, PointNodePtr Light_list, long double Kd, long double c1,long double c2, long double c3, long double Ia, long double Ka) {
    PointNodePtr ptr;
    VECTOR L,N;
    COLOR final_color;
    long double Distance, I, Ip, Final_I;

    Final_I = 0;

    N = get_normal_sphere(sphere, intersection);

    if (Light_list== NULL){
        final_color = color;

    } else{
        for (ptr = Light_list;ptr != NULL;ptr = ptr->next){ 
            Ip = ptr->Ip;
            L = getNormVectorFromPoints(intersection,ptr->point); 
            Distance = getDistance(intersection, ptr->point);
            I = get_partial_intensity(N, L, Distance, Kd, Ip, c1, c2, c3);
            Final_I = Final_I + I;
        }
    }

    Final_I = Final_I + (Ia * Ka);
    if (Final_I > 1) {Final_I = 1;}

    final_color.r = Final_I * color.r;
    final_color.g = Final_I * color.g;
    final_color.b = Final_I * color.b;

    return final_color;

}

//Get Color
COLOR get_color(SHAPE_PTR shape, POINT intersection, PointNodePtr Light_list, long double Ia, long double Ka){
    int id = shape->id;
    long double Kd, Ip, c1, c2, c3;
    COLOR final_color, base_color;
    
    base_color = shape->color;
    Kd = shape->Kd;
    c1 = shape->c1;
    c2 = shape->c2;
    c3 = shape->c3;

//Color for spheres
    if (id == 0){
        SPHERE s = (shape->shape).sphere;
        final_color = get_sphere_color (&s, base_color,intersection, Light_list, Kd, c1, c2, c3, Ia, Ka);
    }

    return final_color;

}