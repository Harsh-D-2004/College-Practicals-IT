#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#include<GL/glut.h>

using namespace std;

#define w  1000
#define h  1000

int r = 10;
int x1 = -1;
int x = 0;
int y = r;
int ya, x2, y2, button;
int H = 0; int K = 0;

void menu (int index)
{
	button = index;
	glutPostRedisplay();
}

void plot (int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x , y);
	glEnd();
	glFlush();
}

void axis()
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = -h; i <= h; i++)
	{
		plot(i, 0);    //Plot X-Axis
		plot(0, i);    //Plot Y-Axis
	}
	glFlush();
}

void CircleWithAxis(int x1, int ya, int x2, int y2)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    int H = x1;
	int K = ya;
	
	int r = abs(sqrt(((x2-x1)*(x2-x1)+(y2-ya)*(y2-ya))));
	
	int d = 3-(2*r);
	
	x = 0;
	y = r;
	
	while (x < y)
	{	
		if (d <= 0)
		{
			d = d+4*x+6;
			x += 1;
		}
		else
		{
			d = d+4*(x-y)+10;
			x += 1;
			y -= 1;
		}
		
		plot (x+H, y+K);
		plot (-x+H, -y+K);
		
		plot (y+H, x+K);
		plot (-y+H, -x+K);
		
		plot (-y+H, x+K);
		plot (y+H, -x+K);
		
		plot (-x+H, y+K);
		plot (x+H, -y+K);
	}
	for (int i = -h; i <= h; i++)
	{
		plot(i, 0);    //Plot X-Axis
		plot(0, i);    //Plot Y-Axis
	}
    //glFlush();
}

void OlympicRing()
{
	glClear(GL_COLOR_BUFFER_BIT);
    
	int r = 100;
	int H = -190;
	int K = 50;
	
	int d = 3-(2*r);
	
	x = 0;
	y = r;
	
	while (x < y)
	{	
		if (d <= 0)
		{
			d = d+4*x+6;
			x += 1;
		}
		else
		{
			d = d+4*(x-y)+10;
			x += 1;
			y -= 1;
		}
		
		plot (x+H, y+K);
		plot (-x+H, -y+K);
		
		plot (y+H, x+K);
		plot (-y+H, -x+K);
		
		plot (-y+H, x+K);
		plot (y+H, -x+K);
		
		plot (-x+H, y+K);
		plot (x+H, -y+K);
		
		
		plot (x+H+2*r+10, y+K);
		plot (-x+H+2*r+10, -y+K);
		
		plot (y+H+2*r+10, x+K);
		plot (-y+H+2*r+10, -x+K);
		
		plot (-y+H+2*r+10, x+K);
		plot (y+H+2*r+10, -x+K);
		
		plot (-x+H+2*r+10, y+K);
		plot (x+H+2*r+10, -y+K);
		
		
		plot (x+H+4*r+20, y+K);
		plot (-x+H+4*r+20, -y+K);
		
		plot (y+H+4*r+20, x+K);
		plot (-y+H+4*r+20, -x+K);
		
		plot (-y+H+4*r+20, x+K);
		plot (y+H+4*r+20, -x+K);
		
		plot (-x+H+4*r+20, y+K);
		plot (x+H+4*r+20, -y+K);
		
		
		plot (x+H+r+10, y+K-r);
		plot (-x+H+r+10, -y+K-r);
		
		plot (y+H+r+10, x+K-r);
		plot (-y+H+r+10, -x+K-r);
		
		plot (-y+H+r+10, x+K-r);
		plot (y+H+r+10, -x+K-r);
		
		plot (-x+H+r+10, y+K-r);
		plot (x+H+r+10, -y+K-r);
		
		
		plot (x+H+3*r+10, y+K-r);
		plot (-x+H+3*r+10, -y+K-r);
		
		plot (y+H+3*r+10, x+K-r);
		plot (-y+H+3*r+10, -x+K-r);
		
		plot (-y+H+3*r+10, x+K-r);
		plot (y+H+3*r+10, -x+K-r);
		
		plot (-x+H+3*r+10, y+K-r);
		plot (x+H+3*r+10, -y+K-r);
	}
    glFlush();
}

