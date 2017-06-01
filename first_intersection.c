#include <float.h>

bool iterate_shape(void *data){
    int id=((SHAPE_PTR)data)->id;
    inter = NULL;
    if (id == SPHERE_ID) {
        inter = get_sphere_intersection (&ray, &((((SHAPE_PTR)data)->shape).sphere));
    }
    else if (id == CONE_ID){
        inter = get_cone_intersection (&ray, &((((SHAPE_PTR)data)->shape).cone));
    }
    else if (id == FCONE_ID){
        inter = get_fcone_intersection (&ray, &((((SHAPE_PTR)data)->shape).fcone));
    }
    else if (id == PLANE_ID){
        inter = get_plane_intersection (&ray, &((((SHAPE_PTR)data)->shape).plane));
    }
    else if (id == POLYGON_ID){
        inter = get_polygon_intersection (&ray, &((((SHAPE_PTR)data)->shape).polygon));
    }
    else if (id == CYLINDER_ID){
        inter = get_cylinder_intersection (&ray, &((((SHAPE_PTR)data)->shape).cylinder));
    }
    else if (id == DISC_ID){
        inter = get_disc_intersection (&ray, &((((SHAPE_PTR)data)->shape).disc));
    }
    else if (id == FCYLINDER_ID){
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