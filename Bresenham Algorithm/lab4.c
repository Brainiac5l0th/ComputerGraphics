#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>

int x1,x2,y1,y2,dx,dy,p,X,Y,absdx,absdy;

void display(void)
{
    /* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);

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
                glColor3ub(255,255,255);
                glBegin(GL_POINTS);
                glVertex2f (X,Y);
                printf("p=%d X=%d Y=%d\n",p,X,Y);
                glEnd();
                Y++;
                p=p+2*dy-2*dx;
            }
            else
            {
                glColor3ub(255,255,255);
                glBegin(GL_POINTS);
                glVertex2f (X,Y);
                printf("p=%d X=%d Y=%d\n",p,X,Y);
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
                glColor3ub(255,255,255);
                glBegin(GL_POINTS);
                glVertex2f (X,Y);
                printf("p=%d X=%d Y=%d\n",p,X,Y);
                glEnd();
                X++;
                p=p+2*absdx-2*absdy;
            }
            else
            {
                glColor3ub(255,255,255);
                glBegin(GL_POINTS);
                glVertex2f (X,Y);
                printf("p=%d X=%d Y=%d\n",p,X,Y);
                glEnd();
                p=p+2*absdx;
            }
            Y++;
        }
    }



    /*	start processing buffered OpenGL routines */
    glutSwapBuffers();
}


void init (void)
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,600,0,600,-600,600);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/

int main(int argc, char** argv)
{
    printf("enter Start points(x1,y1):\n");
    scanf("%d %d",&x1,&y1);
    printf("enter End points(x2,y2):\n");
    scanf("%d %d",&x2,&y2);
    printf("\n");
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Mr.Bresenham_172-15-9846(Shawon Talukder)");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
