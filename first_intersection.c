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
    else if (id == 3){
        inter = get_polygon_intersection (&ray, &((((SHAPE_PTR)data)->shape).polygon));
    }
    else if (id == 4){
        inter = get_cylinder_intersection (&ray, &((((SHAPE_PTR)data)->shape).cylinder));
    }
    else if (id == 5){
        inter = get_disc_intersection (&ray, &((((SHAPE_PTR)data)->shape).disc));
    }
    else if (id == 6){
        inter = get_fcylinder_intersection (&ray, &((((SHAPE_PTR)data)->shape).fcylinder));
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