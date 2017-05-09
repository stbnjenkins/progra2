//Begining
/*TAGS
    0 -> esphere
*/

#include "color.h"
#include "real_point.h"

typedef struct Figure_Node{
    int tag;
    double R;
    COLOR_PTR color;
    Real_PointPtr center;
    struct Figure_Node *next;
} Figure_Node, *Figure_NodePtr;

//Creating Node
Figure_NodePtr figure_create_list(){
    Figure_NodePtr first;
    first = NULL;
    return first;
}

//Creating Node
Figure_NodePtr figure_create_node(Real_PointPtr center, double R, int tag, COLOR_PTR color){
    Figure_NodePtr newnode = (Figure_NodePtr) malloc(sizeof(Figure_Node));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newnode->center = center;
        newnode->R = R;
        newnode->tag=0;
        newnode->color=color;
        newnode->next = NULL;
        return newnode;
    }
}

//Inserting Node at Last
Figure_NodePtr figure_insert_node_last(Real_PointPtr center, double R, int tag, COLOR_PTR color, Figure_NodePtr first){
    Figure_NodePtr ptr,newnode;  
    newnode = figure_create_node(center, R, tag, color);
    if (first == NULL) {
        first = newnode;
        first->next = NULL;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;
                return first;
            }
        }
    }
}   