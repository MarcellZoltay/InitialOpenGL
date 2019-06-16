#include "stdafx.h"
#include "Material.h"

using namespace Framework;

void Material::commit() 
{
	shaderProgram->use();
}
