#include "xEventSystem/Event.h"
class Window;
#ifndef WINDOW_RESIZE_EVENT_H
#define WINDOW_RESIZE_EVENT_H
struct WindowResizeEvent
{
	int event_id;
	int owner_object_id;
	Window* window;
};
#endif