// xApp.cpp : Defines the entry point for the application.
//
#include "Application.h"

class MyApplication : public Application
{
public:
	MyApplication(const char* name);
};

MyApplication::MyApplication(const char* name) : Application(name)
{

}

int main()
{
	MyApplication* app = new MyApplication("xApp Demo");
	app->MainLoop();
	return 0;
}
