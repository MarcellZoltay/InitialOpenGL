#pragma once

#include "ShaderProgram.h"

namespace Framework {

	class Material
	{
	protected:
		std::shared_ptr<ShaderProgram> shaderProgram;

	public:
		Material(std::shared_ptr<ShaderProgram> shaderProgram)
		{
			this->shaderProgram = shaderProgram;
		}

		virtual void commit() = 0;

		virtual ~Material() {}
	};

}