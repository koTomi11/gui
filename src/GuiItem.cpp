#include <GuiItem.h>

#include "GuiContext.h"

#include <iostream>

GuiItem::GuiItem(int x, int y, int width, int height)
{
	m_x = x; m_y = y; m_width = width; m_height = height;
	m_state = ItemState_NORMAL;

	m_globalX = m_x;
	m_globalY = m_y;
}

void GuiItem::addChild(GuiItem* item)
{
	item->m_parents = this;
	m_items.push_back(item);
}


void GuiItem::draw()
{
	switch(m_state)
	{

		case ItemState_NORMAL: drawNormal(GuiContext::getRender()); break;
		case ItemState_HOVERED: drawHovered(GuiContext::getRender()); break;
		case ItemState_PRESSED: drawPressed(GuiContext::getRender()); break;

	}
}

void GuiItem::update()
{
	IWindow* w = GuiContext::WINDOW;
	
	if (w->getMouseX() > m_globalX && w->getMouseY() > m_globalY &&
		w->getMouseX() < m_globalX + m_width && w->getMouseY() < m_globalY + m_height)
	{
		m_mouseOn = true;
	}
	else
	{
		m_mouseOn = false;
	}

	
	if (m_mouseOn)
	{
		if (GuiContext::WINDOW->isMouseLeftClick())
		{
			
			if (m_state == ItemState_HOVERED || m_state == ItemState_PRESSED)
			{
				m_state = ItemState_PRESSED;
			}
		}
		else
		{
			
			if (m_state == ItemState_PRESSED)
			{
				activated();
			}
			m_state = ItemState_HOVERED;
		}
	}
	else
	{
		m_state = ItemState_NORMAL;
	}

}

void GuiItem::activated()
{

}

void GuiItem::remove()
{

}

void GuiItem::drawNormal(IRender2d* r)
{
	r->setColor(10, 80, 181);
	r->fillRect(m_x, m_y, m_width, m_height);
}

void GuiItem::drawHovered(IRender2d* r)
{
	drawNormal(r);
	r->setColor(10, 10, 181);
	r->fillRect(m_x, m_y, m_width, m_height);
}

void GuiItem::drawPressed(IRender2d* r)
{
	drawNormal(r);
	r->setColor(10,200, 181);
	r->fillRect(m_x, m_y, m_width, m_height);
}
