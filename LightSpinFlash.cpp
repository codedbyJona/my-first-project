#include <stdlib.h>
#include <math.h>
#include "glut.h"
#include <GL/gl.h>
#include <GL/glu.h>
/* It was possible to make this program through the use of the books:

Dave Shreiner. (2010). OPENGL Programming Guide 7th edition.
The Official Guide to Learning Open GL, Versions 3.0 and 3.1.
The Khronos OPENGL ARB Working Group.

and

F.S. Hill, JR., Stephen M. (2007). Kelley Computer Graphics Using Open GL.
Pearson International Edition

*/

GLfloat theta;
GLfloat rot = 1.0;
GLfloat lookx = -100, looky = -100, lookz = -100;

void init(void)
{
	// Clear the color of the window and set the color 
	// to (0.0, 0.0, 0.0, 0.0)
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// defines the Shade Model either 
	// FLAT with each pixel treated with
	// same shading, or SMOOTH with each pixel's
	// color resulting from interpolation
	glShadeModel(GL_SMOOTH);

	// Enable the Light Source and
	// assign it to the identifier GL_LIGHT0
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// used to eliminate hidden surface
	// (try to remove glEnable(GL_DEPTH_TEST);)
	glEnable(GL_DEPTH_TEST);

}

void rayTracing(void)
{

	int nRows = 20;
	int nCols = 20;
	float length = 1.0;

	// The topmost matrix is copied 
	// so that its contents are duplicated 
	// and located in the topmost and 
	// second from the top matrices
	glPushMatrix();
	// The Light Source is temporarily disabled
	glDisable(GL_LIGHTING);
	// The color is set to (0.0, 0.0, 0.0)
	glColor3f(0.0, 0.0, 0.0);
	// The Light Source assigned to the identifier
	// GL_LIGHT0 is enabled
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// The rotations about the Z, Y and X
	// axis are given to the rays just
	// to be traced below
	glRotatef(theta, 0.0, 0.0, rot);
	glRotatef(theta, 0.0, rot, 0.0);
	glRotatef(theta, rot, 0.0, 0.0);
	glRotatef(theta, 0.0, 0.0, 0.0);

	// Trace the rays
	for (int row = 0; row < nRows; row++)
	{
		for (int col = 0; col < nCols; col++)
		{
			// compute the rays directions						
			glBegin(GL_LINES);
			glVertex2f(0, 0);
			glVertex2f(length + row, length + col);
			glEnd();
		}
	}

	// Removes the topmost matrix
	// The second from the top matrices
	// becomes the topmost matrix
	glPopMatrix();

}

void BluePlanet(void) {

	GLfloat Blue[] = { 0.0, 0.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Blue);// pgs.214-227
	// syntax: glLight{if}(GL_ENUM light, GLenum pname, TYPE param), 
	// syntax: glLight{if}v(GL_ENUM light, GLenum pname, TYPE *param);
	// The characteristic of the light is defined by pname, which specifies
	// a named parameter (see Table 5-1, pg. 215).
	// 'param' indicates the values to which the 'pname' characteristic is set.
	// 'param' is a pointer to an array if the vector version is used OR
	// 'param' is the vaue itself if the non-vector version is used.
	// The nonvector version can be used to set only single-valued light characteristics:
	// Try: glLightf(GL_LIGHT2, GL_DIFFUSE, 45.0);

	// The Light Source assigned to the identifier
	// GL_LIGHT2 is enabled: //pgs. 10, 54, 213
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);

	glutSolidSphere(0.1, 10, 8); // draw planet

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT2);

}

void RedPlanet(void) {

	GLfloat Red[] = { 1.0, 0.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Red);// pgs.214-227
	// syntax: glLight{if}(GL_ENUM light, GLenum pname, TYPE param), 
	// syntax: glLight{if}v(GL_ENUM light, GLenum pname, TYPE *param);
	// The characteristic of the light is defined by pname, which specifies
	// a named parameter (see Table 5-1, pg. 215).
	// 'param' indicates the values to which the 'pname' characteristic is set.
	// 'param' is a pointer to an array if the vector version is used OR
	// 'param' is the vaue itself if the non-vector version is used.
	// The nonvector version can be used to set only single-valued light characteristics:
	// Try: glLightf(GL_LIGHT2, GL_DIFFUSE, 45.0);

	// The Light Source assigned to the identifier
	// GL_LIGHT2 is enabled: //pgs. 10, 54, 213
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glutSolidSphere(0.1, 30, 30); // draw planet

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT1);

}

