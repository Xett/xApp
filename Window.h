#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "xEventSystem/EventSystem.h"
#ifndef WINDOW_H
#define WINDOW_H
class Window
{
	EventSystem* event_system;
	GLFWwindow* window;
public:
	Window(EventSystem* event_system, const char* window_name);
	static void WindowResized(GLFWwindow* window, int width, int height);
	static void KeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);
	void MainLoop();
	GLFWwindow* GetWindow();
};
#endif
