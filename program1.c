#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h> //following libraries are for generating random number
#include <time.h>   //for the random selection of global vertex


//global list of vertices group in pairs of 2
//A call to glVertexPointer(2, GL_FLOAT, position_in_array, global_triangle_vertices);
//will access each point of the equilateral triangle 
GLfloat global_triangle_vertices[] = {0.5, 0.75, 0.25, 0.25, 0.75, 0.25, 0.1, 0.1};
//each vertex pair can be accessed through glArrayElement(position). position is groups of 2


void display() {

   glClear (GL_COLOR_BUFFER_BIT); //as stated in class the display function always starts with clear
   glColor3f (1.0, 1.0, 1.0); //white points with black background
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2, GL_FLOAT, 0, global_triangle_vertices);
   
   //glBegin(GL_POINTS); //draw our points from global array
   glDrawArrays(GL_POINTS, 0, 4);
   
   glDisableClientState(GL_VERTEX_ARRAY);
   //glArrayElement(3);
   //glEnd();
   //glutSwapBuffers();
   glFlush();
   
}

void init() {

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
void reshape(int w, int h) {
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int return_random_int() { //
   int int_to_return = rand() % 3; //we have 3 vertices
   return int_to_return;
}

void draw_midpoints() {
   
   global_triangle_vertices[6] = 0.5;
   global_triangle_vertices[7] = 0.5;
   glutPostRedisplay();
   /*
   glClear (GL_COLOR_BUFFER_BIT); //as stated in class the display function always starts with clear
   glColor3f (1.0, 1.0, 1.0); //white points with black background
   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2, GL_FLOAT, 0, global_triangle_vertices);
   glDrawArrays(GL_POINTS, 0, 4);
   glDisableClientState(GL_VERTEX_ARRAY); 
   */
}


void calculate_midpoints() {

}

int main(int argc, char** argv) {
   srand(time(NULL)); //seed our random number generator

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (750, 750);//make a big window
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("Jacob Webb Program 1");
   init();
   glutDisplayFunc(display);
   //glutKeyboardFunc(calculate_midpoints);
   
   draw_midpoints();
   
   
   glutMainLoop();
   
   return 0;   /* ANSI C requires main to return int. */
}