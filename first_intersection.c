#include <float.h>

bool iterate_shape(void *data){
//    printShape((SHAPE_PTR)data);
    inter = get_sphere_intersection (&ray, &((((SHAPE_PTR)data)->shape).sphere));

    if (inter != NULL) {
        if ((tmin > inter->t) && (inter->t > EPSILON)) {
            ptr = (SHAPE_PTR)data;
            tmin = inter->t;    
        }
    }
    return TRUE;
}

//First Intersection
SHAPE_PTR first_intersection (list *shapeList) {
    tmin=LDBL_MAX;
    ptr = NULL;
    list_for_each(shapeList, iterate_shape);
    return ptr;
}