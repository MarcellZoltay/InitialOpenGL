#pragma once

#include <math.h>

namespace Framework {

	struct mat2
	{
		float m[2][2];

		mat2()
		{
			m[0][0] = 1; m[0][1] = 0;
			m[1][0] = 0; m[1][1] = 1;
		}
		mat2(float m00, float m01,
			 float m10, float m11)
		{
			m[0][0] = m00; m[0][1] = m01;
			m[1][0] = m10; m[1][1] = m11;
		}

		mat2 operator*(float a) const
		{
			mat2 result;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					result.m[i][j] = this->m[i][j] * a;
				}
			}
			return result;
		}
		mat2 operator*(const mat2& right) const
		{
			mat2 result;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					result.m[i][j] = 0;
					for (int k = 0; k < 2; k++) result.m[i][j] += m[i][k] * right.m[k][j];
				}
			}
			return result;
		}

		float determinant()
		{
			return m[0][0] * m[1][1] - m[0][1] * m[1][0];
		}

		mat2 transpose()
		{
			return mat2(m[0][0], m[1][0],
						m[0][1], m[1][1]);
		}

		mat2 adjugate()
		{
			return (mat2( m[1][1], -m[1][0],
						 -m[0][1],  m[0][0])).transpose();
		}

		mat2 invert()
		{
			float det = this->determinant();
			if (det == 0.0)
			{
				return *this;
			}

			return mat2(this->adjugate() * ((float)1.0 / det));
		}

		float* operator&()
		{
			return &m[0][0];
		}

	};

}