#ifndef ANIMATION_H_
#define ANIMATION_H_

extern float DEPTH;
extern float DEPTH_X;
extern float DEPTH_Y;
extern float ARM_ROTATION;
extern float LEG_ROTATION;
extern float WING_ROTATION;
extern int IS_WALKING;
extern int IS_FLYING_UP;
extern int IS_FLYING_FLAT;
extern int moveMode[];

void
moveCharacterForward ();

void
moveCharacterBackward ();

void
moveCharacterRight ();

void
moveCharacterLeft ();

void
moveCharacterUp ();

void
walk (unsigned char key, int x, int y);

void
flyFlat();

void
initialize ();

#endif
