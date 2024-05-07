#include <GL/glut.h>
#include <cmath>

int click = 0;
int x1_coord, y1_coord, x2_coord, y2_coord;
int lineType = 1;

int Sign(int val) {
    if (val < 0) return -1;
    else if (val == 0) return 0;
    else return 1;
}

void Bresenham(int x1, int y1, int x2, int y2, int type) {
    int x = x1, y = y1;
    int Dx = abs(x2 - x1);
    int Dy = abs(y2 - y1);
    int s1 = Sign(x2 - x1);
    int s2 = Sign(y2 - y1);
    int interchange = 0;

    if (Dy > Dx) {
        int temp = Dx;
        Dx = Dy;
        Dy = temp;
        interchange = 1;
    }

    int e = 2 * Dy - Dx;

    for (int i = 0; i < Dx; ++i) {
        if (type == 1) {
            glVertex2i(x, y);
        } else if (type == 2) {
            if (i % 3 != 0)
                glVertex2i(x, y);
        } else if (type == 3) {
            if ((i / 5) % 2 == 0)
                glVertex2i(x, y);
        } else if (type == 4) {
            for (int j = -1; j <= 1; ++j)
                for (int k = -1; k <= 1; ++k)
                    glVertex2i(x + j, y + k);
        }

        while (e >= 0) {
            if (interchange == 1)
                x += s1;
            else
                y += s2;
            e -= 2 * Dx;
        }

        if (interchange == 1)
            y += s2;
        else
            x += s1;
        e += 2 * Dy;
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_POINTS);
    switch (lineType) {
        case 1:
            Bresenham(x1, y1, x2, y2, 1);
            break;
        case 2:
            Bresenham(x1, y1, x2, y2, 2);
            break;
        case 3:
            Bresenham(x1, y1, x2, y2, 3);
            break;
        case 4:
            Bresenham(x1, y1, x2, y2, 4);
            break;
        case 5:
            break;
        default:
            break;
    }
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 250);
    glVertex2f(500, 250);
    glVertex2f(250, 0);
    glVertex2f(250, 500);
    glEnd();
    if (click == 2) {
        drawLine(x1_coord, y1_coord, x2_coord, y2_coord);
        click = 0;
    }
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        click++;
        if (click == 1) {
            x1_coord = x;
            y1_coord = 500 - y;
        } else if (click == 2) {
            x2_coord = x;
            y2_coord = 500 - y;
            glutPostRedisplay();
        }
    }
}

void menu(int value) {
    lineType = value;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutCreateMenu(menu);
    glutAddMenuEntry("Simple", 1);
    glutAddMenuEntry("Dotted", 2);
    glutAddMenuEntry("Dashed", 3);
    glutAddMenuEntry("Broad", 4);
    glutAddMenuEntry("Object:", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
