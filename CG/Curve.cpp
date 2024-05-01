#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

class Point
{
public:
    int x, y;
    void setxy(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

int option;
static int POINTSNUM = 0;
static Point points[4];
float ox, oy, nx, ny;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glMatrixMode(GL_PROJECTION); // Set matrix mode to projection
    glLoadIdentity(); // Load identity matrix
    gluOrtho2D(0.0, 600.0, 0.0, 480.0); // Set orthographic projection
}

void setPoint(Point p)
{
    glBegin(GL_POINTS); // Begin drawing points
    glVertex2f(p.x, p.y); // Set vertex for the point
    glEnd(); // End drawing points
    glFlush(); // Flush the drawing commands
}

void setLine(Point p1, Point p2)
{
    glBegin(GL_LINES); // Begin drawing lines
    glVertex2f(p1.x, p1.y); // Set vertex for the start of the line
    glVertex2f(p2.x, p2.y); // Set vertex for the end of the line
    glEnd(); // End drawing lines
    glFlush(); // Flush the drawing commands
}

void drawBezierCurve(Point p0, Point p1, Point p2, Point p3, int level)
{
    // Draw lines connecting user points
    if (POINTSNUM > 1)
    {
        for (int i = 0; i < POINTSNUM - 1; i++)
        {
            setLine(points[i], points[i + 1]); // Draw a line between consecutive points
        }
    }

    // Draw Bezier curve
    if (level <= 0)
    {
        setLine(p0, p3); // Draw a line between the first and last control points
    }
    else
    {
        // Calculate intermediate control points
        Point p01, p12, p23, p012, p123, p0123;
        p01.x = (p0.x + p1.x) / 2;
        p01.y = (p0.y + p1.y) / 2;
        p12.x = (p1.x + p2.x) / 2;
        p12.y = (p1.y + p2.y) / 2;
        p23.x = (p2.x + p3.x) / 2;
        p23.y = (p2.y + p3.y) / 2;
        p012.x = (p01.x + p12.x) / 2;
        p012.y = (p01.y + p12.y) / 2;
        p123.x = (p12.x + p23.x) / 2;
        p123.y = (p12.y + p23.y) / 2;
        p0123.x = (p012.x + p123.x) / 2;
        p0123.y = (p012.y + p123.y) / 2;

        // Recursive call for the two halves of the curve
        drawBezierCurve(p0, p01, p012, p0123, level - 1);
        drawBezierCurve(p0123, p123, p23, p3, level - 1);
    }
}

void kc(float dir, float l, int it)
{
    float ndir = ((3.14 * dir) / 180);
    nx = ox + (l * cos(ndir));
    ny = oy + (l * sin(ndir));

    if (it == 0)
    {
        glBegin(GL_LINE_LOOP);
        glVertex2f(ox, oy);
        glVertex2f(nx, ny);
        glEnd();
        ox = nx;
        oy = ny;
    }
    else
    {
        it--;
        kc(dir, l, it);
        dir = dir + 60;
        kc(dir, l, it);
        dir = dir - 120;
        kc(dir, l, it);
        dir = dir + 60;
        kc(dir, l, it);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glFlush(); // Flush the drawing commands
}

void myMouseFunction(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (option == 1) // Bezier Curve option
        {
            points[POINTSNUM].setxy(x, 480 - y); // Set user point
            glColor3f(1.0, 0.0, 0.0); // Set drawing color to red
            setPoint(points[POINTSNUM]); // Draw the point
            glColor3f(0.0, 0.0, 0.0); // Set drawing color to black
            if (POINTSNUM > 0)
                setLine(points[POINTSNUM - 1], points[POINTSNUM]); // Draw line between consecutive points

            if (POINTSNUM == 3)
                drawBezierCurve(points[0], points[1], points[2], points[3], 5); // Draw Bezier curve with level 5
            POINTSNUM++; // Increment number of user points
        }
        else if (option == 2) // Koch Curve option
        {
            glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
            glColor3f(0.0f, 0.0f, 0.0f); // Set drawing color to black
            ox = 190; // Center of the window horizontally
            oy = 280; // Center of the window vertically
            kc(0, 10, 3);    // Draw the first side of the triangle
            kc(-120, 10, 3); // Draw the second side of the triangle
            kc(120, 10, 3);
            glFlush(); // Flush the drawing commands
        }
    }
}

void menu(int choice)
{
    option = choice; // Set the option based on user selection
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bezier and Koch Curves");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseFunction);
    glutCreateMenu(menu);
    glutAddMenuEntry("Bezier Curve", 1);
    glutAddMenuEntry("Koch Curve", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

