#include <float.h>

MAGNITUD_PTR inter;
SHAPE_PTR ptr = NULL;
RAY ray;
long double tmin;

bool iterate_shape(void *data){
//    printShape((SHAPE_PTR)data);
    inter = get_sphere_intersection (&ray, &((((SHAPE_PTR)data)->shape).sphere));

    if (inter != NULL) {
        if (tmin > inter->t) {
            ptr = (SHAPE_PTR)data;
            tmin = inter->t;    
        }
    }
    return TRUE;
}

//RAy Tracher
void ray_tracer (list *shapeList, POINT_PTR eye, int resx, int resy, PointNodePtr Light_list, long double Ia, long double Ka){
    int i, j;
    COLOR color;
    POINT intersection;

     for (i = 0; i < resx; i++) {
       for (j = 0; j < resy; j++) {
            tmin=LDBL_MAX;
            ptr = NULL;
            ray = find_ray (eye, i, j);
            list_for_each(shapeList, iterate_shape);

            if (ptr != NULL) { 
                intersection = get_point_from_ray (&ray, tmin);
                
                color = get_color(ptr, intersection, Light_list, Ia, Ka);
 
                plot(resx, resy, i, j, color.r, color.g, color.b);
 
            }
       }
     }
}