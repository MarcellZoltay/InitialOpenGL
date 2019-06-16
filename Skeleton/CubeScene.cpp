#include "CubeScene.h"

using namespace Skeleton;

void CubeScene::createObjects() 
{
	CubeSceneObject *sceneObject = new CubeSceneObject();
	//sceneObject->translate(vec3(1, 1, 1));

	sceneObjects.push_back(sceneObject);
}

void CubeScene::update(double dt)
{
	// animate scene objects here
	//sceneObjects.at(0)->rotate(dt, vec3(0, 1, 0));

	Scene::update(dt);
}