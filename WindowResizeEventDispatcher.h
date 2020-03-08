#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "xEventSystem/EventDispatcher.h"
class EventSystem;
class WindowResizeEvent;
class Window;
#ifndef WINDOW_RESIZE_EVENT_DISPATCHER_H
#define WINDOW_RESIZE_EVENT_DISPATCHER_H
class WindowResizeEventDispatcher : public EventDispatcher
{
public:
	WindowResizeEventDispatcher(EventSystem* event_system, int id, Window* window);
	WindowResizeEvent DispatchEvent();
	static void GLFWSetWindowSizeCallback(GLFWwindow* window, int width, int height);
	void CallEvent();
	Window* window;
	EventSystem* event_system;
};
#endif