#version 330			// Shader 3.3
precision highp float;	// normal floats, makes no difference on desktop computers
	
//uniform vec3 color;		// uniform variable, the color of the primitive

in vec3 vertexColor;
out vec4 outColor;		// computed color of the current pixel

void main() {
	outColor = vec4(vertexColor.x, vertexColor.y, vertexColor.z, 1);	// computed color is the color of the primitive
}