#pragma once

#include <map>

#include "Math/vec2.h"
#include "Math/vec3.h"
#include "Math/mat4.h"

namespace Framework {

	class PerspectiveCamera
	{
		vec3 position;
		vec3 ahead;
		vec3 right;
		vec3 up;
		vec3 worldUp;
		float yaw;
		float pitch;
		float roll;

		float fieldOfView;
		float aspectRatio;
		float nearPlane;
		float farPlane;

		float speed;

		bool isDragging;
		vec2 mousePosition;
		vec2 mouseDelta;

		mat4 viewMatrix;
		mat4 projMatrix;
		mat4 viewProjMatrix;

	public:
		PerspectiveCamera();

		void updateViewMatrix();
		void updateProjMatrix();

		void setAspectRatio(float aspectRatio);

		mat4 getViewMatrix();
		mat4 getProjMatrix();
		mat4 getViewProjMatrix();

		void move(double dt, const std::map<unsigned char, bool> &keysPressed);
		void translate(const vec3& t);

		void mouseDown(int pX, int pY);
		void mouseUp();
		void mouseMove(int pX, int pY);

		~PerspectiveCamera() {}
	};

}