#pragma once

#include <math.h>
#include "mat2.h"

namespace Framework {

	struct mat3
	{
		float m[3][3];

		mat3()
		{
			m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
			m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
			m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
		}
		mat3(float m00, float m01, float m02,
			 float m10, float m11, float m12,
			 float m20, float m21, float m22)
		{
			m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
			m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
			m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
		}

		mat3 operator*(float a) const
		{
			mat3 result;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					result.m[i][j] = this->m[i][j] * a;
				}
			}
			return result;
		}
		mat3 operator*(const mat3& right) const
		{
			mat3 result;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					result.m[i][j] = 0;
					for (int k = 0; k < 3; k++) result.m[i][j] += m[i][k] * right.m[k][j];
				}
			}
			return result;
		}

		float determinant()
		{
			float subDetM00 = mat2(m[1][1], m[1][2],
								   m[2][1], m[2][2]).determinant();

			float subDetM01 = mat2(m[1][0], m[1][2],
								   m[2][0], m[2][2]).determinant();

			float subDetM02 = mat2(m[1][0], m[1][1],
								   m[2][0], m[2][1]).determinant();

			return m[0][0] * subDetM00 - m[0][1] * subDetM01 + m[0][2] * subDetM02;
		}

		mat3 transpose()
		{
			return mat3(m[0][0], m[1][0], m[2][0],
						m[0][1], m[1][1], m[2][1],
						m[0][2], m[1][2], m[2][2]);
		}

		mat3 adjugate()
		{
			float subDetM00 = mat2(m[1][1], m[1][2],
								   m[2][1], m[2][2]).determinant();

			float subDetM01 = mat2(m[1][0], m[1][2],
								   m[2][0], m[2][2]).determinant();

			float subDetM02 = mat2(m[1][0], m[1][1],
								   m[2][0], m[2][1]).determinant();
			
			float subDetM10 = mat2(m[0][1], m[0][2],
								   m[2][1], m[2][2]).determinant();

			float subDetM11 = mat2(m[0][0], m[0][2],
								   m[2][0], m[2][2]).determinant();

			float subDetM12 = mat2(m[0][0], m[0][1],
								   m[2][0], m[2][1]).determinant();

			float subDetM20 = mat2(m[0][1], m[0][2],
								   m[1][1], m[1][2]).determinant();

			float subDetM21 = mat2(m[0][0], m[0][2],
								   m[1][0], m[1][2]).determinant();

			float subDetM22 = mat2(m[0][0], m[0][1],
								   m[1][0], m[1][1]).determinant();

			return (mat3( subDetM00, -subDetM01,  subDetM02,
						 -subDetM10,  subDetM11, -subDetM12,
						  subDetM20, -subDetM21,  subDetM22)).transpose();
		}

		mat3 invert()
		{
			float det = this->determinant();
			if (det == 0.0)
			{
				return *this;
			}

			return mat3(this->adjugate() * ((float)1.0 / det));
		}

		float* operator&()
		{
			return &m[0][0];
		}

	};

}