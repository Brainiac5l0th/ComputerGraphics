#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int r,x,y,p;

void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);
    x=0;
    y=r;
    p=1-r;
    while(x<y)
    {
        glColor3ub(244, 42, 65);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);
        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);
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


    /* draw white polygon (rectangle) with corners at
    *(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */


    /* don't wait!

    *	start processing buffered OpenGL routines */
    glutSwapBuffers();
}

void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -600, 600);
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
    printf("Enter your lucky number as Radius(R)\n");
    scanf("%d",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow ("BD_FLAG_172-15-9846(Shawon Talukder)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */

}
