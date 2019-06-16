#pragma once

#include <memory>
#include "Material.h"

using namespace Framework;

namespace Skeleton {

	class SolidMaterial : public Material
	{
		SolidMaterial(std::shared_ptr<ShaderProgram> program) : Material(program) {}
	
	public:
		static std::shared_ptr<SolidMaterial> create(std::shared_ptr<ShaderProgram> program)
		{
			return std::shared_ptr<SolidMaterial>(new SolidMaterial(program));
		}

		void commit();		

		~SolidMaterial() {}
	};

}