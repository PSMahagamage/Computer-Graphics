#include <gl/glut.h>
#include <stdlib.h>

void drawing_point(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void displaydrawing(){
    bresendrawer(180,10,15,145);
    glFlush();
}

void bresendrawer(int x0, int y0, int xEndP, int yEndP)
{
    int dx = fabs(xEndP - x0);
    int dy = fabs(yEndP - y0);

    int p = 2 * dy - dx;

    int DyMul2 = 2 * dy;
    int DyMinDxMul2 = 2 * (dy - dx);

    int x, y;

    if (x0 > xEndP) {
        x = xEndP;
        y = yEndP;
        xEndP = x0;
    }else {
        x = x0;
        y = y0;
    }

    drawing_point (x, y);

    while (x < xEndP){
        x++;
        if (p < 0)
            p += DyMul2;
        else{
            y++;
            p += DyMinDxMul2;
        }

        drawing_point (x, y);
    }
}

void initmodes(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glOrtho(-500.0,500.0,-500.0,500.0,-1.0,1.0);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Question-02 Bresenham line drawing algorithm for slopes");

    initmodes();

	glutDisplayFunc(displaydrawing);

	glutMainLoop();
}
