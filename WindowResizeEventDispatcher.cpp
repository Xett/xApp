#include "xEventSystem/EventSystem.h"
#include "WindowResizeEvent.h"
#include "Window.h"
#include "WindowResizeEventDispatcher.h"

WindowResizeEventDispatcher::WindowResizeEventDispatcher(EventSystem* event_system, int id, Window* window) : EventDispatcher(id)
{
	this->event_system = event_system;
	this->window = window;
	glfwSetWindowUserPointer(this->window->GetWindow(), this);
}

WindowResizeEvent WindowResizeEventDispatcher::DispatchEvent()
{
	return WindowResizeEvent{ this->GetId(),0,window };
}

void WindowResizeEventDispatcher::CallEvent()
{
	this->event_system->CallEvent(this->GetId());
}