void LightSpinFlash_v3(void)
{
	// sets a position
	GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

	/// Your Input starts here

	// Step 1: projects the rays of light
	// Use the function provided in this
	// program to do ray tracing
	// One line of code:




	// Step 2: Use the OpenGL function that
	// performs the following operation:
	// The topmost matrix is copied 
	// so that its contents are duplicated 
	// and located in the topmost and 
	// second from the top matrices
	// One line of code:




	// Step 3: Rotation of the Light Source GL_LIGHT0
	// Use the angle 'theta' to animate. Enforce the
	// following 4 rotations: A. about the xAxis, 
	// B. about the yAxis, C. about the zAxis,
	// D. the rotation about the origin (0, 0, 0)
	// that shows up to be motion across the frustrum
	// Four lines of code:



	// Step 4: Create the Light Source specified by GL_LIGHT0 with the 
	// characteristic to be a positioned light at the position
	// indicated through GLfloat position [] = {0.0, 0.0, 1.5, 1.0};
	// Hint: use the glLightfv() function
	// One line of code:




	// Step 5: position the cube at X = 0, Y = 0, Z = 1.5
	// Hint: Use the command: glTranslated()
	// One line of code:



	// Step 6:  A. Temporarily disable the Light Source
	// B. Set the color to your favorite 
	// C. Wire the cube with edge size '0.2' 
	// Three lines of code:



	// Step 7: position the cube using X = 0, Y = 0, Z =- 1.5
	// Hint: Use the command: glTranslated()
	// One line of code:



	// Step 8:  A. Temporarily disable the Light Source
	// B. Set the color to your favorite 
	// C. Wire the cube with edge size '0.2' 
	// Three lines of code:




	// Step 9: Enable the Light Source GL_LIGHT0 again
	// One line of code:




	// Step 10: Use the OpenGL function that
	// performs the following operation:
	// Remove the topmost matrix from the stack
	// and the second from the top matrices
	// becomes the topmost matrix
	// One line of code:


	// Step 11: Use the command gluLookAt() to
	// define (-100, -100, -100) as the point in the center of the scene being looked at
	// Since the command gluLookAt defines a viewing matrix, the point (-100, -100, -100)
	// becomes practically the center of the scene
	// Hint: lookx = -100, looky = -100, lookz = -100; eye of the camera at (0.0, 0.0, 0.0);
	// Up vector: (0.0, 1.0, 0.0)
	// One line of code:



	// Step 12: Make an if statement and condition 
	// the statement to the theta angle >= 0.0
	// and <= 180.0. Instructions on how to use
	// the brackets of the if statement are
	// provided below. 
	// Then do the following.
	// A. Use the function provided by the program
	// to draw a RedPlanet(). B. Set your favorite
	// color. C. Disable the Light Source.
	// Four lines of code:



		// do not use the closing bracket of the if statement yet.


	// Step 13: (Rotations of the Torus) 
	// Use the angle 'theta' to animate. Enforce the
	// following 4 rotations: A. about the xAxis, 
	// B. about the yAxis, C. about the zAxis,
	// D. the rotation about the origin (0, 0, 0)
	// that shows up to be motion across the frustrum
	// Four lines of code:




		// Step 14: Wire the Torus. You may use the solid torus too:
		// void SolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings)
		// Hint: both solid torus and wired torus take 4 arguments
		// One line of code:




	// now close the if statement with the
	// closing bracket.



	// Step 14: Make an if statement and condition 
	// the statement to the theta angle > 180.0
	// and <= 360.0. Instructions on how to use
	// the brackets of the if statement are
	// provided below. 
	// Then do the following.
	// A. Use the function provided by the program
	// to draw a BluePlanet(). B. Set your favorite
	// color. C. Disable the Light Source.
	// Four lines of code:




		// do not use the closing bracket of the if statement yet.

		// Step 15: (Rotations of the Torus) 
		// Use the angle 'theta' to animate. Enforce the
		// following 4 rotations: A. about the xAxis, 
		// B. about the yAxis, C. about the zAxis,
		// D. the rotation about the origin (0, 0, 0)
		// that shows up to be motion across the frustrum
		// Four lines of code:





		// Step 16: Wire the Torus. You may use the solid torus too:
		// void SolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings)
		// Hint: both solid torus and wired torus take 4 arguments
		// One line of code:


		// now use the closing bracket of the if statement


	/// Your Input ends here
}  // end of function

