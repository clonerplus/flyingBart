#include "body.h"
#include "body_utils.h"
#include "animation.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

float rSkin = 255.0 / 255.0; // color of the skin
float gSkin = 217.0 / 255.0;
float bSkin = 15.0 / 255.0;

float rShirt = 222.0 / 255.0; // color of the shirt
float gShirt = 90.0 / 255.0;
float bShirt = 57.0 / 255.0;

float rShort = 33.0 / 255.0; // color of the short
float gShort = 209.0 / 255.0;
float bShort = 255.0 / 255.0;

void
drawEye (int xTranslation)
{
    int rotation = 1;
    if (xTranslation < 0)
        rotation = -1;

    // Draw the sclera
    glColor3f (0.9, 0.9, 0.9);
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X + 0.27 * xTranslation, DEPTH_Y + 1.3, DEPTH + 0.6);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);

    }  else if (moveMode[3]) {
        glTranslatef (DEPTH_X + 0.6, 1.3, DEPTH + 0.27 * xTranslation);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    } else {
        glTranslatef (DEPTH_X - 0.6, 1.3, DEPTH + 0.27 * xTranslation);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    }
    glScalef (0.25, 0.25, 0.1);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    // Draw the pupil
    glColor3f (0.25, 0.25, 0.25);
    glPushMatrix ();
    if (moveMode[0] || moveMode[1]){ // walk forward backward
        glTranslatef (DEPTH_X + 0.27 * xTranslation, DEPTH_Y + 1.2, DEPTH + 0.8);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    }  else if (moveMode[3]) { // walk right
        glTranslatef (DEPTH_X + 0.77, 1.3, DEPTH + 0.4 * xTranslation);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    } else if (moveMode[2]) { // walk left
        glTranslatef (DEPTH_X - 0.8, 1.3, DEPTH + 0.4 * xTranslation);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    } else if (moveMode[4]) { // fly
        if (IS_FLYING_FLAT)
            glTranslatef (DEPTH_X + 0.27 * xTranslation, DEPTH_Y + 1.3, DEPTH + 0.8);
        else
            glTranslatef (DEPTH_X + 0.27 * xTranslation, DEPTH_Y + 1.4, DEPTH + 0.8);
        glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    }
    glScalef (0.05, 0.05, 0.01);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawMouth ()
{
    glColor3f (0.25, 0.25, 0.25);
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]) {
        glTranslatef (DEPTH_X, DEPTH_Y + 0.6, DEPTH);
        glScalef (0.55, 0.15, 0.57);

    } else if (moveMode[3]) {
        glTranslatef (DEPTH_X + 0.3, 0.65, DEPTH);
        glScalef (0.3, 0.04, 0.6);

    } else {
        glTranslatef (DEPTH_X - 0.3, 0.65, DEPTH);
        glScalef (0.3, 0.04, 0.6);
    }

    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawNose ()
{
    // Draw the first part of the nose with a cylinder
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X, DEPTH_Y + 0.7, DEPTH + 0.9);

    } else if (moveMode[3]) {
        glTranslatef (DEPTH_X + .4, 0.88, DEPTH);
        glRotatef(90, 0.0, 1.0, 0);

    } else {
        glTranslatef (DEPTH_X - .8, 0.88, DEPTH);
        glRotatef(90, 0.0, 1.0, 0);
    }
    glScalef (0.1, 0.1, 0.4);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();

    // Draw the last part of the nose with a sphere
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X, DEPTH_Y + 0.7, DEPTH + 1.3);
    } else if (moveMode[3]) {
        glTranslatef (DEPTH_X + .8, 0.88, DEPTH);
    } else {
        glTranslatef (DEPTH_X - .8, 0.88, DEPTH);
    }
    glScalef (0.1, 0.1, 0.1);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawEar(int xTranslation)
{
    int rotation = 1;
    if (xTranslation > 0)
        rotation = -1;

    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X + 0.71 * xTranslation, DEPTH_Y + 1.3, DEPTH);
        glRotatef (30, 0.0, 0.0, 0.5 * rotation);

    } else {
        glTranslatef (DEPTH_X, 1.3, DEPTH + 0.71 * xTranslation);
        glRotatef (30, 0.5 * rotation * -1, 0.0, 0);
    }


    glScalef (0.08, 0.12, 0.05);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawFace ()
{
    drawNose ();
    drawEye (-1);
    drawEye (1);
    drawMouth ();
}

