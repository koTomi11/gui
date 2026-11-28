#pragma once

#include "IWindow.h"
#include "IRender2d.h"
#include "GuiItem.h"

class GuiContext
{

public:

	static IWindow* WINDOW;
	static IRender2d* RENDER;
	static GuiItem* ROOT;

	static IRender2d* getRender();

	static void calculateGlobalPositions();

};