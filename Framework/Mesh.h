#pragma once

#include "Geometry.h"
#include "Material.h"

namespace Framework {

	class Mesh
	{
		std::shared_ptr<Geometry> geometry;
		std::shared_ptr<Material> material;

	public:
		Mesh(std::shared_ptr<Geometry> geometry, std::shared_ptr<Material> material)
		{
			this->geometry = geometry;
			this->material = material;
		}

		void draw();

		~Mesh() {}
	};

}