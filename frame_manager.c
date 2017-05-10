//frame manager

Figure_NodePtr list_of_figures = NULL;

//create list of provinces poligons
Figure_NodePtr create_list_of_figures (){
    Figure_NodePtr first = figure_create_list();

    Real_PointPtr center; 
    double R; 
    int tag; 
    COLOR_PTR color;

    //Inserting first figure
    center->x=100.0;center->y=100.0;center->z=100.0;
    R= 10;
    tag=0;
    color->r=1;color->g=0;color->b=0;
    first = figure_insert_node_last(center, R, tag, color, first);
    return first;
}


//Run plotter with mode
void frame_plotter (int res){
    ini_buffer(res, res);

    list_of_figures = create_list_of_figures();

    //call some function to plot
    
} 