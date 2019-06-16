#pragma once

#include "Math/mymath.h"
#include "Mesh.h"
#include "PerspectiveCamera.h"

namespace Framework {

	class GameObject
	{
	protected:
		vec3 position;
		vec3 orientation;
		vec3 scale;

		mat4 modelMatrix;

		Mesh *mesh;
		std::shared_ptr<ShaderProgram> shaderProgram;

		void updateModelMatrix();
		
	public:
		GameObject(Mesh *mesh, std::shared_ptr<ShaderProgram> shaderProgram)
		{
			this->mesh = mesh;
			this->shaderProgram = shaderProgram;

			position = vec3();
			orientation = vec3();
			scale = vec3(1, 1, 1);

			modelMatrix = mat4();
		}

		void rescale(const vec3& s);
		void rotateX(float angleX);
		void rotateY(float angleY);
		void rotateZ(float angleZ);
		void rotate(float angle, const vec3& r);
		void translate(const vec3& t);

		virtual void move(double dt) {}
		virtual void draw(PerspectiveCamera* camera);

		~GameObject()
		{
			delete mesh;
		}
	};

}