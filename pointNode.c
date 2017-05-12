#include "point.h"

typedef struct PointNode{
    POINT point;
    long double Ip;
    struct PointNode *next;
} PointNode, *PointNodePtr;

// Creating List
PointNodePtr create_list(){
    PointNodePtr first;
    first = NULL;
    return first;
}

// Creating Node
PointNodePtr create_node(POINT myPoint, long double Ip){
    PointNodePtr newnode = (PointNodePtr) malloc(sizeof(PointNode));
    if (newnode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    } else {
        newnode->point = myPoint;
        newnode->Ip = Ip;
        newnode->next = NULL;
        return newnode;
    }
}

//Inserting Node at Last
 PointNodePtr insert_node_last(POINT myPoint, long double Ip, PointNodePtr first){
    PointNodePtr ptr, newnode;
    newnode = create_node(myPoint, Ip);

    if (first == NULL) {
        first = newnode;
        first->next = NULL;
        return first;
    } else {
        for (ptr = first;ptr != NULL;ptr = ptr->next) {    
            if (ptr->next == NULL){
                ptr->next = newnode;
                newnode->next = NULL;                    
                return first;
            }
        }
    }
}    

// Displays non-empty List from Beginning to End
void display(PointNodePtr first){
    PointNodePtr ptr;
    if (first == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else{
        for (ptr = first;ptr != NULL;ptr = ptr->next){    
            printf("Point.x -> %Lf\nPoint.y -> %Lf\nPoint.z -> %Lf\n", (ptr->point).x, (ptr->point).y, (ptr->point).z);
        }
    }
}