
void ray_tracer (POINT_PTR eye, int resx, int resy){
    int i, j;

    SPHERE my_sphere = create_sphere((POINT){550.0 ,400.0 ,10000.0},10000.0);

    MAGNITUD_PTR t;
    RAY ray;

     for (i = 0; i < resx; i++) {
       for (j = 0; j < resy; j++) {

            ray = find_ray (eye, i, j);

            t = get_sphere_intersection (&ray, &my_sphere);

            if (t != NULL) {
                plot(resx, resy, i, j, 0.0, 0.0, 0.0);
            }

   //         exit(0);

       }
     }
}