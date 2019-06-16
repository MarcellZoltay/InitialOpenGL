#pragma once

#include <vector>

#include "Math/vec3.h"
#include "GameObject.h"
#include "PerspectiveCamera.h"

namespace Framework {

	class SceneObject
	{
	protected:
		vec3 position;
		vec3 orientation;

		std::vector<GameObject*> gameObjects;

	public:
		SceneObject() 
		{
			position = vec3();
			orientation = vec3();
		}

		virtual void animate(double dt) = 0;
		void draw(PerspectiveCamera* camera);

		void translate(const vec3& t);
		void rotate(float angle, const vec3& r);

		virtual ~SceneObject() 
		{
			for (GameObject *obj : gameObjects) {
				delete obj;
			}
			gameObjects.clear();
		}
	};

}