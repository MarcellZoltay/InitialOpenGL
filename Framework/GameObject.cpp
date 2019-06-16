#include "stdafx.h"
#include "GameObject.h"

using namespace Framework;

void GameObject::rescale(const vec3& s)
{
	this->scale *= s;
}

void GameObject::rotateX(float angleX)
{
	this->orientation.x += angleX;

	if (this->orientation.x > 2 * PI)
		this->orientation.x -= 2 * PI;
}
void GameObject::rotateY(float angleY)
{
	this->orientation.y += angleY;

	if (this->orientation.y > 2 * PI)
		this->orientation.y -= 2 * PI;
}
void GameObject::rotateZ(float angleZ)
{
	this->orientation.z += angleZ;

	if (this->orientation.z > 2 * PI)
		this->orientation.z -= 2 * PI;
}
void GameObject::rotate(float angle, const vec3& r)
{
	this->position = (vec4(this->position, 1) * rotationMatrix(angle, r)).xyz();
}

void GameObject::translate(const vec3& t)
{
	this->position += t;
}

void GameObject::updateModelMatrix()
{
	this->modelMatrix = scaleMatrix(this->scale) * 
						rotationMatrix(this->orientation.x, vec3(1, 0, 0)) *
						rotationMatrix(this->orientation.y, vec3(0, 1, 0)) *
						rotationMatrix(this->orientation.z, vec3(0, 0, 1)) *
						translateMatrix(this->position);
}

void GameObject::draw(PerspectiveCamera* camera) 
{
	this->updateModelMatrix();

	shaderProgram->setUniformMat4("MVP", modelMatrix * camera->getViewProjMatrix());

	mesh->draw();
}