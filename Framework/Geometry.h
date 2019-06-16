#pragma once

#include "GL/glew.h"
#include "GL/freeglut.h"

namespace Framework {

	class Geometry
	{
	protected:
		unsigned int vao;
		unsigned int vbo_indices;
		int indexCount;

	public:
		Geometry() {}

		virtual void draw() = 0;

		virtual ~Geometry() {}
	};

}