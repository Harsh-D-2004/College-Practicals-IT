#include<iostream>
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>
#include<GL/glut.h>

using namespace std;


void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-600.0, 600.0,-400.0, 400.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
      glColor3f(1.0, 1.0, 1.0);
}

int sign(float x)
{
    if(x<0)
    {
        return -1;
    }
    else if(x>=0)
    {
       return 0;
    }
    else
    {
        return 1;
    }
}



void my_func()
{

        glClear(GL_COLOR_BUFFER_BIT);


    float x0,x1,y0,y1;
    cout<<"Enter coordinates of first point"<<endl;
    cout << "X0 = ";
    cin>>x0;
    cout<<endl;
    cout << "Y0 = ";
    cin>>y0;
    cout<<endl;
    cout<<"Enter coordinates of second point"<<endl;
    cout << "X1 = ";
    cin>>x1;
    cout<<endl;
    cout << "Y1 = ";
    cin>>y1;
    cout<<endl;


    if(x0==x1 & y0 == y1)
    {
        cout<<"BOTH POINTS ARE SAME"<<endl;
        return;
    }


    float dx,dy,slope,k;

    dx = x1-x0;
    dy = y1-y0;

    if(abs(dx)>abs(dy))
    {
        k = dx;
    }
    else
    {
        k = dy;
    }


    float DX,DY;
    DX = dx/k;
    DY = dy/k;

    float x = x0 + 0.5*sign(DX);
    float y = y0  + 0.5*sign(DY);


    glBegin(GL_POINTS);
    glPointSize(10);
    for(int j=0; j<=k; j++)
    {

        glVertex2d(round(x),round(y));


        x += DX;
        y += DY;

    }
    glEnd();

   glFlush();

}

int main(int charc , char ** charv)
{
    glutInit(&charc,charv);
    glutInitWindowPosition(400,200);
    glutInitWindowSize(600,600);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);


    glutCreateWindow("DDA 1");


    glutDisplayFunc(my_func);
    myInit();

    glutMainLoop();

}
