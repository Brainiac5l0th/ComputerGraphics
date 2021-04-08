#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void circle(int a, int b, int r)
{
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

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx,dy,p,X,Y,absdx,absdy;
    dx=x2-x1;
    dy=y2-y1;
    if(dx<0)
    {
        absdx=dx*(-1);
    }
    else
    {
        absdx=dx;
    }
    dy=y2-y1;
    if(dy<0)
    {
        absdy=dy*(-1);
    }
    else
    {
        absdy=dy;
    }
    X=x1;
    Y=y1;
    if(absdx>absdy)
    {
        p=2*absdy-absdx;
        while(X<=x2)
        {
            if(p>=0)
            {
                glBegin(GL_POINTS);
                glVertex2i(X,Y);
                glEnd();
                Y++;
                p=p+2*dy-2*dx;
            }
            else
            {
                glBegin(GL_POINTS);
                glVertex2i(X,Y);
                glEnd();
                p=p+2*dy;
            }
            X++;
        }
    }
    else
    {
        p=2*absdx-absdy;
        while(Y<=y2)
        {
            if(p>=0)
            {
                glBegin(GL_POINTS);
                glVertex2i(X,Y);
                glEnd();
                X++;
                p=p+2*dx-2*dy;
            }
            else
            {
                glBegin(GL_POINTS);
                glVertex2i(X,Y);
                glEnd();
                p=p+2*dx;
            }
            Y++;
        }
    }
}

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub(44, 174, 102);

    //left side chaka full kaaj-->

    // left side chaka
    glBegin(GL_POINTS);
    circle(-500,0,250);
    glBegin(GL_POINTS);
    circle(-500,0,220);

    //left side inside chaka
    glBegin(GL_POINTS);
    circle(-500,0,50);

    //LEFT SIDE CHAKA CIRCLE
    glBegin(GL_POLYGON);
    circle(-500,0,10);


    //right side chaka full kaaj-->
    //right side chaka
    glBegin(GL_POINTS);
    circle(600,0,250);
    glBegin(GL_POINTS);
    circle(600,0,220);

    //right side inside chaka
    glBegin(GL_POINTS);
    circle(600,0,50);

    //RIGHT SIDE CHAKA CIRCLE
    glBegin(GL_POLYGON);
    circle(600,0,10);


    //paddle design
    glBegin(GL_POINTS);
    circle(0,50,100);

    glBegin(GL_POINTS);
    circle(0,50,30);


    //paddle inside CIRCLE
    glBegin(GL_POLYGON);
    circle(0,50,10);



    //left chaka to paddle connection
    bresenham(-500,50,0,150);
    bresenham(-500,-50,0,-100);


    //paddle bar
    bresenham(0, 50, 100, 200);
    bresenham(-100, -100, 0, 50);

    //left side paddle bar
    glBegin(GL_POLYGON);
    glVertex2i (-140, -100);
    glVertex2i (-60, -100);
    glVertex2i (-60, -110);
    glVertex2i (-140, -110);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-500,10);
    glVertex2i (10, 60);
    glVertex2i (10, 40);
    glVertex2i (-500,-10);
    glEnd();


    //right side paddle bar
    glBegin(GL_POLYGON);
    glVertex2i (60, 210);
    glVertex2i (140, 210);
    glVertex2i (140, 200);
    glVertex2i (60, 200);
    glEnd();


    //paddle to seat position line
    glBegin(GL_POLYGON);
    glVertex2i (-100, 450);
    glVertex2i (-80, 450);
    glVertex2i (10, 50);
    glVertex2i (-10, 50);
    glEnd();


    //from back tire to seat connection
    glBegin(GL_POLYGON);
    glVertex2i (-500, 10);
    glVertex2i (-80, 450);
    glVertex2i (-50, 450);
    glVertex2i (-500, -10);
    glEnd();


    //seat position
    glBegin(GL_POLYGON);
    glVertex2i (-100, 500);
    glVertex2i (-80, 500);
    glVertex2i (-80, 450);
    glVertex2i (-100, 450);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-150, 550);
    glVertex2i (10, 520);
    glVertex2i (20, 500);
    glVertex2i (-150, 500);
    glEnd();


    //LEFT SIDE TILL HALDLE BAR
    glBegin(GL_POLYGON);
    glVertex2i (400, 450);
    glVertex2i (420, 450);
    glVertex2i (610, 0);
    glVertex2i (590, 0);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2i (-80, 450);
    glVertex2i (420, 450);
    glVertex2i (420, 430);
    glVertex2i (-80, 430);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (-80, 420);
    glVertex2i (420, 420);
    glVertex2i (420, 400);
    glVertex2i (-80, 400);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2i (430, 420);
    glVertex2i (420, 400);
    glVertex2i (10, 50);
    glVertex2i (-10, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (400, 500);
    glVertex2i (420, 500);
    glVertex2i (420, 450);
    glVertex2i (400, 450);
    glEnd();


    //HANDLE BAR
    glBegin(GL_POLYGON);
    glVertex2i (550, 580);
    glVertex2i (570, 580);
    glVertex2i (420, 500);
    glVertex2i (400, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i (480, 650);
    glVertex2i (670, 500);
    glVertex2i (650, 500);
    glVertex2i (460, 650);
    glEnd();


    glutSwapBuffers();

}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.98, 0.96, 0.96, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-900, 900, -900, 900);
}

/*

*	Declare initial window size, position, and display mode

*	(single buffer & RGBA). Open window with "hello"

*	In its title bar. Call initialization routines.

*	Register callback function to display graphics.

*	Enter main loop and process events.


*/

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("172-15-9846(Shawon Talukder)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */

}
