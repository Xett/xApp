#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
struct Event;
class EventSystem;
class WindowResizeEventDispatcher;
#ifndef WINDOW_H
#define WINDOW_H
class Window
{
	EventSystem* event_system;
	GLFWwindow* window;
	WindowResizeEventDispatcher* window_resize_event_dispatcher;
public:
	Window(EventSystem* event_system, const char* window_name);
	static void glfwWindowResized(GLFWwindow* window, int width, int height);
	static void KeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void WindowResized(Event event);
	void MainLoop();
	GLFWwindow* GetWindow();
	int* GetWidth();
	int* GetHeight();
};
#endif