void
drawHairSpike (float x, float z)
{
    if (x * 1000 > 0)
        x -= 0.08;
    else if(x * 10 != 0)
        x += 0.08;

    if (z * 1000 > 0)
        z -= 0.08;
    else if(z * 10 != 0)
        z += 0.08;

    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]) {
        glTranslatef (DEPTH_X + x, DEPTH_Y + 2.2, DEPTH + z);
        glScalef (0.1, 0.2, 0.1);
        glRotatef (90, 1.0, 0.0, 0.0);
    } else {
        glTranslatef (DEPTH_X + z, 2.2, DEPTH + x);
        glScalef (0.1, 0.2, 0.1);
        glRotatef (90, 1.0, 0.0, 0.0);
    }
    gluCylinder (gluNewQuadric (), 0.2, 0.8, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawHair ()
{
    VertexCoordinates coordinates;
    int i;
    int j;
    int nAux;
    float radiusAux;
    int radius = 0.7;
    int n = 4;
    int ns[4] = { 17, 15, 5, 1 };
    float radiuses[4] = { 0.7, 0.47, 0.3, 0 };
    for (i = 0; i < n; i++)
    {
        nAux = ns[i];
        radiusAux = radiuses[i];
        for (j = 0; j < nAux; j++)
        {
            coordinates = getSpikeCoordinates (0.0, 0.0, radiusAux, nAux, j);
            drawHairSpike (coordinates.x, coordinates.z);
        }
    }
}

void
drawNeck ()
{
    glColor3f (rSkin, rSkin, bSkin);
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + 0.35, DEPTH);
    glScalef (0.2, 0.2, 0.2);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawHead ()
{
    glColor3f (rSkin, gSkin, bSkin);

    /**
    Drawing a sphere that represent the bottom part of the head
    **/
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + 1.0, DEPTH);
    glScalef (0.7, 0.7, 0.7);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    /**
    Drawing a cylinder that represent the top part of the head
    **/
    glPushMatrix ();
    glTranslatef(DEPTH_X, DEPTH_Y + 2.0, DEPTH);
    glScalef (0.7, 1.0, 0.7);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();

    // Head cover
    glPushMatrix ();
    glTranslatef(DEPTH_X, DEPTH_Y + 2.0, DEPTH);
    glScalef (0.7, 0.001, 0.7);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    drawEar (-1);
    drawEar (1);
    drawNeck ();
    drawHair ();
    if (!moveMode[1]) // don't draw the face in backward walk
        drawFace ();
}

void
drawArm (int xTranslation)
{
    glColor3f (rShirt, gShirt, bShirt);

    // The shirt piece that cover part of the arm
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]) {
        glTranslatef (DEPTH_X + 0.2 * xTranslation, DEPTH_Y + 0.05, DEPTH);
        glScalef (0.3, 0.19, 0.22);
    } else {
        glTranslatef (DEPTH_X, 0.05, DEPTH + 0.2 * xTranslation);
        glScalef (0.27, 0.2, 0.25);
    }
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    glColor3f (rSkin, gSkin, bSkin);

    // The arm
    glPushMatrix ();
    //forward, backward
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]) {
        glTranslatef (DEPTH_X + 0.3 * xTranslation, DEPTH_Y + 0.05, DEPTH);
        glRotatef (15, 0.0, 0.0, 1.0 * xTranslation);
        glScalef (0.13, 0.9, 0.13);
        glRotatef (90, 1.0, 0.0, 0.0);
        glRotatef (ARM_ROTATION * xTranslation, 1.0, 0.0, 0.0);
    //right, left
    } else {
        glTranslatef (DEPTH_X + LEG_ROTATION/200, 0.0 + abs(LEG_ROTATION/300), DEPTH + 0.28 * xTranslation);
        glScalef (0.14, 0.9, 0.14);
        glRotatef (90, 1.0, 0.0, 0.0);
        glRotatef (LEG_ROTATION/1.5 * xTranslation, 0.0, 1.0, 0.0);


    }
    gluCylinder (gluNewQuadric (), 1.0, 0.8, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawArms ()
{
    drawArm (-1);
    drawArm (1);
}

void
drawHand (int xTranslation)
{
    glColor3f (rSkin, gSkin, bSkin);

    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        if (xTranslation == -1){
            glTranslatef (DEPTH_X + .565 * xTranslation, DEPTH_Y + -0.9, DEPTH);
            glScalef (0.13, 0.13, 0.13);
            glTranslatef ((ARM_ROTATION/50) * xTranslation * -1,  (ARM_ROTATION/20) * xTranslation * -1, DEPTH * (ARM_ROTATION/100) * xTranslation);

        } else {
            glTranslatef (DEPTH_X + .548 * xTranslation,  DEPTH_Y + -0.875, DEPTH);
            glScalef (0.13, 0.13, 0.13);
            glTranslatef ((ARM_ROTATION/450) * xTranslation * -1,  (ARM_ROTATION/30) * xTranslation * -1, DEPTH * (ARM_ROTATION/450) * xTranslation);
        }
        gluSphere (gluNewQuadric (), 1.0, 100, 100);
    } else {
        if (xTranslation == -1){
            glTranslatef (DEPTH_X + (LEG_ROTATION/120) * xTranslation, -0.9, DEPTH + .3 * xTranslation);
            glScalef (0.13, 0.13, 0.13);
            glTranslatef (DEPTH_X + (LEG_ROTATION/100) * xTranslation,  (LEG_ROTATION/20) * xTranslation * -1, DEPTH + .3 * xTranslation);
        //front hand
        } else {
            glTranslatef (DEPTH_X + (LEG_ROTATION/120) * xTranslation, -0.9, DEPTH + .3 * xTranslation);
            glScalef (0.13, 0.13, 0.13);
//            glTranslatef (DEPTH_X + (LEG_ROTATION/50) * xTranslation,  -0.9 + (LEG_ROTATION/120) * xTranslation, DEPTH + .3 * xTranslation + (LEG_ROTATION/10000) * xTranslation);
//            glTranslatef (DEPTH_X, -0.9, DEPTH);
        }
        gluSphere (gluNewQuadric (), 1.1, 100, 100);
    }

    glPopMatrix ();
}

