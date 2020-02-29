// xApp.cpp : Defines the entry point for the application.
//
#include "Application.h"

int main()
{
	Application* app = new Application("Test");
	app->MainLoop();
	return 0;
}
