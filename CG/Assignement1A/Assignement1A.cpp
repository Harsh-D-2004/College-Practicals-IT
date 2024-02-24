#include<iostream>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>

#include<cmath>
#define h  1000
#define w  1000

int screenWidth = 1000;
int screenHeight = 1000;
bool showAxes = true;


using namespace std;


void myInit()        //myInit function
{
    glClearColor(0.0, 1.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500.0,500.0,-500.0,500.0);

      glColor3f(1.0, 0.0, 0.0);
}

void put_pixel(int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();


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


int selected ;
void menu(int index)
{
    selected = index;

    glutSwapBuffers();
   glutPostRedisplay();

}

void DDA(int x0 , int y0 , int x1 , int y1)
{
    if(x0==x1 && y0 == y1)
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

        glVertex2i(round(x),round(y));


        x += DX;
        y += DY;

        }

    glEnd();
    glFlush();
}


void DDA_Simple()
{


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


    if(x0==x1 && y0 == y1)
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

        glVertex2i(round(x),round(y));


        x += DX;
        y += DY;

        }

    glEnd();
    glFlush();
}


void DDA_Solid()
{


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


    if(x0==x1 && y0 == y1)
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

	
    glLineWidth(50.0);
    glBegin(GL_LINES);


        for(int j=0; j<=k; j++)
        {

        glVertex2i(round(x),round(y));


        x += DX;
        y += DY;

        }

    glEnd();
    glFlush();
}

void DDA_Dotted()
{
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


    if(x0==x1 && y0 == y1)
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


    for(int l=0; l<=k; l++)
    {
        if(l%2 !=0){
        glVertex2i(round(x),round(y));

        }
        x += DX;
        y += DY;

    }
    glEnd();
    glFlush();

}

void DDA_Dashed()
{
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


    if(x0==x1 && y0 == y1)
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


    for(int n=0; n<=k; n++)
    {
        if(n%5 !=0){
        glVertex2i(round(x),round(y));

        }
        x += DX;
        y += DY;

    }
    glEnd();

    glFlush();

}

void Display_Boat()
{
	DDA(-30 , -50 , 30 , -50);
	DDA(-30 , -50 , -50 , 0);
	DDA(-50 , 0 , 50 , 0);
	DDA(30 , -50 , 50 , 0);
	
	DDA(-35 , 0 , 0 , 50);
	DDA(35 , 0 , 0 , 50);

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


void my_func()
{
 	glClear(GL_COLOR_BUFFER_BIT);
 	
    if(showAxes)
    {
    	axes();
    }	
   
    if(selected == 1)
	{
        DDA_Simple();

	}
	else if(selected == 2)
	{
        DDA_Dotted();

	}
	else if(selected == 3)
	{	
	DDA_Dashed();
	}
	else if(selected == 4)
	{
	DDA_Solid();
	}
	else if(selected == 5)
	{
	Display_Boat();
	}
   glFlush();



}

int main(int charc , char ** charv)
{
    glutInit(&charc,charv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(400,200);
    glutInitWindowSize(1000,1000);


	glutCreateWindow("MENU");

    glutDisplayFunc(my_func);


    glutCreateMenu(menu);
    glutAddMenuEntry("SIMPLE",1);
    glutAddMenuEntry("DOTTED",2);
    glutAddMenuEntry("DASHED",3);
    glutAddMenuEntry("SOLID",4);
    glutAddMenuEntry("BOAT",5);
	
    glutMouseFunc(myMouse);

    //glutAttachMenu(GLUT_RIGHT_BUTTON);

    myInit();

    glutMainLoop();
    return 0;

}
