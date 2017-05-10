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
        }
    }
    return TRUE;
}

//RAy Tracher
void ray_tracer (list *shapeList, POINT_PTR eye, int resx, int resy){
    int i, j;

     for (i = 0; i < resx; i++) {
       for (j = 0; j < resy; j++) {
            tmin=LDBL_MAX;
            ptr = NULL;
            ray = find_ray (eye, i, j);
            list_for_each(shapeList, iterate_shape);

            if (ptr != NULL) { 
                plot(resx, resy, i, j, (ptr->color).r, (ptr->color).g, (ptr->color).b);
            }
       }
     }
}