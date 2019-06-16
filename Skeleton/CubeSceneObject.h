#pragma once

#include "SceneObject.h"
#include "ShaderProgram.h"
#include "Geometries/CubeGeometry.h"
#include "Materials/SolidMaterial.h"
#include "Mesh.h"
#include "GameObject.h"

using namespace Framework;

namespace Skeleton {

	class CubeSceneObject : public SceneObject
	{
	public:
		CubeSceneObject();

		void animate(double dt);

		~CubeSceneObject() {}
	};

}