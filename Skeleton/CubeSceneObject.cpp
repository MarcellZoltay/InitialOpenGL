#include "CubeSceneObject.h"

using namespace Skeleton;

CubeSceneObject::CubeSceneObject()
{
	std::shared_ptr<ShaderProgram> program = ShaderProgram::create("Shaders/basicVS.vert", "Shaders/solidFS.frag");

	std::shared_ptr<Geometry> cubeGeometry = CubeGeometry::create();
	std::shared_ptr<Material> material = SolidMaterial::create(program);

	Mesh *mesh1 = new Mesh(cubeGeometry, material);
	GameObject *gameObj1 = new GameObject(mesh1, program);
	gameObj1->rescale(vec3(0.5, 0.5, 0.5));
	gameObj1->rotate(3.14 / 4.0, vec3(0, 0, 1));
	gameObj1->translate(vec3(0.5, 0.5, 0));
	gameObjects.push_back(gameObj1);
	
	Mesh *mesh2 = new Mesh(cubeGeometry, material);
	GameObject *gameObj2 = new GameObject(mesh2, program);
	gameObj2->rescale(vec3(0.5, 0.5, 0.5));
	gameObj2->rotate(3.14 / 4.0, vec3(0, 0, 1));
	gameObj2->translate(vec3(-0.5, 0.5, 0));
	gameObjects.push_back(gameObj2);
	
	Mesh *mesh3 = new Mesh(cubeGeometry, material);
	GameObject *gameObj3 = new GameObject(mesh3, program);
	gameObj3->rescale(vec3(0.5, 0.5, 0.5));
	gameObj3->rotate(3.14 / 4.0, vec3(0, 0, 1));
	gameObj3->translate(vec3(-0.5, -0.5, 0));
	gameObjects.push_back(gameObj3);
	
	Mesh *mesh4 = new Mesh(cubeGeometry, material);
	GameObject *gameObj4 = new GameObject(mesh4, program);
	gameObj4->rescale(vec3(0.5, 0.5, 0.5));
	gameObj4->rotate(3.14 / 4.0, vec3(0, 0, 1));
	gameObj4->translate(vec3(0.5, -0.5, 0));
	gameObjects.push_back(gameObj4);
		
}

void CubeSceneObject::animate(double dt)
{
	std::vector<GameObject*>::iterator it;
	for (it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->rotateX(dt);
		(*it)->rotateY(dt);

		(*it)->rotate(dt, vec3(0, 0, 1));
	}

}
