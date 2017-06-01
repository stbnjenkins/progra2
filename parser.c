#include <stdio.h>
#include <stdlib.h>
#include "general.h"

void parseFile(){
    FILE *fp;
    char str1[20];
    long double n1,n2,n3,n4;
    COLOR color;
    long double kd, ks, ka, kn, c1, c2, c3, o1,o2;
    POINT center, p;
    long double r,l1, l2;
    long double a,b,c,d,h;
    int v, jj;
    VECTOR myvector;
    printf("Opening file...");
    fp = fopen("test2.txt", "r+");
    printf("File opened\n");
    
    list_new(&shapeList, sizeof(SHAPE), NULL);

    // Process file
    while(!feof(fp)){
        fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
        if(strcmp("EYE", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            eye.x = n1;
            eye.y = n2;
            eye.z = n3;
            continue;
        }
        if(strcmp("IA", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            Ia = n1;
            continue;
        }
        if(strcmp("ENSITY", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            Enable_intensity = (int)n1;

            continue;
        }
        if(strcmp("SHADOW", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            Enable_Shadow = (int)n1;
            continue;
        }
        if(strcmp("ESPECULAR", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            Enable_Especular = (int)n1;
            continue;
        }
        if(strcmp("RESOLUTION", str1) == 0){
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            resx = (int)n1;
            resy = (int)n2;
            continue;
        }
        if(strcmp("SPHERE", str1) == 0){
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }

                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;      
                    continue;          
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;  
                    continue;               
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;  
                    continue;               
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;  
                    continue;               
                }

                if(strcmp("END", str1) == 0){
                    SPHERE s1 = create_sphere(center, r);
                    SHAPE x1 = {SPHERE_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)s1};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
            
        }

        if(strcmp("MYDISC", str1) == 0){
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }
                if(strcmp("vector", str1) == 0){
                    //vector
                    myvector.x = n1;
                    myvector.y = n2;
                    myvector.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;   
                    continue;             
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;     
                    continue;            
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;     
                    continue;            
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;     
                    continue;            
                }

                if(strcmp("END", str1) == 0){
                    normalizeVector(&myvector);
                    DISC d1 = create_disc(center, r, myvector);
                    SHAPE x1 = {DISC_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)d1};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        }

       if(strcmp("CONE", str1) == 0){
           while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("d", str1) == 0){
                    // radio
                    d = n1;
                    continue; 
                }
                if(strcmp("h", str1) == 0){
                    // radio
                    h = n1;
                    continue; 
                }
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }
                if(strcmp("vector", str1) == 0){
                    //vector
                    myvector.x = n1;
                    myvector.y = n2;
                    myvector.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;     
                    continue;           
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1; 
                    continue;                
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;     
                    continue;            
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3; 
                    continue;                
                }

                if(strcmp("END", str1) == 0){
                    normalizeVector(&myvector);
                    CONE con = create_cone(center, d, h, myvector);
                    SHAPE x1 = {CONE_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)con};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        } 


       if(strcmp("FCONE", str1) == 0){
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("d", str1) == 0){
                    // radio
                    d = n1;
                    continue; 
                }
                if(strcmp("h", str1) == 0){
                    // radio
                    h = n1;
                    continue; 
                }
                if(strcmp("l1", str1) == 0){
                    // radio
                    l1 = n1;
                    continue; 
                }
                if(strcmp("l2", str1) == 0){
                    // radio
                    l2 = n1;
                    continue; 
                }
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }
                if(strcmp("vector", str1) == 0){
                    //vector
                    myvector.x = n1;
                    myvector.y = n2;
                    myvector.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;  
                    continue;              
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;  
                    continue;               
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;   
                    continue;              
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;  
                    continue;               
                }

                if(strcmp("END", str1) == 0){
                    normalizeVector(&myvector);
                    FCONE fcon = create_fcone(center, d, h, myvector, l1, l2);
                    SHAPE x1 = {FCONE_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)fcon};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        } 

        if(strcmp("CYLINDER", str1) == 0){

            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }
                if(strcmp("vector", str1) == 0){
                    //vector
                    myvector.x = n1;
                    myvector.y = n2;
                    myvector.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;   
                    continue;             
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;     
                    continue;            
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;   
                    continue;              
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;   
                    continue;              
                }

                if(strcmp("END", str1) == 0){
                    normalizeVector(&myvector);
                    CYLINDER cil = create_cylinder(center, r, myvector);
                    SHAPE x1 = {CYLINDER_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)cil};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        }

        if(strcmp("FCYLINDER", str1) == 0){
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("radio", str1) == 0){
                    // radio
                    r = n1;
                    continue; 
                }
                if(strcmp("l1", str1) == 0){
                    // radio
                    l1 = n1;
                    continue; 
                }
                if(strcmp("l2", str1) == 0){
                    // radio
                    l2 = n1;
                    continue; 
                }
                if(strcmp("centro", str1) == 0){
                    // centro
                    center.x = n1;
                    center.y = n2;
                    center.z = n3;
                    continue; 
                }
                if(strcmp("vector", str1) == 0){
                    //vector
                    myvector.x = n1;
                    myvector.y = n2;
                    myvector.z = n3;
                    continue; 
                }

                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1; 
                    continue;               
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;      
                    continue;           
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;   
                    continue;              
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;    
                    continue;             
                }

                if(strcmp("END", str1) == 0){
                    normalizeVector(&myvector);
                    FCYLINDER cil = create_fcylinder(center, r, myvector, l1, l2);
                    SHAPE x1 = {FCYLINDER_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)cil};
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        }


        if(strcmp("PLANE", str1) == 0){
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("coef", str1) == 0){
                    //coeficientes
                    a = n1;
                    b = n2;
                    c = n3;
                    d = n4;
                    continue; 
                }
                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1;   
                    continue;             
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;   
                    continue;              
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1; 
                    continue;                
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;      
                    continue;           
                }

                if(strcmp("END", str1) == 0){
                    PLANE p1 = create_plane(a, b, c, d);
                    SHAPE x1 = {PLANE_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)p1};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }
        }

        if(strcmp("POLYGON", str1) == 0){
            POLYGON poly;
            while(1){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                if(strcmp("v_number", str1) == 0){
                    v = (int) n1;
                    jj = 0;
                    poly = create_empty_polygon();
                    while(jj < v){
                        fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                        p.x = n1;
                        p.y = n2;
                        p.z = n3;
                        addVertex(&poly, p);
                        jj++;
                    }
                    continue; 
                }
                if(strcmp("c1", str1) == 0){
                    // c1
                    c1 = n1;
                    continue; 
                }

                if(strcmp("c2", str1) == 0){
                    // c2
                    c2 = n1;
                    continue; 
                }

                if(strcmp("c3", str1) == 0){
                    // c3
                    c3 = n1;
                    continue; 
                }
                if(strcmp("o1", str1) == 0){
                    // o1
                    o1 = n1;
                    continue; 
                }

                if(strcmp("o2", str1) == 0){
                    // o2
                    o2 = n1;
                    continue; 
                }

                if(strcmp("kd", str1) == 0){
                    // kd
                    kd = n1; 
                    continue;              
                }

                if(strcmp("ks", str1) == 0){
                    //ks
                    ks = n1;         
                    continue;        
                }

                if(strcmp("ka", str1) == 0){
                    //ka
                    ka = n1;
                    continue; 
                }

                if(strcmp("kn", str1) == 0){
                    //kn
                    kn = n1;
                    continue;                 
                }

                if(strcmp("color", str1) == 0){
                    // color
                    color.r = n1;
                    color.g = n2;
                    color.b = n3;         
                    continue;       
                }

                if(strcmp("END", str1) == 0){
                    put_plane_on_polygon(&poly);
                    SHAPE x1 = {POLYGON_ID, color, kd,ks,ka,kn,c1,c2,c3,o1,o2, (SHAPE_U)poly};
                    // printShape(&x1);
                    list_append(&shapeList, &x1);
                    break;
                }
            }

        }
        
    }

    printf("Closing file...");
    fclose(fp);
    printf("File closed\n");
    return;
}