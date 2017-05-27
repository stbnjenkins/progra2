#include <stdio.h>
#include <stdlib.h>
#include "general.h"

void parseFile(){
    FILE *fp;
    char str1[20];
    long double n1,n2,n3,n4;
    COLOR color;
    long double kd, ks, ka, kn, c1, c2, c3;
    POINT center, p;
    long double r;
    long double a,b,c,d;
    int v, jj;
    VECTOR myvector;
    printf("Opening file...");
    fp = fopen("test.txt", "r+");
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
            // radio
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            r = n1;
            // centro
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            center.x = n1;
            center.y = n2;
            center.z = n3;

            // c1
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c1 = n1;

            // c2
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c2 = n1;

            // c3
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c3 = n1;
            // kd
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kd = n1;

            //ks
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ks = n1;

            //ka
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ka = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            SPHERE s1 = create_sphere(center, r);
            SHAPE x1 = {0, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)s1};
            // printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }

        if(strcmp("MYDISC", str1) == 0){
            // radio
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            r = n1;
            // centro
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            center.x = n1;
            center.y = n2;
            center.z = n3;

            // vector
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            myvector.x = n1;
            myvector.y = n2;
            myvector.z = n3;

            // c1
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c1 = n1;

            // c2
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c2 = n1;

            // c3
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c3 = n1;
            // kd
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kd = n1;

            //ks
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ks = n1;

            //ka
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ka = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            DISC d1 = create_disc(center, r, myvector);
            SHAPE x1 = {5, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)d1};
            // printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }

        if(strcmp("CYLINDER", str1) == 0){
            // radio
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            r = n1;
            // centro
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            center.x = n1;
            center.y = n2;
            center.z = n3;

            // vector Q
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            myvector.x = n1;
            myvector.y = n2;
            myvector.z = n3;

            // c1
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c1 = n1;

            // c2
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c2 = n1;

            // c3
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c3 = n1;
            // kd
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kd = n1;

            //ks
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ks = n1;

            //ka
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ka = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            CYLINDER cil = create_cylinder(center, r, myvector);
            SHAPE x1 = {4, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)cil};
            // printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }


        if(strcmp("PLANE", str1) == 0){
            // coef
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            a = n1;
            b = n2;
            c = n3;
            d = n4;

            // c1
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c1 = n1;

            // c2
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c2 = n1;

            // c3
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c3 = n1;
            // kd
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kd = n1;

            //ks
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ks = n1;

            //ka
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ka = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            PLANE p1 = create_plane(a, b, c, d);
            SHAPE x1 = {2, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)p1};
            // printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }

        if(strcmp("POLYGON", str1) == 0){
            // vertex
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            v = (int) n1;
            jj = 0;
            POLYGON poly = create_empty_polygon();
            while(jj < v){
                fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
                p.x = n1;
                p.y = n2;
                p.z = n3;
                addVertex(&poly, p);
                jj++;
            }

            // c1
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c1 = n1;

            // c2
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c2 = n1;

            // c3
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            c3 = n1;
            // kd
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kd = n1;

            //ks
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ks = n1;

            //ka
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            ka = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            put_plane_on_polygon(&poly);
            SHAPE x1 = {3, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)poly};
            // printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }
        
    }


    printf("Closing file...");
    fclose(fp);
    printf("File closed\n");
    return;
}