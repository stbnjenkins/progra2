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

//Change Ip on FLight
void change_ip_node (int index, long double Ip, PointNodePtr first) {
    PointNodePtr ptr= first;
    int actual_index = 0;
    if (first == NULL){
        printf("\nEMPTY LIST:");
        printf(":No nodes in the list to display\n");
    } else{
        for (actual_index = 0; actual_index < index; actual_index++ ){
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("Wrong Index for Light, Exiting...\n");
                exit(0);
            }
        }
         ptr->Ip=Ip + ptr->Ip;
         if ((ptr->Ip) < 0) {ptr->Ip=0;}
         else if ((ptr->Ip) > 1) {ptr->Ip=1;}
         printf("Cambiando Ip de Luz %d:%Lf\n", index, ptr->Ip);
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
