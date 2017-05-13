#include <float.h>

//RAY TRACER CODE

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