//frame manager

//Initialize Shapes
list create_list_of_shapes(){

//Define Shapes
    SPHERE s1 = create_sphere((POINT){800.0, 300.0, 1000.0}, 450.0);
    SPHERE s2 = create_sphere((POINT){950.0, 200.0, 200.0}, 200.0);
    SPHERE s3 = create_sphere((POINT){100.0, 300.0, 2000.0}, 450.0);
    SPHERE s4 = create_sphere((POINT){160.0, 180.0, 400.0}, 250.0);

//Put shape attribute
    SHAPE x1 = {0, ((COLOR){0.0,1.0,0.0}), 1.0, 2.0, 0.0,0.0, (SHAPE_U)s1};
    SHAPE x2 = {0, ((COLOR){0.0,0.0,1.0}), 1.0, 2.0, 0.0,0.0, (SHAPE_U)s2};
    SHAPE x3 = {0, ((COLOR){1.0,0.0,0.0}), 1.0, 2.0, 0.0,0.0, (SHAPE_U)s3};
    SHAPE x4 = {0, ((COLOR){1.0,0.93,0.0}), 1.0, 2.0, 0.0,0.0, (SHAPE_U)s4};

//Create List
    list_new(&shapeList, sizeof(SHAPE), NULL);
    list_append(&shapeList, &x1);
    list_append(&shapeList, &x2);
    list_append(&shapeList, &x3);
    list_append(&shapeList, &x4);

    return shapeList;
}

//Initialize Lights
void create_list_of_lights() {
    POINT light1; light1.x = 2000.0; light1.y = 2000.0; light1.z = -1000.0; 
    Light_list = insert_node_last(light1, 1.0, Light_list);
    POINT light2; light2.x = 0.0; light2.y = 2000.0; light2.z = -500.0; 
    Light_list = insert_node_last(light2, 0.0, Light_list);
    POINT light3; light3.x = 550.0; light3.y = 2000.0; light3.z = 500.0; 
    Light_list = insert_node_last(light3, 0.0, Light_list);
}

//Run plotter
void frame_plotter (int resx, int resy, list shapeList, POINT eye){
    ini_buffer(resx, resy);
    plot_framebuffer(resx,resy);

    ray_tracer(&shapeList, &eye, resx, resy, Light_list, Ia, Ka);

    plot_framebuffer(resx,resy);

} 

//Initialize frame
void initialize_frame(int resx, int resy){
    POINT eye; eye.x = 550.0; eye.y = 400.0; eye.z = -2000.0;
    shapeList = create_list_of_shapes();
 //   create_list_of_lights();
    frame_plotter (resx, resy, shapeList, eye); 
}

//Change Ia


//CHange Ka


//Change Ip per light
