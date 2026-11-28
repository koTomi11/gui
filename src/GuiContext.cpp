#include "GuiContext.h"

IWindow* GuiContext::WINDOW;
IRender2d* GuiContext::RENDER;
GuiItem* GuiContext::ROOT;
GuiItem* GuiContext::ACTIVATED;

IRender2d* GuiContext::getRender()
{
	return RENDER;
}

void GuiContext::calculateGlobalPositions()
{
	int x = 0, y = 0;

	GuiItem* item = ROOT;
	while (item != nullptr)
	{
		x += item->m_x;
		
		//globalY += item->m_y;

		//item = item->m_parent;
	}
}
