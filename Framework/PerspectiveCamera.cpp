#include "PerspectiveCamera.h"

using namespace Framework;

PerspectiveCamera::PerspectiveCamera()
{
	position = vec3();
	ahead = vec3(0, 0, -1);
	right = vec3(1, 0, 0);
	up = vec3(0, 1, 0);

	worldUp = vec3(0, 1, 0);

	yaw = 0;
	pitch = 0;
	roll = 0;

	fieldOfView = 1;
	aspectRatio = 1;
	nearPlane = 0.1;
	farPlane = 1000.0;

	speed = 1;

	isDragging = false;
	mousePosition = vec2();
	mouseDelta = vec2();

	viewMatrix = mat4();
	projMatrix = mat4();
	viewProjMatrix = mat4();

	this->updateViewMatrix();
	this->updateProjMatrix();
}

void PerspectiveCamera::updateViewMatrix()
{
	this->viewMatrix = (mat4(
		 this->right.x,	 this->right.y,  this->right.z, 0,
		 this->up.x,	 this->up.y,	 this->up.z,	0,
		-this->ahead.x, -this->ahead.y, -this->ahead.z, 0,
		 0, 0, 0, 1) 
		* translateMatrix(this->position)).invert();
	this->viewProjMatrix = this->viewMatrix * this->projMatrix;
}
void PerspectiveCamera::updateProjMatrix()
{
	float yScale = 1.0 / tanf(this->fieldOfView * 0.5);
	float xScale = yScale / this->aspectRatio;
	float n = this->nearPlane;
	float f = this->farPlane;

	this->projMatrix = mat4(
		xScale,	0,		0,			  0,
		0,		yScale,	0,			  0,
		0,		0,		(n+f)/(n-f), -1,
		0,		0,		2*n*f/(n-f),  0);
	this->viewProjMatrix = this->viewMatrix * this->projMatrix;
}

void PerspectiveCamera::setAspectRatio(float aspectRatio)
{
	this->aspectRatio = aspectRatio;
	this->updateProjMatrix();
}

mat4 PerspectiveCamera::getViewMatrix()
{
	return this->viewMatrix;
}
mat4 PerspectiveCamera::getProjMatrix()
{
	return this->projMatrix;
}
mat4 PerspectiveCamera::getViewProjMatrix()
{
	return this->viewProjMatrix;
}

void PerspectiveCamera::move(double dt, const std::map<unsigned char, bool> &keysPressed)
{
	if (isDragging)
	{
		this->yaw -= this->mouseDelta.x * 0.002;
		this->pitch -= this->mouseDelta.y * 0.002;

		if (this->pitch > 3.14 / 2.0)
		{
			this->pitch = 3.14 / 2.0;
		}
		if (this->pitch < -3.14 / 2.0)
		{
			this->pitch = -3.14 / 2.0;
		}

		this->mouseDelta = vec2();

		this->ahead = vec3(
			-sinf(this->yaw) * cosf(this->pitch),
			sinf(this->pitch),
			-cosf(this->yaw) * cos(this->pitch)
		);
		this->right = cross(this->ahead, this->worldUp);
		this->right = normalize(this->right);
		this->up = cross(this->right, this->ahead);
	}

	std::map<unsigned char, bool>::const_iterator itW = keysPressed.find('w');
	std::map<unsigned char, bool>::const_iterator itS = keysPressed.find('s');
	std::map<unsigned char, bool>::const_iterator itA = keysPressed.find('a');
	std::map<unsigned char, bool>::const_iterator itD = keysPressed.find('d');
	std::map<unsigned char, bool>::const_iterator itE = keysPressed.find('e');
	std::map<unsigned char, bool>::const_iterator itQ = keysPressed.find('q');

	if (itW != keysPressed.end() && itW->second)
	{
		this->position += this->ahead * (dt * this->speed);
	}
	if (itS != keysPressed.end() && itS->second)
	{
		this->position += this->ahead * (-dt * this->speed);
	}
	if (itD != keysPressed.end() && itD->second)
	{
		this->position += this->right * (dt * this->speed);
	}
	if (itA != keysPressed.end() && itA->second)
	{
		this->position += this->right * (-dt * this->speed);
	}
	if (itE != keysPressed.end() && itE->second)
	{
		this->position += this->worldUp * (dt * this->speed);
	}
	if (itQ != keysPressed.end() && itQ->second)
	{
		this->position += this->worldUp * (-dt * this->speed);
	}

	this->updateViewMatrix();
}
void PerspectiveCamera::translate(const vec3& t)
{
	this->position += t;
	this->updateViewMatrix();
}

void PerspectiveCamera::mouseDown(int pX, int pY)
{
	isDragging = true;
	mousePosition.x = pX;
	mousePosition.y = pY;
	mouseDelta = vec2();
}
void PerspectiveCamera::mouseUp()
{
	isDragging = false;
	mousePosition = vec2();
}
void PerspectiveCamera::mouseMove(int x, int y)
{
	mouseDelta.x = x - mousePosition.x;
	mouseDelta.y = y - mousePosition.y;
	mousePosition.x = x;
	mousePosition.y = y;
}