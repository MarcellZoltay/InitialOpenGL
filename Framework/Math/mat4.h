#pragma once

#include <math.h>
#include "vec3.h"
#include "mat3.h"

namespace Framework {

	struct mat4
	{
		float m[4][4];

		mat4() 
		{
			m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
			m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
			m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
			m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
		}
		mat4(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23,
			 float m30, float m31, float m32, float m33) 
		{
			m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
			m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
			m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
			m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
		}

		mat4 operator*(float a) const
		{
			mat4 result;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					result.m[i][j] = this->m[i][j] * a;
				}
			}
			return result;
		}
		mat4 operator*(const mat4& right) const 
		{
			mat4 result;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					result.m[i][j] = 0;
					for (int k = 0; k < 4; k++) result.m[i][j] += m[i][k] * right.m[k][j];
				}
			}
			return result;
		}

		float determinant()
		{
			float subDetM00 = mat3(m[1][1], m[1][2], m[1][3],
								   m[2][1], m[2][2], m[2][3],
								   m[3][1], m[3][2], m[3][3]).determinant();

			float subDetM01 = mat3(m[1][0], m[1][2], m[1][3],
								   m[2][0], m[2][2], m[2][3],
								   m[3][0], m[3][2], m[3][3]).determinant();

			float subDetM02 = mat3(m[1][0], m[1][1], m[1][3],
								   m[2][0], m[2][1], m[2][3],
								   m[3][0], m[3][1], m[3][3]).determinant();

			float subDetM03 = mat3(m[1][0], m[1][1], m[1][2],
								   m[2][0], m[2][1], m[2][2],
								   m[3][0], m[3][1], m[3][2]).determinant();

			return m[0][0] * subDetM00 - m[0][1] * subDetM01 + m[0][2] * subDetM02 - m[0][3] * subDetM03;
		}

		mat4 transpose()
		{
			return mat4(m[0][0], m[1][0], m[2][0], m[3][0],
						m[0][1], m[1][1], m[2][1], m[3][1],
						m[0][2], m[1][2], m[2][2], m[3][2],
						m[0][3], m[1][3], m[2][3], m[3][3]);
		}

		mat4 adjugate()
		{
			float subDetM00 = mat3(m[1][1], m[1][2], m[1][3],
								   m[2][1], m[2][2], m[2][3],
								   m[3][1], m[3][2], m[3][3]).determinant();

			float subDetM01 = mat3(m[1][0], m[1][2], m[1][3],
								   m[2][0], m[2][2], m[2][3],
								   m[3][0], m[3][2], m[3][3]).determinant();

			float subDetM02 = mat3(m[1][0], m[1][1], m[1][3],
								   m[2][0], m[2][1], m[2][3],
								   m[3][0], m[3][1], m[3][3]).determinant();

			float subDetM03 = mat3(m[1][0], m[1][1], m[1][2],
								   m[2][0], m[2][1], m[2][2],
								   m[3][0], m[3][1], m[3][2]).determinant();

			float subDetM10 = mat3(m[0][1], m[0][2], m[0][3],
								   m[2][1], m[2][2], m[2][3],
								   m[3][1], m[3][2], m[3][3]).determinant();

			float subDetM11 = mat3(m[0][0], m[0][2], m[0][3],
								   m[2][0], m[2][2], m[2][3],
								   m[3][0], m[3][2], m[3][3]).determinant();

			float subDetM12 = mat3(m[0][0], m[0][1], m[0][3],
								   m[2][0], m[2][1], m[2][3],
								   m[3][0], m[3][1], m[3][3]).determinant();

			float subDetM13 = mat3(m[0][0], m[0][1], m[0][2],
								   m[2][0], m[2][1], m[2][2],
								   m[3][0], m[3][1], m[3][2]).determinant();

			float subDetM20 = mat3(m[0][1], m[0][2], m[0][3],
								   m[1][1], m[1][2], m[1][3],
								   m[3][1], m[3][2], m[3][3]).determinant();

			float subDetM21 = mat3(m[0][0], m[0][2], m[0][3],
								   m[1][0], m[1][2], m[1][3],
								   m[3][0], m[3][2], m[3][3]).determinant();

			float subDetM22 = mat3(m[0][0], m[0][1], m[0][3],
								   m[1][0], m[1][1], m[1][3],
								   m[3][0], m[3][1], m[3][3]).determinant();

			float subDetM23 = mat3(m[0][0], m[0][1], m[0][2],
								   m[1][0], m[1][1], m[1][2],
								   m[3][0], m[3][1], m[3][2]).determinant();

			float subDetM30 = mat3(m[0][1], m[0][2], m[0][3],
								   m[1][1], m[1][2], m[1][3],
								   m[2][1], m[0][2], m[2][3]).determinant();

			float subDetM31 = mat3(m[0][0], m[0][2], m[0][3],
								   m[1][0], m[1][2], m[1][3],
								   m[2][0], m[2][2], m[2][3]).determinant();

			float subDetM32 = mat3(m[0][0], m[0][1], m[0][3],
								   m[1][0], m[1][1], m[1][3],
								   m[2][0], m[2][1], m[2][3]).determinant();

			float subDetM33 = mat3(m[0][0], m[0][1], m[0][2],
								   m[1][0], m[1][1], m[1][2],
								   m[2][0], m[2][1], m[2][2]).determinant();

			return (mat4( subDetM00, -subDetM01,  subDetM02, -subDetM03,
						 -subDetM10,  subDetM11, -subDetM12,  subDetM13,
						  subDetM20, -subDetM21,  subDetM22, -subDetM23,
						 -subDetM30,  subDetM31, -subDetM32,  subDetM33)).transpose();
		}

		mat4 invert()
		{
			float det = this->determinant();
			if (det == 0.0)
			{
				return *this;
			}

			return mat4(this->adjugate() * ((float)1.0 / det));
		}

		float* operator&() 
		{
			return &m[0][0];
		}

	};


	inline mat4 scaleMatrix(vec3 s) {
		return mat4(s.x, 0, 0, 0,
					0, s.y, 0, 0,
					0, 0, s.z, 0,
					0, 0, 0, 1);
	}
	inline mat4 rotationMatrix(float angle, vec3 r) {
		float c = cosf(angle), s = sinf(angle);
		r = normalize(r);
		return mat4(c + (r.x*r.x)*(1 - c),		r.x*r.y*(1 - c) - r.z*s,	r.x*r.z*(1 - c) + r.y*s,	0,
					r.y*r.x*(1 - c) + r.z*s,	c + (r.y*r.y)*(1 - c),		r.y*r.z*(1 - c) - r.x*s,	0,
					r.z*r.x*(1 - c) - r.y*s,	r.z*r.y*(1 - c) + r.x*s,	c + (r.z*r.z)*(1 - c),		0,
					0, 0, 0, 1);
	}
	inline mat4 translateMatrix(vec3 t) {
		return mat4(1, 0, 0, 0,
					0, 1, 0, 0,
					0, 0, 1, 0,
					t.x, t.y, t.z, 1);
	}

}