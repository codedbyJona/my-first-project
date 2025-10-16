#include "glut.h"
#include <math.h>   // For sine and cosine functions

// Rotation angles and speeds
float angleCube1 = 0, angleCube2 = 0, angleSphere = 0;
float speedCube1 = 0.6, speedCube2 = 0.3, speedSphere = 0.5;

// Scale and visibility flags
int showCube1 = 1, showCube2 = 1, showSphere = 1;
float cube1Scale = 1.0, cube2Scale = 0.5;
float sphereRadius = 0.4;
float M_PI = 3.14;
// Lighting flag
int lightingOn = 1;

// Animation parameters for object movement
float moveTime = 0.0;
float moveSpeed = 0.05;  // Speed of the movement

// Initialize lighting and material
void initLighting() {
    GLfloat lightPos[] = { 2.0, 2.0, 2.0, 1.0 };
    GLfloat ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.1, 0.1, 0.1, 1.0);
    initLighting();
}

// Draw a cube at a specified location
void drawCube(float x, float y, float z, float scale, float angle, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, 1, 1, 1);
    glScalef(scale, scale, scale);
    glColor3f(r, g, b);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Draw a sphere at a position
void drawSphere(float x, float y, float z, float radius, float angle, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(angle, 0, 1, 0);
    glColor3f(r, g, b);
    glutSolidSphere(radius, 30, 30);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(3, 3, 6,  // Eye position
        0, 0, 0,  // Look at
        0, 1, 0); // Up vector

    // Compute new positions for animation
    float x1 = 2.0 * sin(moveTime);   // Horizontal movement of the first cube
    float z1 = 2.0 * cos(moveTime);   // Vertical movement of the first cube
    float y2 = 2.0 * cos(moveTime);   // Vertical movement of the second cube
    float x2 = 2.0 * sin(moveTime);   // Horizontal movement of the second cube
    float zSphere = 3.0 * sin(moveTime); // Circular movement for sphere

    // Draw objects
    if (showCube1) drawCube(x1, 0, z1, cube1Scale, angleCube1, 1, 0, 0); // Red cube
    if (showCube2) drawCube(x2, y2, 0, cube2Scale, angleCube2, 0, 1, 0); // Green cube
    if (showSphere) drawSphere(0, zSphere, 0, sphereRadius, angleSphere, 0, 0, 1); // Blue sphere

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    angleCube1 += speedCube1;
    angleCube2 += speedCube2;
    angleSphere += speedSphere;
    if (angleCube1 > 360) angleCube1 -= 360;
    if (angleCube2 > 360) angleCube2 -= 360;
    if (angleSphere > 360) angleSphere -= 360;

    // Update moveTime for animation
    moveTime += moveSpeed;
    if (moveTime > 2 * M_PI) moveTime -= 2 * M_PI; // Reset after one full cycle

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': showCube1 = !showCube1; break;
    case '2': showCube2 = !showCube2; break;
    case '3': showSphere = !showSphere; break;
    case '+': sphereRadius += 0.1f; break;
    case '-': sphereRadius -= 0.1f; if (sphereRadius < 0.1f) sphereRadius = 0.1f; break;
    case 'l': case 'L':
        lightingOn = !lightingOn;
        if (lightingOn) glEnable(GL_LIGHTING);
        else glDisable(GL_LIGHTING);
        break;
    case 27: exit(0); // ESC to exit
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Animated Scene");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}

