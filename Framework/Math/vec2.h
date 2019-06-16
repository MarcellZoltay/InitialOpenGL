#pragma once

#include <math.h>

namespace Framework {

	struct vec2
	{
		float x, y;

		vec2(float x0 = 0, float y0 = 0)
		{
			x = x0; y = y0;
		}

		vec2 operator+(const vec2& v) const
		{
			return vec2(x + v.x, y + v.y);
		}
		void operator+=(const vec2 right)
		{
			x += right.x; y += right.y;
		}

		vec2 operator-() const
		{
			return vec2(-x, -y);
		}
		vec2 operator-(const vec2& v) const
		{
			return vec2(x - v.x, y - v.y);
		}

		vec2 operator*(float a) const
		{
			return vec2(x * a, y * a);
		}
		vec2 operator*(const vec2& v) const
		{
			return vec2(x * v.x, y * v.y);
		}
		void operator*=(const vec2 right) 
		{
			x *= right.x; y *= right.y;
		}

	};
}