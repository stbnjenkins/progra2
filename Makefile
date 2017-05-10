make:
	gcc main.c -o raytracing.out -lGL -lGLU -lglut -std=c99 -fno-builtin -lm -D_GNU_SOURCE