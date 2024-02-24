#include <stdio.h>
#include<iostream>
#include <math.h>
#include <GL/glut.h>

int xc = 320, yc = 240;
#define h  1000
#define w  1000

int screenWidth = 1000;
int screenHeight = 1000;
bool showAxes = true;

using namespace std;

void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void plot_point_olympic(int x, int y , int c1 , int c2)
{
  glBegin(GL_POINTS);
  glVertex2i(c1+x, c2+y);
  glVertex2i(c1+x, c2-y);
  glVertex2i(c1+y, c2+x);
  glVertex2i(c1+y, c2-x);
  glVertex2i(c1-x, c2-y);
  glVertex2i(c1-y, c2-x);
  glVertex2i(c1-x, c2+y);
  glVertex2i(c1-y, c2+x);
  glEnd();
}

void bresenham_circle(int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}

void concentric_circles(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  int radius1 = 100, radius2 = 200;
  bresenham_circle(radius1);
  bresenham_circle(radius2);
}

void bresenham_circle_olympic(int r , int c1 , int c2)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  plot_point_olympic(x,y,c1,c2);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point_olympic(x,y,c1,c2);
  }
  glFlush();
}

void bresenham_spiral(int num_turns, int num_points)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float theta = 0.0;
    float delta_theta = 2 * M_PI / num_points;
    int radius = 10;
    
    for(int loop = 0 ; loop < num_turns ; ++loop)
    {
    	    for (int i = 0; i < num_points; ++i)
	    {
		int x = radius * cos(theta);
		int y = radius * sin(theta);

		bresenham_circle(x);
		theta += delta_theta;
	    }
	    radius += 10 + 10;
    }
    

    glFlush();
}

void put_pixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void axes()
{   if(showAxes)
    {
    	for(int i= -h ;i <=h;i++)
	{
		put_pixel(i,0);
		put_pixel(0,i);
        }
    }
    
}

void myMouse(int button , int state , int x , int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            std::cout << "Left button clicked at coordinates: (" << x << ", " << screenHeight - y << ")" << std::endl;
	    showAxes = !showAxes;
            glutPostRedisplay();
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            std::cout << "Right button clicked at coordinates: (" << x << ", " << screenHeight - y << ")" << std::endl;
            glutAttachMenu(GLUT_RIGHT_BUTTON);
            glutPostRedisplay();
        }
    }
}

void drawScene(int option)
{	
	int rad = 50;
	float spacing = 2.5 * rad;
	
    if(showAxes)
    {
    	axes();
    }
	
    switch (option)
    {
    case 1: // Circle
        glBegin(GL_POINTS);
        bresenham_circle(100);
        glEnd();
        glFlush();
        break;
    case 2: // Concentric Circles
        glBegin(GL_POINTS);
		concentric_circles();
        glEnd();
        glFlush();
        break;
    case 3: // olympic circles
        glBegin(GL_POINTS);
        rad = 50;
		bresenham_circle_olympic(rad , xc , yc);
		bresenham_circle_olympic(rad , xc+spacing , yc);
		bresenham_circle_olympic(rad , xc+2*spacing , yc);
		bresenham_circle_olympic(rad , xc+0.5*spacing , yc-1.5*rad);
		bresenham_circle_olympic(rad , xc+1.5*spacing , yc-1.5*rad);
        glEnd();
        glFlush();
        break;
        
     case 4:
     	glBegin(GL_POINTS);
     		bresenham_spiral(5 , 100);
     	glEnd();
        glFlush();
     	break;
     		
     	
    default:
        break;
    }
    glFlush();
}

void createMenu()
{
    glutCreateMenu(drawScene);
    glutAddMenuEntry("Circle", 1);
    glutAddMenuEntry("Concentric Circles", 2);
    glutAddMenuEntry("Olympic Circles", 3);
    glutAddMenuEntry("Spiral", 4);
    //glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("bresenham_circle");
  glutDisplayFunc(display);
  createMenu();
  glutMouseFunc(myMouse);
  Init();
  glutMainLoop();
  
  return 0;
}
