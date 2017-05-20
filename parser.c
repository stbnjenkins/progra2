#include <stdio.h>
#include <stdlib.h>


list parseFile(){
    FILE *fp;
    char str1[20];
    long double n1,n2,n3,n4;
    COLOR color;
    long double kd, ks, ka, kn, c1, c2, c3;
    POINT center;
    long double r;
    long double a,b,c,d;
    printf("Opening file...");
    fp = fopen("test.txt", "r+");
    printf("File opened\n");
    
    list_new(&shapeList, sizeof(SHAPE), NULL);

    // Process file
    while(!feof(fp)){
        fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
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
            ks = n1;

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
            printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }

        if(strcmp("PLANE", str1) == 0){
            printf("ENTRE EN PLAAAAAANE\n\n");
            // radio
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
            ks = n1;

            //kn
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            kn = n1;
            // color
            fscanf(fp, "%s %Lf %Lf %Lf %Lf", str1, &n1, &n2, &n3, &n4);
            color.r = n1;
            color.g = n2;
            color.b = n3;

            PLANE p1 = create_plane(0, 1, 0, 0);
            SHAPE x1 = {2, color, kd,ks,ka,kn,c1,c2,c3, (SHAPE_U)p1};
            printShape(&x1);
            list_append(&shapeList, &x1);
            continue;
        }
        
    }


    printf("Closing file...");
    fclose(fp);
    printf("File closed\n");
    return shapeList;
}