#include<iostream>
#include<windows.h>
#include<GL/glut.h>
#define h  1000
#define w  1000


using namespace std;


void myInit()
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500.0,-500.0,500.0,500.0);

      glColor3f(0.0, 0.0, 0.0);
}

void put_pixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();

	glFlush();
}


void my_func()
{

    glClear(GL_COLOR_BUFFER_BIT);

	for(int i= -h ;i <=h;i++)
	{
		put_pixel(i,0);
		put_pixel(0,i);
    }

   glFlush();

}

int main(int charc , char ** charv)
{
    glutInit(&charc,charv);
    glutInitWindowPosition(400,200);
    glutInitWindowSize(1000,1000);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("DDA 1");
    glutDisplayFunc(my_func);
    myInit();

    glutMainLoop();

}
