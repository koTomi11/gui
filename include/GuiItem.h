#pragma once

#include <vector>
#include "IRender2d.h"

enum ItemState
{
	ItemState_NORMAL,
	ItemState_HOVERED,
	ItemState_PRESSED,
};

class GuiItem
{

public:

	bool m_mouseOn;
	ItemState m_state;
	int m_x, m_y, m_width, m_height;
	int m_globalX, m_globalY;
	GuiItem* m_parents;



	bool m_visible;
	std::vector<GuiItem*> m_items;

	GuiItem(int x, int y, int width, int height);
	void addChild(GuiItem* item);

	void draw();
	void update();
	void remove();
	
	virtual void activated();
	virtual void drawNormal(IRender2d* r);
	virtual void drawHovered(IRender2d* r);
	virtual void drawPressed(IRender2d* r);

};