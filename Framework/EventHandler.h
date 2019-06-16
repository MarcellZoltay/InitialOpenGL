#pragma once

namespace Framework 
{

	// Idle event indicating that some time elapsed: do animation here
	void onIdle();

	// Window has become invalid
	void onDisplay();

	// Window is resized
	void onReshape(int width, int height);
	
	// Key of ASCII code pressed
	void onKeyboard(unsigned char key, int pX, int pY);
	
	// Key of ASCII code released
	void onKeyboardUp(unsigned char key, int pX, int pY);
	
	// Mouse click event
	void onMouse(int button, int state, int pX, int pY);
	
	// Move mouse with key pressed
	void onMouseMotion(int pX, int pY);
	
}