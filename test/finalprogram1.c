#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h> //following libraries are for generating random number
#include <time.h>   //for the random selection of global vertex
/*
	IF YOU ARE COMPILING WITH A MAC USE THE FOLLOWING IN THE COMMAND LINE
	gcc -o program1 program1.c -L/System/Library/Frameworks -framework GLUT -framework OpenGL

*/

//global list of vertices group in pairs of 2
//A call to glVertexPointer(2, GL_FLOAT, position_in_array, global_triangle_vertices);
//will access each point of the equilateral triangle 
GLfloat global_triangle_vertices[] = {0.5, 0.75, 0.25, 0.25, 0.75, 0.25, 0.1, 0.1};
//each vertex pair can be accessed through glArrayElement(position). position is groups of 2

int id = 0; //for keyboard callback

void display() {
	
	glClear(GL_COLOR_BUFFER_BIT); //as stated in class the display function always starts with clear
	glColor3f (1.0, 1.0, 1.0); //white points with black background
	glBegin(GL_POINTS);
	glVertex2f(global_triangle_vertices[0], global_triangle_vertices[1]);
	glVertex2f(global_triangle_vertices[2], global_triangle_vertices[3]);
	glVertex2f(global_triangle_vertices[4], global_triangle_vertices[5]);
	glVertex2f(global_triangle_vertices[6], global_triangle_vertices[7]);
	glEnd();
	glFlush();
	int i = 0;
	while(i < 10000) {	
		int random_vertex = rand() %3; //random number from 0-2   
		GLfloat px, py, vx, vy; 
		if(random_vertex == 0) {
			px = global_triangle_vertices[6]; //get values for old x and y of point P
			py = global_triangle_vertices[7]; 
			vx = global_triangle_vertices[0]; //first vertex is position 0 and 1
			vy = global_triangle_vertices[1];
			//calculate midpoint between them
			px = (px+vx)/2;
			py = (py+vy)/2;
			//now update global values and call draw
			global_triangle_vertices[6] = px;
			global_triangle_vertices[7] = py;
		}  
		else if(random_vertex == 1) {
			px = global_triangle_vertices[6]; //get values for old x and y of point P
			py = global_triangle_vertices[7]; 
			vx = global_triangle_vertices[2]; //first vertex is position 0 and 1
			vy = global_triangle_vertices[3];
			//calculate midpoint between them
			px = (px+vx)/2;
			py = (py+vy)/2;
			//now update global values and call draw
			global_triangle_vertices[6] = px;
			global_triangle_vertices[7] = py;
		}
		else if(random_vertex == 2) {
			px = global_triangle_vertices[6]; //get values for old x and y of point P
			py = global_triangle_vertices[7]; 
			vx = global_triangle_vertices[4]; //first vertex is position 0 and 1
			vy = global_triangle_vertices[5];
			//calculate midpoint between them
			px = (px+vx)/2;
			py = (py+vy)/2;
			//now update global values and call draw
			global_triangle_vertices[6] = px;
			global_triangle_vertices[7] = py;
		} 
		i++;
		//draw our new midpoint!
		glColor3f (1.0, 1.0, 1.0); //white points with black background
		glBegin(GL_POINTS);
		glVertex2f(global_triangle_vertices[6], global_triangle_vertices[7]);
		glEnd();
		glFlush();
	}  
}

void init() {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:
         glutDestroyWindow(id);
         exit(0);
         break;
      default:
         break;
   }

}

void reshape(int width, int height) {
   glViewport(0, 0, (GLsizei)width, (GLsizei)height);
   glMatrixMode(GL_PROJECTION);
   //glLoadIdentity();
   glOrtho(0.0, width, 0, height, 0.0, 0.0);
}

int main(int argc, char** argv) {
   srand(time(NULL)); //seed our random number generator

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (450, 450);//make a big window
   glutInitWindowPosition (50, 50);
   id = glutCreateWindow ("Jacob Webb Program 1"); //capture window id
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   
   
   glutMainLoop();
   
   return 0;
}
