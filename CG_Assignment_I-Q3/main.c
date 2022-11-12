#include <stdio.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

GLfloat T = 0;

int init(){
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
}

void draw_square(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[]){

    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex3fv(A);
        glTexCoord2f(1.0, 0.0);
        glVertex3fv(B);
        glTexCoord2f(1.0, 1.0);
        glVertex3fv(C);
        glTexCoord2f(0.0, 1.0);
        glVertex3fv(D);
    glEnd();

}


void cube(GLfloat V0[],GLfloat V1[],GLfloat V2[],GLfloat V3[],GLfloat V4[],GLfloat V5[],GLfloat V6[],GLfloat V7[]){

    //front side square
    glColor3f(1,0,0);
    draw_square(V1,V5,V6,V2);

    //back side square
    glColor3f(0,1,1);
    draw_square(V0,V4,V7,V3);


    //right side square
    glColor3f(0,0,1);
    draw_square(V0,V1,V2,V3);

    //left side square
    glColor3f(0,1,0);
    draw_square(V4,V5,V6,V7);


    //top side square
    glColor3f(1,0,1);
    draw_square(V1,V0,V4,V5);

    //bottom side square
    glColor3f(1,1,0);
    draw_square(V3,V7,V6,V2);

}

void displayRoCube(){
    GLfloat V[8][3] = {
        {-0.5,0.5,0.5},{0.5,0.5,0.5},{0.5,-0.5,0.5},{-0.5,-0.5,0.5},{-0.5,0.5,-0.5},{0.5,0.5,-0.5},{0.5,-0.5,-0.5},{-0.5,-0.5,-0.5}};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(T,0,1,1);

    cube(V[0],V[1],V[2],V[3],V[4],V[5],V[6],V[7]);

    glutSwapBuffers();
}

void spin(){
    T = T + 0.005;

    if(T>360){
        T=0;
    }

   glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(250,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Question-3 Preferred 3D Model rendering with OpenGL and mapping/applying a texture");

    //int width, height, nrChannels;
    //unsigned char *data = stbi_load("texture.jpg", &width, &height, &nrChannels, 0);

    init();

    glutDisplayFunc(displayRoCube);

    glutIdleFunc(spin);

    glutMainLoop();

}
