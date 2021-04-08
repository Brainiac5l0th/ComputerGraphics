#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
int x1,y1,x2,y2,dx,dy,steps,absdx,absdy,i;
float m,xin,yin,x,y;

void display(void)
{
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
    dx=x2-x1;
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
    m=(float)dy/dx;
    if(absdx>absdy)
    {
        steps=absdx;
    }
    else
    {
        steps=absdy;
    }
    xin=(float)dx/steps;
    yin=(float)dy/steps;
    x=x1;
    y=y1;
    for(i=1; i<=steps; i++)
    {
        x=x+xin;
        y=y+yin;
        glColor3ub(255,255,255);
        glBegin(GL_POINTS);
        glVertex2f (x,y);
        glEnd();
    }
    /* draw white polygon (rectangle) with corners at
    *(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
    //glColor3f (1.0, 0.25, 1.0);
    // glBegin(GL_POLYGON);
    // glVertex3f (0.25, 0.25, 0.0);
    // glVertex3f (0.75, 0.25, 0.0);
    // glVertex3f (0.75, 0.75, 0.0);
    // glVertex3f (0.25, 0.75, 0.0);

    /* don't wait!

    *	start processing buffered OpenGL routines */
    glutSwapBuffers();

}

void init(void)
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,600,0,600,-600,600);
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
    printf("enter first end points:");
    scanf("%d %d",&x1,&y1);
    printf("enter last end points:");
    scanf("%d %d",&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("DDA Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */

}
