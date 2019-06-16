#include "SceneObject.h"

using namespace Framework;

void SceneObject::draw(PerspectiveCamera* camera)
{
	std::vector<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->draw(camera);
	}
}

void SceneObject::translate(const vec3& t)
{
	this->position += t;

	std::vector<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->translate(t);
	}
}

void SceneObject::rotate(float angle, const vec3& r)
{
	std::vector<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->translate(-this->position);
		(*it)->rotate(angle, r);
		(*it)->translate(this->position);
	}
}