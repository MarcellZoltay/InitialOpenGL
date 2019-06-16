// CubeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "EventHandler.h"
#include "App.h"
#include "CubeApp.h"

using namespace Skeleton;

Framework::App *app;

int main(int argc, char * argv[])
{
	app = new CubeApp(argc, argv);
	app->createScene();

	// Register event handlers
	glutDisplayFunc(onDisplay);                
	glutMouseFunc(onMouse);
	glutIdleFunc(onIdle);
	glutKeyboardFunc(onKeyboard);
	glutKeyboardUpFunc(onKeyboardUp);
	glutMotionFunc(onMouseMotion);
	glutReshapeFunc(onReshape);
	
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	app->run();

	delete app;

	return 1;
}

void Framework::onIdle()
{
	app->update();

	glutPostRedisplay();
}
void Framework::onDisplay()
{
	app->render();
}

void Framework::onReshape(int width, int height)
{
	glViewport(0, 0, width, height);

	app->resize(width, height);
}

void Framework::onKeyboard(unsigned char key, int pX, int pY)
{
	app->keyPressed(key);
}
void Framework::onKeyboardUp(unsigned char key, int pX, int pY)
{
	app->keyReleased(key);
}

void Framework::onMouse(int button, int state, int pX, int pY)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		app->mouseDown(pX, pY);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		app->mouseUp();
	}
}
void Framework::onMouseMotion(int pX, int pY)
{
	app->mouseMove(pX, pY);
}