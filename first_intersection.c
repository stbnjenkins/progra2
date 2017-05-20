#include <float.h>

bool iterate_shape(void *data){
    int id=((SHAPE_PTR)data)->id;
    inter = NULL;
    if (id == 0) {
        inter = get_sphere_intersection (&ray, &((((SHAPE_PTR)data)->shape).sphere));
    }
    else if (id == 2){
        inter = get_plane_intersection (&ray, &((((SHAPE_PTR)data)->shape).plane));
    }

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