void ConcentricCircle(int x1, int ya, int x2, int y2)
{
	glClear(GL_COLOR_BUFFER_BIT);
    
	int H = x1;
	int K = ya;
	int r, n, drc;
	r = abs(sqrt(((x2-x1)*(x2-x1)+(y2-ya)*(y2-ya))));
	cout<<"Enter number of concentric circles: ";
	cin>>n;
	cout<<"Radius Decrement:";
	cin>>drc;
	
	int d = 3-(2*r);
	
	for(int i = 0; i < n; i++)
	{
		x = 0;
		y = r;
		
		while (x < y)
		{	
			if (d <= 0)
			{
				d = d+4*x+6;
				x += 1;
			}
			else
			{
				d = d+4*(x-y)+10;
				x += 1;
				y -= 1;
			}
			
			plot (x+H, y+K);
			plot (-x+H, -y+K);
			
			plot (y+H, x+K);
			plot (-y+H, -x+K);
			
			plot (-y+H, x+K);
			plot (y+H, -x+K);
			
			plot (-x+H, y+K);
			plot (x+H, -y+K);
		}
		for (int i = -h; i <= h; i++)
		{
			plot(i, 0);    //Plot X-Axis
			plot(0, i);    //Plot Y-Axis
		}
	    glFlush();
	    r -= drc;
	}
}

void UpperHalf()
{	
	int d = 3 - 2 * r;
    int x = 0;
    int y = r;
	while (x < y)
	{	
		plot (x+H, y+K);
		plot (y+H, x+K);			
		plot (-y+H, x+K);			
		plot (-x+H, y+K);
		
		if (d <= 0)
		{
			d = d+4*x+6;
			x += 1;
		}
		else
		{
			d = d+4*(x-y)+10;
			x += 1;
			y -= 1;
		}
	}
}

void LowerHalf()
{
	int d = 3 - 2 * r;
    int x = 0;
    int y = r;
	while (x < y)
	{	
		plot (-x+H, -y+K);
		plot (-y+H, -x+K);
		plot (y+H, -x+K);
		plot (x+H, -y+K);
		
		if (d <= 0)
		{
			d = d+4*x+6;
			x += 1;
		}
		else
		{
			d = d+4*(x-y)+10;
			x += 1;
			y -= 1;
		}
	}
}

void Spiral()
{
	glClear(GL_COLOR_BUFFER_BIT);
    for (int i = -h; i <= h; i++)
	{
		plot(i, 0);    //Plot X-Axis
		plot(0, i);    //Plot Y-Axis
	}
	for(int i = 0; i < 7; i++)
	{
		UpperHalf();
		H += 20;
		r += 20;
		
		LowerHalf();
		H -= 20;
		r += 20;
	}
    glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}

void myMouse(int BUTTON, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
        if (BUTTON == GLUT_LEFT_BUTTON)
		{
			if (x1 == -1)
            {
                x1 = 500-x;
                ya = 450-y;
            }
            else
            {
                x2 = 500-x;
                y2 = 450-y;

                if (button == 1)
				{
					CircleWithAxis(x1, ya, x2, y2);	
				}
				
				else if (button == 2)
				{
					OlympicRing();
				}
				
				else if (button == 3)
				{
					ConcentricCircle(x1, ya, x2, y2);
				}
				
				else if (button == 4)
				{
					Spiral();
				}
                glFlush();
                x1=-1;
            }
        }
        else if(BUTTON == GLUT_MIDDLE_BUTTON)
        {
            for (int i = -h; i <= h; i++)
			{
				plot(i, 0);    //Plot X-Axis
				plot(0, i);    //Plot Y-Axis
			}
        }
    }
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(500.0, -500.0, -500.0, 500.0);  //Set origin
		glColor3f(0.0, 0.0, 0.0);				
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow ("Menu : ");
	glutDisplayFunc (display);
	glutMouseFunc(myMouse);
	glutCreateMenu(menu);
	glutAddMenuEntry("Simple Circle", 1);
	glutAddMenuEntry("Olympic Rings", 2);
	glutAddMenuEntry("Concentric Circles", 3);
	glutAddMenuEntry("Spiral", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}
