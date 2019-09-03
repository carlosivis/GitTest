//Includes
#include <stdio.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
//Defines
#define sizex 500
#define sizey 500
int gamestate = 0;

void setup(){
	glClearColor (0, 0, 0, 1);
}

void escfunc (){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex2f(-200,-200);
		glVertex2f(200,-200);
		glVertex2f(200,200);
		glVertex2f(-200,200);
	glEnd();
	glFlush();

}

void drawscene(){
	if(gamestate==1)
			escfunc();
	else{
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}

}

typedef struct ball
{
	int speedx;
	int speedy;
	int x;
	int y;
} ball;

void resetball (ball x){
}

void keypress (unsigned char key, int x, int y){
	switch (key){
		case 27 :
			if(!gamestate){
				//escfunc();
				glutPostRedisplay();
				gamestate = 1;
			}
			else{
				gamestate = 0;
				glutPostRedisplay();
			}
		break;
	}
}

void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-500, sizex, -500, sizey, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitContextVersion(1, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   //Stuff not worth looking at (yet)
   glutInitWindowSize(1000, 1000);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Pong Prototype");
   //Self explanatory names
   glutDisplayFunc(drawscene);
   glutKeyboardFunc(keypress);
   glutReshapeFunc(redimensionada);
   //No idea how reshaping works so I'll just copy the teacher's code
   setup();
   glTimerFunc(33,)
   glutMainLoop();
   //The main loop proper, receives no parameters (I think)
   }
