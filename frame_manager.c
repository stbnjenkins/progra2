//frame manager

//Initialize Shapes
list create_list_of_shapes(){

//Define Shapes
    SPHERE s1 = create_sphere((POINT){800.0, 450.0, 1000.0}, 450.0);
    SPHERE s2 = create_sphere((POINT){950.0, 200.0, 200.0}, 200.0);
    SPHERE s3 = create_sphere((POINT){100.0, 450.0, 2000.0}, 450.0);
    SPHERE s4 = create_sphere((POINT){160.0, 250.0, 400.0}, 250.0);
    PLANE pl = create_plane(0, 1, 0, 0);

//Put Table
    POINT p1 = {x: 200.0, y: 200.0, z: 0.0};
    POINT p2 = {x: 200.0, y: 200.0, z: 800.0};
    POINT p3 = {x: 900.0, y: 200.0, z: 800.0};
    POINT p4 = {x: 900.0, y: 200.0, z: 0.0};
    POLYGON poly = create_polygon(4, p1,p2,p3,p4);

//Put shape attribute kd,,ka,c1,c2,c3
    SHAPE x1 = {0, ((COLOR){0.0,1.0,0.0}), 1.0,1.0,0.5,10.0,2.0,0.0,0.0, (SHAPE_U)s1};
    SHAPE x2 = {0, ((COLOR){0.0,0.0,1.0}), 1.0,1.0,0.1,10.0,2.0,0.0,0.0, (SHAPE_U)s2};
    SHAPE x3 = {0, ((COLOR){1.0,0.0,0.0}), 1.0,1.0,0.9,10.0,2.0,0.0,0.0, (SHAPE_U)s3};
    SHAPE x4 = {0, ((COLOR){1.0,0.93,0.0}), 1.0,1.0,0.7,10.0,2.0,0.0,0.0, (SHAPE_U)s4};
    SHAPE x5 = {2, ((COLOR){0.5,0.5,0.5}), 1.0, 1.0,1.0,10.0,2.0,0.0,0.0, (SHAPE_U)pl};
    SHAPE x6 = {3, ((COLOR){0.8,0.8,0.8}), 1.0, 1.0,1.0,10.0,2.0,0.0,0.0, (SHAPE_U)poly};

//Create List
    list_new(&shapeList, sizeof(SHAPE), NULL);
    list_append(&shapeList, &x1);
    list_append(&shapeList, &x2);
    list_append(&shapeList, &x3);
    list_append(&shapeList, &x4);
    list_append(&shapeList, &x5);
    list_append(&shapeList, &x6);

    return shapeList;
}

//Initialize Lights
void create_list_of_lights() {
    POINT light1; light1.x = 2000.0; light1.y = 2000.0; light1.z = -1000.0; 
    Light_list = insert_node_last(light1, 0.2, Light_list);
    POINT light2; light2.x = 0.0; light2.y = 2000.0; light2.z = -500.0; 
    Light_list = insert_node_last(light2, 0.8, Light_list);
    POINT light3; light3.x = 550.0; light3.y = 2000.0; light3.z = 500.0; 
    Light_list = insert_node_last(light3, 0.6, Light_list);
}

//Run plotter
void frame_plotter (int resx, int resy, POINT eye){
    ini_buffer(resx, resy);
    plot_framebuffer(resx,resy);

    ray_tracer(&eye, resx, resy, Light_list);

    plot_framebuffer(resx,resy);

} 

//Initialize frame
void initialize_frame(int resx, int resy){
    list_destroy(&shapeList);
    parseFile();
    frame_plotter (resx, resy, eye); 
}

