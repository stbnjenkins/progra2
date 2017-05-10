
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
            // printf("Reiniciar\n");
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
            // printf("Reiniciar\n");
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
                // printf("%d\n", fill_mode);
				return;
		case GLUT_KEY_F2 :
				// printf("%d\n", fill_mode);
				return;
		case GLUT_KEY_F3 :
				// printf("%d\n", fill_mode);
				return;
        case GLUT_KEY_LEFT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    // printf("Pan left con shift\n");
                    return;
                }
				// printf("Pan left\n");
				return;
        case GLUT_KEY_RIGHT :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    // printf("Pan right con shift\n");
                    return;
                }
				// printf("Pan right\n");
				return;
        case GLUT_KEY_DOWN :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    // printf("Pan down con shift\n");
                    return;
                }
				// printf("Pan down\n");
				return;
        case GLUT_KEY_UP :
                if (mod == (GLUT_ACTIVE_SHIFT)) {
                    // printf("Pan up con shift\n");
                    return;
                }
				// printf("Pan up\n");
				return;
	}
}