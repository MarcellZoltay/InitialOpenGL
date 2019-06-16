#include "stdafx.h"
#include "App.h"

using namespace Framework;

App::App(int argc, char * argv[])
{
	glutInit(&argc, argv);

	int majorVersion = 3, minorVersion = 3;
	glutInitContextVersion(majorVersion, minorVersion);

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	
	glutCreateWindow(argv[0]);
	//glutFullScreen();

	glewExperimental = true;
	glewInit();

	printf("GL Vendor    : %s\n", glGetString(GL_VENDOR));
	printf("GL Renderer  : %s\n", glGetString(GL_RENDERER));
	printf("GL Version (string)  : %s\n", glGetString(GL_VERSION));
	glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &minorVersion);
	printf("GL Version (integer) : %d.%d\n", majorVersion, minorVersion);
	printf("GLSL Version : %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	glViewport(0, 0, windowWidth, windowHeight);

	glEnable(GL_DEPTH_TEST);


	lastTime = glutGet(GLUT_ELAPSED_TIME);

	camera = new PerspectiveCamera();
}

void App::createScene() 
{
	scene = this->newScene();
	scene->createObjects();
}

void App::run()
{
	glutMainLoop();
}

void App::update()
{
	double time = glutGet(GLUT_ELAPSED_TIME);
	double dt = (time - lastTime) / 1000.0;
	lastTime = time;

	camera->move(dt, keysPressed);
	scene->update(dt);
}

void App::render() 
{
	scene->render(camera);
}

void App::resize(int width, int height)
{
	camera->setAspectRatio((float)width / height);
}

void App::keyPressed(unsigned char key)
{
	keysPressed[key] = true;
}
void App::keyReleased(unsigned char key)
{
	keysPressed[key] = false;
}

void App::mouseDown(int pX, int pY)
{
	camera->mouseDown(pX, pY);
}
void App::mouseUp()
{
	camera->mouseUp();
}
void App::mouseMove(int pX, int pY)
{
	camera->mouseMove(pX, pY);
}