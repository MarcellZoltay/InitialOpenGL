#pragma once

#include <math.h>
#include "vec3.h"
#include "mat4.h"

namespace Framework {

	struct vec4 {

		float x, y, z, w;

		vec4(float x0 = 0, float y0 = 0, float z0 = 0, float w0 = 0) 
		{
			x = x0; y = y0; z = z0; w = w0;
		}
		vec4(const vec3& v, float w0 = 1)
		{
			x = v.x; y = v.y; z = v.z; w = w0;
		}

		vec4 operator+(const vec4& v) const 
		{
			return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
		}
		void operator+=(const vec4 right) {
			x += right.x; y += right.y; z += right.z, w += right.w;
		}

		vec4 operator-(const vec4& v) const 
		{
			return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
		}
		void operator-=(const vec4 right) {
			x -= right.x; y -= right.y; z -= right.z, w -= right.z;
		}

		vec4 operator*(float a) const 
		{ 
			return vec4(x * a, y * a, z * a, w * a); 
		}
		vec4 operator*(const vec4& v) const 
		{
			return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
		}

		vec4 operator/(float d) const 
		{ 
			return vec4(x / d, y / d, z / d, w / d);
		}

		vec4 operator*(const mat4& mat) 
		{
			return vec4(x * mat.m[0][0] + y * mat.m[1][0] + z * mat.m[2][0] + w * mat.m[3][0],
						x * mat.m[0][1] + y * mat.m[1][1] + z * mat.m[2][1] + w * mat.m[3][1],
						x * mat.m[0][2] + y * mat.m[1][2] + z * mat.m[2][2] + w * mat.m[3][2],
						x * mat.m[0][3] + y * mat.m[1][3] + z * mat.m[2][3] + w * mat.m[3][3]);
		}

		vec3 xyz()
		{
			return vec3(x, y, z);
		}

	};


	inline float dot(const vec4& v1, const vec4& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
	}

}

