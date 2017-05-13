#include <float.h>

//RAY TRACER CODE

// bool iterate_shape(void *data){
// //    printShape((SHAPE_PTR)data);
//     inter = get_sphere_intersection (&ray, &((((SHAPE_PTR)data)->shape).sphere));

//     if (inter != NULL) {
//         if ((tmin > inter->t) && (inter->t > EPSILON)) {
//             ptr = (SHAPE_PTR)data;
//             tmin = inter->t;    
//         }
//     }
//     return TRUE;
// }

// //First Intersection
// SHAPE_PTR first_intersection (list *shapeList) {
//     tmin=LDBL_MAX;
//     ptr = NULL;
//     list_for_each(shapeList, iterate_shape);
//     return ptr;
// }

//RAy Tracer
void ray_tracer (list *shapeList, POINT_PTR eye, int resx, int resy, PointNodePtr Light_list){
    int i, j;
    COLOR color;
    POINT intersection;

     for (i = 0; i < resx; i++) {
       for (j = 0; j < resy; j++) {

//First Intersection
            ray = find_ray (eye, i, j);
            ptr = first_intersection(shapeList);

//De que color

            if (ptr != NULL) { 
                intersection = get_point_from_ray (&ray, tmin);
                
                color = get_color(ptr, intersection, Light_list);
 
                plot(resx, resy, i, j, color.r, color.g, color.b);
 
            }
       }
     }
}