#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Math/mymath.h"

#include "GL/glew.h"
#include "GL/freeglut.h"

namespace Framework {

	class ShaderProgram
	{
		unsigned int ID;

		void getErrorInfo(unsigned int handle);
		void checkShader(unsigned int shader, const char * message);
		void checkLinking(unsigned int program);

		void createProgram(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath);

		ShaderProgram(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath)
		{ 
			createProgram(vertexShaderPath, fragmentShaderPath);
		}

	public:
		static std::shared_ptr<ShaderProgram> create(const GLchar* vertexShaderPath, const GLchar* fragmentShaderPath)
		{
			return std::shared_ptr<ShaderProgram>(new ShaderProgram(vertexShaderPath, fragmentShaderPath));
		}

		unsigned int getId();

		void use();

		void setUniformVec3(const std::string &name, vec3 value) const;
		void setUniformVec4(const std::string &name, vec4 value) const;
		void setUniformMat4(const std::string &name, mat4 value) const;

		~ShaderProgram()
		{
			glDeleteProgram(ID);
		}
	};

}