void
drawHands ()
{
    drawHand (-1);
    drawHand (1);
}

void
drawLeg (int xTranslation)
{
    glColor3f (rShort, gShort, bShort);

    // The part of the short that cover part of the legal
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X + 0.16 * xTranslation, DEPTH_Y + -1.3, DEPTH);
        glScalef (0.14, 0.35, 0.14);
        glRotatef (90, 1.0, 0.0, 0.0);
        glRotatef (LEG_ROTATION * xTranslation, 1.0, 0.0, 0.0);
    } else {
        glTranslatef (DEPTH_X + LEG_ROTATION/400, -1.3, DEPTH + 0.16 * xTranslation);
        glScalef (0.14, 0.35, 0.14);
        glRotatef (90, 1.0, 0.0, 0.0);
        glRotatef (LEG_ROTATION * xTranslation, 0.0, 1.0, 0.0);
    }
    gluCylinder (gluNewQuadric (), 1.0, 1.0, 1.0, 100, 100);
    glPopMatrix ();

    glColor3f (rSkin, gSkin, bSkin);

    // The leg
    glPushMatrix ();
    // forward, backward
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X + 0.16 * xTranslation, DEPTH_Y + -1.6, DEPTH);
        glScalef (0.13, 0.5, 0.13);
        glRotatef (90, 1.0, 0.0, 0.0);
        glRotatef (LEG_ROTATION * xTranslation, 1.0, 0.0, 0.0);

    } else {
        if (xTranslation == -1){
            glTranslatef (DEPTH_X + LEG_ROTATION/1000 * xTranslation, -1.6, DEPTH + 0.16 * xTranslation);
            glScalef (0.13, 0.5, 0.13);
            glRotatef (90, 1.0, 0.0, 0.0);
            glRotatef (LEG_ROTATION/2 * xTranslation, 0.0, 1.0, 0.0);
        // right, left
        } else {
            glTranslatef (DEPTH_X + LEG_ROTATION/200, -1.61, DEPTH + 0.16 * xTranslation);
            glScalef (0.13, 0.5, 0.13);
            glRotatef (90, 1.0, 0.0, 0.0);
            glRotatef (LEG_ROTATION * xTranslation, 0.0, 1.0, 0.0);
        }
    }
    gluCylinder (gluNewQuadric (), 1.0, 1.0, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawLegs ()
{
    drawLeg (-1);
    drawLeg (1);
}

void
drawFoot (int xTranslation)
{
    glColor3f (rShort, gShort, bShort);

    // One shoe
    glPushMatrix ();
    if (moveMode[0] || moveMode[1] || moveMode[4] || moveMode[5]){
        glTranslatef (DEPTH_X + 0.16 * xTranslation, DEPTH_Y + -2.1, DEPTH);
        glScalef (0.13, 0.15, 0.13);
        gluSphere (gluNewQuadric (), 1.0, 100, 100);
    } else {
        if (xTranslation == -1)
            glTranslatef (DEPTH_X + LEG_ROTATION/200 * xTranslation, -2.2+ pow((LEG_ROTATION/100), 2), DEPTH + 0.16 * xTranslation);
        else
            glTranslatef (DEPTH_X + LEG_ROTATION/100 * xTranslation, -2.2+ pow((LEG_ROTATION/100), 2), DEPTH + 0.16 * xTranslation);
        glScalef (0.13, 0.15, 0.13);
        gluSphere (gluNewQuadric (), 1.15, 100, 100);
    }

    glPopMatrix ();
}

void
drawFeet ()
{
    drawFoot (-1);
    drawFoot (1);
}

void
drawBody ()
{
    glColor3f (rShirt, gShirt, bShirt);

    // The body
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + 0.2, DEPTH);
    glScalef (0.7, 1.0, 0.7);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 0.35, 0.5, 1.3, 100, 100);
    glPopMatrix ();

    // Top cover
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + 0.2, DEPTH);
    glScalef (0.245, 0.001, 0.245);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    // Bottom cover
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + -1.1, DEPTH);
    glScalef (0.35, 0.001, 0.35);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    glColor3f (rShort, gShort, bShort);

    // The short
    glPushMatrix ();
    glTranslatef (DEPTH_X, DEPTH_Y + -1.1, DEPTH);
    glScalef (0.35, 0.4, 0.35);
    gluSphere (gluNewQuadric (), 1.04, 100, 100);
    glPopMatrix ();
}

