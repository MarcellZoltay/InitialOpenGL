#pragma once

#include "Scene.h"
#include "CubeSceneObject.h"

using namespace Framework;

namespace Skeleton
{
	class CubeScene : public Scene
	{
	public:
		CubeScene() {}

		void createObjects();

		void update(double dt);

		~CubeScene() {}
	};
}