#include "stdafx.h"
#include "Mesh.h"

using namespace Framework;

void Mesh::draw() 
{
	material->commit();
	geometry->draw();
}