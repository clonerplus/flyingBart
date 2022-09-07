#include <glut.h>
#include <GL/gl.h>
#include "body.h"
#include "animation.h"
#include "scenario.h"

void
init ()
{
    initialize (); // initialize the animation part
    loadTexture (); // not yet prepared
}

void
resize (int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport (0, 0, width, height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity () ;
}

void
display ()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d (0.95, 0.95, 0.95);

    drawCharacter ();
    drawScenario ();

    glutSwapBuffers ();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int
main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (10,10);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow ("move animation");

    init ();
    glutReshapeFunc (resize); // camera view change
    glutDisplayFunc (display);// show in monitor on OpenGL window
    glutKeyboardFunc (walk);  // use keyboard to control move

    glClearColor (0.8, 0.8, 0.7, 1);
    glEnable (GL_CULL_FACE);
    glCullFace (GL_BACK);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LESS);

    glEnable (GL_LIGHT0);
    glEnable (GL_NORMALIZE);
    glEnable (GL_COLOR_MATERIAL);
    glEnable (GL_LIGHTING);

    glLightfv (GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv (GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv (GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv (GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv (GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv (GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv (GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv (GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop ();

    return 0;
}
