#include<GL/glut.h>
#include<windows.h>


void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void displayhbe()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0);
    glColor3f(255, 255, 255);


    glBegin(GL_QUADS);

    glVertex2i(125,100);
    glVertex2i(125,225);
    glVertex2i(325,100);
    glVertex2i(325,225);
    glVertex2i(125,100);
    glVertex2i(325,100);
    glVertex2i(125,225);
    glVertex2i(325,225);

    //window1
    glColor3f(255,0,0);
    glVertex2i(150,150);
    glVertex2i(150,175);

    glVertex2i(175,150);
    glVertex2i(175,175);

    glVertex2i(150,175);
    glVertex2i(175,175);

    glVertex2i(150,150);
    glVertex2i(175,150);

    //window2
    glColor3f(255,0,0);
    glVertex2i(275,150);
    glVertex2i(275,175);

    glVertex2i(300,150);
    glVertex2i(300,175);

    glVertex2i(275,175);
    glVertex2i(300,175);

    glVertex2i(275,150);
    glVertex2i(300,150);

    //door
    glColor3f(0, 0, 255);

    glVertex2i(200,100);
    glVertex2i(200,175);

    glVertex2i(250,100);
    glVertex2i(250,175);

    glVertex2i(200,175);
    glVertex2i(250,175);

    glVertex2i(200,100);
    glVertex2i(250,100);



    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2i(125,225);
    glVertex2i(225,325);

    glVertex2i(325,225);
    glVertex2i(225,335);

    glVertex2i(125,225);
    glVertex2i(325,225);



    glEnd();
    glFlush();
}

int main()
{

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,100);
    glutCreateWindow("172-15-9846");
    init();
    glutDisplayFunc(displayhbe);
    glutMainLoop();
    return 0;
}
