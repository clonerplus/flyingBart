#include <GL/gl.h>
#include <GL/glut.h>
#include "scenario.h"

#define GLOBAL_SIZE 0.5
#define LEG_XSCALE 0.2
#define FOOT_YSCALE 1.0
#define CENTER_X 0.0
#define CENTER_Y 0.0
#define CENTER_Z 0.0


void
loadTexture ()
{

}

void
drawScenario ()
{
    glColor3f(0.25, 0.5, 0.8);
    // Ground
    int minx = (int) CENTER_X - 30;
    int maxx = (int) CENTER_X + 30;
    int minz = (int) CENTER_Z - 30;
    int maxz = (int) CENTER_Z + 30;
    for (int x = minx; x <= maxx; ++ x) {
        glBegin(GL_LINES);
        glVertex3f(x, -GLOBAL_SIZE * LEG_XSCALE * 18 - GLOBAL_SIZE * FOOT_YSCALE, minz);
        glVertex3f(x, -GLOBAL_SIZE * LEG_XSCALE * 18 - GLOBAL_SIZE * FOOT_YSCALE, maxz);
        glEnd();
    }

    for (int z = minz; z <= maxz; ++ z) {
        glBegin(GL_LINES);
        glVertex3f(minx, -GLOBAL_SIZE * LEG_XSCALE * 18 - GLOBAL_SIZE * FOOT_YSCALE, z);
        glVertex3f(maxx, -GLOBAL_SIZE * LEG_XSCALE * 18 - GLOBAL_SIZE * FOOT_YSCALE, z);
        glEnd();
    }
//    glColor3f(0.25, 0.25, 0.25);
//    glBegin(GL_LINES);
//    glVertex3f(0, -2, -15);
//    glVertex3f(0, -2, -10);
//    glEnd();
//    glBegin(GL_LINES);
//    glVertex3f(0, -2, -15);
//    glVertex3f(1, -2, -15);
//    glEnd();
//    glBegin(GL_LINES);
//    glVertex3f(0, -2, -10);
//    glVertex3f(1, -2, -15);
//    glEnd();
    




}
