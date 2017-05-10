#include <stdio.h>
#include "list.c"
#include "shapes.c"

bool iterate_shape(void *data){
    printShape((SHAPE_PTR)data);
    return TRUE;
}

int main(){
    SPHERE s1 = create_sphere((POINT){5.0, 6, 10.0}, 4.0);
    SPHERE s2 = create_sphere((POINT){10.0, 40.0, 50}, 10.0);
    CONE c1 = create_cone((POINT){4.0, 20.5, 80.0}, 100.0, 40.0);
    // conePrint(&c1);

    // shape init'
    SHAPE x3 = {1, ((COLOR){0.1,0.5,0.3}), 0.4, 0.5, 0.5,0.0, (SHAPE_U)c1};
    SHAPE x1 = {0, ((COLOR){1.0,0.1,0.2}), 1.0, 1.0, 0.0,0.0, (SHAPE_U)s1};
    SHAPE x2 = {0, ((COLOR){0.0,1.0,0.8}), 1.0, 1.0, 0.0,0.0, (SHAPE_U)s2};
    
    //spherePrint(&(x1.shape.sphere));

    list shapeList;
    list_new(&shapeList, sizeof(SHAPE), NULL);
    list_append(&shapeList, &x1);
    list_append(&shapeList, &x2);
    list_append(&shapeList, &x3);
    list_for_each(&shapeList, iterate_shape);
}