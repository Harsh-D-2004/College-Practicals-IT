#include<iostream>
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#include<GL/glut.h>
#define h  1000
#define w  1000
using namespace std;

float x1 = -400, x2 = 400, ya = -200, y2 = 200;

void simpleline()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float dy = (y2 - ya);
    float dx = (x2 - x1);
    float k, Dx, Dy, x, y;

    if (abs(dx) > abs(dy))
    {
        k = abs(dx);
    }
    else
    {
        k = abs(dy);
    }

    Dx = dx / k;
    Dy = dy / k;

    x = x1;
    y = ya;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int i = 0; i < k; i++)
    {
        x = x + Dx;
        y = y + Dy;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
    glutSwapBuffers();
}


void put_pixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();

	glFlush();
}

void axis()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = -h; i <= h; i++)
    {
        put_pixel(i, 0);    //Plot X-Axis
        put_pixel(0, i);    //Plot Y-Axis
    }

    glFlush();
    glutSwapBuffers();
}

void menu(int index)
{
    if (index == 1)
    {
        cout << "Display Simple Line";
        simpleline();
    }
    else if (index == 2)
    {
        cout << "Display Axis";
        axis();
    }
    else if (index == 3)
    {
        cout << "Display Dotted Line";
        //dottedline();
    }
    else if (index == 4)
    {
        cout << "Display Boat";
        //boat();
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    axis();
    simpleline();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow ("Menu : ");
	glutDisplayFunc (display);
	glutIdleFunc (display);

    glutCreateMenu(menu);
    glutAddMenuEntry("Simple Line", 1);
    glutAddMenuEntry("Axis", 2);
    glutAddMenuEntry("Dotted Line", 3);
    glutAddMenuEntry("Boat", 4);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();

    return 0;
}

