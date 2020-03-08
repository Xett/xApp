#include "Application.h"
Application::Application(const char* window_name)
{
	this->event_system = new EventSystem();
	glfwSetErrorCallback(this->ShowGLFWError);
	if (!glfwInit())
	{
		std::cerr << "GLFW Error: Failed to initialise!" << '\n';
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	this->window = new Window(this->event_system, window_name);

	glfwSwapInterval(1);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cerr << "GLEW Error: " << glewGetErrorString(err) << '\n';
		glfwTerminate();
		exit(-1);
	}

	std::cout << glGetString(GL_VERSION) << '\n';

	int nr_extensions = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &nr_extensions);

	for (int i = 0; i < nr_extensions; i++)
	{
		std::cout << glGetStringi(GL_EXTENSIONS, i) << '\n';
	}
}

void Application::ShowGLFWError(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << '\n';
}

void Application::MainLoop()
{
	this->window->MainLoop();
	glfwTerminate();
}