void
drawWing(int xTranslation, int wingShape)
{
    glColor3f (1.0, 1.0, 1.0);
    GLdouble x = wingShape * 0.3, y = 3;
    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        if (moveMode[0]){
            glTranslatef(DEPTH_X, DEPTH_Y + -0.3, DEPTH - 0.35);
            glRotatef (90, x, xTranslation * 1.0, 0.0);
            glScalef(1, 1, y);
            gluCylinder(gluNewQuadric (), 0.35, 0.03, .5, 100, 100);

        } else if (moveMode[1]) {
            if (wingShape == -1)
                glTranslatef(DEPTH_X, DEPTH_Y + -0.3, DEPTH + 0.35);
            else
                glTranslatef(DEPTH_X, DEPTH_Y + -0.3, DEPTH + 0.3);

            glRotatef (90, x, xTranslation * 1.0, 0.0);
//            glTranslatef(DEPTH_X, DEPTH_Y + -0.3, DEPTH + 0.35);
//            glRotatef (90, x+.5, xTranslation, xTranslation);
            glScalef(1, 1, y);
            gluCylinder(gluNewQuadric (), 0.35, 0.03, .5, 100, 100);

        } else if (moveMode[3]) { // walk right
            glTranslatef(DEPTH_X - 0.35, DEPTH_Y + -0.3, DEPTH);
            if (wingShape == 1)
                glRotatef (90, 0.0, xTranslation, x);
            else
                glRotatef (90, x/5, xTranslation, x);
            glScalef(1, 1, y);
            gluCylinder(gluNewQuadric (), 0.25, 0.03, .45, 100, 100);

        } else if (moveMode[2]) { // walk left
            glTranslatef(DEPTH_X + 0.35, DEPTH_Y + -0.3, DEPTH + 0.07);
            if (wingShape == 1)
                glRotatef (90, 0.0, -xTranslation, -x);
            else
                glRotatef (90, x/5, -xTranslation, -x);
            glScalef(1, 1, y);
            gluCylinder(gluNewQuadric (), 0.25, 0.03, .45, 100, 100);

        } else if (moveMode[4]) {
            glTranslatef(DEPTH_X, DEPTH_Y + -0.3, DEPTH - 0.35);
            glRotatef (90, x + WING_ROTATION, xTranslation * 1.0, 0.0);
            glScalef(1, 1, y);
            gluCylinder(gluNewQuadric (), 0.35, 0.03, .5, 100, 100);
        }

        glPopMatrix ();

        x-=0.1;
        y+=1;

    }

}

void
drawWings() {
    drawWing(-1, 1);
    drawWing(-1, -1);
    if (!(moveMode[2] || moveMode[3])){
        drawWing(1, 1);
        drawWing(1, -1);
    }
}

void
drawCharacter () // calling functions to draw parts separately
{
    drawBody ();
    drawHead ();
    drawLegs ();
    drawFeet ();
    drawArms ();
    drawHands ();
    drawWings();
}
