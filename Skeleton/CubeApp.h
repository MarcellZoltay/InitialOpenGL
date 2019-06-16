#pragma once

#include "App.h"
#include "CubeScene.h"

using namespace Framework;

namespace Skeleton {

	class CubeApp : public App
	{
	public:
		CubeApp(int argc, char * argv[]) : App(argc, argv) 
		{
			this->camera->translate(vec3(0, 0, 5));
		}

		Scene* newScene();

		~CubeApp() {}
	};

}

