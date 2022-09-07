#include "animation.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

float DEPTH = -15;
float DEPTH_X = 0;
float DEPTH_Y = 0;
float ARM_ROTATION = 0;
float LEG_ROTATION = 0;
float WING_ROTATION = 0;
int IS_WALKING;
int IS_FLYING_UP;
int IS_FLYING_FLAT;
int moveMode[6] = {1, 0, 0, 0, 0, 0};

int ARM_ROTATION_FACTOR;
int ARM_ROTATION_LIMIT;
int LEG_ROTATION_FACTOR;
int LEG_ROTATION_LIMIT;
int WING_ROTATION_FACTOR;
int WING_ROTATION_LIMIT;

void
moveCharacterForward ()
{
    if (ARM_ROTATION >= ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = -1;
    else if (ARM_ROTATION <= -ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = 1;

    if (LEG_ROTATION >= LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = -1;
    else if (LEG_ROTATION <= -LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = 1;

    DEPTH += 0.05; // speed of camera movement
    ARM_ROTATION += 1.0 * ARM_ROTATION_FACTOR; // speed of hand movements
    LEG_ROTATION += 1.5 * LEG_ROTATION_FACTOR; // speed of leg  movements
    glutPostRedisplay ();
}

void
moveCharacterBackward ()
{
    if (ARM_ROTATION >= ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = -1;
    else if (ARM_ROTATION <= -ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = 1;

    if (LEG_ROTATION >= LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = -1;
    else if (LEG_ROTATION <= -LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = 1;

    DEPTH -= 0.05; // speed of camera movement
    ARM_ROTATION += 1.0 * ARM_ROTATION_FACTOR; // speed of hand movements
    LEG_ROTATION += 1.5 * LEG_ROTATION_FACTOR; // speed of leg  movements
    glutPostRedisplay ();
}

void
moveCharacterRight ()
{
    if (ARM_ROTATION >= ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = -1;
    else if (ARM_ROTATION <= -ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = 1;

    if (LEG_ROTATION >= LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = -1;
    else if (LEG_ROTATION <= -LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = 1;

    DEPTH_X += 0.02; // speed of camera movement
    ARM_ROTATION += 1.0 * ARM_ROTATION_FACTOR; // speed of hand movements
    LEG_ROTATION += 1.5 * LEG_ROTATION_FACTOR; // speed of leg  movements
    glutPostRedisplay ();
}

void
moveCharacterLeft ()
{
    if (ARM_ROTATION >= ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = -1;
    else if (ARM_ROTATION <= -ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = 1;

    if (LEG_ROTATION >= LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = -1;
    else if (LEG_ROTATION <= -LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = 1;

    DEPTH_X -= 0.02; // speed of camera movement
    ARM_ROTATION += 1.0 * ARM_ROTATION_FACTOR; // speed of hand movements
    LEG_ROTATION += 1.5 * LEG_ROTATION_FACTOR; // speed of leg  movements
    glutPostRedisplay ();
}

void
moveCharacterUp ()
{
    ARM_ROTATION = LEG_ROTATION = 0.0;

    if (WING_ROTATION >= WING_ROTATION_LIMIT)
        WING_ROTATION_FACTOR = -1;
    else if (WING_ROTATION <= -WING_ROTATION_LIMIT)
        WING_ROTATION_FACTOR = 1;

    WING_ROTATION += 0.06 * WING_ROTATION_FACTOR;

    if (WING_ROTATION_FACTOR == 1){
        DEPTH_Y += 0.025;

    } else {
        DEPTH_Y -= 0.003; // speed of camera movement
    }

    glutPostRedisplay ();
}


void
walk (unsigned char key, int x, int y)
{
    switch (key) {
        case 'w': // walk backward
            if (!IS_WALKING && !IS_FLYING_UP)
        {
            glutIdleFunc(moveCharacterForward);
            memset(moveMode, 0, sizeof moveMode);
            moveMode[0] = 1;
            IS_WALKING = 1;
            IS_FLYING_UP = 0;
        }
        break;
        case 's': // walk forward
            if (!IS_WALKING && !IS_FLYING_UP)
        {
            glutIdleFunc(moveCharacterBackward);
            memset(moveMode, 0, sizeof moveMode);
            moveMode[1] = 1;
            IS_WALKING = 1;
            IS_FLYING_UP = 0;
        }
        break;
        case 'a': // walk to left
            if (!IS_WALKING && !IS_FLYING_UP)
        {
                glutIdleFunc(moveCharacterLeft);
                memset(moveMode, 0, sizeof moveMode);
                moveMode[2] = 1;
                IS_WALKING = 1;
                IS_FLYING_UP = 0;
        }
        break;
        case 'd': // walk to right
            if (!IS_WALKING && !IS_FLYING_UP)
        {
                glutIdleFunc(moveCharacterRight);
                memset(moveMode, 0, sizeof moveMode);
                moveMode[3] = 1;
                IS_WALKING = 1;
                IS_FLYING_UP = 0;
        }
        break;
        case 'i': // flyFlat up
            if (!IS_WALKING && !IS_FLYING_UP)
        {
            glutIdleFunc(moveCharacterUp);
            memset(moveMode, 0, sizeof moveMode);
            moveMode[4] = 1;
            IS_WALKING = 0;
            IS_FLYING_UP = 1;
            IS_FLYING_FLAT = 0;
        }
        break;
        case 'r': // stops the character or flies flat
        {
            if (IS_FLYING_UP){
                glutIdleFunc(flyFlat);
                IS_FLYING_FLAT = 1;
                IS_FLYING_UP = 0;
            }

            else initialize ();
        }
        break;
        case 27:
        {
            exit(0);
        }
    }
}

void
flyFlat ()
{

    if (WING_ROTATION >= WING_ROTATION_LIMIT)
        WING_ROTATION_FACTOR = -1;
    else if (WING_ROTATION <= -WING_ROTATION_LIMIT)
        WING_ROTATION_FACTOR = 1;

    WING_ROTATION += 0.06 * WING_ROTATION_FACTOR;

    if (WING_ROTATION_FACTOR == 1){
        DEPTH_Y += 0.005;

    } else {
        DEPTH_Y -= 0.005; // speed of camera movement
    }

    glutPostRedisplay ();

}

void
initialize ()
{

    IS_WALKING = IS_FLYING_UP = IS_FLYING_FLAT = 0;
    ARM_ROTATION_FACTOR = -1;
    ARM_ROTATION_LIMIT = 10;
    LEG_ROTATION_FACTOR = 1;
    LEG_ROTATION_LIMIT = 15;
    WING_ROTATION_FACTOR = 1;
    WING_ROTATION_LIMIT = 1;

    glutIdleFunc (NULL);
}
