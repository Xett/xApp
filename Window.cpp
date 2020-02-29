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
	glfwSetWindowSizeCallback(this->window, this->WindowResized);
	glfwSetKeyCallback(this->window, this->KeyPressed);
}

void Window::WindowResized(GLFWwindow* window, int width, int height)
{
	std::cout << "Window resized, new window size: " << width << " x " << height << '\n';

	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void Window::KeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == 'Q' && action == GLFW_PRESS)
	{
		glfwTerminate();
		exit(0);
	}
}

void Window::MainLoop()
{
	glClearColor(0, 0, 1, 1);
	while (!glfwWindowShouldClose(this->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(this->window);

		glfwPollEvents();
	}

	glfwDestroyWindow(this->window);
}

GLFWwindow* Window::GetWindow()
{
	return this->window;
}