#include <float.h>

//RAY TRACER CODE

//RAy Tracer
void ray_tracer (POINT_PTR eye, int resx, int resy, PointNodePtr Light_list){
    int i, j;
    COLOR color;
    POINT intersection;

     for (i = 0; i < resx; i++) {
       for (j = 0; j < resy; j++) {

            //de que color
            ray = find_ray (eye, i, j);
            color = get_color2(reflection_levels);
            plot(resx, resy, i, j, color.r, color.g, color.b);

       }
     }
}