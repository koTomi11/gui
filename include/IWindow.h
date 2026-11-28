#pragma once

class IWindow
{

public:

	virtual int getWidth() = 0;
	virtual int getHeight() = 0;

	virtual bool isMouseLeftClick() = 0;
	virtual bool isMouseRightClick() = 0;

	virtual int getMouseX() = 0;
	virtual int getMouseY() = 0;

};