void display(void)
{

	// Clear either the COLOR_BUFFER 
	// or the DEPTH_BUFFER (used for hidden
	// surfaces removal)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// The topmost matrix is copied 
	// so that its contents are duplicated 
	// and located in the topmost and 
	// second from the top matrices
	glPushMatrix();

	// Positioning of the Scene
	glTranslatef(0.75, 0.0, -5.0);

	// make the scene appear
	LightSpinFlash_v3();

	// Removes the topmost matrix
	// The second from the top matrices
	// becomes the topmost matrix
	glPopMatrix();

	// The topmost matrix is copied 
	// so that its contents are duplicated 
	// and located in the topmost and 
	// second from the top matrices
	glPushMatrix();

	// Positioning of the Scene
	glTranslatef(-0.75, 0.0, -5.0);

	// make the scene appear
	LightSpinFlash_v3();

	// Removes the topmost matrix
	// The second from the top matrices
	// becomes the topmost matrix
	glPopMatrix();
	glutSwapBuffers();

	// forces prevously issued commands to 
	// begin execution ('try to remove glFlush();')
	glFlush();

}

void reshape(int w, int h)
{
	// While reshaping sets the size of the viewport
	// the same as the size of the viewing window
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// When used with the parameter GL_PROJECTION,
	// the command glMatrixMode() specifies that 
	// the subsequent transformation matrices are
	// made to the 'Projection Matrix': in this
	// case both of glLoadIdentity() and gluPerspective().
	glMatrixMode(GL_PROJECTION);
	// Load the Identity Matrix
	glLoadIdentity();

	// void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble near, GLdouble far)
	// Creates a matrix for symmetric perspective-view 
	// and multiplies the current matrix by it. 
	// fovy is the angle of the field of view in the YZ plane, 
	// its value must be in the range [0, 180]. 
	// aspect is the aspect ratio, which is width divided 
	// by height. near and far values are the distances 
	// between the viewpoint and the clipping planes along 
	// the Z axis. near and far should always be positive.
	// (try remove the command: gluPerspective(40.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);) 
	gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	// Now the command glMatrixMode() is called
	// with the parameter GL_MODELVIEW, which means
	// that the subsequent transformation matrices 
	// will be applied to the 'ModelView' Matrix (The current matrix)
	// instead of the 'Projection Matrix'
	glMatrixMode(GL_MODELVIEW);
	// Load the Identity Matrix
	glLoadIdentity();

}

// sets the value of the 
// rotational angle theta
void spin(void)
{

	theta += (double)0.1;
	if (theta > 360.0) theta -= 360.0;

	// Practically causes the command:
	// glutMainLoop() to call display()
	// to render again (try remove the
	// command: glutPostRedisplay();)
	glutPostRedisplay();

}


int main(int argc, char** argv)
{

	glutInit(&argc, argv);

	// specifies a display mode, in this case the
	// display mode is either a single buffer (GLUT_SINGLE)
	// or a RGB color model (GLUT_RGB) or a depth buffer (GLUT_DEPTH)
	// used to remove hidden surfaces
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	// sets the Viewing Window Size
	glutInitWindowSize(500, 500);

	// set the Viewing Window position onto the screen
	glutInitWindowPosition(100, 100);

	// Create the Viewing Window and assign it with
	// the name which is the argument passed to the
	// function glutCreateWindow()
	glutCreateWindow("Light Spin Flash");

	// call the function init()
	init();
	// receives as input the display function
	glutDisplayFunc(display);
	// receives as input the reshape function
	glutReshapeFunc(reshape);
	// specifies the function, 'spin' in this 
	// case, to be executed, if no other events
	// are pending. If NULL is passed
	// as argument, then the execution is disabled
	glutIdleFunc(spin);
	// enters the GLUT processing loop never to return
	glutMainLoop();

	return 0;             /* ANSI C requires main to return int. */

}