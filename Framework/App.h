#pragma once

#include <windows.h>
#include <map>

#include "Scene.h"
#include "PerspectiveCamera.h"

#include "GL/glew.h"
#include "GL/freeglut.h"


namespace Framework {

	class App
	{
	protected:
		unsigned int windowWidth = 600;
		unsigned int windowHeight = 600;

		double lastTime;

		std::map<unsigned char, bool> keysPressed;
		
		PerspectiveCamera *camera;
		Scene *scene;

		virtual Scene* newScene() = 0;
	
	public:
		App(int argc, char * argv[]);

		void createScene();
		void run();

		void update();
		void render();

		void resize(int width, int height);

		void keyPressed(unsigned char key);
		void keyReleased(unsigned char key);

		void mouseDown(int pX, int pY);
		void mouseUp();
		void mouseMove(int pX, int pY);

		virtual ~App()
		{
			delete camera;
			delete scene;
		}
	};
}