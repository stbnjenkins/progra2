
void processNormalKeys(unsigned char key, int x, int y) {
    int mod = glutGetModifiers();
	switch(key){
        case 27: //escape
            exit(0);
        case 74: // J
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Rotar manecillas reloj con shift\n");
                return;
            }
            // printf("Rotar manecillas reloj\n");
            return;
        case 75: // K
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Rotar contrario manecillas reloj con shift\n");
                return;
            }
            // printf("Rotar contrario manecillas reloj\n");
            return;
        case 81: // Q
            exit(0);
        case 82: // R
            printf("Reiniciando\n");
            initialize_frame(resx, resy);
            return;
        case 88: // X
            if (Enable_Shadow == 0) {
                printf("Habilitando Sombra\n");
                Enable_Shadow = 1;
                frame_plotter (resx, resy, shapeList, eye);
                return;
            } else {
                printf("Deshabilitando Sombra\n");
                Enable_Shadow = 0;
                frame_plotter (resx, resy, shapeList, eye);
                return;
            }
        case 90: // Z
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Zoom out con shift\n");
                return;
            }
            // printf("Zoom out\n");
            return;
        case 106: // j
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Rotar manecillas reloj con shift\n");
                return;
            }
            // printf("Rotar manecillas reloj\n");
            return;
        case 107: // k
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Rotar contrario manecillas reloj con shift\n");
                return;
            }
            // printf("Rotar contrario manecillas reloj\n");
            return;
        case 113: // q
            exit(0);
        case 114: // r
            printf("Reiniciando\n");
            initialize_frame(resx, resy);
            return;        
        case 120: // x
            if (Enable_Shadow == 0) {
                printf("Habilitando Sombra\n");
                Enable_Shadow = 1;
                frame_plotter (resx, resy, shapeList, eye);
                return;
            } else {
                printf("Deshabilitando Sombra\n");
                Enable_Shadow = 0;
                frame_plotter (resx, resy, shapeList, eye);
                return;
            }
        case 122: // z
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Zoom out con shift\n");
                return;
            }
            // printf("Zoom out\n");
            return;
    }
}
// rotacion, pan y zoom
void processSpecialKeys(int key, int x, int y) {
    int mod = glutGetModifiers();
	switch(key) {
		case GLUT_KEY_F1 :
                printf("Factor de Atenuacion Constante\n");
                list_for_each(&shapeList, constant);
                frame_plotter (resx, resy, shapeList, eye);
				return;
		case GLUT_KEY_F2 :
                printf("Factor de Atenuacion Lineal\n");
                list_for_each(&shapeList, linear);
                frame_plotter (resx, resy, shapeList, eye);
				return;
		case GLUT_KEY_F3 :
                printf("Factor de Atenuacion Cuadratico\n");
				list_for_each(&shapeList, quadratic);
				frame_plotter (resx, resy, shapeList, eye);
				return;

        case GLUT_KEY_F4 :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    change_ip_node(0,-0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                } else {
                    change_ip_node(0,0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                }
        case GLUT_KEY_F5 :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    change_ip_node(1,-0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                } else {
                    change_ip_node(1,0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                }
        case GLUT_KEY_F6 :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    change_ip_node(2,-0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                } else {
                    change_ip_node(2,0.2,Light_list);
				    frame_plotter (resx, resy, shapeList, eye);
				    return;
                }


        case GLUT_KEY_DOWN :
                Ia -= 0.2;
                if(Ia<0) Ia = 0.0;
                printf("Disminuyendo Ia:%Lf\n",Ia);
                frame_plotter (resx, resy, shapeList, eye);
				return;
        case GLUT_KEY_UP :
                Ia += 0.2;
                if(Ia>1) Ia = 1.0;
                printf("Aumentando Ia:%Lf\n",Ia);
                frame_plotter (resx, resy, shapeList, eye);
				return;
	}
}
