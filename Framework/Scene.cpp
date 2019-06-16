#include "stdafx.h"
#include "Scene.h"

using namespace Framework;

void Scene::update(double dt) 
{
	std::vector<SceneObject*>::iterator it;
	for (it = sceneObjects.begin(); it != sceneObjects.end(); ++it)
	{
		(*it)->animate(dt);
	}
}

void Scene::render(PerspectiveCamera* camera) 
{
	glClearColor(this->backgroundColor.x, this->backgroundColor.y, this->backgroundColor.z, this->backgroundColor.w);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::vector<SceneObject*>::iterator it;
	for (it = sceneObjects.begin(); it != sceneObjects.end(); ++it)
	{
		(*it)->draw(camera);
	}

	glutSwapBuffers();
}
