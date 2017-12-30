#ifndef WINDOW_H_
#define WINDOW_H_

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

// The window class. Manages the window and input.
class Window
{
private:
	static GLFWwindow * window;
public:
	static void init();
	static void clear();
	static void update();

	static bool isRunning()
	{
		return !glfwWindowShouldClose(window);
	}

	static bool isKeyDown(int key)
	{
		return glfwGetKey(window, key) > 0;	// GLFW returns 1 or 2 when key down
	}
};

#endif