#include "CubeGeometry.h"

using namespace Skeleton;

CubeGeometry::CubeGeometry() 
{
	glGenVertexArrays(1, &vao);	// get 1 vao id
	glBindVertexArray(vao);		// make it active

	// vbo vertices
	unsigned int vbo_vertices;
	glGenBuffers(1, &vbo_vertices);	// Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);

	float vertices[] = {
		 0.5f,   0.5f,   0.5f,		//v0
		 0.5f,   0.5f,  -0.5f,		//v1
		-0.5f,   0.5f,  -0.5f,		//v2
		-0.5f,   0.5f,   0.5f,		//v3
		
		 0.5f,  -0.5f,   0.5f,		//v4
		 0.5f,  -0.5f,  -0.5f,		//v5
		-0.5f,  -0.5f,  -0.5f,		//v6
		-0.5f,  -0.5f,   0.5f,		//v7
	};
	glBufferData(GL_ARRAY_BUFFER, 	// Copy to GPU target
		sizeof(vertices),			// # bytes
		vertices,	      			// address
		GL_STATIC_DRAW);			// we do not change later


	// vbo colors
	unsigned int vbo_colors;
	glGenBuffers(1, &vbo_colors);	// Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);

	float colors[] = {
		1.0f,   0.0f,   0.0f,	//c0
		0.0f,   1.0f,   0.0f,	//c1
		0.0f,   0.0f,   1.0f,	//c2
		1.0f,   1.0f,   1.0f,	//c3

		0.0f,   0.0f,   1.0f,	//c4
		1.0f,   1.0f,   1.0f,	//c5
		1.0f,   0.0f,   0.0f,	//c6
		0.0f,   1.0f,   0.0f,	//c7
	};
	glBufferData(GL_ARRAY_BUFFER, 	// Copy to GPU target
		sizeof(colors),				// # bytes
		colors,	      				// address
		GL_STATIC_DRAW);			// we do not change later


	// vbo indices
	glGenBuffers(1, &vbo_indices);	// Generate 1 buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_indices);

	unsigned int indices[] = {
		0, 1, 2,
		0, 3, 2,	// upper

		4, 5, 6,
		4, 7, 6,	// lower

		0, 1, 5,
		0, 4, 5,	// right

		3, 2, 6,
		3, 7, 6,	// left

		0, 3, 7,
		0, 4, 7,	// front

		1, 2, 6,
		1, 5, 6,	// rear
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 	// Copy to GPU target
		sizeof(indices),					// # bytes
		indices,	      					// address
		GL_STATIC_DRAW);					// we do not change later
	
	indexCount = (sizeof(indices) / sizeof(*indices));


	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glEnableVertexAttribArray(0);	// AttribArray 0
	glVertexAttribPointer(0,		// vbo -> AttribArray 0
		3, GL_FLOAT, GL_FALSE,		// three floats/attrib, not fixed-point
		0, NULL); 					// stride, offset: tightly packed

	glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
	glEnableVertexAttribArray(1);	// AttribArray 1
	glVertexAttribPointer(1,		// vbo -> AttribArray 1
		3, GL_FLOAT, GL_FALSE,		// three floats/attrib, not fixed-point
		0, NULL); 					// stride, offset: tightly packed

	glBindVertexArray(0);
}

void CubeGeometry::draw() 
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void*)0);
	glBindVertexArray(0);
}