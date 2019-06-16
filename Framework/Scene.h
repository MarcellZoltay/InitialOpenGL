#pragma once

#include <vector>

#include "Math/vec4.h"
#include "SceneObject.h"
#include "PerspectiveCamera.h"

#include "GL/glew.h"
#include "GL/freeglut.h"

namespace Framework {

	class Scene
	{
	protected:
		vec4 backgroundColor;

		std::vector<SceneObject*> sceneObjects;

	public:
		Scene() {}

		virtual void createObjects() = 0;

		virtual void update(double dt);
		void render(PerspectiveCamera* camera);

		virtual ~Scene() 
		{
			for (SceneObject *obj : sceneObjects) {
				delete obj;
			}
			sceneObjects.clear();
		}
	};

}