
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void circle(int a, int b, int r)
{

   glColor3ub(244, 42, 65);;
    int x,y,p;
    x=0;
    y=r;
    p=1-r;
    while(x<y)
    {
        glVertex2i(a+x,b+y);
        glVertex2i(a-x,b+y);
        glVertex2i(a+x,b-y);
        glVertex2i(a-x,b-y);
        glVertex2i(a+y,b+x);
        glVertex2i(a-y,b+x);
        glVertex2i(a+y,b-x);
        glVertex2i(a-y,b-x);
        if(p<0)
        {
            p=p+2*x+1;
        }
        else
        {
            y=y-1;
            p=p+2*x+1-2*y;
        }
        x=x+1;
    }
    glEnd();
}

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    circle(40,150,280);




    //<----------main middle part starts--------->
    glColor3ub(245,245,220);

    //left pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (-190, 400);
    glVertex2i (-100, 400);
    glVertex2i (-100, -400);
    glVertex2i (-190, -400);
    glEnd();

    //middle pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (-10, 400);
    glVertex2i (80, 400);
    glVertex2i (80, -400);
    glVertex2i (-10, -400);
    glEnd();

    //right pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (170, 400);
    glVertex2i (260, 400);
    glVertex2i (260, -400);
    glVertex2i (170, -400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-190, 400);
    glVertex2i (260, 400);
    glVertex2i (260, 340);
    glVertex2i (-190, 340);
    glEnd();

    //baka pillar left
    glBegin(GL_POLYGON);
    glVertex2i (-190, 400);
    glVertex2i (-210, 600);
    glVertex2i (-140, 600);
    glVertex2i (-100, 400);
    glEnd();

    //baka pillar middle
    glBegin(GL_POLYGON);
    glVertex2i (-10, 400);
    glVertex2i (0, 600);
    glVertex2i (70, 600);
    glVertex2i (80, -400);
    glEnd();

    //baka pillar right
    glBegin(GL_POLYGON);
    glVertex2i (170, 400);
    glVertex2i (220, 600);
    glVertex2i (290, 600);
    glVertex2i (260, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-215, 650);
    glVertex2i (300, 650);
    glVertex2i (290, 600);
    glVertex2i (-210, 600);
    glEnd();
    //<----------main middle part ends--------->


    //right side left pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (390, 280);
    glVertex2i (480, 280);
    glVertex2i (480, -400);
    glVertex2i (390, -400);
    glEnd();


    //right side right pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (600, 280);
    glVertex2i (690, 280);
    glVertex2i (690, -400);
    glVertex2i (600, -400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (390, 330);
    glVertex2i (690, 330);
    glVertex2i (690, 280);
    glVertex2i (390, 280);
    glEnd();


    //-----left side right pillar----
    glBegin(GL_POLYGON);
    glVertex2i (-320, 280);
    glVertex2i (-410, 280);
    glVertex2i (-410, -400);
    glVertex2i (-320, -400);
    glEnd();


    //left side left pillar-->
    glBegin(GL_POLYGON);
    glVertex2i (-530, 280);
    glVertex2i (-620, 280);
    glVertex2i (-620, -400);
    glVertex2i (-530, -400);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-620, 330);
    glVertex2i (-320, 330);
    glVertex2i (-320, 280);
    glVertex2i (-620, 280);
    glEnd();


    //flag.......>

    glColor3ub(120, 80, 20);
    glBegin(GL_POLYGON);
    glVertex2i (-750, -400);
    glVertex2i (-750, 700);
    glVertex2i (-720, 760);
    glVertex2i (-720, -460);
    glEnd();

    glColor3ub (0, 106, 78);
    glBegin(GL_POLYGON);
    glVertex2i (-720, 700);
    glVertex2i (-400, 700);
    glVertex2i (-400, 450);
    glVertex2i (-720, 450);
    glEnd();

    glBegin(GL_POLYGON);
    circle(-580,575,80);

    //floor----->
    glColor3ub(188,143,143);
    glBegin(GL_POLYGON);
    glVertex2i (-800, -400);
    glVertex2i (850, -400);
    glVertex2i (880, -460);
    glVertex2i (-830, -460);
    glEnd();



    glutSwapBuffers();

}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.7, 0.75,0.71, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-900, 900, -900, 900);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("172-15-9846(Shawon Talukder)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */

}
