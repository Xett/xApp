#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"
#include "xEventSystem/EventSystem.h"
#ifndef APPLICATION_H
#define APPLICATION_H
class Application
{
	Window* window;
	EventSystem* event_system;
public:
	Application(const char* window_name);
	static void ShowGLFWError(int error, const char* description);
	void MainLoop();
};

#endif