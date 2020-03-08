#include "xEventSystem/EventSystem.h"
#include "xEventSystem/Event.h"
#include "WindowResizeEventDispatcher.h"
#include "Window.h"
Window::Window(EventSystem* event_system, const char* window_name)
{
	this->event_system = event_system;
	this->window = glfwCreateWindow(800, 600, window_name, NULL, NULL);
	if (!this->window)
	{
		std::cerr << "window failed to create" << '\n';
		glfwTerminate();
		exit(-1);
	}
	glfwMakeContextCurrent(this->window);
	window_resize_event_dispatcher = new WindowResizeEventDispatcher(this->event_system, 0, this);
	glfwSetWindowSizeCallback(GetWindow(), glfwWindowResized);
	glfwSetKeyCallback(this->window, this->KeyPressed);

	event_system->AddEvent(*window_resize_event_dispatcher);
	event_system->Bind(window_resize_event_dispatcher->GetId(),&WindowResized);
}

void Window::KeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == 'Q' && action == GLFW_PRESS)
	{
		glfwTerminate();
		exit(0);
	}
}

void Window::glfwWindowResized(GLFWwindow* window, int width, int height)
{
	WindowResizeEventDispatcher* event_dispatcher=static_cast<WindowResizeEventDispatcher*>(glfwGetWindowUserPointer(window));
	event_dispatcher->CallEvent();
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(event_dispatcher->window->GetWindow());

	glfwPollEvents();
	event_dispatcher->event_system->ProcessAllAndYieldAll();
}

void Window::WindowResized(Event event)
{
	std::cout << "window Resized!\n";
	//glfwGetWindowSize(window->GetWindow(), window->GetWidth(), window->GetHeight());
	//std::cout << "Window resized, new window size: " << window->GetWidth() << " x " << window->GetHeight() << '\n';

	//glClearColor(0, 0, 1, 1);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glfwSwapBuffers(window->GetWindow());
}

void Window::MainLoop()
{
	glClearColor(0, 0, 1, 1);
	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(this->window);

		glfwPollEvents();
		event_system->ProcessAllAndYieldAll();
	}

	glfwDestroyWindow(this->window);
}

GLFWwindow* Window::GetWindow()
{
	return this->window;
}