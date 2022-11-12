#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

void displayLine(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glBegin(GL_LINES);
        glVertex2f(180,15);
        glVertex2f(10,145);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Question-01 Straight Line for given Cartesian endpoint coordinates");

    glutDisplayFunc(displayLine);

    glMatrixMode (GL_PROJECTION);

    glLoadIdentity ( );
    glOrtho(-500.0,500.0,-500.0,500.0,-1.0,1.0);

    glMatrixMode (GL_MODELVIEW);
    glutMainLoop();

    return 0;
}
