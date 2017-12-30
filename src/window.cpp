#include "window.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

GLFWwindow * Window::window;

// Initializes GLFW and creates the window.
void Window::init()
{
	if (!glfwInit())
	{
		cout << "Failed to initialize GLFW!\n";
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(800, 600, "Quadcraft 0.1", nullptr, nullptr);
	if (!window)
	{
		cout << "Failed to create window!\n";
		exit(1);
	}
	glfwMakeContextCurrent(window);
}

// Close the window and uninitializes GLFW.
void Window::clear()
{
	glfwTerminate();
}

void Window::update()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}