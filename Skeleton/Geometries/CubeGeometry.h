#pragma once

#include <memory>
#include "Geometry.h"

using namespace Framework;

namespace Skeleton {

	class CubeGeometry : public Geometry
	{
		CubeGeometry();

	public:
		static std::shared_ptr<CubeGeometry> create() 
		{
			return std::shared_ptr<CubeGeometry>(new CubeGeometry());
		}

		void draw();

		~CubeGeometry() {}
	};

}