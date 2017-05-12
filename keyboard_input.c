
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
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Zoom in con shift\n");
                return;
            }
            // printf("Zoom in\n");
            return;
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
            if (mod == (GLUT_ACTIVE_SHIFT)) {
                // printf("Zoom in con shift\n");
                return;
            }
            // printf("Zoom in\n");
            return;
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
                list_for_each(&shapeList, constant);
                frame_plotter (resx, resy, shapeList, eye);
				return;
		case GLUT_KEY_F2 :
                list_for_each(&shapeList, linear);
                frame_plotter (resx, resy, shapeList, eye);
				return;
		case GLUT_KEY_F3 :
				list_for_each(&shapeList, quadratic);
				frame_plotter (resx, resy, shapeList, eye);
				return;

        case GLUT_KEY_DOWN :
                Ia -= 0.2;
                if(Ia<0) Ia = 0.0;
                frame_plotter (resx, resy, shapeList, eye);
				return;
        case GLUT_KEY_UP :
                Ia += 0.2;
                if(Ia>1) Ia = 1.0;
                frame_plotter (resx, resy, shapeList, eye);
				return;
	}
}
